#include <stdio.h>

size_t  strlen(char *str)
{
    size_t lenght;

    lenght = 0;
    if (str)
        while(str[++lenght])
            ;

    return lenght;
}

int     is_char(char c)
{
    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
        return 1;
    
    return 0;
}

char    to_lower(char c)
{
    if (c <= 'Z' && c >= 'A')
        return c + 32;
    
    return c;
}

int     is_valid_palindrome(char *str)
{
    size_t  i;
    size_t  j;
    size_t  lenght;

    i = 0;
    lenght = strlen(str) - 1;
    j = lenght;
    printf("string size %ld\n", lenght);

    while (i < lenght && j > 0)
    {
        while(!is_char(str[i]))
        {
            i++;
        }
        while (j > 0 && !is_char(str[j]))
        {
            j--;
        }
        
        if (to_lower(str[i++]) != to_lower(str[j--]))
            return 0;
    }
    
    return 1;
}

int     main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("please provide string to check palindrome on\n");
        return 1;
    }

    printf("the provided string is %s\n", is_valid_palindrome(argv[1]) ? "valid" : "not valid");
    
    return 0;
}