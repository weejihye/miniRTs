#include "vector.h"
#include "point.h"

double	get_radian(double seta)
{
	return (seta / 180 * M_PI);
}

double	point_len(t_point point1, t_point point2)
{
	return (sqrt(pow(point1.x - point2.x, 2) 
			+ pow(point1.y - point2.y, 2)
			+ pow(point1.z - point2.z, 2)));
}

double	point_len_origin(t_point point)
{
	const t_point	origin = {0, 0, 0};

	return (point_len(point, origin));
}
