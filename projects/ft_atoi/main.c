#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str);

int		main(int args, char *argv[])
{
	(void)args;
	int correct;
	int output;

	correct = atoi(argv[1]);
	output = ft_atoi(argv[1]);
	if (correct != output)
		printf("\nCorrect: |%d|\nOutput: |%d|\n", correct, output);
	return (0);
}