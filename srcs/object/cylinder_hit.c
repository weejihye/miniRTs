/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:39:44 by pji               #+#    #+#             */
/*   Updated: 2023/05/04 16:02:09 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

int		cyl_plane(t_point dot[2], t_cyl cyl, t_vec v);
t_point	cyl_2(t_point dot[2], t_cyl cyl, t_vec v, t_vec qe);
int	is_cam_in_cyl(t_cyl cyl);

t_point	hit_cylinder(t_cyl cyl, t_vec v)
{
	t_vec	qe;
	t_point	dot[2];

	if (v_cmp(cyl.vec, v) == 1)
	{
		if (cyl_plane(dot, cyl, v) == 0)
			return ((t_point){NAN, NAN, NAN});
		else
			return (check_ahead(v, dot));
	}
	qe.x = v_dot(v, v) - pow(v_dot(v, cyl.vec), 2);
	qe.y = 2 * (v_dot(v, cyl.c) - v_dot(v, cyl.vec) * v_dot(cyl.c, cyl.vec));
	qe.z = v_dot(cyl.c, cyl.c) - pow(v_dot(cyl.c, cyl.vec), 2) - pow(cyl.r, 2);
	qe.z = pow(qe.y, 2) - 4 * qe.x * qe.z;
	if (qe.z < 0)
		return ((t_point){NAN, NAN, NAN});
	if (qe.z == 0)
	{
		dot[0] = v_mlt((-1) * qe.y / 2 / qe.x, v);
		check_front(v, &(dot[0]));
		return (dot[0]);
	}
	if (qe.z > 0)
		return (cyl_2(dot, cyl, v, qe));
	return ((t_point){NAN, NAN, NAN});
}

int	cyl_plane(t_point dot[2], t_cyl cyl, t_vec v)
{
	t_plane	plane;
	int		n;

	n = 0;
	plane.c = v_sub(cyl.c, v_mlt(-1 * cyl.h / 2, cyl.vec));
	plane.vec = cyl.vec;
	dot[n] = hit_plane(plane, v);
	if (!isnan(dot[n].x) && point_len(plane.c, dot[n]) <= cyl.r)
		++n;
	plane.c = v_sub(cyl.c, v_mlt(cyl.h / 2, cyl.vec));
	dot[n] = hit_plane(plane, v);
	if (!isnan(dot[n].x) && point_len(plane.c, dot[n]) <= cyl.r)
		++n;
	return (n);
}

t_point	cyl_2(t_point dot[2], t_cyl cyl, t_vec v, t_vec qe)
{
	double	t;
	int		n;
	int		count;

	n = cyl_plane(dot, cyl, v);
	count = -1;
	while (++count < 2)
	{
		if (n != 2)
		{
			dot[n] = v_mlt((-1 * qe.y + sqrt(qe.z)
						* pow(-1, count)) / (2 * qe.x) * (-1), v);
			if (!isnan(dot[n].x))
			{
				t = v_dot(v_sub(dot[n], cyl.c), cyl.vec);
				n += (t >= cyl.h / 2 * -1 && t <= cyl.h / 2);
			}
		}
	}
	if (n == 0)
		return ((t_point){NAN, NAN, NAN});
	if (n == 2)
		return (check_ahead(v, dot));
	check_front(v, &(dot[0]));
	return (dot[0]);
}

double	cyl_ratio(t_cyl cyl, t_light light, t_point p)
{
	const t_vec	vec = v_sub(light.lgt_origin, p);
	t_plane		plane;
	t_vec		temp;
	double		t;
	int			count;

	count = -1;
	while (++count < 2)
	{
		plane.c = v_add(cyl.c, v_mlt(cyl.h / 2 * pow(-1, count), cyl.vec));
		if (v_dot(cyl.vec, v_sub(p, plane.c)) < ERR_R
			&& v_dot(cyl.vec, v_sub(p, plane.c)) > -ERR_R)
		{
			plane.vec = v_mlt(pow(-1, count), cyl.vec);
			t = plane_ratio(plane, light, p);
			if (is_cam_in_cyl(cyl))
				return (t);
			if (t > 0)
				return (t);
			return (0);
		}
	}
	temp = v_sub(p, v_add(cyl.c, v_mlt(v_dot(cyl.vec, v_sub(p, cyl.c))
					/ v_dot(cyl.vec, cyl.vec), cyl.vec)));
	t = v_dot(temp, vec)
		/ point_len_origin(vec);
	if (is_cam_in_cyl(cyl))
		return (-t);
	if (t > 0)
		return (t);
	return (0);
}

double	cyl_reflect(t_cyl cyl, t_light light, t_point p)
{
	const t_vec	vec = v_sub(light.lgt_origin, p);
	t_plane		plane;
	double		t;

	plane.c = v_add(cyl.c, v_mlt(cyl.h / 2, cyl.vec));
	if (v_dot(cyl.vec, v_sub(p, plane.c)) < ERR_R
		&& v_dot(cyl.vec, v_sub(p, plane.c)) > -ERR_R)
	{
		plane.vec = cyl.vec;
		return (plane_reflect(plane, light, p));
	}
	plane.c = v_sub(cyl.c, v_mlt(cyl.h / 2, cyl.vec));
	if (v_dot(cyl.vec, v_sub(p, plane.c)) < ERR_R
		&& v_dot(cyl.vec, v_sub(p, plane.c)) > -ERR_R)
	{
		plane.vec = cyl.vec;
		return (plane_reflect(plane, light, p));
	}
	t = v_dot(cyl.vec, v_sub(p, cyl.c)) / v_dot(cyl.vec, cyl.vec);
	plane.vec = v_nor(v_sub(p, v_add(cyl.c, v_mlt(t, cyl.vec))));
	t = v_dot(plane.vec, vec) / point_len_origin(vec);
	if (is_cam_in_cyl(cyl))
		return (plane_reflect(plane, light, p));
	if (t <= 0)
		return (0);
	return (plane_reflect(plane, light, p));
}

int	is_cam_in_cyl(t_cyl cyl)
{
	return (point_len((t_vec){0, 0, 0},
		v_add(cyl.c, v_mlt(v_dot(cyl.vec, cyl.c)
				/ v_dot(cyl.vec, cyl.vec), cyl.vec))) < cyl.r);
}
