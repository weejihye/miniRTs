/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:35:52 by jwee              #+#    #+#             */
/*   Updated: 2023/04/26 15:01:42 by jwee             ###   ########.fr       */
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
	t_ambient *amb = (t_ambient *)info.objs->next->next->next->next->next->p_obj;
	t_cam *cam = (t_cam *)info.objs->next->next->next->next->p_obj;
	t_light *light = (t_light *)info.objs->next->next->next->p_obj;
	t_sp *sp = (t_sp *)info.objs->next->next->p_obj;
	t_plane *pl = (t_plane *)info.objs->next->p_obj;
	t_cyl *cyl = (t_cyl *)info.objs->p_obj;
	printf("camera : %f %f %f %f %f %f %d\n", cam->origin.x, cam->origin.y, cam->origin.z, cam->axis.x, cam->axis.y, cam->axis.z, cam->fov);
	printf("ambient : %f %d %d %d\n", amb->ratio, amb->rgb.r, amb->rgb.g, amb->rgb.b);
	printf("light : %f %f %f %f %d %d %d\n", light->origin.x, light->origin.y, light->origin.z, light->ratio, light->rgb.r, light->rgb.g, light->rgb.b);
	printf("sphere : %f %f %f %f %d %d %d\n", sp->c.x, sp->c.y, sp->c.z, sp->r, sp->rgb.r, sp->rgb.g, sp->rgb.b);
	printf("plane : %f %f %f %f %f %f %d %d %d\n", pl->c.x, pl->c.y, pl->c.z, pl->vec.x, pl->vec.y, pl->vec.z, pl->rgb.r, pl->rgb.g, pl->rgb.b);
	printf("cylinder : %f %f %f %f %f %f %f %f %d %d %d\n", cyl->c.x, cyl->c.y, cyl->c.z, cyl->vec.x, cyl->vec.y, cyl->vec.z, cyl->r, cyl->h, cyl->rgb.r, cyl->rgb.g, cyl->rgb.b);
	while (!info.objs)
	{
		free(info.objs);
		info.objs = info.objs->next;
	}
	system("leaks miniRT");
	return (0);
}