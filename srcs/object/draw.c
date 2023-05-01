#include "miniRT.h"

void	draw_pixel(t_objs *objs, t_point point);
void	draw_sphere(t_objs *objs, t_sp *sp, t_point point, t_point hit);
void	draw_plane(t_objs *objs, t_plane *p, t_point point, t_point hit);
void	draw_cylinder(t_objs *objs, t_cyl *cyl, t_point point, t_point hit);
t_vec	monitor_dot(t_point point, t_cam cam);
void	my_mlx_pixel_put(t_img *img, t_point point, t_rgb rgb);

void	draw(t_mlx mlx, t_objs *objs)
{
	t_point p;

	objs->mlx = mlx;
	p.y = 0;
	while (p.y < objs->cam.height)
	{
		p.x = 0;
		while (p.x < objs->cam.width)
		{
			draw_pixel(objs, p);
			++p.x;
		}
		++p.y;
	}

}

void	draw_pixel(t_objs *objs, t_point point)
{
	t_point	hit;
	t_obj	*hit_obj;
	t_vec	v;
	t_obj	*temp;
	t_point	p;

	hit_obj = NULL;
	v = monitor_dot(point, objs->cam);
	temp = objs->obj;
	while (temp)
	{
		if (temp->type == OB_SP)
			p = hit_sphere(*(t_sp *)(temp->p_obj), v);
		if (temp->type == OB_CYL)
			p = hit_cylinder(*(t_cyl *)(temp->p_obj), v);
		if (temp->type == OB_PL)
			p = hit_plane(*(t_plane *)(temp->p_obj), v);
		if (hit_obj == NULL || point_len_origin(hit) > point_len_origin(p))
		{
			hit = p;
			hit_obj = temp;
		}
		temp = temp->next;
	}
	if (hit_obj)
	{
		if (hit_obj->type == OB_SP)
			draw_sphere(objs, hit_obj->p_obj, p, hit);
		if (hit_obj->type == OB_CYL)
			draw_cylinder(objs, hit_obj->p_obj, p, hit);
		if (hit_obj->type == OB_PL)
			draw_plane(objs, hit_obj->p_obj, p, hit);
	}
}

void	draw_sphere(t_objs *objs, t_sp *sp, t_point point, t_point hit)
{
	double	ang;
	t_rgb	rgb;

	ang = sphere_angle(*sp, objs->light, hit);
	if (ang >= M_PI_2 || ang < 0)
		return ;
	rgb.r = ((double)sp->rgb.r / 255) * (objs->light.lgt_rgb.r / sin(ang)
			+ objs->light.amb_rgb.r);
	rgb.g = ((double)sp->rgb.g / 255) * (objs->light.lgt_rgb.g / sin(ang)
			+ objs->light.amb_rgb.g);
	rgb.b = ((double)sp->rgb.b / 255) * (objs->light.lgt_rgb.b / sin(ang)
			+ objs->light.amb_rgb.b);
	my_mlx_pixel_put(&objs->mlx.img, point, rgb);
}

void	draw_plane(t_objs *objs, t_plane *p, t_point point, t_point hit)
{
	double	ang;
	t_rgb	rgb;

	ang = plane_angle(*p, objs->light, hit);
	if (ang >= M_PI_2 || ang < 0)
		return ;
	rgb.r = ((double)p->rgb.r / 255) * (objs->light.lgt_rgb.r / sin(ang)
			+ objs->light.amb_rgb.r);
	rgb.g = ((double)p->rgb.g / 255) * (objs->light.lgt_rgb.g / sin(ang)
			+ objs->light.amb_rgb.g);
	rgb.b = ((double)p->rgb.b / 255) * (objs->light.lgt_rgb.b / sin(ang)
			+ objs->light.amb_rgb.b);
	my_mlx_pixel_put(&objs->mlx.img, point, rgb);
}

void	draw_cylinder(t_objs *objs, t_cyl *cyl, t_point point, t_point hit)
{
	double	ang;
	t_rgb	rgb;

	ang = cyl_angle(*cyl, objs->light, hit);
	if (ang >= M_PI_2 || ang < 0)
		return ;
	rgb.r = ((double)cyl->rgb.r / 255) * (objs->light.lgt_rgb.r / sin(ang)
			+ objs->light.amb_rgb.r);
	rgb.g = ((double)cyl->rgb.g / 255) * (objs->light.lgt_rgb.g / sin(ang)
			+ objs->light.amb_rgb.g);
	rgb.b = ((double)cyl->rgb.b / 255) * (objs->light.lgt_rgb.b / sin(ang)
			+ objs->light.amb_rgb.b);
	my_mlx_pixel_put(&objs->mlx.img, point, rgb);
}

t_vec	monitor_dot(t_point point, t_cam cam)
{
	return (v_nor(v_add(cam.view_center,
				v_add(v_mlt(cam.width / 2 - 0.5 - point.x, cam.horizon),
					v_mlt(cam.height / 2 - 0.5 - point.y, cam.vertical)))));
}

void	my_mlx_pixel_put(t_img *img, t_point point, t_rgb rgb)
{
	char	*dst;

	dst = img->addr + ((int)point.y * img->line_length
			+ (int)point.x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color(rgb);
}