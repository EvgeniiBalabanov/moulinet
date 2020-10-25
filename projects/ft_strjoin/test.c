#include <stdio.h>
#include <string.h>

char	*ft_strjoin(char *str_1, char const *str_2);

int		test_ft_strjoin(char *correct, char *str_1, char *str_2)
{
	char *output;

	output = ft_strjoin(str_1, str_2);
	if (strcmp(correct, output))
	{
		printf("\nExample: |%s|%s|\nCorrect: |%s|\nOutput: |%s|\n", str_1, str_2, correct, output);
		return (-1);
	}
	return (0);
}