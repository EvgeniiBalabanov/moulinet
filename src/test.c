#include "header.h"

void	ft_make(t_config *config, char *option)
{
	char *command;

	command = ft_concat_str(8, "cd ", ft_path_get_str(config->path_local), "/projects/", config->project,
		" && make ", option, " PATH_PROJECT=", ft_path_get_str(config->path_project));
	system(command);
	free(command);
}

void	ft_get_args(char ***args, t_config *config)
{
	char *path_str;
	char *file;
	t_path *path;
	t_path *all_path;

	path_str = ft_concat_str(3, "/projects/", config->project, "/data.csv");
	path = ft_path_init(path_str);
	all_path = ft_path_concat(config->path_local, path);
	file = ft_read_file(all_path);
	*args = ft_split_str(file, "\n");
	free(path);
	free(file);
}

void	ft_test_cycle(char **args, t_config *config)
{
	char *command;
	int output;
	int count_error;
	int counter;

	count_error = 0;
	counter = 0;
	while (args[counter])
	{
		command = ft_concat_str(5, ft_path_get_str(config->path_local), "/projects/", config->project, "/test.out ", ft_str_remove_shielding(args[counter]));
		output = system(command);
		if (output)
		{
			ft_printf("Exit code is |%d|\n", output);
			count_error += 1;
		}
		free(command);
		counter++;
	}
	if (!count_error) ft_printf("&gOK!&o\n");
	else ft_printf("&rFAIL!\n&y\tFAIL\tOK\tALL\n\t&r%d\t&g%d\t&y%d&o\n", count_error, counter - count_error, counter);
}

void	ft_test(t_config *config)
{
	char **args;

	ft_make(config, "");
	ft_get_args(&args, config);
	ft_test_cycle(args, config);
	ft_make(config, "fclean");
	free(args);
	return ;
}