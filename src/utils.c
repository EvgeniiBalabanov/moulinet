#include "header.h"

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter])
	{
		counter++;
	}
	return counter;
}

void	ft_print_str(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_print_int(int num)
{
	int res;
	char a;

	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		res = ft_print_int(num);
	}
	else
	{
		if (num == 0) return 0;
		res = ft_print_int(num / 10);
		a = num % 10 + '0';
		write(1, &a, 1);
	}
	return (res + 1);
}

void ft_str_copy(char *trg, char *src)
{
	int counter;

	counter = 0;
	while (src[counter])
	{
		trg[counter] = src[counter];
		counter++;
	}
	trg[counter] = '\0';
}

char	*ft_concat_str(int params, ...)
{
	va_list	arg;
	int		length;
	char	*trg;
	char	*str;

	va_start(arg, params);
	length = 0;
	trg = malloc(length);
	while (params--)
	{
		str = va_arg(arg, char *);
		trg = realloc(trg, length + ft_strlen(str) + 1);
		ft_str_copy(trg + length, str);
		length += ft_strlen(str);
	}
	trg[length] = '\0';
	va_end(arg);
	return (trg);
}

int		ft_strcmp(char *trg, char *src)
{
	int counter;

	counter = 0;
	while (src[counter])
	{
		if (!trg[counter]) return (0);
		if (trg[counter] != src[counter]) return (0);
		counter++;
	}
	if (!trg[counter]) return (1);
	return (0);
}

char **ft_split_str(char *src, char *pattern)
{
	char **result;
	int counter_result;
	int counter_src;
	int counter_pattern = 0;

	result = malloc(sizeof(char *) * 128);
	counter_result = 0;
	counter_src = 0;
	while (src[counter_src])
	{
		if (pattern[counter_pattern] == src[counter_src])
			counter_pattern++;
		else counter_pattern = 0;
		if ((pattern[counter_pattern] == 0) + !src[counter_src + 1] == 1)
		{
			src[counter_src - counter_pattern + 1 - (src[counter_src - counter_pattern] == '\n')] = '\0';
			if (ft_strlen(src)) result[counter_result++] = src;
			src = src + counter_src + 1;
			counter_src = 0;
			counter_pattern = 0;
		}
		else counter_src++;
	}
	result[counter_result++] = 0;
	return (result);
}

void	ft_read_file(char **file_str, char *path, t_config *config)
{
	int		file_description;
	size_t	count_bite;
	size_t	bytes_read;

	path = ft_concat_str(2, config->path_local, path);
	file_description = open(path, O_RDONLY);
	count_bite = 0;
	bytes_read = 1;
	while ((int)bytes_read > 0)
	{
		*file_str = count_bite == 0 ? malloc(256 + 1) : realloc(*file_str, count_bite + 256 + 1);
		bytes_read = read(file_description, *file_str + count_bite, 256);
		count_bite += bytes_read;
	}
	(*file_str)[count_bite] = '\0';
	free(path);
	close(file_description);
}

void	ft_print_file(char *path, t_config *config)
{
	char	*file_str;

	ft_read_file(&file_str, path, config);
	ft_printf(file_str, path);
	free(file_str);
}