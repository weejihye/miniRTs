/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:05:58 by jwee              #+#    #+#             */
/*   Updated: 2022/07/14 20:31:48 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *str, size_t count)
{
	char	temp;
	size_t	i;

	i = 0;
	while (i < count / 2)
	{
		temp = str[i];
		str[i] = str[count - i - 1];
		str[count - i - 1] = temp;
		i++;
	}
}

static size_t	ft_maxcount(long long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_nzero(char *temp)
{
	temp[0] = '0';
	temp[1] = '\0';
	return (temp);
}

char	*ft_itoa(int n)
{
	char		*temp;
	long long	nb;
	size_t		i;
	size_t		count;

	nb = (long long)n;
	count = ft_maxcount(nb);
	temp = (char *)malloc(sizeof(char) * (count + 1));
	if (!temp)
		return (NULL);
	if (n == 0)
		return (ft_nzero(temp));
	if (nb < 0)
		nb *= -1;
	i = 0;
	while (nb)
	{
		temp[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		temp[i++] = '-';
	temp[i] = '\0';
	ft_swap(temp, count);
	return (temp);
}
