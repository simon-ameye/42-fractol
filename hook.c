/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:48:45 by sameye            #+#    #+#             */
/*   Updated: 2021/09/08 18:30:40 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_press(int keycode, t_mlx *mlx)
{
	double	sensib;

	sensib = 0.1 / mlx->view.scale;
	if (keycode == KEY_UP_M || keycode == KEY_UP_L)
		mlx->view.y -= sensib;
	if (keycode == KEY_DOWN_M || keycode == KEY_DOWN_L)
		mlx->view.y += sensib;
	if (keycode == KEY_LEFT_M || keycode == KEY_LEFT_L)
		mlx->view.x -= sensib;
	if (keycode == KEY_RIGHT_M || keycode == KEY_RIGHT_L)
		mlx->view.x += sensib;
	if (keycode == KEY_PLUS_M || keycode == KEY_PLUS_L)
		mlx->view.scale *= 1.1;
	if (keycode == KEY_MINUS_M || keycode == KEY_MINUS_L)
		mlx->view.scale *= 0.9;
	if (keycode == KEY_SPACE_M || keycode == KEY_SPACE_L)
		init_view(mlx);
	if (keycode == KEY_ESC_M || keycode == KEY_ESC_L)
	{
		destroy(mlx);
		return (EXIT_SUCCESS);
	}
	computeprint(mlx);
	return (EXIT_SUCCESS);
}

int	mouse_press(int keycode, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (keycode == 4)
		mlx->view.scale *= 1.1;
	if (keycode == 5)
		mlx->view.scale *= 0.9;
	computeprint(mlx);
	return (EXIT_SUCCESS);
}

int	destroy_press(int keycode, int x, int y, t_mlx *mlx)
{
	(void) keycode;
	(void) x;
	(void) y;
	(void) mlx;
	exit(EXIT_SUCCESS);
}
