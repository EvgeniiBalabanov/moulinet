#include "header.h"


char	*ft_red(char *src)
{
	char *result;

	result = ft_concat_str(3, "\033[1;31m", src, "\033[0m");
	return (result);
}

char	*ft_green(char *src)
{
	char *result;

	result = ft_concat_str(3, "\033[0;32m", src, "\033[0m");
	return (result);
}

char	*ft_blue(char *src)
{
	char *result;

	result = ft_concat_str(3, "\033[0;34m", src, "\033[0m");
	return (result);
}