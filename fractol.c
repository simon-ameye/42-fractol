/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:55 by sameye            #+#    #+#             */
/*   Updated: 2021/09/07 12:33:35 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

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

int entrycheck(int ac, char **av, t_mlx *mlx)
{
	if (ac < 2)
	{
		ft_putstr_fd(PARAM_LIST, 1);
		return (0);
	}
	if (fracparse(av[1], mlx) == 0)
	{
		ft_putstr_fd(PARAM_LIST, 1);
		return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	t_mlx mlx;

	if (entrycheck(ac, av, &mlx) == 0)
		return (0);
	init_mlx(&mlx);
	init_view(&mlx);
	drawfractal(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}