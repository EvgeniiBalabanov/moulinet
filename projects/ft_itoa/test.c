#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_itoa(int n);

int		test_ft_itoa(char *str)
{
	char *output;

	output = ft_itoa(atoi(str));
	if (strcmp(str, output))
	{
		printf("\nExample/Correct: |%s|\nOutput: |%s|\n", str, output);
		return (-1);
	}
	return (0);
}