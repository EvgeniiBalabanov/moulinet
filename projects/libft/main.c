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
	else if(!strcmp(argv[1], "ft_strjoin")) result = test_ft_strjoin(argv[2], argv[3], argv[4]);
	else if(!strcmp(argv[1], "ft_strcmp")) result = test_ft_strcmp(argv[2], argv[3]);
	else if(!strcmp(argv[1], "ft_strncmp")) result = test_ft_strncmp(argv[2], argv[3], argv[4]);
	else if(!strcmp(argv[1], "ft_itoa")) result = test_ft_itoa(argv[2]);
	else if(!strcmp(argv[1], "ft_isascii")) result = test_ft_isascii(argv[2]);
	else if(!strcmp(argv[1], "ft_isprint")) result = test_ft_isprint(argv[2]);
	else if(!strcmp(argv[1], "ft_isdigit")) result = test_ft_isdigit(argv[2]);
	if (result) printf("In %s project\n", argv[1]);
	return (result);
}