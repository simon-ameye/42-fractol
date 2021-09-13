/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:19:51 by sameye            #+#    #+#             */
/*   Updated: 2021/09/13 11:46:08 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_params(int ac, char **av, t_mlx *mlx)
{	
	int	r;
	int	i;

	mlx->frac.c_re = C_RE;
	mlx->frac.c_im = C_IM;
	if (ac == 4)
	{
		r = ft_atoi(av[2]);
		i = ft_atoi(av[3]);
		if (r >= -100 && r < 100)
		{
			if (i >= 0 && i <= 100)
			{
				mlx->frac.c_re = r / 100.0;
				mlx->frac.c_im = i / 100.0;
			}
		}
	}
}

int	print_params(void)
{
	ft_putstr_fd(PARAM_LIST1, 1);
	ft_putstr_fd(PARAM_LIST2, 1);
	ft_putstr_fd(PARAM_LIST3, 1);
	ft_putstr_fd(PARAM_LIST4, 1);
	return (0);
}
