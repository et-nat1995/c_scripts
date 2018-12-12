#include <stdio.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
//keep below 10
#define Q 8

void printQueens(int q[]);
int placeTheQueens(int q[], int n);
void queens_logic(int q[], int n);

int counter = 0;
FILE *file;

int main()
{
    clock_t start;
    int quee[Q];
    
    start   = clock();
    file    = fopen("8Queens.txt", "w");
    
    queens_logic(quee, 0);
    fprintf(file, "It took this script %f seconds to solve this problem.\n",
            ((double)clock() - start)/CLOCKS_PER_SEC);
    fprintf(file, "With a total amount of %d solutions.\n", counter);
    fclose(file);
    
}
void queens_logic(int q[], int n)
{
    int i;
    if(n == Q)
    {
        printQueens(q);
        counter++;
    }
    else
    {
        for(i = 0; i < Q; i++)
        {
            q[n] = i;
            if(placeTheQueens(q, n))
                queens_logic(q, n+1);
        }
    }
}


int placeTheQueens(int q[], int n)
{
    int i;
    
    for(i = 0; i < n; i++)
    {
        if(q[i] == q[n])
            return FALSE;
        if((q[i] - q[n]) == (n - i))
            return FALSE;
        if((q[n] - q[i]) == (n - i))
            return FALSE;
    }
    return TRUE;
}

void printQueens(int q[])
{
    int i, j;
    for(i = 0; i < Q; i++)
    {
        for(j = 0; j < Q; j++)
        {
            if(q[i] == j)
                fprintf(file,"Q ");
            else
                fprintf(file, "* ");
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}
