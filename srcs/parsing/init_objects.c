#include "miniRT.h"

int	init_sphere(t_info *info, char **infos)
{
	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("sphere number of properties is invalid\n"));
	if (vec_syntax_check(infos[1]) || vec_syntax_check(infos[3]) || double_syntax_check(infos[2]))
		return (print_error("sphere syntax invalid\n"));
	info->sphere = malloc(sizeof(t_sp));
	if (!info->sphere)
		return (print_error("sphere structure malloc fail\n"));
	if (input_value_to_vec(&info->sphere->center.x, &info->sphere->center.y, &info->sphere->center.z, infos[1])
		|| input_value_to_vec(&info->sphere->rgb.r, &info->sphere->rgb.g, &info->sphere->rgb.b, infos[3]))
		return (print_error("sphere vector init fail"));
	if (info->sphere->r = ft_stod(infos[2], 0.0, 1);
	if (!ft_isdouble(info->sphere->center.x) || !ft_isdouble(info->sphere->center.y)
		|| !ft_isdouble(info->sphere->center.z) || info->sphere->fov < 0
		|| info->sphere->fov > 180)
		return (print_error("out of range\n"));
	return (0);
}