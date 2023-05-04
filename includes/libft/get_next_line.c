/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:18:58 by jwee              #+#    #+#             */
/*   Updated: 2023/05/04 19:26:59 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(int fd, char *save)
{
	char	*buff;
	int		rsize;

	rsize = 1;
	while (!ft_strchr(save, '\n') && rsize)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		rsize = read(fd, buff, BUFFER_SIZE);
		if (rsize < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[rsize] = '\0';
		save = ft_strjoin(save, buff, 1);
		free(buff);
	}
	return (save);
}

static char	*ft_get_result(char *save)
{
	int		i;
	char	*temp;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		temp[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		temp[i] = save[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static char	*ft_get_save(char *save)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		temp[j++] = save[i++];
	temp[j] = '\0';
	free(save);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_get_line(fd, save);
	if (!save)
		return (NULL);
	result = ft_get_result(save);
	save = ft_get_save(save);
	return (result);
}
