char	*ft_input(void);
int		ft_strlen(char *str);
void	ft_print_str(char *str);
int		ft_print_int(int num);
void	ft_printf(char *params, ...);
char	*ft_concat_str(int params, ...);
char	**ft_split_str(char *src, char *pattern);
int		ft_strcmp(char *trg, char *src);
void	ft_print_file(t_path *path);
char	*ft_read_file(t_path *path);
char	*ft_strcpy(char *src);
char	*ft_strcpyn(char *src, int n);
char	*ft_str_remove_shielding(char *str);

char	*ft_red(char *src);
char	*ft_green(char *src);
char	*ft_blue(char *src);

void	ft_test(t_config *config);

t_path	*ft_path_init(char *str);
char	*ft_path_get_str(t_path *path);
void	ft_path_free(t_path *path);
char	*ft_path_get_str_with_str(t_path *path, char *str_path);
t_path	*ft_path_concat(t_path *old, t_path *new);
t_path	*ft_path_concat_ps(t_path *old, char *new);
t_path	*ft_path_concat_ss(char *old, char *new);