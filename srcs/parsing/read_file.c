/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:14:38 by jwee              #+#    #+#             */
/*   Updated: 2023/05/08 15:46:03 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_infos(char **temp, char ****infos, int i)
{
	(*infos) = malloc(sizeof(char **) * (i + 1));
	if (!*infos)
		exit(print_error("parsing: infos malloc fail\n"));
	(*infos)[i] = NULL;
	i = -1;
	while (temp[++i])
		(*infos)[i] = ft_split_spaces(temp[i]);
}

static void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
		free(temp[i++]);
}

static int	get_buffer(char ****infos, int fd)
{
	char	*buff;
	char	*temp[100];
	int		i;

	i = 0;
	buff = (char *)1;
	ft_memset(temp, 0, sizeof(char *) * 100);
	while (buff)
	{
		buff = get_next_line(fd);
		if (!buff || *buff == '\n' || *buff == 0)
		{
			free(buff);
			continue ;
		}
		temp[i++] = buff;
		if (ft_strchr(buff, '\n') == 0)
			break ;
		temp[i - 1][ft_strchr(buff, '\n') - 1] = 0;
	}
	if (!temp[0])
		return (1);
	get_infos(temp, infos, i);
	free_temp(temp);
	return (0);
}

int	read_rt(char *file, char ****infos)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("parsing: open file fail\n"));
	get_buffer(infos, fd);
	close(fd);
	if (!(*infos))
		return (print_error("parsing: get infos error\n"));
	return (0);
}
