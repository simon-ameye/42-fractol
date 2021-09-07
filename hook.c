/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:48:45 by sameye            #+#    #+#             */
/*   Updated: 2021/09/07 12:43:02 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	double sensib;

	printf("pressed:%i\n", keycode);
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
	if (keycode == 49)
		init_view(mlx);
	if (keycode == 53)
	{
		if (mlx->win != NULL)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win);
		if (mlx->img.img_ptr != NULL)
			mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
		exit(EXIT_SUCCESS);
		return (0);
	}
	drawfractal(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (1);
}