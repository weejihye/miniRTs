#include "objects.h"

int	hit_plane(t_plane plane, t_vec vector)
{
	if (v_dot(plane.vec, vector))
		return (1);
	return (0);
}

t_vec	get_contant_plain(t_plane plane, t_vec vector)
{
	double	a;
	t_vec	point;

	if (!hit_plane(plane, vector))
	{
		point.x = NAN;
		return (point);
	}
	a = v_dot(plane.vec, plane.point)
		/ v_dot(plane.vec, vector);
	point.x = vector.x * a;
	point.y = vector.y * a;
	point.z = vector.z * a;
	return (point);
}
