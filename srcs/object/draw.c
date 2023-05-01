#include "miniRT.h"

void	draw_pixel(t_objs *objs, t_dot dot);
void	draw_sphere(t_objs *objs, t_sp *sp, t_dot dot, t_point hit);
void	draw_plane(t_objs *objs, t_plane *p, t_dot dot, t_point hit);
void	draw_cylinder(t_objs *objs, t_cyl *cyl, t_dot dot, t_point hit);
t_vec	monitor_dot(t_dot dot, t_cam cam);
void	my_mlx_pixel_put(t_img *img, t_dot dot, t_rgb rgb);


void	print_point(t_point p);/////

void	draw(t_mlx mlx, t_objs *objs)
{
	t_dot dot;

	objs->mlx = mlx;
	dot.y = 0;
	while (dot.y < objs->cam.height)
	{
		dot.x = 0;
		while (dot.x < objs->cam.width)
		{
			draw_pixel(objs, dot);
			++dot.x;
		}
		++dot.y;
		// printf("\n");
	}

}

void	draw_pixel(t_objs *objs, t_dot dot)
{
	t_point	hit;
	t_obj	*hit_obj;
	t_vec	v;
	t_obj	*temp;
	t_point	p;

	hit_obj = NULL;
	v = monitor_dot(dot, objs->cam);
	temp = objs->obj;
	while (temp)
	{
		if (temp->type == OB_SP)
			p = hit_sphere(*(t_sp *)(temp->p_obj), v);
		if (temp->type == OB_CYL)
			p = hit_cylinder(*(t_cyl *)(temp->p_obj), v);
		if (temp->type == OB_PL)
			p = hit_plane(*(t_plane *)(temp->p_obj), v);
		if (!isnan(p.x) && (hit_obj == NULL || point_len_origin(hit) > point_len_origin(p)))
		{
			hit = p;
			hit_obj = temp;
		}
		temp = temp->next;
	}
	if (hit_obj)
	{
		// printf("* ");
		if (hit_obj->type == OB_SP)
			draw_sphere(objs, hit_obj->p_obj, dot, hit);
		if (hit_obj->type == OB_CYL)
			draw_cylinder(objs, hit_obj->p_obj, dot, hit);
		if (hit_obj->type == OB_PL)
			draw_plane(objs, hit_obj->p_obj, dot, hit);
	}
	// else
	// 	printf("  ");
}

void	draw_sphere(t_objs *objs, t_sp *sp, t_dot dot, t_point hit)
{
	double	ang;
	t_rgb	rgb;
	double	t;

	ang = sphere_angle(*sp, objs->light, hit);
	if (ang > M_PI_2 || ang < 0 || isnan(ang))
		return ;
	t = ((double)sp->rgb.r / 255) * ((double)objs->light.lgt_rgb.r / 255 * sin(ang) * objs->light.lgt_ratio
			+ (double)objs->light.amb_rgb.r / 255 * objs->light.amb_ratio);
	if (t >= 1)
		rgb.r = 255;
	else
		rgb.r = t * 255;
	t = ((double)sp->rgb.g / 255) * ((double)objs->light.lgt_rgb.g / 255 * sin(ang) * objs->light.lgt_ratio
			+ (double)objs->light.amb_rgb.g / 255 * objs->light.amb_ratio);
	if (t >= 1)
		rgb.g = 255;
	else
		rgb.g = t * 255;
	t = ((double)sp->rgb.b / 255) * ((double)objs->light.lgt_rgb.b / 255 * sin(ang) * objs->light.lgt_ratio
			+ (double)objs->light.amb_rgb.b / 255 * objs->light.amb_ratio);
	if (t >= 1)
		rgb.b = 255;
	else
		rgb.b = t * 255;
	my_mlx_pixel_put(&objs->mlx.img, dot, rgb);
}

void	draw_plane(t_objs *objs, t_plane *p, t_dot dot, t_point hit)
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
	my_mlx_pixel_put(&objs->mlx.img, dot, rgb);
}

void	draw_cylinder(t_objs *objs, t_cyl *cyl, t_dot dot, t_point hit)
{
	double	ang;

	t_rgb	rgb;

	ang = cyl_angle(*cyl, objs->light, hit);
	if (ang >= M_PI_2 || ang < 0)
		return ;
	rgb.r = (double)cyl->rgb.r * ((double)(objs->light.lgt_rgb.r) * objs->light.lgt_ratio / sin(ang) + (double)(objs->light.amb_rgb.r) * objs->light.amb_ratio);
	rgb.g= ((double)cyl->rgb.g / 255) * ((double)(objs->light.lgt_rgb.g)
			/ sin(ang) + (double)(objs->light.amb_rgb.g));
	rgb.b = ((double)cyl->rgb.b / 255) * ((double)(objs->light.lgt_rgb.b)
			/ sin(ang) + (double)(objs->light.amb_rgb.b));
	my_mlx_pixel_put(&objs->mlx.img, dot, rgb);
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
	*(unsigned int*)dst = color(rgb);
	rgb.b = 1;
}