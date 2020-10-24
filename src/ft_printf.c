#include "header.h"

void	ft_printf(char *params, ...)
{
	va_list arg;
	char *str;
	
	str = params;
	va_start(arg, params);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
			{
				ft_print_str(va_arg(arg, char *));
			}
			else if (*str == 'd' || *str == 'c')
				ft_print_int(va_arg(arg, int));
			else if (*str == 'p')
			{
				char *buf = ft_path_get_str(va_arg(arg, t_path *));
				ft_print_str(buf);
				free(buf);
			}
		}
		else if
		 (*str == '&')
		{
			str++;
			if (*str == 'R') ft_print_str("\033[1;31m");
			else if (*str == 'r') ft_print_str("\033[0;31m");
			else if (*str == 'g') ft_print_str("\033[0;32m");
			else if (*str == 'b') ft_print_str("\033[0;34m");
			else if (*str == 'y') ft_print_str("\033[0;33m");
			else if (*str == 'm') ft_print_str("\033[0;35m");
			else if (*str == 'o') ft_print_str("\033[0m");
		}
		else
			write(1, str, 1);
		str++;
	}
	va_end(arg);
}