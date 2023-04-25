#include "miniRT.h"

int	double_syntax_check(char *str)
{
	int	dot_count;

	if (*str != '-' && *str != '+' && !ft_isdigit(*str))
		return (1);
	while (*(++str))
	{
		if (*str == '.')
		{
			if (++dot_count > 1)
				return (0);
			continue ;
		}
		if (!ft_isdigit(*str))
			return (1);
	}
	return (0);
}

int	vec_syntax_check(char *info)
{
	int	dot_count;
	int	comma_count;

	dot_count = 0;
	comma_count = 0;
	if ((!ft_isdigit(*info) && *info != '-')
		|| (*info == '-' && !ft_isdigit(*(info + 1))))
		return (print_error("false start\n"));
	while (*(++info))
	{
		if ((!ft_isdigit(*info) && *info != '.' && *info != ',' )
			|| ((*info == '.' || *info == ',') && !ft_isdigit(*(info + 1))))
			return (print_error("syntax check fail : invalid input\n"));
		if (*info == '.')
			if (++dot_count > 1)
				return (print_error("more than 1 dot\n"));
		if (*info == ',')
		{
			comma_count++;
			dot_count = 0;
		}
	}
	if (comma_count != 2)
		return (print_error("invalid number of comma\n"));
	return (0);
}