#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(char *str)
{
	char	*reversed;
	size_t	lenght;
	int		i;

	i = 0;
	lenght = strlen(str);
	reversed = (char*)malloc(lenght * sizeof(char) + 1);

	while (i < lenght)
	{
		reversed[i++] = str[lenght - i - 1];
	}
	reversed[i] = '\0';

	return reversed;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("please provide string to reverse\n");
		return 1;
	}

	// print it directly? probably that's not the purpose of the challenge
	printf("%s\n", reverse(argv[1]));
	return 0;
}