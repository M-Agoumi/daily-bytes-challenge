#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int     is_uppercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

int     is_char(char c)
{
    if (is_uppercase(c) || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

size_t  count_words(const char *str)
{
    size_t  words_count;
    size_t  i;
    int     word;

    i = 0;
    word = 0;
    while (str[i])
    {
        if (is_char(str[i])) {
            if (!word) {
                words_count++;
                word = 1;
            }
        } else {
            word = 0;
        }
        i++;
    }
    
    return words_count;
}

static	int		ft_start(const char *s, int cu)
{
	while (!is_char(s[cu]) && s[cu] != '\0')
		cu++;
	return (cu);
}

static int		ft_end(const char *s, int cu)
{
	while (is_char(s[cu]) && s[cu] != '\0')
		cu++;
	return (cu);
}


char	*strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*res;
	size_t	i;

	if (s == NULL)
		return (NULL);
	str = (char*)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	res = str;
	i = -1;
	while (++i < len)
		*str++ = s[start++];
	*str = '\0';
	return (res);
}

char			**get_words(char const *s)
{
	char	**str;
	int		len;
	int		i;
	int		cu;
	int		end;

	if (!s)
		return (NULL);
	i = 0;
	len = count_words(s);
	if (NULL == (str = (char**)malloc((len + 1) * sizeof(char*))))
		return (NULL);
	cu = 0;
	while (i < len)
	{
		cu = ft_start(s, cu);
		end = ft_end(s, cu + 1);
		str[i] = strsub(s, cu, end - cu);
		cu = end;
		i++;
	}
	str[i] = 0;
	return (str);
}

int	all_capital(char **words)
{
	int i;
	int j;

	i = 0;
	while (words[i])
	{
		j = 0;
		while (words[i][j])
		{
			if (is_char(words[i][j]))
				if (!is_uppercase(words[i][j]))
					return 0;
			j++;
		}
		i++;
	}

	return 1;
}

int	all_lower(char **words)
{
	int i;
        int j;

        i = 0;
        while (words[i])
        {
                j = 0;
                while (words[i][j])
                {
                        if (is_char(words[i][j]))
                                if (is_uppercase(words[i][j]))
                                        return 0;
                        j++;
                }
                i++;
        }

        return 1;
}

int	first_capital(char **words)
{
	int i;
	int j;

	i = 0;
	while (words[i])
	{
		if (!is_uppercase(words[i][0]))
			return 0;
		j = 1;
		while (words[i][j])
		{
			if (is_uppercase(words[i][j]))
				return 0;
			j++;
		}
		i++;
	}

	return 1;
}

int     is_correctly_capitalized(const char *str)
{
    // identifie patter first? work as we go?
    // second option seems better performance wise, more ifs tho
    // pattern: 1 => all lower case, 2 => all uppercase, 3 => first character uppercase, 0 => invalide
    char **words;

    words = get_words(str);
    
    if (all_capital(words))
	    return 1;
    if (all_lower(words))
	    return 2;
    if (first_capital(words))
	    return 3;

    return 0;
}

int     main(int argc, char **argv)
{
	int pattern;

	if (argc < 2)
	{
        	printf("please provide string to check\n");
        	return 1;
	}

	pattern = is_correctly_capitalized((const char*)argv[1]);
	if (pattern == 1)
		printf("the string is correctly capitalized: all capital\n");
	else if (pattern == 2)
		printf("the string is correctly capitalized: all lowercase\n");
	else if (pattern == 3)
                printf("the string is correctly capitalized: first letter uppercase\n");
	else
                printf("the string is not correctly capitalized\n");
	return 0;
}
