#include "miniRT.h"

static void	get_infos(char **temp, char ****infos, int i)
{
	(*infos) = malloc(sizeof(char **) * (i + 1));
	if (!*infos)
		exit(print_error("infos malloc fail"));
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
	close(fd);
	return (0);
}