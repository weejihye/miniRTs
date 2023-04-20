/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:17:46 by jwee              #+#    #+#             */
/*   Updated: 2023/04/19 18:29:27 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

int coloring(int t, int r, int g, int b){
	int color = (t << 24 | r << 16 | g << 8 | b);
	return (color);
}

int color(int t, t_rgb rgb)
{
	return (coloring(t, rgb.x * 255, rgb.y * 255, rgb.z * 255));
}

