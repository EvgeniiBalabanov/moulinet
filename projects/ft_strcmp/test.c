#include <stdio.h>
#include <string.h>

int		ft_strcmp(const char *str_1, const char *str_2);

int		test_ft_strcmp(char *str_1, char *str_2)
{
	int correct;
	int output;

	correct = strcmp(str_1, str_2);
	output = ft_strcmp(str_1, str_2);
	if (correct != output)
	{
		printf("\nExample: |%s|%s|\nCorrect: |%d|\nOutput: |%d|\n", str_1, str_2, correct, output);
		return (-1);
	}
	return (0);
}