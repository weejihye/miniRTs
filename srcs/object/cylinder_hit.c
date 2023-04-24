#include "objects.h"

t_point	hit_cylinder(t_cyl cyl, t_vec v)
{
	double	a;
	double	b;
	double	c;
	t_vec	w;
	double	t;
	t_point	dot[2];
	t_plane	plane;

	w = v_sub(cyl.center, v_mlt(-1 * cyl.h / 2, cyl.vec));

	a = v_dot(v, v) - pow(v_dot(v, cyl.vec), 2);
	b = 2 * (v_dot(v, w) - v_dot(v, cyl.vec) * v_dot(w, cyl.vec));
	c = v_dot(w, w) - pow(v_dot(w, cyl.vec), 2) - pow(cyl.r, 2);

	t = pow(b, 2) - 4 * a * c;
	if (t < 0)
	{
		plane.center = w;
		plane.vec = cyl.vec;
		dot[0] = hit_plain(plane, v);
		if (point_len(w, dot[0]) < cyl.r)
		{
			dot[0].x = NAN;
			return (dot[0]);
		}
		plane.center = v_sub(cyl.center, v_mlt(cyl.h / 2, cyl.vec));
		dot[1] = hit_plain(plane, v);
	}
	if (t > 0)
	{
		dot[0] = v_mlt((-1 * b + sqrt(t)) / (2 * a) * (-1), v);//
		dot[1] = v_mlt((-1 * b - sqrt(t)) / (2 * a) * (-1), v);//
	}
	if (t == 0)
	{
		plane.center = w;
		plane.vec = cyl.vec;
		dot[0] = hit_plain(plane, v);
		if (point_len(w, dot[0]) > cyl.r)
		{
			plane.center = v_sub(cyl.center, v_mlt(cyl.h / 2, cyl.vec));
			dot[0] = hit_plain(plane, v);
		}
		dot[1] = v_mlt(-1 * b / (2 * a), v);
	}
	if (point_len_origin(dot[0]) < point_len_origin(dot[1]))
		return (dot[0]);
	else
		return (dot[1]);
}

