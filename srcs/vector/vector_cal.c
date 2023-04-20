#include "../../includes/vector.h"

t_vec	vec(double x, double y, double z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	v_add(t_vec v1, t_vec v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec	v_sub(t_vec v1, t_vec v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec	v_mlt(double a, t_vec v)
{
	v.x *= a;
	v.y *= a;
	v.z *= a;
	return (v);
}

t_vec	v_div(double a, t_vec v)
{
	if (a == 0)
		return (vec(0, 0, 0));
	return (v_mlt(1 / a, v));
}

double	get_radian(double seta)
{
	return (seta / 180 * M_PI);
}

double		get_len(t_vec point1, t_vec point2)
{
	return (sqrt(pow(point1.x - point2.x, 2) 
			+ pow(point1.y - point2.y, 2)
			+ pow(point1.z - point2.z, 2)));
}

double	get_len_origin(t_vec point)
{
	const t_vec	origin = {0, 0, 0};
	return (get_len(point, origin));
}