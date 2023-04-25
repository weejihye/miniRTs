/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:35:52 by jwee              #+#    #+#             */
/*   Updated: 2023/04/25 22:28:38 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	init_info(info, infos);
	free_triple_ptr(infos);
	//for (int i = 0; infos[i]; i++)
	//	for(int j = 0; infos[i][j]; j++)
	//		printf("%s\n", infos[i][j]);
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
	system("leaks miniRT");
	return (0);
}