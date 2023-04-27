#include "vector.h"
#include <stdio.h> //

void	print_point(t_point p);
t_point	check_ahead(t_vec v, t_point *temp)
{
	if (v_dot(temp[0], v) < 0 && v_dot(temp[1], v) < 0)
		return ((t_point){NAN, NAN, NAN});
	if (v_dot(temp[0], v) < 0)
		return (temp[1]);
	if (v_dot(temp[1], v) < 0)
		return (temp[0]);
	if (point_len_origin(temp[0]) < point_len_origin(temp[1]))
		return (temp[0]);
	else
		return (temp[1]);
}

void	check_front(t_vec v, t_vec *temp)
{
	if (v_dot(temp[0], v) < 0)
		temp[0].x = NAN;
}
