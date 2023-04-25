#include "vector.h"

int	check_ahead(t_vec v, t_vec *temp)
{
	if (temp[0].x < 0 != v.x < 0 && temp[1].x < 0 != v.x < 0)
	{
		temp[0].x = NAN;
		return (0);
	}
	if (temp[0].x < 0 != v.x < 0)
		return (1);
	if (temp[1].x < 0 != v.x < 0)
		return (0);
	if (point_len_origin(temp[0]) < point_len_origin(temp[1]))
		return (0);
	else
		return (1);
}

void	check_front(t_vec v, t_vec *temp)
{
	if (temp[0].x < 0 != v.x < 0)
		temp[0].x = NAN;
}