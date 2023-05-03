/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:41:06 by pji               #+#    #+#             */
/*   Updated: 2023/05/03 15:41:07 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# define _USE_MATH_DEFINES
# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_rgb_ratio
{
	double	r;
	double	g;
	double	b;
}	t_rgb_r;

typedef t_vec	t_point;

typedef struct s_ray
{
	t_point	*ori;
	t_vec	*dir;
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
int		v_cmp(t_vec v1, t_vec v2);

double	point_len(t_vec point1, t_vec point2);
double	point_len_origin(t_vec point);

double	get_radian(double seta);

#endif