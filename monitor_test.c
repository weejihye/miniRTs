#include "objects.h"
#include "vector.h"
#include <math.h>
#define	SIZE 50

void	print_point(t_point p);
typedef struct s_moniter
{
	int	w;
	int	h;
	int	fov;
	//etc
}	t_monitor;

t_vec	moniter_dot(t_point point, t_monitor monitor, t_vec v)
{
	t_vec		w;
	t_vec		h;
	const t_vec	y = {0, 1, 0};

	w = v_nor(v_cro(y, v));
	h = v_nor(v_cro(v, w));
	// print_point(w); printf("\n");
	// print_point(h); printf("\n");
	if (monitor.fov == 180)
		return (v_nor(v_add(v_mlt(monitor.w / 2 - point.x, w), v_mlt(monitor.h / 2 - point.y, h))));
	return (v_nor(v_add(v_mlt(monitor.w / 2 / tan(get_radian(monitor.fov / 2)), v), v_add(v_mlt(monitor.w / 2 - point.x, w), v_mlt(monitor.h / 2 - point.y, h)))));
}

int	main()
{
	t_plane	plane;
	plane.c = (t_vec){0, 0, 1};
	plane.vec = v_nor((t_vec){10, 18, 12});

	t_cyl	cyl;
	cyl.c = vec(10, 0, 0);
	cyl.h = 2;
	cyl.r = 1;
	cyl.vec = v_nor(vec(0, 1, 0));

	t_sp	sphere;
	sphere.c = vec(0, 0, 6);
	sphere.r = 4;

	t_monitor	moniter;
	moniter.w = 16 * SIZE;
	moniter.h = 9 * SIZE;
	moniter.fov = 180;

	t_vec	v = v_nor(vec(1, 0, 0));
	t_point	p;

	p.y = 0;
	while (p.y < moniter.h)
	{
		p.x = 0;
		while (p.x < moniter.w)
		{
			if (0)
				;
			else if (!isnan(sphere_hit(sphere, moniter_dot(p, moniter, v)).x))
				printf("▲  ");
			// else if (!isnan(hit_cylinder(cyl, moniter_dot(p, moniter, v)).x))
			// 	printf("◎  ");
			// else if (!isnan(hit_plane(plane,  moniter_dot(p, moniter, v)).x))
			// 	printf("■  ");
			else
				printf("   ");
			++p.x;
		}
		printf("\n");
		++p.y;
	}
	printf("%f\n", get_radian(180 / 2));
}