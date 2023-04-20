#define _USE_MATH_DEFINES
#include "objects.h"

t_vec	get_contact_sphere(t_sp sphere, t_vec vec)
{
	t_vec point;
	double	den;
	int		zero_count;
	double	len;
	t_vec	*point_contact;
	t_vec	temp[2];

	zero_count = 0;
	if (vec.x == 0)
		++zero_count;
	if (vec.y == 0)
		++zero_count;
	if (vec.z == 0)
		++zero_count;
	if (zero_count < 2)
	{
		den = (pow(vec.y * vec.z, 2) + pow(vec.x * vec.z, 2) + pow(vec.x * vec.y, 2));
		point.x = (sphere.point.x * pow(vec.y * vec.z, 2) + sphere.point.y * vec.y * pow(vec.z, 2) + sphere.point.z * pow(vec.y, 2) * vec.z) / den;
		point.y = (sphere.point.x * vec.x * pow(vec.z, 2) + sphere.point.y * pow(vec.x * vec.z, 2) + sphere.point.z * pow(vec.x, 2) * vec.z) / den;
		point.z = (sphere.point.x * vec.x * pow(vec.y, 2) + sphere.point.y * vec.y * pow(vec.x, 2) + sphere.point.z * pow(vec.x * vec.z, 2)) / den;
	}
	else
	{
		point.x = 0;
		point.y = 0;
		point.z = 0;
		if (vec.x == 0 && vec.y == 0)
			point.z = sphere.point.z;
		if (vec.x == 0 && vec.z == 0)
			point.y = sphere.point.y;
		if (vec.y == 0 && vec.z == 0)
			point.x = sphere.point.x;
	}
	len = get_len(sphere.point, point);
	if (len > sphere.r)
	{
		point.x = NAN;
		return (point);
	}
	if (len == sphere.r)
		return (point);
	if (len < sphere.r)
	{
		temp[1] = get_minus(point, sphere.point);
		temp[0] = get_sum(temp[1], get_multiply(vec, len));//vec은 유닛 백터로 들어와야함
		temp[1] = get_sum(temp[1], get_multiply(vec, len * -1));//vec은 유닛 백터로 들어와야함
		if (get_len_origin(temp[0]))
	}
	return ();
}