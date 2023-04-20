#include "vector.h"
#include "point.h"

double	get_radian(double seta)
{
	return (seta / 180 * M_PI);
}

double	point_len(t_vec point1, t_vec point2)
{
	return (sqrt(pow(point1.x - point2.x, 2) 
			+ pow(point1.y - point2.y, 2)
			+ pow(point1.z - point2.z, 2)));
}

double	point_len_origin(t_vec point)
{
	const t_vec	origin = {0, 0, 0};

	return (point_len(point, origin));
}
