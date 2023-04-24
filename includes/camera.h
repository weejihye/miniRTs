/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:02:54 by jwee              #+#    #+#             */
/*   Updated: 2023/04/24 22:27:08 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"

typedef struct s_cam
{
	t_point	origin;
	t_vec	viewpoint;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	int		fov;
	t_vec	horizon;
	t_vec	vertical;
	t_point	corner;
}	t_cam;



#endif