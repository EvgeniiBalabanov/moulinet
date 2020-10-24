#include "header.h"

void	ft_print_promt(t_config *config)
{
	ft_printf("&Rmoulinet&g:&y%s&g> &o", config->project);
}

void	ft_list(t_config *config)
{
	char *command;
	char *path_local;

	path_local = ft_path_get_str(config->path_local);
	command = ft_concat_str(3, "ls ", path_local, "/projects/ | cat");
	system(command);

	free(path_local);
	free(command);
}

void	ft_set(char **options, t_config *config)
{
	char *str_path;
	t_path *path_1;
	t_path *path_2;

	if (ft_strcmp("path", *options))
	{
		str_path = malloc(128);
		getcwd(str_path, 128);
		ft_path_free(config->path_project);
		path_1 = ft_path_init(str_path);
		path_2 = ft_path_init(options[1]);
		config->path_project = ft_path_concat(path_1, path_2);

		free(str_path);
		ft_path_free(path_1);
		ft_path_free(path_2);
	}
	else ft_printf("&rError!&o\nNot correct option for set '&r%s&o'\n", *options);
}

void	ft_show_config(t_config *config)
{
	char *file;
	// char *path_local;
	// char *path_project;

	file = ft_read_file(config->path_config_template);
	// path_local = ft_path_get_str(config->path_local);
	// path_project = ft_path_get_str(config->path_project);
	ft_printf(file, config->path_local, config->project, config->path_project);

	free(file);
	// free(path_local);
	// free(path_project);
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

	if (ft_strcmp("help", *options))		ft_print_file(config->path_main_help);
	else if (ft_strcmp("list", *options))	ft_list(config);
	else if (ft_strcmp("get", *options))	config->project = options[1];
	else if (ft_strcmp("set", *options))	ft_set(options+1, config);
	else if (ft_strcmp("config", *options))	ft_show_config(config);
	else if (ft_strcmp("test", *options))	ft_test(config);
	else if (ft_strcmp("create", *options))	ft_printf("Create!\n");
	else if (ft_strcmp("back", *options))	config->project = "\0";
	else if (ft_strcmp("exit", *options))	exit(0);
	else system(input);
}

void	init_config(t_config **config, char *argv[])
{
	int counter;
	t_path *path_config_template;
	t_path *path_main_help;

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
	(*config)->path_local = ft_path_init(argv[0]);
	(*config)->path_project = 0;
	path_config_template = ft_path_init("./config/show_config.txt");
	(*config)->path_config_template = ft_path_concat((*config)->path_local, path_config_template);
	path_main_help = ft_path_init("./config/main_help.txt");
	(*config)->path_main_help = ft_path_concat((*config)->path_local, path_main_help);

	ft_path_free(path_config_template);
	ft_path_free(path_main_help);
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

	// char *res = ft_str_remove_shielding(argv[1]);
	// ft_printf(res);
	return (0);
}