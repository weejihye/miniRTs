#include "miniRT.h"

int	check_normalized_vec(t_vec vec)
{
	if ((pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)) != 1)
		return (1);
	return (0);
}

int	free_triple_ptr(char ***str)
{
	int	i;
	int	j;

	if (!str)
		return (1);
	i = 0;
	j = 0;
	if (str)
	{
		while (str[i])
		{
			j = 0;
			while (str[i][j])
			{
				free(str[i][j]);
				j++;
			}
			free(str[i]);
			i++;
		}
		free(str);
	}
	return (1);
}

int	free_double_ptr(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	return (1);
}

int	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "Error\n", 6);
	return (1);
}
