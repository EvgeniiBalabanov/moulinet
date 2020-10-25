#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str);

int		test_ft_atoi(char *str)
{
	int correct;
	int output;

	correct = atoi(str);
	output = ft_atoi(str);
	if (correct != output)
	{
		printf("\nCorrect: |%d|\nOutput: |%d|\n", correct, output);
		return (-1);
	}
	return (0);
}