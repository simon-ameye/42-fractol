/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:50 by sameye            #+#    #+#             */
/*   Updated: 2021/09/08 16:03:14 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, WIN_NAME);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.size_l, &mlx->img.endian);
}

void	init_view(t_mlx *mlx)
{
	mlx->view.scale = 1;
	mlx->view.x = 0;
	if (mlx->frac.frac == 'm')
		mlx->view.x = -0.66;
	mlx->view.y = 0;
}

int	destroy(t_mlx *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	if (mlx->img.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	free (mlx->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
