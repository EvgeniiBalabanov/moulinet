#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int		ft_isalpha(int num);

int		test_ft_isalpha(char *str)
{
	int correct;
	int output;

	correct = isalpha(atoi(str));
	output = ft_isalpha(atoi(str));
	if (correct != output)
	{
		printf("\nExample: |%s|\nCorrect: |%d|\nOutput: |%d|\n", str, correct, output);
		return (-1);
	}
	return (0);
}