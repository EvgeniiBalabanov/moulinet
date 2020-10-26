#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int		ft_toupper(int num);

int		test_ft_toupper(char *str)
{
	int correct;
	int output;

	correct = toupper(atoi(str));
	output = ft_toupper(atoi(str));
	if (correct != output)
	{
		printf("\nExample: |%s|\nCorrect: |%d|\nOutput: |%d|\n", str, correct, output);
		return (-1);
	}
	return (0);
}