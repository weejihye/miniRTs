#include "miniRT.h"

int	init_camera(t_info *info, char **infos)
{
	int		i;
	char	**viewpoint_str;

	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("camera number of properties is invalid\n"));
	vec_syntax_check(infos[1]);
	vec_syntax_check(infos[2]);
	viewpoint_str = ft_split(infos[1], ',');
	info->cam = malloc(sizeof(t_cam));
	info->cam->origin.x = ft_stod(viewpoint_str[0], 0.0, 1);
	info->cam->origin.y = ft_stod(viewpoint_str[1], 0.0, 1);
	info->cam->origin.z = ft_stod(viewpoint_str[2], 0.0, 1);
	info->cam->fov = ft_atoi_valid(infos[3]);
	if (!ft_isdouble(info->cam->origin.x) || !ft_isdouble(info->cam->origin.y)
		|| !ft_isdouble(info->cam->origin.z) || info->cam->fov < 0
		|| info->cam->fov > 180)
		return (print_error("out of range\n"));
	return (0);
}