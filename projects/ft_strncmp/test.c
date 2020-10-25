#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		test_ft_strncmp(char *str_1, char *str_2, char *n)
{
	int correct;
	int output;

	correct = strncmp(str_1, str_2, atoi(n));
	output = ft_strncmp(str_1, str_2, atoi(n));
	if (correct != output)
	{
		printf("\nExample: |%s|%s|%s|\nCorrect: |%d|\nOutput: |%d|\n", str_1, str_2, n, correct, output);
		return (-1);
	}
	return (0);
}