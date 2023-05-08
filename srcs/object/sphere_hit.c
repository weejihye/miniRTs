/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:40:55 by pji               #+#    #+#             */
/*   Updated: 2023/05/08 14:51:18 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "point.h"

t_point	hit_sphere(t_sp s, t_vec v)
{
	double	len;
	t_vec	temp[2];

	if (point_len_origin(s.c) == s.r)
		return ((t_vec){0, 0, 0});
	temp[0] = v_mlt(v_dot(v, s.c) / v_dot(v, v), v);
	len = point_len(s.c, temp[0]);
	if (len < s.r)
	{
		temp[1] = v_sub(temp[0], s.c);
		temp[0] = v_add(v_add(temp[1], v_mlt(sqrt(pow(s.r, 2)
							- pow(len, 2)), v)), s.c);
		temp[1] = v_add(v_add(temp[1], v_mlt(sqrt(pow(s.r, 2)
							- pow(len, 2)) * -1, v)), s.c);
		return (check_ahead(v, temp));
	}
	if (len > s.r)
		temp[0].x = NAN;
	if (len == s.r)
		check_front(v, &(temp[0]));
	return (temp[0]);
}

double	sphere_ratio(t_sp s, t_light light, t_point point)
{
	const t_vec	a = v_sub(s.c, point);
	const t_vec	b = v_sub(light.lgt_origin, point);
	const t_vec	c = v_sub(light.lgt_origin, s.c);
	t_plane		p;

	p.c = point;
	p.vec = v_nor(a);
	if (point_len_origin(s.c) < s.r && point_len_origin(c) < s.r)
	{
		p.vec = v_mlt(-1, p.vec);
		return (plane_ratio(p, light, point));
	}
	if (pow(s.r, 2) + pow(point_len_origin(b), 2) > pow(point_len_origin(c), 2))
		return (0);
	return (plane_ratio(p, light, point));
}

double	sphere_reflect(t_sp s, t_light light, t_point point)
{
	const t_vec		a = v_sub(point, s.c);
	const t_vec		b = v_sub(light.lgt_origin, point);
	const t_vec		c = v_sub(light.lgt_origin, s.c);
	t_plane			plane;

	plane.vec = v_nor(a);
	if (point_len_origin(s.c) < s.r && point_len_origin(c) < s.r)
	{
		plane.vec = v_mlt(-1, plane.vec);
		return (plane_reflect(plane, light, point));
	}
	if (pow(s.r, 2) + pow(point_len_origin(b), 2) > pow(point_len_origin(c), 2))
		return (0);
	return (plane_reflect(plane, light, point));
}
