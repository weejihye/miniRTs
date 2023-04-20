/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:40:19 by jwee              #+#    #+#             */
/*   Updated: 2022/07/20 19:55:53 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static int	ft_check_minmax(unsigned long long num)
{
	if (num > 0x7FFFFFFFFFFFFFFF)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			negative;

	i = 0;
	negative = 1;
	num = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		num = num * 10 + str[i] - '0';
		if ((negative == 1 && (unsigned long long)num > 0x7FFFFFFFFFFFFFFF)
			|| (negative == -1 && (unsigned long long)num > 0x8000000000000000))
			return (ft_check_minmax(negative * num));
		i++;
	}
	return (negative * num);
}
