#ifndef OBJECTS_H
# define OBJECTS_H
# define ERR_R 0.000000001
# include "vector.h"
# include <stdio.h> //

enum e_type
{
	OB_SP,
	OB_CYL,
	OB_PL,
	OB_CAM,
	OB_LGT,
};

enum e_syl_hit
{
	TOP,
	BOT,
	MID
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
	t_point			c;
	t_vec			vec;
	t_rgb			rgb;
	double			r;
	double			h;
	enum e_syl_hit	hit;
}	t_cyl;

typedef struct s_light
{
	t_point	lgt_origin;
	t_rgb_r	lgt_rgb_ratio;
	t_rgb_r	amb_rgb_ratio;
}	t_light;

typedef struct s_moniter_dot
{
	int	x;
	int	y;
}	t_dot;

typedef struct s_hit_info
{
	t_obj		*obj;
	t_point		p;
}	t_hit;

//아직 도형의 내부에 있을 경우나 카메라 뒤에 있는 경우가 완벽하게 처리 되지 않았음
//들어오는 백터는 원점을 지나며 원점 백터이여하고 반환값은 성공시 해당 포인트 실패시 x에 nan
t_point	hit_sphere(t_sp s, t_vec v);
t_point	hit_plane(t_plane plane, t_vec vector);
t_point	hit_cylinder(t_cyl cyl, t_vec v);

double	plane_ratio(t_plane plane, t_light light, t_point point);
double	sphere_ratio(t_sp s, t_light light, t_point point);
double	cyl_ratio(t_cyl cyl, t_light light, t_point p);

double	plane_reflect(t_plane plane, t_light light, t_point point);
double	sphere_reflect(t_sp s, t_light light, t_point point);
double	cyl_reflect(t_cyl cyl, t_light light, t_point p);

t_point	check_ahead(t_vec v, t_point *temp);
void	check_front(t_vec v, t_vec *temp);

int		color(t_rgb rgb);
t_rgb_r	get_light_ratio(t_rgb rgb, double ratio);
t_rgb	get_color(double ratio, double ref, t_rgb rgb, t_light light);
#endif