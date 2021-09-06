/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:55 by sameye            #+#    #+#             */
/*   Updated: 2021/09/06 20:17:38 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int interpol (int x, int x0, int x1, int y0, int y1)
{
	if (x <= x0)
		return (y0);
	if (x >= x1)
		return (y1);
	return (y0 + (x - x0) * (y1 - y0) / (x1 - x0));
}

int	itertocolor(int i)
{
	int r;
	int g;
	int b;

	b = interpol(i, MAX_ITER * 0 / 3, MAX_ITER * 1 / 3, 255, 0);
	g = interpol(i, MAX_ITER * 1 / 3, MAX_ITER * 2 / 3, 255, 0);
	r = interpol(i, MAX_ITER * 2 / 3, MAX_ITER * 3 / 3, 255, 0);
	return (r << 16 | g << 8 | b);
}

t_complex pixtocplx(t_pix *p, t_mlx *mlx)
{
	t_complex res;

	res.r = 1.5 * (p->x - WIN_W / 2) / (0.5 * mlx->view.scale * WIN_W) + mlx->view.x;
	res.i = (p->y - WIN_H / 2) / (0.5 * mlx->view.scale * WIN_H) + mlx->view.y;
	return (res);
}

void itercplx(t_pix *p, t_mlx *mlx)
{
	t_complex z;

	p->iter = 0;
	z = pixtocplx(p, mlx);
	while (p->iter < MAX_ITER)
	{
		z = sum(square(z), (t_complex){.r = C_RE, .i = C_IM});
		if( squaremodul(z) > MODUL * MODUL)
			break;
		p->iter++;
	}
}

void drawfractal(t_mlx *mlx)
{
	t_pix p;

	p.x = 0;
	while (p.x < WIN_W)
	{
		p.y = 0;
		while (p.y < WIN_H)
		{
			itercplx(&p, mlx);
			mlx->img.data[p.y * WIN_W + p.x] = itertocolor(p.iter);
			p.y++;
		}
		p.x++;
	}
}

void init_view(t_mlx *mlx)
{
	mlx->view.scale = 1;
	mlx->view.x = 0;
	mlx->view.y = 0;
}

int	key_hook(int keycode, t_mlx *mlx)
{
	double sensib;

	sensib = 0.1 / mlx->view.scale;
	printf("Hello from key_hook!, %i, %f\n", keycode, sensib);

	if (keycode == 126)
		mlx->view.y -= sensib;
	if (keycode == 125)
		mlx->view.y += sensib;
	if (keycode == 123)
		mlx->view.x -= sensib;
	if (keycode == 124)
		mlx->view.x += sensib;
	if (keycode == 44)
		mlx->view.scale *= 1.1;
	if (keycode == 24)
		mlx->view.scale *= 0.9;
	//mlx->view.scale = mlx->view.scale * 1.5;
	drawfractal(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (1);
}

int main(void)
{
	t_mlx mlx;

	init_mlx(&mlx);
	init_view(&mlx);
	drawfractal(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}