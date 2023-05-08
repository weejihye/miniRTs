/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:14:34 by jwee              #+#    #+#             */
/*   Updated: 2023/05/08 15:46:01 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_point(t_objs *objs, t_vec direction)
{
	t_obj	*temp;

	temp = objs->obj;
	while (temp)
	{	
		if (temp->type == OB_SP)
			((t_sp *)(temp->p_obj))->c
				= v_sub(((t_sp *)(temp->p_obj))->c, direction);
		if (temp->type == OB_CYL)
			((t_cyl *)(temp->p_obj))->c
				= v_sub(((t_cyl *)(temp->p_obj))->c, direction);
		if (temp->type == OB_PL)
			((t_plane *)(temp->p_obj))->c
				= v_sub(((t_plane *)(temp->p_obj))->c, direction);
		temp = temp->next;
	}
	objs->light.lgt_origin = v_sub(objs->light.lgt_origin, direction);
}

static int	init_info(t_objs *objs, char ***infos)
{
	int	count;

	count = 0;
	--infos;
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

	if (!file || check_filename(file))
		return (print_error("filename: invalid extention\n"));
	infos = NULL;
	objs->obj = NULL;
	if (read_rt(file, &infos) || init_info(objs, infos))
		return (free_triple_ptr(infos));
	move_point(objs, objs->cam.origin);
	free_triple_ptr(infos);
	return (0);
}
