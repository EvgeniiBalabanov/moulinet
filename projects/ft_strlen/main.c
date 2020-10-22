#include <stdio.h>

int		ft_strlen(char *str);

int		ft_atoi(char *str)
{
	int result;
	int positive;

	positive = 1;
	result = 0;
	while (9 <= *str && *str <= 13) str++;
	if (*str == '-')
	{
		positive *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9') result = 10 * result + (*str++ - '0');
	return (result * positive);
}

int		main(int args, char *argv[])
{
	(void)args;
	if (ft_atoi(argv[1]) != ft_strlen(argv[2]))
		printf("\nCorrect: |%s|\nOutput: |%s|\n", argv[1], argv[2]);
	return (0);
}