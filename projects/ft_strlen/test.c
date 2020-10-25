#include <stdio.h>
#include <string.h>

int		ft_strlen(char *str);

int		test_ft_strlen(char *str)
{
	int correct;
	int output;

	correct = strlen(str);
	output = ft_strlen(str);
	if (correct != output)
	{
		printf("\nExample: |%s|\nCorrect: |%d|\nOutput: |%d|\n", str, correct, output);
		return (-1);
	}
	return (0);
}