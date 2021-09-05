/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:50 by sameye            #+#    #+#             */
/*   Updated: 2021/09/03 18:01:05 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window init_window(void)
{
	t_window window;

	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, WIN_X, WIN_Y, WIN_NAME);
	window.img = mlx_new_image(window.mlx, WIN_X, WIN_Y);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel, &window.line_length,
								&window.endian);
	return(window);
}