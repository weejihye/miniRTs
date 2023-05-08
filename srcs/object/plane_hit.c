/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:40:51 by pji               #+#    #+#             */
/*   Updated: 2023/05/08 15:04:03 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "miniRT.h"

int	hit_plane_check(t_plane plane, t_vec vector)
{
	if (v_dot(plane.vec, vector))
		return (1);
	return (0);
}

t_point	hit_plane(t_plane plane, t_vec vector)
{
	t_point	point;

	if (!hit_plane_check(plane, vector))
	{
		point.x = NAN;
		return (point);
	}
	point = v_mlt(v_dot(plane.vec, plane.c)
			/ v_dot(plane.vec, vector), vector);
	check_front(vector, &point);
	return (point);
}

double	plane_ratio(t_plane plane, t_light light, t_point point)
{
	const t_vec		vec = v_sub(point, light.lgt_origin);
	const double	ratio = v_dot(plane.vec, vec)
		/ point_len_origin(vec) / point_len_origin(plane.vec);

	if (v_dot(plane.vec, point)
		* v_dot(plane.vec, v_sub(light.lgt_origin, point)) > 0)
		return (0);
	if (ratio < ERR_R && ratio > -ERR_R)
		return (0);
	if (ratio > 0)
		return (ratio);
	else
		return (cos(M_PI - acos(ratio)));
}

double	plane_reflect(t_plane plane, t_light light, t_point point)
{
	const t_vec		vec = v_sub(light.lgt_origin, point);
	const t_vec		ref_vec = v_add(point,
			v_mlt(v_dot(point, plane.vec) * -2, plane.vec));
	const double	t = v_dot(ref_vec, vec)
		/ point_len_origin(ref_vec) / point_len_origin(vec);

	if (v_dot(plane.vec, point)
		* v_dot(plane.vec, v_sub(light.lgt_origin, point)) > 0)
		return (0);
	if (t > 0.9)
		return (pow((t - 0.9) * 10, 2));
	return (0);
}
