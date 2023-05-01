#include "miniRT.h"

typedef struct s_monitor
{
	int	w;
	int	h;
	int	fov;
	//etc
}	t_monitor;

t_vec	monitor_dot(t_point point, t_monitor monitor, t_vec v)
{
	t_vec		w;
	t_vec		h;
	const t_vec	y = {0, 1, 0};

	w = v_nor(v_cro(y, v));
	h = v_nor(v_cro(v, w));
	return (v_nor(v_add(v_mlt(monitor.w / 2 / tan(get_radian((double)monitor.fov / 2)), v), v_add(v_mlt(monitor.w / 2 - 0.5 - point.x, w),
					v_mlt(monitor.h / 2 - 0.5 - point.y, h)))));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	draw_shape(t_mlx mlx, t_obj *objs)
{
	t_monitor	monitor;
	t_vec		v;
	t_point		p;

	v = v_nor(vec(1, 0 ,0));
	monitor.w = 16 * SIZE;
	monitor.h = 9 * SIZE;
	monitor.fov = 170;
	p.y = 0;
	while (p.y < monitor.h)
	{
		p.x = 0;
		while (p.x < monitor.w)
		{
			if (0)
				;
			else if (!isnan(hit_cylinder(*((t_cyl *)(objs->p_obj)),
					monitor_dot(p, monitor, v)).x))
				my_mlx_pixel_put(&mlx.img, p.x, p.y, 0x00104040);
			else
				my_mlx_pixel_put(&mlx.img, p.x, p.y, 0x00000000);
			++p.x;
		}
		++p.y;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_obj		*objs;
	t_light		*light;

	if (parsing(&objs, &light, argv[1]))
	{
		system("leaks miniRT");
		return (1);
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 600, 400, "miniRT");
	mlx.img.img = mlx_new_image(mlx.mlx, 600, 400);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	draw_shape(mlx, objs);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, press_key, &objs);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, press_button_exit, &objs);
	mlx_loop(mlx.mlx);
	system("leaks miniRT");
	return (0);
}