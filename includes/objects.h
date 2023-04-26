#ifndef OBJECTS_H
# define OBJECTS_H

# include "miniRT.h"
# include "vector.h"
# include <stdio.h> //

enum e_type
{
	OB_SP,
	OB_CYL,
	OB_PL,
	OB_CAM,
	OB_AMB,
	OB_LGT,
};

typedef struct s_object
{
	enum e_type			type;
	void				*p_obj;
	struct s_object		*next;
}	t_obj;

typedef struct s_sphere
{
	double	r;
	t_point	c;
	t_rgb	rgb;
}	t_sp;

typedef struct s_plane
{
	t_point	c;
	t_vec	vec;
	t_rgb	rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_point	c;
	t_vec	vec;
	t_rgb	rgb;
	double	r;
	double	h;
}	t_cyl;

//아직 도형의 내부에 있을 경우나 카메라 뒤에 있는 경우가 완벽하게 처리 되지 않았음
//들어오는 백터는 원점을 지나며 원점 백터이여하고 반환값은 성공시 해당 포인트 실패시 x에 nan
t_point	sphere_hit(t_sp s, t_vec v);
t_vec	hit_plane(t_plane plane, t_vec vector);
t_point	hit_cylinder(t_cyl cyl, t_vec v);

double	cyl_angle(t_cyl cyl, t_vec v, t_point p);

int		check_ahead(t_vec v, t_vec *temp);
void	check_front(t_vec v, t_vec *temp);

t_plane	new_plane(t_point center, t_rgb rgb, t_vec vec);
#endif