/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:55 by sameye            #+#    #+#             */
/*   Updated: 2021/09/06 14:50:17 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int interpol (int x, int x0, int x1, int y0, int y1)
{
	if (x <= x0)
		return (y0);
	if (x >= x1)
		return (y1);
	return (y0 + (x - x0) * (y1 - y0) / (x1 - x0));
}

int	iter2color(int i)
{
	int r;
	int g;
	int b;

	b = interpol(i, MAX_ITER * 0 / 3, MAX_ITER * 1 / 3, 255, 0);
	g = interpol(i, MAX_ITER * 1 / 3, MAX_ITER * 2 / 3, 255, 0);
	r = interpol(i, MAX_ITER * 2 / 3, MAX_ITER * 3 / 3, 255, 0);
	return (create_trgb(r, g, b));
}

void	my_mlx_pixel_put(t_window *window, int x, int y, int color)
{
	char	*dst;

	dst = window->addr + (y * window->line_length + x * (window->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_complex pixtocplx(t_pix p, t_view view)
{
	t_complex res;

	res.r = 1.5 * (p.x - WIN_X / 2) / (0.5 * view.scale * WIN_X) + view.x;
	res.i = (p.y - WIN_Y / 2) / (0.5 * view.scale * WIN_Y) + view.y;
	return (res);
}

int main(void)
{
	t_window window;
	t_complex z;
	t_complex c;
	t_view view;
	t_pix p;
	double modul;

	window = init_window();
	
	p.x = 0;
	c.r = -0.5;
	c.i = 0.5;
	modul = 2;
	view.scale = 2.0;
	view.x = 0;
	view.y = 0;

	while (p.x < WIN_X)
	{
		p.y = 0;
		while (p.y < WIN_Y)
		{
			p.iter = 0;
			z = pixtocplx(p, view);
			while (p.iter < MAX_ITER)
			{
				//printf("x%i, y%i, iter%i, r%f, i%f\n", p.x, p.y, p.iter, z.r, z.i);
				z = sum(square(z), c);
				if( squaremodul(z) > modul * modul)
					break;
				p.iter++;
			}
			//printf("iter%i\n", p.iter);
			my_mlx_pixel_put(&window, p.x, p.y, iter2color(p.iter));
			p.y++;
		}
		p.x++;
	}
	mlx_put_image_to_window(window.mlx, window.mlx_win, window.img, 0, 0);
	mlx_loop(window.mlx);
}