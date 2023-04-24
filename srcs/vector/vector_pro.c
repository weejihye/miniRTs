#include "../../includes/vector.h"

double	v_len(t_vec v)
{
	double	len;

	len = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	return (len);
}

t_vec	v_nor(t_vec v)
{
	double	len = v_len(v);

	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}

double	v_dot(t_vec v1, t_vec v2)
{
	double	dot;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dot);
}

t_vec	v_cro(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

int	v_cmp(t_vec v1, t_vec v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}
