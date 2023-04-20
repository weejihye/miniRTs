#include "includes/miniRT.h"

double	str_to_double(const char *str, double res, int sign)
{
	double	frac;

	frac = 0.1;
	if (str == NULL)
		return (0.0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		res = res * 10.0 + (double)(*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			res += (double)(*str++ - '0') * frac;
			frac /= 10.0;
		}
	}
	return (sign * res);
}
