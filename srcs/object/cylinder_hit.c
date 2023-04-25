#include "objects.h"

t_point	hit_cylinder(t_cyl cyl, t_vec v)
{
	double	a;
	double	b;
	double	c;
	t_vec	w;
	t_point	dot[2];
	t_plane	plane;

	w = v_sub(cyl.center, v_mlt(-1 * cyl.h / 2, cyl.vec));
	a = v_dot(v, v) - pow(v_dot(v, cyl.vec), 2);
	b = 2 * (v_dot(v, w) - v_dot(v, cyl.vec) * v_dot(w, cyl.vec));
	c = v_dot(w, w) - pow(v_dot(w, cyl.vec), 2) - pow(cyl.r, 2);
	c = pow(b, 2) - 4 * a * c;
	if (c < 0)
	{
		plane.center = w;
		plane.vec = cyl.vec;
		dot[0] = hit_plane(plane, v);
		if (dot[0].x == NAN || point_len(w, dot[0]) < cyl.r)
		{
			dot[0].x = NAN;
			return (dot[0]);
		}
		plane.center = v_sub(cyl.center, v_mlt(cyl.h / 2, cyl.vec));
		dot[1] = hit_plane(plane, v);
	}
	if (c == 0)
	{
		dot[1] = v_mlt(-1 * b / (2 * a), v);
		if (v_dot(v, cyl.vec) == 0)
		{
			check_front(v, &(dot[1]));
			return (dot[1]);
		}
		plane.center = w;
		plane.vec = cyl.vec;
		dot[0] = hit_plane(plane, v);
		if (point_len(w, dot[0]) > cyl.r)
		{
			plane.center = v_sub(cyl.center, v_mlt(cyl.h / 2, cyl.vec));
			dot[0] = hit_plane(plane, v);
			if (point_len(plane.center, dot[0]) > cyl.r)
			{
				check_front(v, &(dot[0]));
				return (dot[0]);
			}
		}
	}
	if (c > 0)
	{
		dot[0] = v_mlt((-1 * b + sqrt(c)) / (2 * a) * (-1), v);//
		dot[1] = v_mlt((-1 * b - sqrt(c)) / (2 * a) * (-1), v);//
	}
	if (check_ahead(v, dot))
		return (dot[1]);
	else
		return (dot[0]);
}

double	cyl_angle(t_cyl cyl, t_vec v, t_point p)
{
	t_point	w;

	w = v_add(cyl.center, v_mlt(cyl.h / 2, cyl.vec));
	if (!(cyl.vec.x * (w.x - cyl.center.x)
			+ cyl.vec.y * (w.y - cyl.center.y)
			+ cyl.vec.z * (w.z - cyl.center.z)))
		return (M_PI_2 - v_angle(cyl.vec, v));
	w = v_sub(cyl.center, v_mlt(cyl.h / 2, cyl.vec));
	if (!(cyl.vec.x * (w.x - cyl.center.x)
			+ cyl.vec.y * (w.y - cyl.center.y)
			+ cyl.vec.z * (w.z - cyl.center.z)))
		return (M_PI_2 - v_angle(cyl.vec, v));
	w.x = pow(cyl.vec.x, 2) * p.x
		+ (pow(cyl.vec.y, 2) + pow(cyl.vec.y, 2)) * cyl.center.x
		+ (cyl.center.y - p.y) * cyl.vec.y * cyl.vec.x
		+ (cyl.center.z - p.z) * cyl.vec.z * cyl.vec.x
		/ (pow(cyl.vec.x, 2) + pow(cyl.vec.y, 2) + pow(cyl.vec.z, 2));
	w.y = cyl.vec.y * (w.x - cyl.center.x) / cyl.vec.x;
	w.z = cyl.vec.z * (w.x - cyl.center.x) / cyl.vec.x;
	printf("%f %f %f\n", w.x, w.y, w.z);
	return (w.x);
}