/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:35:52 by jwee              #+#    #+#             */
/*   Updated: 2023/04/26 13:30:08 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	zero_setting(t_info *info)
{
	info->cam = NULL;
	info->ambient = NULL;
	info->light = NULL;
	info->sphere = NULL;
	info->cylinder = NULL;
	info->plane = NULL;
}

int	init_info(t_info *info, char ***infos)
{
	while (*infos)
	{
		if (!ft_strcmp(**infos, "C"))
			init_camera(info, *infos);
		else if (!ft_strcmp(**infos, "A"))
			init_ambient(info, *infos);
		else if (!ft_strcmp(**infos, "L"))
			init_light(info, *infos);
		else if (!ft_strcmp(**infos, "sp"))
			init_sphere(info, *infos);
		else if (!ft_strcmp(**infos, "pl"))
			init_plane(info, *infos);
		else if (!ft_strcmp(**infos, "cy"))
			init_cylinder(info, *infos);
		infos++;
	}
	return (0);
}

int	parsing(t_info *info, char *file)
{
	char	***infos;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("parsing error : open file fail"));
	read_rt(fd, &infos);
	close(fd);
	zero_setting(info);
	init_info(info, infos);
	free_triple_ptr(infos);
	return (0);
}

int main(int argc, char *argv[])
{
	t_info info;

	(void)argc;
	parsing(&info, argv[1]);
	printf("camera : %f %f %f %f %f %f %d\n", info.cam->origin.x, info.cam->origin.y, info.cam->origin.z, info.cam->axis.x, info.cam->axis.y, info.cam->axis.z, info.cam->fov);
	printf("ambient : %f %d %d %d\n", info.ambient->ratio, info.ambient->rgb.r, info.ambient->rgb.g, info.ambient->rgb.b);
	printf("light : %f %f %f %f %d %d %d\n", info.light->origin.x, info.light->origin.y, info.light->origin.z, info.light->ratio, info.light->rgb.r, info.light->rgb.g, info.light->rgb.b);
	printf("sphere : %f %f %f %f %d %d %d\n", info.sphere->c.x, info.sphere->c.y, info.sphere->c.z, info.sphere->r, info.sphere->rgb.r, info.sphere->rgb.g, info.sphere->rgb.b);
	printf("plane : %f %f %f %f %f %f %d %d %d\n", info.plane->c.x, info.plane->c.y, info.plane->c.z, info.plane->vec.x, info.plane->vec.y, info.plane->vec.z, info.plane->rgb.r, info.plane->rgb.g, info.plane->rgb.b);
	printf("plane : %f %f %f %f %f %f %f %f %d %d %d\n", info.cylinder->c.x, info.cylinder->c.y, info.cylinder->c.z, info.cylinder->vec.x, info.cylinder->vec.y, info.cylinder->vec.z, info.cylinder->r, info.cylinder->h, info.cylinder->rgb.r, info.cylinder->rgb.g, info.cylinder->rgb.b);
	system("leaks miniRT");
	return (0);
}