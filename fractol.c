/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:55 by sameye            #+#    #+#             */
/*   Updated: 2021/09/05 18:42:12 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_window *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void pixtocplx(t_pix p, t_window win)
{
	
}

int main(void)
{
	t_window window;

	t_complex z;
	t_complex c;
	t_view view;
	t_pix p;
	int iter;
	double n;

	window = init_window();
	
	my_mlx_pixel_put(&window, 5, 5, 0x00FF0000);
	p.x = 0;
	p.y = 0;
	c.r = -0.5;
	c.i = 0.5;
	n = 4;
	view.scale = 1;
	view.x = 0;
	view.y = 0;

	

	

	while (p.x <= WIN_X)
	{
		while (p.y <= WIN_Y)
		{
			iter = 0;
			norm = 0;
			p = 
			while (norm <= n)
			{
				
			}
			p.x++;
			p.y++;
		}
	}


	mlx_put_image_to_window(window.mlx, window.mlx_win, window.img, 0, 0);

	mlx_loop(window.mlx);
}