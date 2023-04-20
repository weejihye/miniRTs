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

typedef struct	s_plane
{
	t_vector	point;
	t_vector	vector;
}	t_plane;

double	get_innerproduct(t_vector vec1, t_vector vec2);

int	hit_plane(t_plane plane, t_vector vector)
{
	if (get_innerproduct(plane.vector, vector))
		return (1);
	return (0);
}

t_vector	get_contant_plain(t_plane plane, t_vector vector)
{
	double	a;
	t_vector	point;

	a = get_innerproduct(plane.point, vector)
		/ get_innerproduct(plane.vector, vector);
	point.x = vector.x * a;
	point.y = vector.y * a;
	point.z = vector.z * a;
	return (point);
}

double	get_innerproduct(t_vector vec1, t_vector vec2)
{
	reutnr (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}
