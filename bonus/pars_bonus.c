#include "fractol_bonus.h"

int check_empty(char *argv)
{
    int i;

    i = 0;
    if (argv[i] == '\0')
        return (1);
    while (argv[i] == 32 || argv[i] == 9)
        i++;
    if (argv[i] == '\0')
        return (1);
    return (0);
}

int julia_numbers_pars(char **argv)
{
    int i;
    int j;
    int flag;

    i = 2;
    j = 0;
    flag = 1;
    if (check_empty(argv[i]) == 1)
        return (1);
    while (argv[i])
    {
        j = 0;
        while (argv[i][j] && (argv[i][j] == 32 || argv[i][j] == 9))
            j++;
        while (argv[i][j] != 32 && argv[i][j] != 9)
        {
            if (argv[i][j] && argv[i][j] >= '0' && argv[i][j] <= '9')
                j++;
            else if (argv[i][j] && argv[i][j] == '.' && flag == 1)
            {
                j++;
                flag = 0;
            }
            else
                break ;
        }
        while (argv[i][j] && (argv[i][j] == 32 || argv[i][j] == 9))
            j++;
        if (argv[i][j] != '\0')
            break ;
        flag = 1;
        i++;
    }
    if (i == 4 && !argv[i])
        return (1);
    return (0);
}

int mandelbrot_check(char *argv)
{
    int i;
    int j;
    char *str1;

    str1 = "mandelbrot";
    i = 0;
    j = 0;
    if (check_empty(argv) == 1)
        return (1);
    while (argv[i] == 32 || argv[i] == 9)
        i++;
    while (argv[i] && argv[i] == str1[j])
    {
        i++;
        j++;
    }
    while (argv[i] == 32 || argv[i] == 9)
        i++;
    if (argv[i] == '\0')
        return (0);
    return (1);
}

int tricorn_check(char *argv)
{
    int i;
    int j;
    char *str1;

    str1 = "tricorn";
    i = 0;
    j = 0;
    if (check_empty(argv) == 1)
        return (1);
    while (argv[i] == 32 || argv[i] == 9)
        i++;
    while (argv[i] && argv[i] == str1[j])
    {
        i++;
        j++;
    }
    while (argv[i] == 32 || argv[i] == 9)
        i++;
    if (argv[i] == '\0')
        return (0);
    return (1);
}
int julia_check(char **argv)
{
    int i;
    int j;
    char *str1;

    str1 = "julia";
    i = 0;
    j = 0;
    if (check_empty(argv[1]) == 1)
        return (1);
    while (argv[1][i] == 32 || argv[1][i] == 9)
        i++;
    while (argv[1][i] && argv[1][i] == str1[j])
    {
        i++;
        j++;
    }
    while (argv[1][i] == 32 || argv[1][i] == 9)
        i++;
    if (argv[1][i] == '\0')
    {
        return (julia_numbers_pars(argv));
    }
    return (0);
}
