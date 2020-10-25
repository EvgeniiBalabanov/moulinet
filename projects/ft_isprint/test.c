#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int		ft_isprint(int num);

int		test_ft_isprint(char *str)
{
	int correct;
	int output;

	correct = isprint(atoi(str));
	output = ft_isprint(atoi(str));
	if (correct != output)
	{
		printf("\nExample: |%s|\nCorrect: |%d|\nOutput: |%d|\n", str, correct, output);
		return (-1);
	}
	return (0);
}