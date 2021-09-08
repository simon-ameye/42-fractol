/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:51:51 by sameye            #+#    #+#             */
/*   Updated: 2021/09/08 15:55:08 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	interpol(int x, t_interp *dm)
{
	if (x <= dm->x0)
		return (dm->y0);
	if (x >= dm->x1)
		return (dm->y1);
	return (dm->y0 + (x - dm->x0) * (dm->y1 - dm->y0) / (dm->x1 - dm->x0));
}

int	itertocolor(int i)
{
	int	r;
	int	g;
	int	b;

	b = interpol(i, &(t_interp){MAX_ITER * 0 / 3, MAX_ITER * 1 / 3, 255, 0});
	g = interpol(i, &(t_interp){MAX_ITER * 1 / 3, MAX_ITER * 2 / 3, 255, 0});
	r = interpol(i, &(t_interp){MAX_ITER * 2 / 3, MAX_ITER * 3 / 3, 255, 0});
	return (r << 16 | g << 8 | b);
}
