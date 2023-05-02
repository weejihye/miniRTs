#include "objects.h"
#include <stdlib.h>

int	hit_plane_check(t_plane plane, t_vec vector)
{
	if (v_dot(plane.vec, vector))
		return (1);
	return (0);
}

t_point	hit_plane(t_plane plane, t_vec vector)
{
	t_point	point;

	// if (v_dot(plane.vec, plane.c) == 0)
	// 	return ((t_point){0, 0, 0});
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
	const t_vec	vec = v_sub(light.lgt_origin, point);
	double		ratio = v_dot(plane.vec, vec) / point_len_origin(vec);

	if (isnan(ratio))
		return (1);
	if (ratio > 0)
		return (ratio);
	else
		return (cos(acos(ratio) - M_PI_2));
}

t_plane	new_plane(t_point center, t_rgb rgb, t_vec vec)
{
	t_plane	p;

	p.c = center;
	p.rgb = rgb;
	p.vec = vec;
	return (p);
}
