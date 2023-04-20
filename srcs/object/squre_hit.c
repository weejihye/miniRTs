#define _USE_MATH_DEFINES
#include "objects.h"
#include "point.h"

static t_point	get_contact_sphere_01(t_sp s, t_vec v);
static t_point	get_contact_sphere_2(t_sp s, t_vec v);

t_point	get_contact_sphere(t_sp s, t_vec v)
{
	t_point	point;
	int		zero_count;
	double	len;
	t_vec	temp[2];
	double	temp_len[2];

	zero_count = (v.x == 0) + (v.y == 0) + (v.z == 0);
	if (zero_count < 2)
		point = get_contact_sphere_01(s, v);
	else
		point = get_contact_sphere_2(s, v);
	len = get_len(s.center, point);
	if (len > s.r)
	{
		point.x = NAN;
		return (point);
	}
	if (len == s.r)
	{
		if (point.x < 0 != v.x < 0)
			point.x = NAN;
		return (point);
	}
	if (len < s.r)
	{
		temp[1] = v_sub(point, s.center);
		temp[0] = v_add(temp[1], v_mlt(len, v));
		temp[1] = v_add(temp[1], v_mlt(len * -1, v));
		if (temp[0].x < 0 != v.x < 0 && temp[1].x < 0 != v.x < 0)
		{
			point.x = NAN;
			return (point);
		}
		if (temp[0].x < 0 != v.x < 0)
			return (temp[1]);
		if (temp[1].x < 0 != v.x < 0)
			return (temp[0]);
		temp_len[0] = get_len_origin(temp[0]);
		temp_len[1] = get_len_origin(temp[1]);
		if (temp_len[0] < temp_len[1])
			return (temp[0]);
		else
			return (temp[1]);
	}
	return (point);
}

static t_point	get_contact_sphere_01(t_sp s, t_vec v)
{
	t_point		point;
	double		den;
	double		ratio;
	const t_vec	v_pow = {pow(v.x, 2), pow(v.y, 2), pow(v.z, 2)};

	den = (v_pow.x * v_pow.y + v_pow.y * v_pow.z + v_pow.z * v_pow.x);
	point.x = (s.center.x * v_pow.y * v_pow.z + s.center.y
			* v.y * v_pow.z + s.center.z * v_pow.y * v.z) / den;
	if (v.x != 0)
	{
		ratio = point.x / v.x;
		point.y = v.y * ratio;
		point.y = v.z * ratio;
	}
	else
	{
		point.y = 0;
		point.z = 0;
	}
	return (point);
}

static t_point	get_contact_sphere_2(t_sp s, t_vec v)
{
	t_point	point;

	point = vec(0, 0, 0);
	if (v.x == 0 && v.y == 0)
		point.z = s.center.z;
	if (v.x == 0 && v.z == 0)
		point.y = s.center.y;
	if (v.y == 0 && v.z == 0)
		point.x = s.center.x;
	return (point);
}
