#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
typedef struct	s_point_3d
{
	int	x;
	int	y;
	int	z;
}	t_point_3d;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct	s_sphere
{
	t_vector	point;
	double		r;
}	t_sphere;

int	squre_hit(t_sphere sphere, t_vector vec)
{
	t_vector	point;

	point.x = (sphere.point.x + sphere.point.y / vec.y + sphere.point.z / vec.z) / (1 + pow(vec.x / vec.y, 2) + pow(vec.x /vec.z, 2));
}

t_vector	get_contact_sphere(t_sphere sphere, t_vector vec)
{
	t_vector point;
	double	den;
	int		zero_count;
	double	len;
	t_vector	*point_contact;
	t_vector	temp[2];

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

double	get_len_origin(t_vector point)
{
	const t_vector	origin = {0, 0, 0};
	return (get_len(point, origin));
}

double		get_len(t_vector point1, t_vector point2)
{
	return (sqrt(pow(point1.x - point2.x, 2) 
			+ pow(point1.y - point2.y, 2)
			+ pow(point1.z - point2.z, 2)));
}

t_vector	get_sum(t_vector vec1, t_vector vec2)
{
	vec1.x = vec1.x + vec2.x;
	vec1.y = vec1.y + vec2.y;
	vec1.z = vec1.z + vec2.z;
	return (vec1);
}

t_vector	get_minus(t_vector vec1, t_vector vec2)
{
	vec1.x = vec1.x - vec2.x;
	vec1.y = vec1.y - vec2.y;
	vec1.z = vec1.z - vec2.z;
	return (vec1);
}

t_vector	get_multiply(t_vector vec, double n)
{
	vec.x = vec.x * n;
	vec.y = vec.y * n;
	vec.z = vec.z * n;
	return (vec);
}