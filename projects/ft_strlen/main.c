#include <stdio.h>
#include <string.h>

int		ft_strlen(char *str);

int		main(int args, char *argv[])
{
	(void)args;
	int correct;
	int output;

	correct = strlen(argv[1]);
	output = ft_strlen(argv[1]);
	if (correct != output)
		printf("\nCorrect: |%d|\nOutput: |%d|\n", correct, output);
	return (0);
}