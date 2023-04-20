/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:04:36 by jwee              #+#    #+#             */
/*   Updated: 2023/04/11 20:06:48 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "miniRT.h"
# include "vector.h"

typedef struct s_sphere
{
	int		radi;
	int		sqradi;
	t_vec	center;
}	t_sp;

#endif