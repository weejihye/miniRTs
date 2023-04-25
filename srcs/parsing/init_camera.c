#include "miniRT.h"

int	init_light(t_info *info, char **infos)
{
	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_light : number of properties is invalid\n"));
	if (double_syntax_check(infos[2]))
		return (print_error("init_light : double check error\n"));
	info->light = malloc(sizeof(t_light));
	if (!info->light)
		return (print_error("init_light : structure malloc fail\n"));
	info->light->ratio = ft_stod(infos[2], 0.0, 1);
	if (!ft_isdouble(info->light->ratio)
		|| str_to_rgb(&info->light->rgb, infos[3])
		|| str_to_vec(&info->light->origin, infos[1]))
	{
		free(info->light);
		return (print_error("init_light : out of range\n"));
	}
	return (0);
}

int	init_ambient(t_info *info, char **infos)
{
	if (!infos[1] || !infos[2] || infos[3])
		return (print_error("init_ambient : number of properties is invalid\n"));
	if (double_syntax_check(infos[1]))
		return (print_error("init_ambient : double check error\n"));
	info->ambient = malloc(sizeof(t_ambient));
	if (!info->ambient)
		return (print_error("init_ambient : structure malloc fail\n"));
	info->ambient->ratio = ft_stod(infos[1], 0.0, 1);
	if (!ft_isdouble(info->ambient->ratio)
		|| str_to_rgb(&info->ambient->rgb, infos[2]))
	{
		free(info->ambient);
		return (print_error("init_ambient : out of range\n"));
	}
	return (0);
}

int	init_camera(t_info *info, char **infos)
{
	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_camera : number of properties is invalid\n"));
	info->cam = malloc(sizeof(t_cam));
	if (!info->cam)
		return (print_error("init_camera : structure malloc fail\n"));
	info->cam->fov = ft_atoi_valid(infos[3]);
	if (str_to_vec(&info->cam->origin, infos[1])
		|| str_to_vec(&info->cam->axis, infos[2])
		|| (info->cam->fov < 0 || info->cam->fov > 180)
		|| check_normalized_vec(info->cam->axis))
	{
		free(info->cam);
		return (print_error("init_camera : fail to input value"));
	}
	return (0);
}
