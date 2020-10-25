#include "libft.h"
#include <stdio.h>
#include <string.h>
#include "header.h"


int		main(int args, char *argv[])
{
	(void)args;

	if (!strcmp(argv[1], "ft_strlen")) return (test_ft_strlen(argv[2]));
	else if(!strcmp(argv[1], "ft_atoi")) return (test_ft_atoi(argv[2]));
	return (-1);
}