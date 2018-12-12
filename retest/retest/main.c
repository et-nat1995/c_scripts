//
//  main.c
//  retest
//
//  Created by Tamir Natanov on 5/16/17.
//  Copyright © 2017 Tamir Natanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Three{
    int value;
    int posI;
    int posJ;
    struct Node *next;
}Three;

typedef struct Node{
    int value;
    struct Node *next;
}Node;

void ex_1();
int **creat_matrix(int *rows, int *cols);
int Make_three(int **mat, Three **arr, int row, int col);
void PrintThree(Three *arr, int size);
void print_mat_dyn(int **mat, int row, int col);
void free_mat(int **mat, int n);

void ex_2();
void createList(Node **head);
void printList(Node *head);
void freeLIst(Node *head);
Node *Even_Odd (Node **list);

int main()
{
//    ex_1();
    ex_2();
    return 0;
}

void ex_1()
{
    int row, col, sum;
    int **Mat;
    Three *arr;
    
    srand((unsigned int)time(NULL));
    
    Mat = creat_matrix(&row, &col);
    print_mat_dyn(Mat, row, col);
    sum = Make_three(Mat, &arr, row, col);
    
    printf("The amount of times PosI + PosJ = Mat[I][J] is true : %d\n", sum);
    if(sum != 0)
        PrintThree(arr, sum);
    else
        printf("Nothing to print here.\n");
    
    free_mat(Mat, row);
    free(arr);
}

int **creat_matrix(int *rows, int *cols)
{
    int i, j;
    int **mat;
    
    printf("How many rows would you like for the matrix?...");
    scanf("%d", rows);
    
    printf("How many columns would you like for the matrix?...");
    scanf("%d", cols);
    
    mat = (int **)malloc(*rows * sizeof(int*));
    
    for(i = 0; i < *rows; i++)
        mat[i] = (int *)malloc(*cols * sizeof(int));
    
    for(i = 0; i < *rows; i++)
    {
        for(j = 0; j < *cols; j++)
        {
            mat[i][j] = rand()%10;
        }
    }
    
    return mat;
}

int Make_three(int **mat, Three **arr, int row, int col)
{
    int i, j, k = 0, sum = 0;
    
    //Counting how many times i+j = mat[][] is true and making an array that is type three of that size
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(i + j == mat[i][j])
            {
                sum++;
            }
        }
    }
    //Checking that sum isnt 0 if it is then to exit if not, then to continue to make the array and the list.
    if(sum != 0)
    {
        *arr = (Three *)malloc(sum*sizeof(Three));
        
        for(i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                if(i + j == mat[i][j])
                {
                    (*arr)[k].value = mat[i][j];
                    (*arr)[k].posI  = i;
                    (*arr)[k].posJ  = j;
                    k++;
                }
            }
        }
    }
    else
        return 0;
    
    return sum;
}

void PrintThree(Three *arr, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("Value:[%d] PosJ:[%d] PosI:[%d]\n", arr[i].value, arr[i].posJ, arr[i].posI);
    }
    printf("\n");
}

void print_mat_dyn(int **mat, int row, int col)
{
    int i, j;
    
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("[%d] ",mat[i][j]);
        }
        printf("\n");
    }
}

void free_mat(int **mat, int n)
{
    int i;
    
    for(i = 0; i < n; i++)
        free(mat[i]);
}

void ex_2()
{
    Node *head = NULL;
    Node *odd  = NULL;
    
    createList(&head);
    
    odd = Even_Odd(&head);
    
//    Printing the list.
    printList(head);
    printList(odd);
    
//    Freeing the lists.
    freeLIst(head);
    freeLIst(odd);
    
}

void createList(Node **head)
{
    Node *temp = NULL;
    int   num;
    
    *head           = (Node *)malloc(sizeof(Node));
    temp            = *head;
    
    printf("Enter a value for the list (To exit enter -1): ");
    scanf("%d", &num);
    
    while(num != -1)
    {
        temp->next  = (Node *)malloc(sizeof(Node));
        temp        = temp->next;
        temp->value = num;
        
        printf("Enter a value for the list (To exit enter -1): ");
        scanf("%d", &num);
        
    }
    
    temp->next      = NULL;

    temp            = *head;
    *head           =(*head)->next;
    free(temp);
    
}

Node *Even_Odd (Node **list)
{
    Node *keeper = (*list);
    Node *temp_odd ,*head ;
    
    if (keeper == NULL)
        return NULL;
    
    head = (Node *)malloc(sizeof(Node));
    
    temp_odd = head;
    temp_odd->next=NULL;
    while (keeper->next) {
        if (keeper->next->value % 2 != 0) {
            temp_odd->next = keeper->next;
            keeper->next = keeper->next->next;
            temp_odd = temp_odd->next;
            temp_odd->next = NULL;
        }
        else keeper = keeper->next;
    }
    temp_odd = head;
    if ((*list)->value % 2 != 0) {
        head = (*list);
        (*list) = (*list)->next;
        head->next = temp_odd->next;
    }
    else head = head->next;
    free(temp_odd);
    return head;
}

void printList(Node *head)
{
    while(head != NULL)
    {
        printf("[%d]->", head->value);
        head = head->next;
    }
    
    printf("NULL\n");
    
}

void freeLIst(Node *head)
{
    if(head == NULL)
        return;
    freeLIst(head->next);
    free(head);
}
