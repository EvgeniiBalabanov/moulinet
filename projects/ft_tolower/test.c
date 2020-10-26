#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int		ft_tolower(int num);

int		test_ft_tolower(char *str)
{
	int correct;
	int output;

	correct = tolower(atoi(str));
	output = ft_tolower(atoi(str));
	if (correct != output)
	{
		printf("\nExample: |%s|\nCorrect: |%d|\nOutput: |%d|\n", str, correct, output);
		return (-1);
	}
	return (0);
}