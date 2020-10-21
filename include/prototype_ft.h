char	*ft_input(void);
int		ft_strlen(char *str);
void	ft_print_str(char *str);
int		ft_print_int(int num);
void	ft_printf(char *params, ...);
char	*ft_concat_str(int params, ...);
char	**ft_split_str(char *src, char *pattern);
int		ft_strcmp(char *trg, char *src);
void	ft_print_file(char *path, t_config *config);
void	ft_read_file(char **file_str, char *path, t_config *config);

char	*ft_red(char *src);
char	*ft_green(char *src);
char	*ft_blue(char *src);