#include "header.h"

void	ft_print_promt()
{
	ft_printf("&Rmoulinet&o&g> &o");
}

void	ft_list(void)
{
	system("ls ./projects/ | cat");
}

void	ft_options(char *input)
{
	char **options;

	if (ft_strlen(input) == 0)
	{
		ft_printf("\n");
		return ;
	}

	if (ft_strlen(input) == 1) return ;
	options = ft_split_str(input, " ");

	if (ft_strcmp("help", *options)) ft_print_file("./config/main_help.txt");
	else if (ft_strcmp("get", *options)) ft_printf("Get!\n");
	else if (ft_strcmp("list", *options)) ft_list();
	else if (ft_strcmp("create", *options)) ft_printf("Create!\n");
	else if (ft_strcmp("exit", *options))
	{
		// free();
		exit(0);
	}
	else
	{
		system(input);
	}
}

void	init_config(t_config **config)
{
	*config = malloc(sizeof(t_config));
	(*config)->project = 0;
}

int		main(void)
{
	char		*input;
	t_config	*config;

	init_config(&config);
	while (1)
	{
		ft_print_promt();
		input = ft_input();
		ft_options(input);
	}
	return (0);
}