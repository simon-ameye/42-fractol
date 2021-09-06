/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:52 by sameye            #+#    #+#             */
/*   Updated: 2021/09/07 00:06:45 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include "mlx.h"
#include "libft.h"

typedef struct		s_view
{
	double		scale;
	double		x;
	double		y;
}					t_view;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_view		view;
}				t_mlx;

typedef struct		s_complex
{
	double		r;
	double		i;
}					t_complex;

typedef struct		s_pix
{
	int		x;
	int		y;
	int			iter;
}					t_pix;

#define WIN_W 900
#define WIN_H 600
#define WIN_NAME "fractol"
#define MAX_ITER 32
#define C_RE -0.5
#define C_IM 0.5
#define MODUL 2


void init_mlx(t_mlx *mlx);
t_complex square(t_complex c);
t_complex mult(t_complex c1, t_complex c2);
t_complex sum(t_complex c1, t_complex c2);
double squaremodul(t_complex c);



#endif