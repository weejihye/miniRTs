/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:41:12 by pji               #+#    #+#             */
/*   Updated: 2023/05/03 15:41:12 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "vector.h"

double	get_radian(double seta);
double	point_len(t_vec point1, t_vec point2);
double	point_len_origin(t_vec point);
#endif