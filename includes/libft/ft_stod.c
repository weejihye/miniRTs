/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:07:36 by jwee              #+#    #+#             */
/*   Updated: 2023/05/03 16:09:30 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_stod(const char *str, double res, int sign)
{
	double	frac;

	frac = 0.1;
	if (str == NULL)
		return (0.0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		res = res * 10.0 + (double)(*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			res += (double)((*str++ - '0') * frac);
			frac /= 10.0;
		}
	}
	return (sign * res);
}
