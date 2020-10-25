typedef struct		s_path
{
	char			*name;
	struct s_path	*next;
}					t_path;

typedef struct		s_config
{
	char			*project;
	t_path			*path_project;
	t_path			*path_local;	//path to moulinet
	t_path			*path_config_template;
	t_path			*path_main_help;
	t_path			*path_template_header;
	t_path			*path_template_main;
	t_path			*path_template_makefile;
	t_path			*path_template_test;
}					t_config;
