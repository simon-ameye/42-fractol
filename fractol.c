/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:55 by sameye            #+#    #+#             */
/*   Updated: 2021/09/05 20:14:50 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter2color(t_pix p)
{
	return ((unsigned int) p.iter);
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

	res.r = (p.x / WIN_X + view.x -0.5) * view.scale;
	res.i = (p.y / WIN_X + view.y -0.5) * view.scale;
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
	double snorm;

	window = init_window();
	
	p.x = 0;
	p.y = 0;
	c.r = -0.5;
	c.i = 0.5;
	modul = 2;
	view.scale = 1;
	view.x = 0;
	view.y = 0;
	//my_mlx_pixel_put(&window, 5, 5, 0x00FF0000);

	while (p.x < WIN_X)
	{
		p.y = 0;
		while (p.y < WIN_Y)
		{
			p.iter = 0;
			snorm = 0;
			z = pixtocplx(p, view);
			while (snorm <= modul * modul && p.iter < MAX_ITER)
			{
				printf("x%i, y%i, iter%i, r%f, i%f\n", (int) p.x, (int) p.y, (int) p.iter, z.r, z.i);
				z = sum(square(z), c);
				snorm = squaremodul(z);
				p.iter++;
			}
			my_mlx_pixel_put(&window, (int) p.x, (int) p.y, (int) p.iter * 1000000);
			p.y++;
		}
		p.x++;
	}

	mlx_put_image_to_window(window.mlx, window.mlx_win, window.img, 0, 0);
	mlx_loop(window.mlx);
}