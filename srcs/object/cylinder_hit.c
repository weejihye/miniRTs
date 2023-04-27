#include "objects.h"

int		cyl_plane(t_point dot[2], t_cyl cyl, t_vec v);
t_point	cyl_2(t_point dot[2], t_cyl cyl, t_vec v, t_vec qe);

t_point	hit_cylinder(t_cyl cyl, t_vec v)
{
	t_vec	qe;
	t_point	dot[2];
	int		n;
	double	t;

	if (v_cmp(cyl.vec, v) == 1)
	{
		if (cyl_plane(dot, cyl, v) == 0)
			return ((t_point){NAN, NAN, NAN});
		else
			return (check_ahead(v, dot));
	}
	qe.x = v_dot(v, v) - pow(v_dot(v, cyl.vec), 2);
	qe.y = 2 * (v_dot(v, cyl.c) - v_dot(v, cyl.vec) * v_dot(cyl.c, cyl.vec));
	qe.z = v_dot(cyl.c, cyl.c) - pow(v_dot(cyl.c, cyl.vec), 2) - pow(cyl.r, 2);
	t = pow(qe.y, 2) - 4 * qe.x * qe.z;
	if (t < 0)
		return ((t_point){NAN, NAN, NAN});
	if (t == 0)
	{
		dot[0] = v_mlt((-1) * qe.y / 2 / qe.x, v);
		check_front(v, &(dot[0]));
		return (dot[0]);
	}
	if (t > 0)
		return (cyl_2(dot, cyl, v, qe));
	return ((t_point){NAN, NAN, NAN});
}

int	cyl_plane(t_point dot[2], t_cyl cyl, t_vec v)
{
	t_plane plane;
	int		n;

	n = 0;
	plane.c = v_sub(cyl.c, v_mlt(-1 * cyl.h / 2, cyl.vec));
	plane.vec = cyl.vec;
	dot[n] = hit_plane(plane, v);
	if (!isnan(dot[n].x) && point_len(plane.c, dot[n]) <= cyl.r)
		++n;
	plane.c = v_sub(cyl.c, v_mlt(cyl.h / 2, cyl.vec));
	dot[n] = hit_plane(plane, v);
	if (!isnan(dot[n].x) && point_len(plane.c, dot[n]) <= cyl.r)
		++n;
	return (n);
}

t_point	cyl_2(t_point dot[2], t_cyl cyl, t_vec v, t_vec qe)
{
	double	t;
	int		n;
	n = cyl_plane(dot, cyl, v);
	if (n != 2)
	{
		dot[n] = v_mlt((-1 * qe.y + sqrt(qe.z)) / (2 * qe.x) * (-1), v);
		if (!isnan(dot[n].x))
		{
			t = v_dot(v_sub(dot[n], cyl.c), cyl.vec);
			n += (t >= cyl.h / 2 * -1 && t <= cyl.h / 2);
		}
	}
	if (n != 2)
	{
		dot[n] = v_mlt((-1 * qe.y - sqrt(qe.z)) / (2 * qe.x) * (-1), v);
		if (!isnan(dot[n].x))
		{
			t = v_dot(v_sub(dot[n], cyl.c), cyl.vec);
			n += (t >= cyl.h / 2 * -1 && t <= cyl.h / 2);
		}
	}
	if (n == 0)
		return ((t_point){NAN, NAN, NAN});
	else if (n == 2)
		return (check_ahead(v, dot));
	else
	{
		check_front(v, &(dot[0]));
		return (dot[0]);
	}
}


double	cyl_angle(t_cyl cyl, t_vec v, t_point p)
{
	t_point	w;
	double	t;

	w = v_add(cyl.c, v_mlt(cyl.h / 2, cyl.vec));
	printf("%f\n", v_dot(cyl.vec, v_sub(p, w)));
	if (!v_dot(cyl.vec, v_sub(p, w)))
		return (M_PI_2 - v_angle(cyl.vec, v));
	w = v_sub(cyl.c, v_mlt(cyl.h / 2, cyl.vec));
	printf("%f\n", v_dot(cyl.vec, v_sub(p, w)));
	if (!v_dot(cyl.vec, v_sub(p, w)))
		return (M_PI_2 - v_angle(cyl.vec, v));
	t = v_dot(cyl.vec, v_sub(p, cyl.c)) / v_dot(cyl.vec, cyl.vec);
	printf("%f\n", t);
	w = v_add(v_mlt(t, cyl.vec), cyl.c);
	printf("%f %f %f\n", w.x, w.y, w.z);
	printf("%f\n", point_len(w, p));
	return (w.x);
}
