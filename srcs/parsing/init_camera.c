#include "miniRT.h"

int	init_light(t_obj **objs, char **infos)
{
	t_light	*light;

	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_light : number of properties is invalid\n"));
	if (double_syntax_check(infos[2]))
		return (print_error("init_light : double check error\n"));
	if (!ft_lstnew_obj(objs, malloc(sizeof(t_light)), OB_LGT))
		return (1);
	light = (t_light *)((*objs)->p_obj);
	light->ratio = ft_stod(infos[2], 0.0, 1);
	if (!ft_isdouble(light->ratio)
		|| str_to_rgb(&light->rgb, infos[3])
		|| str_to_vec(&light->origin, infos[1]))
	{
		free(light);
		return (print_error("init_light : out of range\n"));
	}
	return (0);
}

int	init_ambient(t_obj **objs, char **infos)
{
	t_ambient	*amb;

	if (!infos[1] || !infos[2] || infos[3])
		return (print_error("init_ambient : number of properties is invalid\n"));
	if (double_syntax_check(infos[1]))
		return (print_error("init_ambient : double check error\n"));
	if (!ft_lstnew_obj(objs, malloc(sizeof(t_ambient)), OB_AMB))
		return (1);
	amb = (t_ambient *)((*objs)->p_obj);
	amb->ratio = ft_stod(infos[1], 0.0, 1);
	if (!ft_isdouble(amb->ratio)
		|| str_to_rgb(&amb->rgb, infos[2]))
	{
		free(amb);
		return (print_error("init_ambient : out of range\n"));
	}
	return (0);
}

int	init_camera(t_obj **objs, char **infos)
{
	t_obj	*objs;
	t_cam	*cam;

	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_camera : number of properties is invalid\n"));
	if (!ft_lstnew_obj(objs, malloc(sizeof(t_cam)), OB_CAM))
		return (1);
	cam = (t_cam *)((*objs)->p_obj);
	cam->fov = ft_atoi_valid(infos[3]);
	if (str_to_vec(&cam->origin, infos[1])
		|| str_to_vec(&cam->axis, infos[2])
		|| (cam->fov < 0 || cam->fov > 180)
		|| check_normalized_vec(cam->axis))
	{
		free(cam);
		return (print_error("init_camera : fail to input value"));
	}
	return (0);
}
