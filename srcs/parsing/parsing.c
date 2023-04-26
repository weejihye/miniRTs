/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:35:52 by jwee              #+#    #+#             */
/*   Updated: 2023/04/26 15:37:48 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


int	init_info(t_obj **objs, char ***infos)
{
	while (*infos)
	{
		if (!ft_strcmp(**infos, "C"))
			init_camera(objs, *infos);
		else if (!ft_strcmp(**infos, "A"))
			init_ambient(objs, *infos);
		else if (!ft_strcmp(**infos, "L"))
			init_light(objs, *infos);
		else if (!ft_strcmp(**infos, "sp"))
			init_sphere(objs, *infos);
		else if (!ft_strcmp(**infos, "pl"))
			init_plane(objs, *infos);
		else if (!ft_strcmp(**infos, "cy"))
			init_cylinder(objs, *infos);
		infos++;
	}
	return (0);
}

int	parsing(t_obj **objs, char *file)
{
	char	***infos;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("parsing error : open file fail"));
	read_rt(fd, &infos);
	close(fd);
	*objs = NULL;
	init_info(objs, infos);
	free_triple_ptr(infos);
	return (0);
}

int main(int argc, char *argv[])
{
	t_obj	*objs;

	(void)argc;
	parsing(&objs, argv[1]);
	t_ambient *amb = (t_ambient *)objs->next->next->next->next->next->p_obj;
	t_cam *cam = (t_cam *)objs->next->next->next->next->p_obj;
	t_light *light = (t_light *)objs->next->next->next->p_obj;
	t_sp *sp = (t_sp *)objs->next->next->p_obj;
	t_plane *pl = (t_plane *)objs->next->p_obj;
	t_cyl *cyl = (t_cyl *)objs->p_obj;
	printf("camera : %f %f %f %f %f %f %d\n", cam->origin.x, cam->origin.y, cam->origin.z, cam->axis.x, cam->axis.y, cam->axis.z, cam->fov);
	printf("ambient : %f %d %d %d\n", amb->ratio, amb->rgb.r, amb->rgb.g, amb->rgb.b);
	printf("light : %f %f %f %f %d %d %d\n", light->origin.x, light->origin.y, light->origin.z, light->ratio, light->rgb.r, light->rgb.g, light->rgb.b);
	printf("sphere : %f %f %f %f %d %d %d\n", sp->c.x, sp->c.y, sp->c.z, sp->r, sp->rgb.r, sp->rgb.g, sp->rgb.b);
	printf("plane : %f %f %f %f %f %f %d %d %d\n", pl->c.x, pl->c.y, pl->c.z, pl->vec.x, pl->vec.y, pl->vec.z, pl->rgb.r, pl->rgb.g, pl->rgb.b);
	printf("cylinder : %f %f %f %f %f %f %f %f %d %d %d\n", cyl->c.x, cyl->c.y, cyl->c.z, cyl->vec.x, cyl->vec.y, cyl->vec.z, cyl->r, cyl->h, cyl->rgb.r, cyl->rgb.g, cyl->rgb.b);
	while (!objs)
	{
		free(objs);
		objs = objs->next;
	}
	system("leaks miniRT");
	return (0);
}
