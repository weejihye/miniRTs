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
	const t_vec		vec = v_sub(light.lgt_origin, point);
	const double	ratio = v_dot(plane.vec, vec)
		/ point_len_origin(vec) / point_len_origin(plane.vec);

	if (ratio < ERR_R && ratio > -ERR_R)
		return (1);
	if (ratio > 0)
		return (ratio);
	else
		return (cos(acos(ratio) - M_PI_2));
}

double	plane_reflect(t_plane plane, t_light light, t_point point)
{
	const t_vec		vec1 = v_sub(light.lgt_origin, point);
	const t_vec		ref_vec = v_add(v_mlt(-1, point),
			v_mlt(v_dot(point, plane.vec) * 2, plane.vec));
	const double	t = v_dot(ref_vec, vec1)
		/ point_len_origin(ref_vec) / point_len_origin(vec1);

	if (t < -0.95)
		return (pow((-t - 0.95) * 20, 2) * 2.1);
	return (0);
}
