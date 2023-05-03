#include "miniRT.h"

t_hit	get_hit_info(t_objs *objs, t_dot dot);
t_vec	monitor_dot(t_dot dot, t_cam cam);
void	my_mlx_pixel_put(t_img *img, t_dot dot, t_rgb rgb);
void	draw_point(t_hit hit, t_objs *objs, t_dot dot);

void	draw(t_mlx mlx, t_objs *objs)
{
	t_dot	dot;
	t_hit	hit;

	objs->mlx = mlx;
	dot.y = 0;
	while (dot.y < objs->cam.height)
	{
		dot.x = 0;
		while (dot.x < objs->cam.width)
		{
			hit = get_hit_info(objs, dot);
			draw_point(hit, objs, dot);
			++dot.x;
		}
		++dot.y;
	}
	mlx_put_image_to_window(objs->mlx.mlx, objs->mlx.win,
		objs->mlx.img.img, 0, 0);
}

t_hit	get_hit_info(t_objs *objs, t_dot dot)
{
	t_vec	v;
	t_hit	temp;
	t_hit	hit;

	hit.obj = NULL;
	v = monitor_dot(dot, objs->cam);
	temp.obj = objs->obj;
	while (temp.obj)
	{
		if (temp.obj->type == OB_SP)
			temp.p = hit_sphere(*(t_sp *)(temp.obj->p_obj), v);
		if (temp.obj->type == OB_CYL)
			temp.p = hit_cylinder(*(t_cyl *)(temp.obj->p_obj), v);
		if (temp.obj->type == OB_PL)
			temp.p = hit_plane(*(t_plane *)(temp.obj->p_obj), v);
		if (!isnan(temp.p.x) && (hit.obj == NULL
				|| point_len_origin(hit.p) > point_len_origin(temp.p)))
			hit = temp;
		temp.obj = temp.obj->next;
	}
	return (hit);
}

void	draw_point(t_hit hit, t_objs *objs, t_dot dot)
{
	if (!hit.obj)
	{
		draw_background(objs, dot);
		return ;
	}
	if (hit.obj->type == OB_SP)
		my_mlx_pixel_put(&objs->mlx.img, dot, get_color(
				sphere_ratio(*(t_sp *)hit.obj->p_obj, objs->light, hit.p),
				sphere_reflect(*(t_sp *)hit.obj->p_obj, objs->light, hit.p),
				((t_sp *)hit.obj->p_obj)->rgb, objs->light));
	if (hit.obj->type == OB_CYL)
		my_mlx_pixel_put(&objs->mlx.img, dot, get_color(
				cyl_ratio(*(t_cyl *)hit.obj->p_obj, objs->light, hit.p),
				cyl_reflect(*(t_cyl *)hit.obj->p_obj, objs->light, hit.p),
				((t_cyl *)hit.obj->p_obj)->rgb, objs->light));
	if (hit.obj->type == OB_PL)
		my_mlx_pixel_put(&objs->mlx.img, dot, get_color(
				plane_ratio(*(t_plane *)hit.obj->p_obj, objs->light, hit.p),
				plane_reflect(*(t_plane *)hit.obj->p_obj, objs->light, hit.p),
				((t_plane *)hit.obj->p_obj)->rgb, objs->light));
}

t_vec	monitor_dot(t_dot dot, t_cam cam)
{
	return (v_nor(v_add(cam.view_center,
				v_add(v_mlt(cam.width / 2 - 0.5 - dot.x, cam.horizon),
					v_mlt(cam.height / 2 - 0.5 - dot.y, cam.vertical)))));
}

void	my_mlx_pixel_put(t_img *img, t_dot dot, t_rgb rgb)
{
	char	*dst;

	dst = img->addr + (dot.y * img->line_length
			+ dot.x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color(rgb);
}
