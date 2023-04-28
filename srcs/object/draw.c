#include "miniRT.h"

void	draw_pixel(t_cam cam, t_mlx mlx, t_obj *obj, t_point point);
void	draw_sphere(t_mlx mlx, t_sp sp, t_point point, t_point hit);
void	draw_plane(t_mlx mlx, t_plane p, t_point point, t_point hit);
void	draw_cylinder(t_mlx mlx, t_cyl cyl, t_point point, t_point hit);
t_vec	monitor_dot(t_point point, t_cam cam);
void	my_mlx_pixel_put(t_img *img, t_point point, t_rgb rgb, int t);

void	draw(t_cam cam, t_mlx mlx, t_obj *obj, t_point point)
{
	t_point p;

	p.y = 0;
	while (p.y < cam.height)
	{
		p.x = 0;
		while (p.x < cam.width)
		{
			draw_pixel(cam, mlx, obj, point);
			++p.x;
		}
		++p.y;
	}

}

void	draw_pixel(t_cam cam, t_mlx mlx, t_obj *obj, t_point point)
{
	t_point	hit;
	t_obj	*hit_obj;
	t_point	p;
	int		hit_flag;
	t_vec	v;

	hit_flag = 1;
	v = monitor_dot(point, cam);
	while (obj)
	{
		if (obj->type == OB_SP)
			p = hit_sphere(*(t_sp *)(obj->p_obj), v);
		if (obj->type == OB_CYL)
			p = hit_cylinder(*(t_cyl *)(obj->p_obj), v);
		if (obj->type == OB_PL)
			p = hit_plane(*(t_plane *)(obj->p_obj), v);
		if (hit_flag || point_len_origin(hit) > point_len_origin(p))
		{
			hit = p;
			hit_obj = obj;
			hit_flag = 0;
		}
		obj = obj->next;
	}
}

void	draw_sphere(t_mlx mlx, t_sp sp, t_point point, t_point hit)//, t_light light)
{
	double ang;

	my_mlx_pixel_put(&mlx.img, point, sp.rgb, 255);
	// ang = sphere_angle(sp, light, point);
	// if (ang >= 90 || ang < 0)
	// 	return ;
	// my_mlx_pixel_put(&mlx.img, point, light.rgb, (int)(255 / sin(ang)));
}

void	draw_plane(t_mlx mlx, t_plane p, t_point point, t_point hit)
{
	my_mlx_pixel_put(&mlx.img, point, p.rgb, 255);
}

void	draw_cylinder(t_mlx mlx, t_cyl cyl, t_point point, t_point hit)
{
	my_mlx_pixel_put(&mlx.img, point, cyl.rgb, 255);
}

t_vec	monitor_dot(t_point point, t_cam cam)
{
	return (v_nor(v_add(cam.view_center,
				v_add(v_mlt(cam.width / 2 - 0.5 - point.x, cam.horizon),
					v_mlt(cam.height / 2 - 0.5 - point.y, cam.vertical)))));
}

void	my_mlx_pixel_put(t_img *img, t_point point, t_rgb rgb, int t)
{
	char	*dst;

	dst = img->addr + ((int)point.y * img->line_length
			+ (int)point.x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color(t, rgb);
}