/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:52 by sameye            #+#    #+#             */
/*   Updated: 2021/09/05 23:44:36 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include "mlx.h"
#include "libft.h"

typedef struct	s_window {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_window;

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

typedef struct		s_view
{
	double		scale;
	double		x;
	double		y;
}					t_view;


#define WIN_X 900
#define WIN_Y 600
#define WIN_NAME "fractol"
#define MAX_ITER 255


t_window init_window(void);
t_complex square(t_complex c);
t_complex mult(t_complex c1, t_complex c2);
t_complex sum(t_complex c1, t_complex c2);
double squaremodul(t_complex c);



#endif