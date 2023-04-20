/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:52:07 by jwee              #+#    #+#             */
/*   Updated: 2022/07/24 15:32:46 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (0);
	while (*haystack && i < len && len)
	{
		j = 0;
		while (haystack[j] == needle[j] && needle[j] && i + j < len)
		{
			j++;
			if (!needle[j])
				return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return (NULL);
}
