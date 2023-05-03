/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:17:46 by jwee              #+#    #+#             */
/*   Updated: 2023/04/27 21:49:51 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "objects.h"

int	color(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb_r	get_light_ratio(t_light	light)
{
	t_rgb_r	r;

	r.r = (double)light.lgt_rgb.r / 255 * light.lgt_ratio;
	r.g = (double)light.lgt_rgb.g / 255 * light.lgt_ratio;
	r.b = (double)light.lgt_rgb.b / 255 * light.lgt_ratio;
	return (r);
}

t_rgb_r	get_ambient_ratio(t_light	light)
{
	t_rgb_r	r;

	r.r = (double)light.amb_rgb.r / 255 * light.amb_ratio;
	r.g = (double)light.amb_rgb.g / 255 * light.amb_ratio;
	r.b = (double)light.amb_rgb.b / 255 * light.amb_ratio;
	return (r);
}

t_rgb	get_color(double ratio, double ref, t_rgb rgb, t_light light)
{
	double	t;

	t = ((double)rgb.r / 255) * (light.lgt_rgb_ratio.r * ratio
			+ light.amb_rgb_ratio.r) + ref * light.lgt_rgb_ratio.r;
	if (t >= 1)
		rgb.r = 255;
	else
		rgb.r = t * 255;
	t = ((double)rgb.g / 255) * (light.lgt_rgb_ratio.g * ratio
			+ light.amb_rgb_ratio.g) + ref * light.lgt_rgb_ratio.g;
	if (t >= 1)
		rgb.g = 255;
	else
		rgb.g = t * 255;
	t = ((double)rgb.b / 255) * (light.lgt_rgb_ratio.b * ratio
			+ light.amb_rgb_ratio.b) + ref * light.lgt_rgb_ratio.b;
	if (t >= 1)
		rgb.b = 255;
	else
		rgb.b = t * 255;
	return (rgb);
}
