#include <stdio.h>


int	is_valid_binary(char *b_nbr)
{
	int i;

	i = -1;
	while (b_nbr[++i])
		if (b_nbr[i] != '0' && b_nbr[i] != '1')
			return 0;
	return 1;
}

char	*add_binary(char *nb_one, char *nb_two)
{
	return "101";
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("please provide the two binaries you want to add\n");
		return 1;
	}
	if (!is_valid_binary(argv[1]) || !is_valid_binary(argv[2]))
	{
		printf("input is not a valid binary\n");
		return 1;
	}
	printf("the addition of %s and %s is %s\n", argv[1], argv[2], add_binary(argv[1], argv[2]));

	return 0;
}
