/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:30:31 by jwee              #+#    #+#             */
/*   Updated: 2023/04/26 01:26:37 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_plane(t_info *info, char **infos)
{
	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_plane : number of properties is invalid\n"));
	info->plane = malloc(sizeof(t_plane));
	if (!info->plane)
		return (print_error("init_plane : structure malloc fail\n"));
	if (str_to_vec(&info->plane->center, infos[1])
		|| str_to_rgb(&info->plane->rgb, infos[3])
		|| str_to_vec(&info->plane->vec, infos[2])
		|| check_normalized_vec(info->plane->vec))
	{
		free(info->plane);
		return (print_error("init_plane : out of range\n"));
	}
	return (0);
}

int	init_sphere(t_info *info, char **infos)
{
	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_sphere : number of properties is invalid\n"));
	if (double_syntax_check(infos[2]))
		return (print_error("init_sphere : double check error\n"));
	info->sphere = malloc(sizeof(t_sp));
	if (!info->sphere)
		return (print_error("init_sphere : structure malloc fail\n"));
	info->sphere->r = ft_stod(infos[2], 0.0, 1);
	if (!ft_isdouble(info->sphere->r)
		|| str_to_rgb(&info->sphere->rgb, infos[3])
		|| str_to_vec(&info->sphere->center, infos[1]))
	{
		free(info->sphere);
		return (print_error("init_sphere : out of range\n"));
	}
	return (0);
}

int	init_cylinder(t_info *info, char **inf)
{
	if (!inf[1] || !inf[2] || !inf[3] || !inf[4] || !inf[5] || inf[6])
		return (print_error("init_cylinder : number of properties error\n"));
	if (double_syntax_check(inf[3]) || double_syntax_check(inf[4]))
		return (print_error("init_cylinder : double check error\n"));
	info->cylinder = malloc(sizeof(t_cyl));
	if (!info->cylinder)
		return (print_error("init_cylinder : structure malloc fail\n"));
	info->cylinder->r = ft_stod(inf[3], 0.0, 1);
	info->cylinder->h = ft_stod(inf[4], 0.0, 1);
	if (!ft_isdouble(info->cylinder->r) || !ft_isdouble(info->cylinder->h)
		|| str_to_rgb(&info->cylinder->rgb, inf[5])
		|| str_to_vec(&info->cylinder->center, inf[1])
		|| str_to_vec(&info->cylinder->vec, inf[2])
		|| check_normalized_vec(info->cylinder->vec))
	{
		free(info->cylinder);
		return (print_error("init_cylinder : out of range\n"));
	}
	return (0);
}