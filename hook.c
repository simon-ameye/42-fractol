/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:48:45 by sameye            #+#    #+#             */
/*   Updated: 2021/09/07 22:22:55 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_press(int keycode, t_mlx *mlx)
{
	double sensib;

	printf("keyboard:%i\n", keycode);
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
		destroy(mlx);
		return(EXIT_SUCCESS);
	}
	drawfractal(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return(EXIT_SUCCESS);
}

int mouse_press(int keycode, int x, int y, t_mlx *mlx)
{
	printf("mouse : %i, %i, %i\n", keycode, x, y);
	if (keycode == 4)
		mlx->view.scale *= 1.1;
	if (keycode == 5)
		mlx->view.scale *= 0.9;
	drawfractal(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

int destroy_press(int keycode, int x, int y, t_mlx *mlx)
{
	(void) keycode;
	(void) x;
	(void) y;
	(void) mlx;
	exit(EXIT_SUCCESS);
}