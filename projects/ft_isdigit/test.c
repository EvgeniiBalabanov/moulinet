#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int		ft_isdigit(int num);

int		test_ft_isdigit(char *str)
{
	int correct;
	int output;

	correct = isdigit(atoi(str));
	output = ft_isdigit(atoi(str));
	if (correct != output)
	{
		printf("\nExample: |%s|\nCorrect: |%d|\nOutput: |%d|\n", str, correct, output);
		return (-1);
	}
	return (0);
}