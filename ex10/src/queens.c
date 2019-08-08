#include "../include/queens.h"
#include <stdio.h>
#include <stdlib.h>

int    QUEEN_IS_HERE(Cell **table, int rows, int columns, int size)
{

    int k = 1;
    while (rows + k < size && columns + k < size)
    {
        if (table[rows + k][columns + k].figure == 'Q')
            return (0);
        k++;
    }
    k = -1;
    while (rows + k >= 0 && columns + k >= 0)
    {
        if (table[rows + k][columns + k].figure == 'Q')
            return (0);
        k--;
    }
    k = 1;
    while (rows + k < size && columns - k >= 0)
    {
        if (table[rows + k][columns - k].figure == 'Q')
            return (0);
        k++;
    }
    k = -1;
    while (rows + k >= 0 && columns - k < size)
    {
        if (table[rows + k][columns - k].figure == 'Q')
            return (0);
        k--;
    }
    k = 0;
    while (k < size)
    {
        if (table[rows][k].figure == 'Q')
            return (0);
        k++;
    }
    return (1);
}

int   recursive_search(Cell **table, int size, int column)
{
    int i;

    i = 0;
    if (column >= size)
    {
        exit (0);
        return (1);
    }
    while (i < size)
    {
        if (table[i][column].figure == 'Q')
            recursive_search(table, size, column + 1);
        i++;
    }
    i = 0;
    while (i < size)
    {
        if (QUEEN_IS_HERE(table, i, column, size))
        {
            table[i][column].figure = 'Q';
            if (recursive_search(table, size, column + 1))
            return (1);
            table[i][column].figure = 'E';
        }
        i++;
    }
    return (0);
}

void    place_queens(Cell **table, int size)
{
    recursive_search(table, size, 0);
}
