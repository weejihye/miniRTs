/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:53:50 by jwee              #+#    #+#             */
/*   Updated: 2022/07/24 15:09:17 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdst;
	const unsigned char	*psrc = src;

	pdst = dst;
	i = 0;
	if (dst < src)
	{
		while (i++ < n)
			pdst[i - 1] = psrc[i - 1];
	}
	else
	{
		while (i < n)
		{
			pdst[n - i - 1] = psrc[n - i - 1];
			i++;
		}
	}
	return (pdst);
}
