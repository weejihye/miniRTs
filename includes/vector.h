#ifndef VECTOR_H
# define VECTOR_H
# define _USE_MATH_DEFINES
# include "miniRT.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_rgb
{
	char	r;
	char	g;
	char	b;
}	t_rgb;

typedef t_vec t_point;

typedef struct s_ray
{
	t_point *ori;
	t_vec *dir;
}	t_ray;

t_vec	vec(double x, double y, double z);
double	v_len(t_vec v);
t_vec	v_nor(t_vec v);
t_vec	v_add(t_vec v1, t_vec v2);
t_vec	v_sub(t_vec v1, t_vec v2);
t_vec	v_mlt(double a, t_vec v);
t_vec	v_div(double a, t_vec v);
double	v_dot(t_vec v1, t_vec v2);
t_vec	v_cro(t_vec v1, t_vec v2);
int		coloring(int t, int r, int g, int b);
int		color(int t, t_rgb rgb);

#endif