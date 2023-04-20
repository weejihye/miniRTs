/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:57:16 by jwee              #+#    #+#             */
/*   Updated: 2023/04/19 16:13:21 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"
#include "../../includes/camera.h"

t_vec v_ray(t_ray *ray, double t)
{
	t_vec v;

	v.x = ray->ori->x + ray->dir->x * t;
	v.y = ray->ori->y + ray->dir->y * t;
	v.z = ray->ori->z + ray->dir->z * t;
	return (v);
}

t_point get_left_corner(t_cam cam)
{
	cam.corner = v_sub(cam.corner, vec(cam.v_w / 2, cam.v_h / 2, cam.focus));
}

int main(void){
	t_point camera = vec(-50, 0, 0);
	t_vec viewpoint = vec(0, 0, 1);
}

