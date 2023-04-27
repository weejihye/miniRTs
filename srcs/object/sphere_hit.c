#define _USE_MATH_DEFINES
#include "objects.h"
#include "point.h"
#define TEST 0 //

static t_point	get_contact_sphere_01(t_sp s, t_vec v);
static t_point	get_contact_sphere_2(t_sp s, t_vec v);

t_point	sphere_hit(t_sp s, t_vec v)
{
	double	len;
	t_vec	temp[2];

	// if ((v.x == 0) + (v.y == 0) + (v.z == 0) < 2)
	// 	temp[0] = get_contact_sphere_01(s, v);
	// else
	// 	temp[0] = get_contact_sphere_2(s, v);
	if (point_len_origin(s.c) == s.r)
		return ((t_vec){0, 0, 0});
	temp[0] = v_mlt(v_dot(v, s.c) / v_dot(v, v), v);
	len = point_len(s.c, temp[0]);
	if (len < s.r)
	{
		if (TEST)
			printf("len < s.r");
		temp[1] = v_sub(temp[0], s.c);
		temp[0] = v_add(v_add(temp[1], v_mlt(sqrt(pow(s.r, 2) - pow(len, 2)), v)), s.c);
		temp[1] = v_add(v_add(temp[1], v_mlt(sqrt(pow(s.r, 2) - pow(len, 2)) * -1, v)), s.c);
		return (check_ahead(v, temp));
	}
	if (len > s.r)
	{
		if (TEST)
			printf("len > s.r");
		temp[0].x = NAN;
	}
	if (len == s.r)
	{
		if (TEST)
			printf("len == s.r");
		check_front(v, &(temp[0]));
	}
	return (temp[0]);
}

static t_point	get_contact_sphere_01(t_sp s, t_vec v)
{
	t_point		point;
	double		ratio;

	ratio = v_dot(s.c, v) / point_len_origin(v);
	point.x = v.x * ratio;
	point.y = v.y * ratio;
	point.z = v.z * ratio;
	return (point);
}

static t_point	get_contact_sphere_2(t_sp s, t_vec v)
{
	t_point	point;

	point = vec(0, 0, 0);
	if (v.x == 0 && v.y == 0)
		point.z = s.c.z;
	if (v.x == 0 && v.z == 0)
		point.y = s.c.y;
	if (v.y == 0 && v.z == 0)
		point.x = s.c.x;
	return (point);
}

double	sphere_angle(t_sp s, t_vec v, t_point point)
{
	return (M_PI_2 - v_angle(v_nor(v_sub(point, s.c)), v));
}
