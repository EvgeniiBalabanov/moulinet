#include "header.h"

void	ft_make(t_config *config)
{
	char *command;

	command = ft_concat_str(5, "cd ", config->path_local, "/projects/", config->project, " && make");
	system(command);
	free(command);
}

void	ft_get_args(char ***args, t_config *config)
{
	char *path;
	char *file;

	path = ft_concat_str(3, "/projects/", config->project, "/data.csv");
	ft_read_file(&file, path, config);
	*args = ft_split_str(file, "\n");
	free(path);
	// free(file);
}

void	ft_test_cycle(char **args, t_config *config)
{
	char *command;

	while (*args)
	{
		command = ft_concat_str(5, config->path_local, "/projects/", config->project, "/test.out ", *args);
		system(command);
		free(command);
		args++;
	}
}

void	ft_test(t_config *config)
{
	char **args;

	ft_make(config);
	ft_get_args(&args, config);
	ft_test_cycle(args, config);
	free(args);
	return ;
}