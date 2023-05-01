#include "objects.h"

int	hit_plane_check(t_plane plane, t_vec vector)
{
	if (v_dot(plane.vec, vector))
		return (1);
	return (0);
}

t_vec	hit_plane(t_plane plane, t_vec vector)
{
	t_vec	point;

	if (v_dot(plane.vec, plane.c) == 0)
		return ((t_point){0, 0, 0});
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

double	plane_angle(t_plane plane, t_light light, t_point point)
{
	const t_vec	vec = v_sub(point, light.lgt_origin);
	double		ang = acos(v_dot(plane.vec, vec) / point_len_origin(vec));

	if (ang > M_PI_2)
		return (ang - M_2_PI);
	else
		return (M_PI_2 - ang);
}

t_plane	new_plane(t_point center, t_rgb rgb, t_vec vec)
{
	t_plane	p;

	p.c = center;
	p.rgb = rgb;
	p.vec = vec;
	return (p);
}
