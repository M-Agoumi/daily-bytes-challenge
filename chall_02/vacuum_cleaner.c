#include <stdio.h>

int     is_starting_point(char *instruction)
{
    int up;
    int side;

    up = 0;
    side = 0;

    while (*instruction)
    {
        if (*instruction == 'U')
            up++;
        else if (*instruction == 'D')
            up--;
        else if (*instruction == 'L')
            side++;
        else if (*instruction == 'R')
        {
            side--;
        }
        *instruction++;
    }
    if (!up && !side)
        return 1;
    
    return 0;
}


int     main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("please provide instruction to check\n");
        return 1;
    }

    printf("the vacuume cleaner %s to its original starting point\n", is_starting_point(argv[1]) ?
    "has returned" : "did not return");
    return 0;
}