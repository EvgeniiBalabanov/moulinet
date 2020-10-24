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

	while (*args)
	{
		command = ft_concat_str(5, ft_path_get_str(config->path_local), "/projects/", config->project, "/test.out ", *args);
		output = system(command);
		if (output) ft_printf("Exit code is |%d|\n", output);
		free(command);
		args++;
	}
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