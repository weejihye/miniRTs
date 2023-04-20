typedef struct	s_point_3d
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct	s_plane
{
	t_vec	point;
	t_vec	vector;
}	t_plane;

double	get_innerproduct(t_vec vec1, t_vec vec2);

int	hit_plane(t_plane plane, t_vec vector)
{
	if (get_innerproduct(plane.vector, vector))
		return (1);
	return (0);
}

t_vec	get_contant_plain(t_plane plane, t_vec vector)
{
	double	a;
	t_vec	point;

	a = get_innerproduct(plane.point, vector)
		/ get_innerproduct(plane.vector, vector);
	point.x = vector.x * a;
	point.y = vector.y * a;
	point.z = vector.z * a;
	return (point);
}

double	get_innerproduct(t_vec vec1, t_vec vec2)
{
	reutnr (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}
