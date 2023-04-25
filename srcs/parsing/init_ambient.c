#include "miniRT.h"

int	init_ambient(t_info *info, char **infos)
{
	int		i;
	char	**rgb_str;

	if (!infos[1] || !infos[2] || infos[3])
		return (print_error("ambient number of properties is invalid\n"));
	if (vec_syntax_check(infos[2]) || double_syntax_check(infos[1]))
		return (print_error("ambient syntax false\n"));
	rgb_str = ft_split(infos[2], ',');
	info->ambient = malloc(sizeof(t_ambient));
	info->ambient->rgb.r = ft_stod(rgb_str[0], 0.0, 1);
	info->ambient->rgb.g = ft_stod(rgb_str[1], 0.0, 1);
	info->ambient->rgb.b = ft_stod(rgb_str[2], 0.0, 1);
	info->ambient->ratio = ft_stod(infos[1], 0.0, 1);
	if (!ft_isdouble(info->ambient->rgb.r) || !ft_isdouble(info->ambient->rgb.g)
		|| !ft_isdouble(info->ambient->rgb.b) || !ft_isdouble(info->ambient->ratio))
		return (print_error("out of range\n"));
	printf("%c %c %c %f\n", info->ambient->rgb.r, info->ambient->rgb.g, info->ambient->rgb.b, info->ambient->ratio);
	return (0);
}
