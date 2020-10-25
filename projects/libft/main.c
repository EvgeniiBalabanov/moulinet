#include "libft.h"
#include <stdio.h>
#include <string.h>
#include "header.h"


int		main(int args, char *argv[])
{
	(void)args;
	int result;

	result = -1;
	if (!strcmp(argv[1], "ft_strlen")) result = test_ft_strlen(argv[2]);
	else if(!strcmp(argv[1], "ft_atoi")) result = test_ft_atoi(argv[2]);
	if (result) printf("In %s project\n", argv[1]);
	return (result);
}