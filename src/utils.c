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

	// if (num == 0) 
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

char	*ft_strcpy(char *src)
{
	char *result;
	int len;

	len = ft_strlen(src);
	result = malloc(len + 1);
	result[len] = '\0';
	while (len--)
	{
		result[len] = src[len];
	}
	return (result);
}

char	*ft_strcpyn(char *src, int n)
{
	char *result;

	result = malloc(n + 1);
	result[n] = '\0';
	while (n--)
	{
		result[n] = src[n];
	}
	return (result);
}

char **ft_split_str(char *src, char *pattern)
{
	char **result;
	int counter_result;
	int counter_pattern;
	int counter_src;
	int len_pattern;


	counter_result = 0;
	counter_pattern = 0;
	counter_src = 0;
	len_pattern = ft_strlen(pattern);
	result = malloc(sizeof(char *) * 128);
	while (*src)
	{
		counter_src++;
		if (*src == pattern[counter_pattern])
		{
			counter_pattern++;
			if (counter_pattern == len_pattern)
			{
				result[counter_result++] = ft_strcpyn(src - counter_src + 1, counter_src - counter_pattern);
				counter_src = 0;
				counter_pattern = 0;
			}
		}
		else counter_pattern = 0;
		src++;
	}
	if (counter_src)
		result[counter_result++] = ft_strcpyn(src - counter_src, counter_src - counter_pattern);
	result[counter_result++] = 0;
	return (result);
}

char	*ft_read_file(t_path *path)
{
	int		file_description;
	size_t	count_bite;
	size_t	bytes_read;
	char	*path_str;
	char	*file_str;

	path_str = ft_path_get_str(path);
	file_description = open(path_str, O_RDONLY);
	count_bite = 0;
	bytes_read = 1;
	while ((int)bytes_read > 0)
	{
		file_str = count_bite == 0 ? malloc(256 + 1) : realloc(file_str, count_bite + 256 + 1);
		bytes_read = read(file_description, file_str + count_bite, 256);
		count_bite += bytes_read;
	}
	file_str[count_bite] = '\0';
	free(path_str);
	close(file_description);
	return (file_str);
}

void	ft_print_file(t_path *path)
{
	char	*file_str;

	file_str = ft_read_file(path);
	ft_printf(file_str);
	free(file_str);
}

int		ft_atoi(char *str)
{
	int result;
	int positive;

	result = 0;
	positive = 1;
	while (9 <= *str && *str <= 13) str++;
	if (*str == '-')
	{
		positive *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9') result = result * 10 + (*str++ - '0');
	return (result * positive);
}

char	*ft_str_remove_shielding(char *str)
{
	int len;
	int counter;
	char *result;
	char *buf;
	int counter_sym;

	len = ft_strlen(str);
	result = malloc(sizeof(char) * (len + 1));
	counter = 0;
	while (*str)
	{
		if (*str == '[')
		{
			str++;
			counter_sym = 0;
			while (*str != ']')
			{
				counter_sym++;
				str++;
			}
			buf = ft_strcpyn(str - counter_sym, counter_sym);
			result[counter++] = (char)ft_atoi(buf);
			free(buf);
		}
		else result[counter++] = *str;
		str++;
	}
	result[counter++] = '\0';
	return (result);
}