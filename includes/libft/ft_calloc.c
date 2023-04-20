/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:06:33 by jwee              #+#    #+#             */
/*   Updated: 2022/07/24 15:53:47 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*temp;
	const size_t	size_max = 0 - 1;

	if (size && count > size_max / size)
		return (NULL);
	if (!size || !count)
	{
		size = 1;
		count = 1;
	}
	temp = (char *)malloc(count * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, (count * size));
	return ((void *)temp);
}
