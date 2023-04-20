/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:35:52 by jwee              #+#    #+#             */
/*   Updated: 2023/04/20 21:28:16 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	read_rt(int fd, char ****infos)
{
	char	*buff;
	char	*temp[100];
	int		i;

	i = 0;
	ft_memset(temp, 0, sizeof(char *) * 100);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (*buff == '\n')
			continue ;
		temp[i++] = buff;
	}
	(*infos) = malloc(sizeof(char **) * (i + 1));
	if (!*infos)
		return (print_error());
	(*infos)[i] = NULL;
	i = -1;
	while (temp[++i])
		(*infos)[i] = ft_split_spaces(temp[i]);
	return (0);
}

int	init_camera(t_info *info, char **infos)
{
	int i;

	i = 1;
	while ()
	return (0);
}

int	init_info(t_info *info, char ***infos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (infos[i])
	{
		while (infos[i][j])
		{
			if (ft_strcmp("C", infos[i][j]))
				init_camera(info, infos[i]);
			j++;
		}
		i++;
	}
	return (0);
}

int	parsing(t_info *info, char *file)
{
	char	***infos;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error());
	read_rt(fd, &infos);
	close(fd);
	init_info(info, infos);
	for (int i = 0; infos[i]; i++)
		for(int j = 0; infos[i][j]; j++)
			printf("%s\n", infos[i][j]);
	return (0);
}

int main(int argc, char *argv[])
{
	t_info info;

	(void)argc;
	parsing(&info, argv[1]);
	return (0);
}