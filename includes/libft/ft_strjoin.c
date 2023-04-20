/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:05:02 by jwee              #+#    #+#             */
/*   Updated: 2022/10/02 14:45:13 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *save, char *buff)
{
	char	*temp;

	if (!save)
	{
		save = malloc (1);
		save[0] = '\0';
	}
	temp = (char *)malloc((ft_strlen(save) + ft_strlen(buff) + 1)
			* sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, save, ft_strlen(save) + 1);
	ft_strlcpy(temp + ft_strlen(save), buff, ft_strlen(buff) + 1);
	free(save);
	return (temp);
}
