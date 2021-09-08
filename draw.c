/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:50:26 by sameye            #+#    #+#             */
/*   Updated: 2021/09/08 16:18:56 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pixtocplx(t_pix *p, t_mlx *mlx)
{
	t_complex	res;

	res.r = 1.5 * (p->x - WIN_W / 2) / (0.5 * mlx->view.scale * WIN_W)
		+ mlx->view.x;
	res.i = (p->y - WIN_H / 2) / (0.5 * mlx->view.scale * WIN_H)
		+ mlx->view.y;
	return (res);
}

void	itercplx(t_pix *p, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;

	setfracttype(mlx, &z, &c, p);
	p->iter = 0;
	while (p->iter < MAX_ITER)
	{
		z = csum(csquare(z), c);
		if (csquaremodul(z) >= MODUL)
			break ;
		p->iter++;
	}
}

void	drawfractal(t_mlx *mlx)
{
	t_pix	p;

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
