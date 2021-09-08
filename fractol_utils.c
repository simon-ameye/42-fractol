/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:08:10 by sameye            #+#    #+#             */
/*   Updated: 2021/09/08 17:33:43 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	csquare(t_complex c)
{
	t_complex	res;

	res.r = c.r * c.r - c.i * c.i;
	res.i = 2 * c.r * c.i;
	return (res);
}

t_complex	cmult(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.r = c1.r * c2.r - c1.i * c2.i;
	res.i = c1.r * c2.i + c1.i * c2.r;
	return (res);
}

double	csquaremodul(t_complex c)
{
	return (c.r * c.r + c.i * c.i);
}

t_complex	csum(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.r = c1.r + c2.r;
	res.i = c1.i + c2.i;
	return (res);
}

t_complex	czerocplx(void)
{
	t_complex	res;

	res.r = 0;
	res.i = 0;
	return (res);
}
