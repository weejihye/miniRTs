/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:09:46 by jwee              #+#    #+#             */
/*   Updated: 2022/10/05 18:45:56 by jh.ks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*ps;
	unsigned char	uc;

	ps = (char *)s;
	uc = (unsigned char)c;
	i = 0;
	if (!ps)
		return (0);
	while (ps[i])
	{
		if (ps[i] == uc)
			return (i + 1);
		i++;
	}
	if (ps[i] == uc)
		return (i + 1);
	return (0);
}
