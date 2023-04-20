/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:21 by jwee              #+#    #+#             */
/*   Updated: 2022/09/28 20:52:11 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrcmp(const char *s1, const char *s2)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	const size_t	len1 = ft_strlen(s1) - 1;
	const size_t	len2 = ft_strlen(s2) - 1;
	size_t			i;

	if (!s1)
		return (-1);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (i < 4)
	{
		if (ps1[len1 - i] != ps2[len2 - i])
			return (-1);
		i++;
	}
	return (0);
}
