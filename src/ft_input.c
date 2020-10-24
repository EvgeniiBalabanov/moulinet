#include "header.h"

char	*ft_input(void)
{
	char *str;
	int len;
	
	str = malloc(256);
	len = read(1, str, 256);
	if (str[len - 1] == '\n') str[len - 1] = 0;
	return str;
}