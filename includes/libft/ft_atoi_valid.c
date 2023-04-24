/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:40:19 by jwee              #+#    #+#             */
/*   Updated: 2023/04/24 22:54:24 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_valid(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (i > 11 || (i == 10 && num < 0))
		return (-1);
	return (num);
}
