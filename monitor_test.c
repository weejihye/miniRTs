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
	return (v_nor(v_add(v_mlt(monitor.w / 2 / tan(get_radian((double)monitor.fov / 2)), v), v_add(v_mlt(point.x - (monitor.w / 2 - 0.5), w), v_mlt(point.y - (monitor.h / 2 - 0.5), h)))));
}

int	main()
{
	t_plane	plane;
	plane.c = (t_vec){0, 0, 1};
	plane.vec = v_nor((t_vec){0, 1, 0});

	t_cyl	cyl;
	cyl.c = vec(10, 0, 0);
	cyl.h = 6;
	cyl.r = 3;
	cyl.vec = v_nor(vec(0, 1, 0));


	t_sp	sphere;
	sphere.c = vec(10, 1, 0);
	sphere.r = 5;

	t_monitor	moniter;
	moniter.w = 16 * SIZE;
	moniter.h = 9 * SIZE;
	moniter.fov = 90;

	t_vec	v = v_nor(vec(1, 0, 0));
	t_point	p;
	t_point	hit;
	double	ang;

	p.y = 0;
	while (p.y < moniter.h)
	{
		p.x = 0;
		while (p.x < moniter.w)
		{
			if (0)
				;
			else if (!isnan(hit_sphere(sphere, moniter_dot(p, moniter, v)).x))
			{
				hit = hit_sphere(sphere, moniter_dot(p, moniter, v));
				ang = sphere_angle(sphere, light, hit);
				if (isnan(ang))
					printf("   ");
				else if (ang > M_PI_4)
					printf("■■ ");
				else
					printf("■■■");
			}
			// 	printf("■■■");
			// else if (!isnan(hit_cylinder(cyl, moniter_dot(p, moniter, v)).x))
			// 	printf("■■ ");
			// else if (!isnan(hit_plane(plane,  moniter_dot(p, moniter, v)).x))
			// 	printf("■  ");
			else
				printf("   ");
			++p.x;
		}
		printf("\n");
		++p.y;
	}
}