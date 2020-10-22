#include "header.h"

void	ft_print_promt(t_config *config)
{
	ft_printf("&Rmoulinet&g:&y%s&g> &o", config->project);
}

void	ft_list(void)
{
	system("ls ./projects/ | cat");
}

void	ft_set(char **options, t_config *config)
{
	if (ft_strcmp("path", *options)) config->path_project = options[1];
	else ft_printf("&rError!&o\nNot correct option for set '&r%s&o'\n", *options);
}

void	ft_show_config(t_config *config)
{
	char *file;

	ft_read_file(&file, "/config/show_config.txt", config);
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

	if (ft_strcmp("help", *options)) ft_print_file("/config/main_help.txt", config);
	else if (ft_strcmp("list", *options)) ft_list();
	else if (ft_strcmp("get", *options)) config->project = options[1];
	else if (ft_strcmp("set", *options)) ft_set(options+1, config);
	else if (ft_strcmp("config", *options)) ft_show_config(config);
	else if (ft_strcmp("test", *options)) ft_test(config);
	else if (ft_strcmp("create", *options)) ft_printf("Create!\n");
	else if (ft_strcmp("back", *options)) config->project = "\0";
	else if (ft_strcmp("exit", *options))
	{
		exit(0);
	}
	else
	{
		system(input);
	}
}

void	init_config(t_config **config, char *argv[])
{
	int counter;

	*config = malloc(sizeof(t_config));
	(*config)->project = "\0";
	(*config)->path_project = "\0";
	counter = ft_strlen(argv[0]);
	while (counter--)
	{
		if (argv[0][counter] == '/')
		{
			argv[0][counter] = '\0';
			break;
		}
	}
	(*config)->path_local = argv[0];
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