/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:55 by sameye            #+#    #+#             */
/*   Updated: 2021/09/05 23:50:14 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_color (t_pix p)
{
	(void) p;
	return (0x00);
}

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

	//printf("r%fr%f\n", res.r, res.i);
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
	int max_iter;
	int color;

	window = init_window();
	
	p.x = 0;
	p.y = 0;
	c.r = -0.5;
	c.i = 0.5;
	modul = 2;
	view.scale = 1.0;
	view.x = 0;
	view.y = 0;
	max_iter = 0;

	//my_mlx_pixel_put(&window, 5, 5, 0x00FF0000);

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
			color = p.iter;
			//printf("iter%i\n", p.iter);
			my_mlx_pixel_put(&window, p.x, p.y, color);
			p.y++;
			if (p.iter > max_iter)
				max_iter = p.iter;
		}
		p.x++;
	}
	printf("max%i", max_iter);
	mlx_put_image_to_window(window.mlx, window.mlx_win, window.img, 0, 0);
	mlx_loop(window.mlx);
}