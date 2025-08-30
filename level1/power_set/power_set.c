#include <stdlib.h>
#include <stdio.h>

void print_table(int *res , int len)
{
    int i = 0;
    while (i < len)
    {
        printf("%d", res[i]);
        if (i != len - 1)
            printf(" ");
        i++;
    }
    printf("\n");
}

void    powerset(int i, int size, int target, int *res, int *tab, int len)
{
    if (size == i)
    {
        int sum = 0;
        int j = 0;
        while (j < len)
        {
            sum += res[j];
            j++;
        }
        if (sum == target)
            print_table(res, len);
        return ;
    }
    res[len] = tab[i];
    powerset(i + 1, size, target, res, tab, len + 1);
    powerset(i + 1, size, target, res, tab, len);
}

int main (int ac , char **av)
{
    if (ac < 3)
        return 1;
    int target = atoi(av[1]);
    int tab[ac - 2];
    int i = 0;
    while (i < ac - 2)
    {
        tab[i] = atoi(av[i + 2]);
        i++;
    }
    int *res = malloc(sizeof(int) * (ac - 2));
    if (!res)
        return 1;
    powerset(0 , ac - 2, target, res, tab, 0);
    free(res);
    return 0;
}