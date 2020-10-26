#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int		ft_isalnum(int n);

int		test_ft_isalnum(char *str)
{
	int correct;
	int output;

	correct = isalnum(atoi(str));
	output = ft_isalnum(atoi(str));
	if (correct != output)
	{
		printf("\nExample: |%s|\nCorrect: |%d|\nOutput: |%d|\n", str, correct, output);
		return (-1);
	}
	return (0);
}