#include "header.h"

char	*ft_input(void)
{
	char *str;
	
	str = malloc(256);
	read(1, str, 256);
	return str;
}