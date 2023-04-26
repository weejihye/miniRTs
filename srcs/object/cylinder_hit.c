#include "objects.h"

t_point	hit_cylinder(t_cyl cyl, t_vec v)
{
	double	a;
	double	b;
	double	c;
	t_vec	w;
	t_point	dot[2];
	t_plane	plane;
	int n;

	a = v_dot(v, v) - pow(v_dot(v, cyl.vec), 2);
	b = 2 * (v_dot(v, cyl.c) - v_dot(v, cyl.vec) * v_dot(cyl.c, cyl.vec));
	c = v_dot(cyl.c, cyl.c) - pow(v_dot(cyl.c, cyl.vec), 2) - pow(cyl.r, 2);
	printf("a : %.20f b : %.20f c : %.20f\n", a, b, c);
	c = pow(b, 2) - 4 * a * c;
	if (c < 0)
	{
		printf("c < 0\n");
		dot[0].x = NAN;
		return (dot[0]);
	}
	if (c == 0)
	{
		if (v_cmp(cyl.vec ,v) == 1)
			c = 1;
		printf("c == 0\n");
		dot[0] = v_mlt((-1) * b / 2 / a, v);
		check_front(v, &(dot[0]));
		return (dot[0]);
	}
	if (c > 0)
	{
		printf("c > 0\n");
		n = 0;
		plane.c = v_sub(cyl.c, v_mlt(-1 * cyl.h / 2, cyl.vec));
		plane.vec = cyl.vec;
		dot[n] = hit_plane(plane, v);
		if (point_len(plane.c, dot[n]) <= cyl.r)
			++n;
		plane.c = v_sub(cyl.c, v_mlt(cyl.h / 2, cyl.vec));
		dot[n] = hit_plane(plane, v);
		if (point_len(plane.c, dot[n]) <= cyl.r)
			++n;
		if (n != 2)
		{
			dot[n] = v_mlt((-1 * b + sqrt(c)) / (2 * a) * (-1), v);
			if (v_dot(v_sub(dot[n], cyl.c), cyl.vec) >= 0 || v_dot(v_sub(dot[n], cyl.c), cyl.vec) <= 1)
				++n;
		}
		if (n != 2)
		{
			dot[n] = v_mlt((-1 * b - sqrt(c)) / (2 * a) * (-1), v);
			if (v_dot(v_sub(dot[n], cyl.c), cyl.vec) >= 0 || v_dot(v_sub(dot[n], cyl.c), cyl.vec) <= 1)
				++n;
		}
		printf("n : %d\n", n);
	}
	if (check_ahead(v, dot))
		return (dot[1]);
	else
		return (dot[0]);
}

double	cyl_angle(t_cyl cyl, t_vec v, t_point p)
{
	t_point	w;

	w = v_add(cyl.c, v_mlt(cyl.h / 2, cyl.vec));
	if (!(cyl.vec.x * (w.x - cyl.c.x)
			+ cyl.vec.y * (w.y - cyl.c.y)
			+ cyl.vec.z * (w.z - cyl.c.z)))
		return (M_PI_2 - v_angle(cyl.vec, v));
	w = v_sub(cyl.c, v_mlt(cyl.h / 2, cyl.vec));
	if (!(cyl.vec.x * (w.x - cyl.c.x)
			+ cyl.vec.y * (w.y - cyl.c.y)
			+ cyl.vec.z * (w.z - cyl.c.z)))
		return (M_PI_2 - v_angle(cyl.vec, v));
	w.x = cyl.vec.x * v_dot(p, cyl.vec)
		+ cyl.c.x * (pow(cyl.vec.y, 2) + pow(cyl.vec.z, 2))
		- cyl.vec.x * cyl.vec.y * cyl.c.y
		- cyl.vec.x * cyl.vec.z * cyl.c.z
		/ (pow(cyl.vec.x, 2) + pow(cyl.vec.y, 2) + pow(cyl.vec.z, 2));
	w.y = cyl.vec.y * (w.x - cyl.c.x) / cyl.vec.x;
	w.z = cyl.vec.z * (w.x - cyl.c.x) / cyl.vec.x;
	printf("%f %f %f\n", w.x, w.y, w.z);
	return (w.x);
}