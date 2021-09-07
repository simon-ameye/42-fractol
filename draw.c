/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:50:26 by sameye            #+#    #+#             */
/*   Updated: 2021/09/07 11:51:29 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void itercplx(t_pix *p, t_mlx *mlx)
{
	t_complex z;
	t_complex c;
	setfracttype(mlx, &z, &c, p);
	p->iter = 0;
	while (p->iter < MAX_ITER)
	{
		z = sum(square(z), c);
		if( squaremodul(z) > MODUL * MODUL)
			break;
		p->iter++;
	}
}

void drawfractal(t_mlx *mlx)
{
	t_pix p;

	p.x = 0;
	while (p.x < WIN_W)
	{
		p.y = 0;
		while (p.y < WIN_H)
		{
			itercplx(&p, mlx);
			mlx->img.data[p.y * WIN_W + p.x] = itertocolor(p.iter);
			p.y++;
		}
		p.x++;
	}
}
