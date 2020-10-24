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
	{
		printf("\nExample: |%s|\nCorrect: |%d|\nOutput: |%d|\n", argv[1], correct, output);
		return (-1);
	}
	return (0);
}