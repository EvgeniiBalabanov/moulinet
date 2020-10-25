char	*ft_input(void);
void	ft_printf(char *params, ...);
void	ft_test(t_config *config);
void	ft_create(t_config *config, char *name);
// utils.c
int		ft_strlen(char *str);
void	ft_print_str(char *str);
int		ft_print_int(int num);
char	*ft_concat_str(int params, ...);
char	**ft_split_str(char *src, char *pattern);
int		ft_strcmp(char *trg, char *src);
char	*ft_strcpy(char *src);
char	*ft_strcpyn(char *src, int n);
char	*ft_str_remove_shielding(char *str);
char	*ft_str_add_args(char *str, ...);
// file.c
void	ft_file_print(t_path *path);
char	*ft_file_read(t_path *path);
void	ft_file_write(t_path *path, char *str);
void	ft_file_write_with_args(t_path *path, char *str, ...);
void	ft_mkdir(t_path *path);
// path.c
t_path	*ft_path_init(char *str);
char	*ft_path_get_str(t_path *path);
void	ft_path_free(t_path *path);
char	*ft_path_get_str_with_str(t_path *path, char *str_path);
t_path	*ft_path_concat(t_path *old, t_path *new);
t_path	*ft_path_concat_ps(t_path *old, char *new);
t_path	*ft_path_concat_ss(char *old, char *new);