/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:02:52 by sameye            #+#    #+#             */
/*   Updated: 2021/09/07 22:21:06 by sameye           ###   ########.fr       */
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

typedef struct	s_frac
{
	char		frac;
}				t_frac;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_view		view;
	t_frac		frac;
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
#define PARAM_LIST "Available parameters list :\nmandelbrot\njulia\n"
#define MAX_ITER 32
#define C_RE -0.5
#define C_IM 0.5
#define MODUL 4

t_complex pixtocplx(t_pix *p, t_mlx *mlx);
void setfracttype(t_mlx *mlx, t_complex *z, t_complex *c, t_pix *p);
int fracparse(char * frac, t_mlx *mlx);
int main(int ac, char **av);
int interpol (int x, int x0, int x1, int y0, int y1);
int	itertocolor(int i);
int	key_hook(int keycode, t_mlx *mlx);
void itercplx(t_pix *p, t_mlx *mlx);
void drawfractal(t_mlx *mlx);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
t_complex square(t_complex c);
t_complex mult(t_complex c1, t_complex c2);
double squaremodul(t_complex c);
t_complex sum(t_complex c1, t_complex c2);
t_complex zerocplx(void);
void init_mlx(t_mlx *mlx);
void init_view(t_mlx *mlx);
int entrycheck(int ac, char **av, t_mlx *mlx);

int	keyboard_press(int keycode, t_mlx *mlx);
int mouse_press(int keycode, int x, int y, t_mlx *mlx);
int destroy_press(int keycode, int x, int y, t_mlx *mlx);
int destroy(t_mlx *mlx);





#endif