#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int		ft_isascii(int num);

int		test_ft_isascii(char *str)
{
	int correct;
	int output;

	correct = isascii(atoi(str));
	output = ft_isascii(atoi(str));
	if (correct != output)
	{
		printf("\nExample: |%s|\nCorrect: |%d|\nOutput: |%d|\n", str, correct, output);
		return (-1);
	}
	return (0);
}