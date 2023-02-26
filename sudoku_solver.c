#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 9

int tab[SIZE][SIZE];
int initialTab[SIZE][SIZE];

int copyArray(int dest[SIZE][SIZE], int src[SIZE][SIZE])
{
    for (int a = 0; a < SIZE; a++)
    {
        for (int b = 0; b < SIZE; b++)
        {
            dest[a][b] = src[a][b];
        }
    }
    return 0;
}

void printArray(int src[SIZE][SIZE])
{
    for (int a = 0; a < SIZE; a++)
    {
        for (int b = 0; b < SIZE; b++)
        {
            printf("%d ", src[a][b]);
        }
        printf("\n");
    }
}

int checkLine(int numberToCheck, int line, int column, int src[SIZE][SIZE])
{
    int found = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (numberToCheck == tab[line][i] && numberToCheck != 0 && numberToCheck <= SIZE)
        {
            found = 1;
            break;
        }
    }
    if (numberToCheck > SIZE)
        found = 1;
    return found;
}

int checkColumn(int numberToCheck, int line, int column, int src[SIZE][SIZE])
{
    int found = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (numberToCheck == tab[i][column] && numberToCheck != 0 && numberToCheck <= SIZE)
        {
            found = 1;
            break;
        }
    }
    if (numberToCheck > SIZE)
        found = 1;
    return found;
}

int checkBlock(int numberToCheck, int line, int column, int src[SIZE][SIZE])
{
    int found = 0;
    int toSearchColumns = column % 3;
    int toSearchLines = line % 3;
    for (int c = column - toSearchColumns; c <= column - toSearchColumns + 2; c++)
    {
        for (int l = line - toSearchLines; l <= line - toSearchLines + 2; l++)
        {
            if (tab[l][c] == numberToCheck && numberToCheck != 0 && numberToCheck <= SIZE)
            {
                found = 1;
                break;
            }
        }
    }
    if (numberToCheck > SIZE)
        found = 1;
    return found;
}

int isASolution(int numberToCheck, int column, int line, int src[SIZE][SIZE])
{
    return (!checkColumn(numberToCheck, line, column, src) && !checkLine(numberToCheck, line, column, src) && !checkBlock(numberToCheck, line, column, src));
}

int backtrack(int number, int indexLine, int indexColumn, int src[SIZE][SIZE])
{
    // printf("J'en suis à number : %d indexLine : %d indexColumn : %d\n", number, indexLine, indexColumn);
    if (indexColumn >= 9)
    {
        return backtrack(number, indexLine + 1, 0, src);
    }
    else if (indexLine >= 9)
    {
        return 1;
    }
    else if (initialTab[indexLine][indexColumn] != 0)
    {
        return backtrack(number, indexLine, indexColumn + 1, src);
    }
    else if (isASolution(number, indexColumn, indexLine, src))
    {
        int copyTab[SIZE][SIZE];
        copyArray(copyTab, src);
        src[indexLine][indexColumn] = number;
        for (int i = 1; i <= SIZE; i++)
        {
            if (backtrack(i, indexLine, indexColumn + 1, src))
            {
                return 1;
            }
        }
        copyArray(src, copyTab);
        return 0;
    }
    else
    {
        return 0;
    }
}

int main()
{
    clock_t begin = clock();

    char temp;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d%c", &initialTab[i][j], &temp);
        }
    }

    int found = 0;
    copyArray(tab, initialTab);

    for (int number = 1; number <= SIZE; number++)
    {
        if (backtrack(number, 0, 0, tab))
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No possible solution !\n\n");
    }
    else
    {
        clock_t end = clock();
        printf("Solution found in %f seconds !\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
        printArray(tab);
    }

    return 0;
}