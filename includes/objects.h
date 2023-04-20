#ifndef OBJECTS_H
# define OBJECTS_H

# include "miniRT.h"
# include "vector.h"

typedef struct s_sphere
{
	int		r;
	t_vec	center;
	t_rgb	rgb;
}	t_sp;

//들어오는 백터는 원점을 지나며 원점 백터이여하고 반환값은 성공시 해당 포인트 실패시 x에 nan
t_point	get_contact_sphere(t_sp s, t_vec v);

#endif