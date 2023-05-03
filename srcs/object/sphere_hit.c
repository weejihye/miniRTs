#include "objects.h"
#include "point.h"

t_point	hit_sphere(t_sp s, t_vec v)
{
	double	len;
	t_vec	temp[2];

	if (point_len_origin(s.c) == s.r)
		return ((t_vec){0, 0, 0});
	temp[0] = v_mlt(v_dot(v, s.c) / v_dot(v, v), v);
	len = point_len(s.c, temp[0]);
	if (len < s.r)
	{
		temp[1] = v_sub(temp[0], s.c);
		temp[0] = v_add(v_add(temp[1], v_mlt(sqrt(pow(s.r, 2)
							- pow(len, 2)), v)), s.c);
		temp[1] = v_add(v_add(temp[1], v_mlt(sqrt(pow(s.r, 2)
							- pow(len, 2)) * -1, v)), s.c);
		return (check_ahead(v, temp));
	}
	if (len > s.r)
		temp[0].x = NAN;
	if (len == s.r)
		check_front(v, &(temp[0]));
	return (temp[0]);
}

double	sphere_ratio(t_sp s, t_light light, t_point point)
{
	const t_vec	a = v_sub(s.c, point);
	const t_vec	b = v_sub(light.lgt_origin, point);
	const t_vec	c = v_sub(light.lgt_origin, s.c);

	if (pow(s.r, 2) + pow(point_len_origin(b), 2) > pow(point_len_origin(c), 2))
		return (0);
	return (v_dot(a, b) / point_len_origin(a) / point_len_origin(b) * -1);
}

double	sphere_reflect(t_sp s, t_light light, t_point point)
{
	const t_vec		a = v_sub(s.c, point);
	const t_vec		b = v_sub(light.lgt_origin, point);
	const t_vec		c = v_sub(light.lgt_origin, s.c);
	t_plane			plane;

	if (pow(s.r, 2) + pow(point_len_origin(b), 2) > pow(point_len_origin(c), 2))
		return (0);
	plane.vec = a;
	return (plane_reflect(plane, light, point));
}
