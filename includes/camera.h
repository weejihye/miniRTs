/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:02:54 by jwee              #+#    #+#             */
/*   Updated: 2023/05/03 15:15:39 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"

typedef struct s_cam
{
	t_point	origin;
	t_vec	axis;
	int		height;
	int		width;
	double	fov;
	t_point	view_center;
	t_vec	horizon;
	t_vec	vertical;
}	t_cam;

#endif