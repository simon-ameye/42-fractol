/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:55 by sameye            #+#    #+#             */
/*   Updated: 2021/09/10 19:20:17 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

void	setfracttype(t_mlx *mlx, t_complex *z, t_complex *c, t_pix *p)
{
	if (mlx->frac.frac == 'm')
	{
		*z = czerocplx();
		*c = pixtocplx(p, mlx);
	}
	if (mlx->frac.frac == 'j')
	{
		*z = pixtocplx(p, mlx);
		*c = (t_complex){.r = mlx->frac.c_re, .i = mlx->frac.c_im};
	}
}

int	fracparse(char *frac, t_mlx *mlx)
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

int	entrycheck(int ac, char **av, t_mlx *mlx)
{
	if (ac < 2)
		return (print_params());
	if (fracparse(av[1], mlx) == 0)
		return (print_params());
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (entrycheck(ac, av, &mlx) == 0)
		return (0);
	init_mlx(&mlx);
	get_params(ac, av, &mlx);
	init_view(&mlx);
	computeprint(&mlx);
	mlx_key_hook(mlx.win, keyboard_press, &mlx);
	mlx_hook(mlx.win, 4, 1L << 2, mouse_press, &mlx);
	mlx_hook(mlx.win, 17, 1L << 2, destroy, &mlx);
	mlx_hook(mlx.win, 15, 1L << 2, computeprint, &mlx);
	mlx_hook(mlx.win, 12, 1L << 15, computeprint, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
