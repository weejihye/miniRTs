/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:38:23 by jwee              #+#    #+#             */
/*   Updated: 2022/07/24 15:30:45 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int					i;
	char				*ps;
	const unsigned char	uc = c;

	ps = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (ps[i] == uc)
			return (ps + i);
		i--;
	}
	return (0);
}
