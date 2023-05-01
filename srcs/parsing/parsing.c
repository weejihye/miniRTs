#include "miniRT.h"

static void	move_point(t_objs *objs)
{
	t_obj	*temp;
	t_cam	*cam;

	temp = objs->obj;
	cam = &objs->cam;
	while (temp)
	{	
		if (temp->type == OB_LGT)
			((t_light *)(temp->p_obj))->lgt_origin
				= v_sub(((t_light *)(temp->p_obj))->lgt_origin, cam->origin);
		if (temp->type == OB_SP)
			((t_sp *)(temp->p_obj))->c
				= v_sub(((t_sp *)(temp->p_obj))->c, cam->origin);
		if (temp->type == OB_CYL)
			((t_cyl *)(temp->p_obj))->c
				= v_sub(((t_cyl *)(temp->p_obj))->c, cam->origin);
		if (temp->type == OB_PL)
			((t_plane *)(temp->p_obj))->c
				= v_sub(((t_plane *)(temp->p_obj))->c, cam->origin);
		temp = temp->next;
	}
	objs->light.lgt_origin = v_sub(objs->light.lgt_origin, cam->origin);
}

static int	init_info(t_objs *objs, char ***infos)
{
	int	count;

	count = 0;
	infos--;
	while (*(++infos))
	{
		if (!ft_strcmp(**infos, "C") && !init_camera(objs, *infos, &count))
			continue ;
		else if (!ft_strcmp(**infos, "A") && !init_amb(objs, *infos, &count))
			continue ;
		else if (!ft_strcmp(**infos, "L") && !init_light(objs, *infos, &count))
			continue ;
		else if (!ft_strcmp(**infos, "sp") && !init_sphere(objs, *infos))
			continue ;
		else if (!ft_strcmp(**infos, "pl") && !init_plane(objs, *infos))
			continue ;
		else if (!ft_strcmp(**infos, "cy") && !init_cylinder(objs, *infos))
			continue ;
		else
			return (1);
	}
	if (count != 7)
		return (1);
	return (0);
}

static int	check_filename(char *file)
{
	char	**temp;
	char	**temp2;

	temp = ft_split(file, '.');
	temp2 = temp;
	while (*(temp + 1))
		temp++;
	if (ft_strcmp(*temp, "rt"))
	{
		free_double_ptr(temp2);
		return (1);
	}
	else
	{
		free_double_ptr(temp2);
		return (0);
	}
}

int	parsing(t_objs *objs, char *file)
{
	char	***infos;
	int		fd;

	if (!file || check_filename(file))
		return (print_error("invalid extention\n"));
	infos = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("parsing error : open file fail"));
	if (read_rt(fd, &infos) || init_info(objs, infos))
		return (free_triple_ptr(infos));
	move_point(objs);
	free_triple_ptr(infos);
	return (0);
}

// int main(int argc, char *argv[])
// {
// 	t_obj	*objs;

// 	(void)argc;
// 	if (parsing(&objs, argv[1])){
// 		remove_list(&objs);
// //		system("leaks miniRT");
// 		return (1);
// 	}

// 		t_light *amb = (t_light *)objs->next->next->next->next->p_obj;
// 		t_cam *cam = (t_cam *)objs->next->next->next->p_obj;
// 		t_light *light = (t_light *)objs->next->next->next->next->p_obj;
// 		t_sp *sp = (t_sp *)objs->next->next->p_obj;
// 		t_plane *pl = (t_plane *)objs->next->p_obj;
// 		t_cyl *cyl = (t_cyl *)objs->p_obj;

// 		printf("object: %d %d %d %d %d\n", OB_SP, OB_CYL, OB_PL, OB_CAM, OB_LGT);
// 		printf("order : %d %d %d %d %d\n", objs->type, objs->next->type, objs->next->next->type, objs->next->next->next->type, objs->next->next->next->next->type);
// 		printf("camera : %f %f %f %f %f %f %f\n", cam->origin.x, cam->origin.y, cam->origin.z, cam->axis.x, cam->axis.y, cam->axis.z, cam->fov);
// 		printf("ambient : %f %d %d %d\n", light->amb_ratio, light->amb_rgb.r, light->amb_rgb.g, light->amb_rgb.b);
// 		printf("light : %f %f %f %f %d %d %d\n", light->lgt_origin.x, light->lgt_origin.y, light->lgt_origin.z, light->lgt_ratio, light->lgt_rgb.r, light->lgt_rgb.g, light->lgt_rgb.b);
// 		printf("sphere : %f %f %f %f %d %d %d\n", sp->c.x, sp->c.y, sp->c.z, sp->r, sp->rgb.r, sp->rgb.g, sp->rgb.b);
// 		printf("plane : %f %f %f %f %f %f %d %d %d\n", pl->c.x, pl->c.y, pl->c.z, pl->vec.x, pl->vec.y, pl->vec.z, pl->rgb.r, pl->rgb.g, pl->rgb.b);
// 		printf("cylinder : %f %f %f %f %f %f %f %f %d %d %d\n", cyl->c.x, cyl->c.y, cyl->c.z, cyl->vec.x, cyl->vec.y, cyl->vec.z, cyl->r, cyl->h, cyl->rgb.r, cyl->rgb.g, cyl->rgb.b);

// 	t_obj *temp;	
// 	temp = find_obj(objs, OB_CAM);
// 	printf("cam!? : %d %d\n", OB_CAM, temp->type);
// 	printf("monitor : %f %f %f\n", cam->corner.x, cam->corner.y, cam->corner.z);
// 	remove_list(&objs);
// //	system("leaks miniRT");
// 	return (0);
// }
