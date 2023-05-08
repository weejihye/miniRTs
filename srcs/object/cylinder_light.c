/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:48:25 by pji               #+#    #+#             */
/*   Updated: 2023/05/08 15:04:13 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

double	cyl_ratio_plane(t_cyl cyl, t_light light, t_point p);
int		is_cam_in_cyl(t_cyl cyl);
int		is_light_in_cyl(t_cyl cyl, t_light light);

double	cyl_ratio(t_cyl cyl, t_light light, t_point p)
{
	const t_vec	vec = v_sub(light.lgt_origin, p);
	t_vec		temp;
	double		t;

	if (is_cam_in_cyl(cyl) ^ is_light_in_cyl(cyl, light))
		return (0);
	t = cyl_ratio_plane(cyl, light, p);
	if (!isnan(t))
		return (t);
	temp = v_sub(p, v_add(cyl.c, v_mlt(v_dot(cyl.vec, v_sub(p, cyl.c))
					/ v_dot(cyl.vec, cyl.vec), cyl.vec)));
	t = v_dot(temp, vec) / point_len_origin(vec);
	if (is_cam_in_cyl(cyl))
		return (-t);
	if (t > 0)
		return (t);
	return (0);
}

double	cyl_ratio_plane(t_cyl cyl, t_light light, t_point p)
{
	int			count;
	t_plane		plane;
	double		t;

	count = -1;
	while (++count < 2)
	{
		plane.c = v_add(cyl.c, v_mlt(cyl.h / 2 * pow(-1, count), cyl.vec));
		t = v_dot(cyl.vec, v_sub(p, plane.c));
		if (t < ERR_R && t > -ERR_R)
		{
			plane.vec = v_mlt(pow(-1, count), cyl.vec);
			t = plane_ratio(plane, light, p);
			if (t > 0)
				return (t);
			return (0);
		}
	}
	return (NAN);
}

double	cyl_reflect(t_cyl cyl, t_light light, t_point p)
{
	const t_vec	vec = v_sub(light.lgt_origin, p);
	t_plane		plane;
	double		t;
	int			n;

	if (is_cam_in_cyl(cyl) ^ is_light_in_cyl(cyl, light))
		return (0);
	n = -1;
	while (++n < 2)
	{
		plane.c = v_add(cyl.c, v_mlt(cyl.h / 2 * pow(-1, n), cyl.vec));
		t = v_dot(cyl.vec, v_sub(p, plane.c));
		if (t < ERR_R && t > -ERR_R)
		{
			plane.vec = v_mlt(pow(-1, n), cyl.vec);
			return (plane_reflect(plane, light, p));
		}
	}
	t = v_dot(cyl.vec, v_sub(p, cyl.c)) / v_dot(cyl.vec, cyl.vec);
	plane.vec = v_nor(v_sub(p, v_add(cyl.c, v_mlt(t, cyl.vec))));
	t = v_dot(plane.vec, vec) / point_len_origin(vec);
	if (t <= 0)
		return (0);
	return (plane_reflect(plane, light, p));
}

int	is_cam_in_cyl(t_cyl cyl)
{
	return (point_len((t_vec){0, 0, 0}, v_add(cyl.c, v_mlt(v_dot(cyl.vec, cyl.c)
				/ v_dot(cyl.vec, cyl.vec), cyl.vec))) < cyl.r);
}

int	is_light_in_cyl(t_cyl cyl, t_light light)
{
	return (point_len(light.lgt_origin, v_add(cyl.c, v_mlt(v_dot(cyl.vec, cyl.c)
					/ v_dot(cyl.vec, cyl.vec), cyl.vec))) < cyl.r);
}
