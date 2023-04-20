/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:59:54 by jwee              #+#    #+#             */
/*   Updated: 2023/04/19 23:34:23 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/camera.h"

t_cam	camera(void)
{
	t_cam cam;

	cam.viewport_height = 1600;
	cam.viewport_width = RATIO * cam.viewport_height;
	cam.focal_length = cam.viewport_width / 2 / tan(cam.fov/2);
	cam.origin = 
	cam.horizon = vec(cam.viewport_width, 0.0, 0.0);
	cam.vertical = vec(0.0, cam.viewport_height, 0.0);
	cam.corner = v_sub(v_sub(v_sub(cam.origin, v_div(2, cam.horizon)), v_div(2, cam.vertical)), vec(0, 0, cam.focal_length));
	return (cam);
}