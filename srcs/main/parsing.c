/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:35:52 by jwee              #+#    #+#             */
/*   Updated: 2023/04/20 16:33:02 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"

int	read_rt(char *file)
{
	int	fd;
	char *buff;
	char **infos[5];
	int i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (*buff == '\n')
			continue ;
		infos[i] = ft_split_spaces(buff);
		i++;
	}
	infos[i] = NULL;
	return (0);
}

int main(int argc, char *argv[])
{
	(void)argc;
	read_rt(argv[1]);
	return (0);
}