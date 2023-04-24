/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:01:07 by jwee              #+#    #+#             */
/*   Updated: 2023/04/24 16:29:20 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		start;
	int		end;

	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (start < end && ft_strchr(set, s1[end]))
		end --;
	temp = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s1 + start, end - start + 2);
	temp[end - start + 1] = '\0';
	return (temp);
}
