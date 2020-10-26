#include "header.h"


char	*ft_file_read(t_path *path)
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

void	ft_file_write(t_path *path, char *str)
{
	char	*path_str;
	int		file_description;

	path_str = ft_path_get_str(path);
	file_description = open(path_str, O_WRONLY | O_CREAT, 0664);
	write(file_description, str, ft_strlen(str));
}

void	ft_file_print(t_path *path)
{
	char	*file_str;

	file_str = ft_file_read(path);
	ft_printf(file_str);
	free(file_str);
}

void	ft_mkdir(t_path *path)
{
	char *path_str;
	char *command;

	path_str = ft_path_get_str(path);
	command = ft_concat_str(2, "mkdir ", path_str);
	system(command);

	free(path_str);
	free(command);
}