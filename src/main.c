#include "header.h"

void	ft_print_promt(t_config *config)
{
	ft_printf("&Rmoulinet&g:&y%s&g> &o", config->project);
}

void	ft_list(t_config *config)
{
	char *command;
	char *path;

	path = ft_path_get_str_with_str(config->path_local, "./projects/");
	command = ft_concat_str(3, "ls ", path, " | cat");
	system(command);

	free(path);
	free(command);
}

void	ft_set(char **options, t_config *config)
{
	char *str_path;

	if (ft_strcmp("path", *options))
	{
		str_path = malloc(128);
		getcwd(str_path, 128);
		ft_path_free(config->path_project);
		config->path_project = ft_path_concat_ss(str_path, options[1]);

		free(str_path);
	}
	else ft_printf("&rError!&o\nNot correct option for set '&r%s&o'\n", *options);
}

void	ft_show_config(t_config *config)
{
	char *file;

	file = ft_file_read(config->path_config_template);
	ft_printf(file, config->path_local, config->project, config->path_project);

	free(file);
}

void	ft_options(char *input, t_config *config)
{
	char **options;

	if (ft_strlen(input) == 0)
	{
		ft_printf("\n");
		return ;
	}
	if (ft_strlen(input) == 1) return ;
	options = ft_split_str(input, " ");

	if (ft_strcmp("help", *options))		ft_file_print(config->path_main_help);
	else if (ft_strcmp("list", *options))	ft_list(config);
	else if (ft_strcmp("get", *options))	config->project = options[1];
	else if (ft_strcmp("set", *options))	ft_set(options+1, config);
	else if (ft_strcmp("config", *options))	ft_show_config(config);
	else if (ft_strcmp("test", *options))	ft_test(config);
	else if (ft_strcmp("create", *options))	ft_create(config, options[1]);
	else if (ft_strcmp("back", *options))	config->project = "\0";
	else if (ft_strcmp("exit", *options))	exit(0);
	else system(input);
}

void	init_config(t_config **config, char *argv[])
{
	int counter;

	*config = malloc(sizeof(t_config));
	(*config)->project = "\0";
	counter = ft_strlen(argv[0]);
	while (counter--)
	{
		if (argv[0][counter] == '/')
		{
			argv[0][counter] = '\0';
			break;
		}
	}
	(*config)->path_project				= 0;
	(*config)->path_local				= ft_path_init(argv[0]);
	(*config)->path_config_template		= ft_path_concat_ps((*config)->path_local, "./config/show_config.txt");
	(*config)->path_main_help			= ft_path_concat_ps((*config)->path_local, "./config/main_help.txt");
	(*config)->path_template_header		= ft_path_concat_ps((*config)->path_local, "./config/templates/header.txt");
	(*config)->path_template_main		= ft_path_concat_ps((*config)->path_local, "./config/templates/main.txt");
	(*config)->path_template_makefile	= ft_path_concat_ps((*config)->path_local, "./config/templates/Makefile.txt");
	(*config)->path_template_test		= ft_path_concat_ps((*config)->path_local, "./config/templates/test.txt");
}

int		main(int args, char *argv[])
{
	char		*input;
	t_config	*config;

	(void)args;
	init_config(&config, argv);
	while (1)
	{
		ft_print_promt(config);
		input = ft_input();
		ft_options(input, config);
	}
	return (0);
}