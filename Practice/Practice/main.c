#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **make_mat(int *arr, int rows);
void fillmat(int **mat, int *arr, int rows);
void free_mat(void **mat, int col);
int *make_array(int n);

int main()
{
    int *arr, **mat, rows;
    
    printf("How many rows woud you like?\n");
    scanf("%d", &rows);
    
    arr = make_array(rows);
    mat = make_mat(arr, rows);
    
    fillmat(mat, arr, rows);
    
    free_mat((void *) mat, rows);
    free(arr);
    return 0;
}

int *make_array(int n)
{
    int i, *arr = (int*)malloc(n *sizeof(int));
    
    
    for(i = 0; i < n; i++)
    {
        printf("Give me the size of row %d...", i+1);
        scanf("%d", &arr[i]);
    }
    
    return arr;
}

int **make_mat(int *arr, int rows)
{
    int **mat = (int **)malloc(rows * sizeof(int*)), i;
    
    for(i = 0; i < rows; i++)
    {
        mat[i] = (int *)malloc(arr[i] * sizeof(int));
    }
    
    return mat;
}

void fillmat(int **mat, int *arr, int rows)
{
    int i, j;
    
    srand((unsigned int)time(NULL));
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j< arr[i]; j++)
        {
            mat[i][j] = rand() %10 + 1;
            printf("[%d] ", mat[i][j]);
        }
        printf("\n");
    }
    
}

void free_mat(void **mat, int col)
{
    int i;
    
    for(i = 0; i < col; i++)
        free(mat[i]);
}
