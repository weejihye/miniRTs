/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:48:05 by jwee              #+#    #+#             */
/*   Updated: 2022/07/24 15:26:00 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	const size_t	dlen = ft_strlen(dst);
	const size_t	slen = ft_strlen(src);

	i = 0;
	if (!dstsize)
		return (slen);
	if (dlen >= dstsize)
		return (slen + dstsize);
	while (i < dstsize - dlen - 1 && i < slen)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
