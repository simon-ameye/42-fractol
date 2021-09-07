/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:55 by sameye            #+#    #+#             */
/*   Updated: 2021/09/07 11:33:27 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

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

void setfracttype(t_mlx *mlx, t_complex *z, t_complex *c, t_pix *p)
{
	if (mlx->frac.frac == 'm')
	{
		*z = zerocplx();
		*c = pixtocplx(p, mlx);
	}
	if (mlx->frac.frac == 'j')
	{
		*z = pixtocplx(p, mlx);
		*c = (t_complex){.r = C_RE, .i = C_IM};
	}
}

void itercplx(t_pix *p, t_mlx *mlx)
{
	t_complex z;
	t_complex c;
	setfracttype(mlx, &z, &c, p);
	p->iter = 0;
	while (p->iter < MAX_ITER)
	{
		z = sum(square(z), c);
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
	drawfractal(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (1);
}
int fracparse(char * frac, t_mlx *mlx)
{
	if (ft_strncmp(frac, "julia", ft_strlen("julia") + 1) == 0)
	{
		mlx->frac.frac = 'j';
		return (1);
	}
	if (ft_strncmp(frac, "mandelbrot", ft_strlen("mandelbrot") + 1) == 0)
	{
		mlx->frac.frac = 'm';
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_mlx mlx;

	if (ac < 2)
		return (0);
	if (fracparse(av[1], &mlx) == 0)
		return (0);
	init_mlx(&mlx);
	init_view(&mlx);
		clock_t begin = clock();
	drawfractal(&mlx);
		clock_t end1 = clock();
		printf("time1%f", (double)(end1 - begin) / CLOCKS_PER_SEC);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
		clock_t end2 = clock();
		printf("time2%f", (double)(end2 - begin) / CLOCKS_PER_SEC);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}