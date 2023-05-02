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

int	coloring(int t, int r, int g, int b)
{
	const int	color = (t << 24 | r << 16 | g << 8 | b);

	return (color);
}

int	color(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb	color_sum(t_rgb color1, t_rgb color2)
{
	color1.b += color2.b;
	color1.g += color2.g;
	color1.r += color2.r;
	return (color1);
}
