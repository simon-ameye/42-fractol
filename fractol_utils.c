/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:08:10 by sameye            #+#    #+#             */
/*   Updated: 2021/09/05 18:58:40 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//(a + ib) (a + ib)
t_complex square(t_complex c)
{
	t_complex res;

	res.r = c.r * c.r - c.i * c.i;
	res.i = 2 * c.r * c.r;
	return (res);
}

t_complex mult(t_complex c1, t_complex c2)
{
	t_complex res;

	res.r = c1.r * c2.r - c1.i * c2.i;
	res.i = c1.r * c2.i + c1.i * c2.r;
	return (res);
}

double squaremodul(t_complex c)
{
	double res;

	res = c.r * c.r + c.i * c.i;
	return (res);
}

t_complex sum(t_complex c1, t_complex c2)
{
	t_complex res;

	res.r = c1.r + c2.r;
	res.i = c1.i + c2.i;
	return (res);
}