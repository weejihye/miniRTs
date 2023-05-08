/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:40 by jwee              #+#    #+#             */
/*   Updated: 2023/05/08 15:44:54 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rotate_camera_xz(t_cam *cam, int key)
{
	const double	seta1 = get_radian(15);
	const double	seta2 = get_radian(-15);

	if (key == KEY_Q)
		cam->axis = vec(cam->axis.x * cos(seta1) - cam->axis.z * sin(seta1),
				cam->axis.y, cam->axis.x * sin(seta1)
				+ cam->axis.z * cos(seta1));
	else
		cam->axis = vec(cam->axis.x * cos(seta2) - cam->axis.z * sin(seta2),
				cam->axis.y, cam->axis.x * sin(seta2)
				+ cam->axis.z * cos(seta2));
	cam->horizon = v_nor(v_cro(vec(0, 1, 0), cam->axis));
	cam->vertical = v_nor(v_cro(cam->axis, cam->horizon));
	cam->view_center = v_mlt((cam->width / 2) / tan(cam->fov / 2), cam->axis);
}

static void	rotate_camera_yz(t_cam *cam, int key)
{
	if (key == KEY_E)
		cam->axis = v_nor(vec(cam->axis.x, cam->axis.y + 0.15, cam->axis.z));
	else
		cam->axis = v_nor(vec(cam->axis.x, cam->axis.y - 0.15, cam->axis.z));
	cam->horizon = v_nor(v_cro(vec(0, 1, 0), cam->axis));
	cam->vertical = v_nor(v_cro(cam->axis, cam->horizon));
	cam->view_center = v_mlt((cam->width / 2) / tan(cam->fov / 2), cam->axis);
}

void	move_camera(int key, t_objs *objs)
{
	if (key == KEY_X)
		move_point(objs, vec(-1, 0, 0));
	else if (key == KEY_S)
		move_point(objs, vec(1, 0, 0));
	else if (key == KEY_C)
		move_point(objs, vec(0, -1, 0));
	else if (key == KEY_D)
		move_point(objs, vec(0, 1, 0));
	else if (key == KEY_Z)
		move_point(objs, vec(0, 0, -1));
	else if (key == KEY_A)
		move_point(objs, vec(0, 0, 1));
	else if (key == KEY_Q || key == KEY_W)
		rotate_camera_xz(&(objs->cam), key);
	else if (key == KEY_E || key == KEY_R)
		rotate_camera_yz(&(objs->cam), key);
	draw(objs->mlx, objs);
}
