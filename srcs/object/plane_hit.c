#include "objects.h"

int	hit_plane_check(t_plane plane, t_vec vector)
{
	if (v_dot(plane.vec, vector))
		return (1);
	return (0);
}

t_vec	hit_plane(t_plane plane, t_vec vector)
{
	double	a;
	t_vec	point;

	if (v_dot(plane.vec, plane.c) == 0)
		return ((t_point){0, 0, 0});
	if (!hit_plane_check(plane, vector))
	{
		point.x = NAN;
		return (point);
	}
	a = v_dot(plane.vec, plane.c)
		/ v_dot(plane.vec, vector);
	point.x = vector.x * a;
	point.y = vector.y * a;
	point.z = vector.z * a;
	check_front(vector, &point);
	return (point);
}

double	plane_angle(t_plane plane, t_vec vec)
{
	return (M_PI_2 - v_angle(plane.vec, vec));
}

t_plane	new_plane(t_point center, t_rgb rgb, t_vec vec)
{
	t_plane	p;

	p.c = center;
	p.rgb = rgb;
	p.vec = vec;
	return (p);
}
