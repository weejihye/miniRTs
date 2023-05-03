#include "miniRT.h"

static void	move_point(t_objs *objs)
{
	t_obj	*temp;
	t_cam	*cam;

	temp = objs->obj;
	cam = &objs->cam;
	while (temp)
	{	
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
    objs->obj = NULL;
	if (fd < 0)
		return (print_error("parsing error : open file fail"));
	if (read_rt(fd, &infos) || init_info(objs, infos))
		return (free_triple_ptr(infos));
	move_point(objs);
	free_triple_ptr(infos);
	return (0);
}
