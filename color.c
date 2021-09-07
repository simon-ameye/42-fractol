/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:51:51 by sameye            #+#    #+#             */
/*   Updated: 2021/09/07 11:52:32 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int interpol (int x, int x0, int x1, int y0, int y1)
{
	if (x <= x0)
		return (y0);
	if (x >= x1)
		return (y1);
	return (y0 + (x - x0) * (y1 - y0) / (x1 - x0));
}

int	itertocolor(int i)
{
	int r;
	int g;
	int b;

	b = interpol(i, MAX_ITER * 0 / 3, MAX_ITER * 1 / 3, 255, 0);
	g = interpol(i, MAX_ITER * 1 / 3, MAX_ITER * 2 / 3, 255, 0);
	r = interpol(i, MAX_ITER * 2 / 3, MAX_ITER * 3 / 3, 255, 0);
	return (r << 16 | g << 8 | b);
}
