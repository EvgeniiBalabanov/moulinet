#include "header.h"

static void	ft_create_header(t_config *config, char *name)
{
	char *str;
	char *str_path;
	char *str_with_args;
	t_path *path;

	str = ft_file_read(config->path_template_header);
	str_path = ft_concat_str(3, "./projects/", name, "/include/header.h");
	path = ft_path_concat_ps(config->path_local, str_path);
	str_with_args = ft_str_add_args(str, name);
	ft_file_write(path, str_with_args);
	ft_path_free(path);
	free(str);
	free(str_path);
	free(str_with_args);
}

static void	ft_create_main(t_config *config, char *name)
{
	char *str;
	char *str_path;
	char *str_with_args;
	t_path *path;

	str = ft_file_read(config->path_template_main);
	str_path = ft_concat_str(3, "./projects/", name, "/main.c");
	path = ft_path_concat_ps(config->path_local, str_path);
	str_with_args = ft_str_add_args(str, name);
	ft_file_write(path, str_with_args);
	ft_path_free(path);
	free(str);
	free(str_path);
	free(str_with_args);
}

static void	ft_create_makefile(t_config *config, char *name)
{
	char *str;
	char *str_path;
	char *str_with_args;
	t_path *path;

	str = ft_file_read(config->path_template_makefile);
	str_path = ft_concat_str(3, "./projects/", name, "/Makefile");
	path = ft_path_concat_ps(config->path_local, str_path);
	str_with_args = ft_str_add_args(str, name);
	ft_file_write(path, str_with_args);
	ft_path_free(path);
	free(str);
	free(str_path);
	free(str_with_args);
}

static void	ft_create_test(t_config *config, char *name)
{
	char *str;
	char *str_path;
	char *str_with_args;
	t_path *path;

	str = ft_file_read(config->path_template_test);
	str_path = ft_concat_str(3, "./projects/", name, "/test.c");
	path = ft_path_concat_ps(config->path_local, str_path);
	str_with_args = ft_str_add_args(str, name, name, name);
	ft_file_write(path, str_with_args);
	ft_path_free(path);
	free(str);
	free(str_path);
	free(str_with_args);
}

static void	ft_create_data(t_config *config, char *name)
{
	char *str_path;
	t_path *path;

	str_path = ft_concat_str(3, "./projects/", name, "/data.csv");
	path = ft_path_concat_ps(config->path_local, str_path);
	ft_file_write(path, "");
	ft_path_free(path);
	free(str_path);
}

static void	ft_create_folders(t_config *config, char *name)
{
	char *str_path;
	t_path *path_folder;

	str_path = ft_concat_str(2, "./projects/", name);
	path_folder = ft_path_concat_ps(config->path_local, str_path);
	ft_mkdir(path_folder);
	free(str_path);
	ft_path_free(path_folder);

	str_path = ft_concat_str(3, "./projects/", name, "/include/");
	path_folder = ft_path_concat_ps(config->path_local, str_path);
	ft_mkdir(path_folder);
	free(str_path);
	ft_path_free(path_folder);
}

void	ft_create(t_config *config, char *name)
{
	ft_create_folders(config, name);
	ft_create_header(config, name);
	ft_create_main(config, name);
	ft_create_makefile(config, name);
	ft_create_test(config, name);
	ft_create_data(config, name);
}