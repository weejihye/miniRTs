#include "miniRT.h"

int	init_light(t_obj **objs, char **infos, int *count)
{
	t_obj	*obj;
	t_light	*light;

	if ((*count & 4) || !infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_light : number of properties is invalid\n"));
	if (double_syntax_check(infos[2]))
		return (print_error("init_light : double check error\n"));
	obj = find_obj(*objs, OB_LGT);
	if (!obj)
	{
		if (!ft_lstnew_obj(objs, malloc(sizeof(t_light)), OB_LGT))
			return (print_error("init_light : camera object add fail\n"));
		obj = *objs;
	}
	light = obj->p_obj;
	light->lgt_ratio = ft_stod(infos[2], 0.0, 1);
	if (!ft_isdouble(light->lgt_ratio)
		|| str_to_rgb(&light->lgt_rgb, infos[3])
		|| str_to_vec(&light->lgt_origin, infos[1]))
		return (1);
	*count += 4;
	return (0);
}

int	init_amb(t_obj **objs, char **infos, int *count)
{
	t_obj	*obj;
	t_light	*amb;

	if ((*count & 2) || !infos[1] || !infos[2] || infos[3])
		return (print_error("init_ambient : number of properties is invalid\n"));
	if (double_syntax_check(infos[1]))
		return (print_error("init_ambient : double check error\n"));
	obj = find_obj(*objs, OB_LGT);
	if (!obj)
	{
		if (!ft_lstnew_obj(objs, malloc(sizeof(t_light)), OB_LGT))
			return (print_error("init_light : camera object add fail\n"));
		obj = *objs;
	}
	amb = obj->p_obj;
	amb->amb_ratio = ft_stod(infos[1], 0.0, 1);
	if (!ft_isdouble(amb->amb_ratio)
		|| str_to_rgb(&amb->amb_rgb, infos[2]))
		return (1);
	*count += 2;
	return (0);
}

static void	init_monitor(t_obj *obj)
{
	t_cam		*cam;
	const t_vec	y = {0, 1, 0};
	t_vec view_center;

	cam = obj->p_obj;
	cam->horizon = v_nor(v_cro(y, cam->axis));
	cam->vertical = v_nor(v_cro(cam->axis, cam->horizon));
	cam->width = 16 * SIZE;
	cam->height = 9 * SIZE;
	cam->focal_length = (cam->width / 2) / tan(cam->fov);
	cam->view_center = v_mlt(cam->focal_length, cam->axis);
	cam->corner = v_sub(v_sub(v_sub(vec(0, 0, 0), v_mlt(1/2 ,cam->horizon)),
				v_mlt(1 / 2, cam->vertical)), vec(0, 0, cam->focal_length));
}

int	init_camera(t_obj **objs, char **infos, int *count)
{
	t_cam	*cam;

	if ((*count & 1) || !infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_camera : number of properties is invalid\n"));
	if (!ft_lstnew_obj(objs, malloc(sizeof(t_cam)), OB_CAM))
		return (print_error("init_camera : camera object add fail\n"));
	cam = (t_cam *)((*objs)->p_obj);
	cam->fov = get_radian(ft_atoi_valid(infos[3]));
	if (str_to_vec(&cam->origin, infos[1])
		|| str_to_vec(&cam->axis, infos[2])
		|| (cam->fov < 0 || cam->fov > 180)
		|| check_normalized_vec(cam->axis))
		return (1);
	init_monitor(*objs);
	*count += 1;
	return (0);
}
