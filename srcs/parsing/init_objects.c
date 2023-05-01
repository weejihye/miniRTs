#include "miniRT.h"

int	init_plane(t_objs *objs, char **infos)
{
	t_plane	*pl;

	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_plane : number of properties is invalid\n"));
	if (!ft_lstnew_obj(&objs->obj, malloc(sizeof(t_plane)), OB_PL))
		return (1);
	pl = (t_plane *)(objs->obj->p_obj);
	if (str_to_vec(&pl->c, infos[1])
		|| str_to_rgb(&pl->rgb, infos[3])
		|| str_to_vec(&pl->vec, infos[2])
		|| check_normalized_vec(pl->vec))
		return (remove_first_node(&objs->obj));
	return (0);
}

int	init_sphere(t_objs *objs, char **infos)
{
	t_sp	*sp;

	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("init_sphere : number of properties is invalid\n"));
	if (double_syntax_check(infos[2]))
		return (print_error("init_sphere : double check error\n"));
	if (!ft_lstnew_obj(&objs->obj, malloc(sizeof(t_sp)), OB_SP))
		return (1);
	sp = (t_sp *)(objs->obj->p_obj);
	sp->r = ft_stod(infos[2], 0.0, 1);
	if (!ft_isdouble(sp->r)
		|| str_to_rgb(&sp->rgb, infos[3])
		|| str_to_vec(&sp->c, infos[1]))
		return (remove_first_node(&objs->obj));
	return (0);
}

int	init_cylinder(t_objs *objs, char **inf)
{
	t_cyl	*cyl;

	if (!inf[1] || !inf[2] || !inf[3] || !inf[4] || !inf[5] || inf[6])
		return (print_error("init_cylinder : number of properties error\n"));
	if (double_syntax_check(inf[3]) || double_syntax_check(inf[4]))
		return (print_error("init_cylinder : double check error\n"));
	if (!ft_lstnew_obj(&objs->obj, malloc(sizeof(t_cyl)), OB_CYL))
		return (1);
	cyl = (t_cyl *)(objs->obj->p_obj);
	cyl->r = ft_stod(inf[3], 0.0, 1);
	cyl->h = ft_stod(inf[4], 0.0, 1);
	if (!ft_isdouble(cyl->r) || !ft_isdouble(cyl->h)
		|| str_to_rgb(&cyl->rgb, inf[5])
		|| str_to_vec(&cyl->c, inf[1])
		|| str_to_vec(&cyl->vec, inf[2])
		|| check_normalized_vec(cyl->vec))
		return (remove_first_node(&objs->obj));
	return (0);
}