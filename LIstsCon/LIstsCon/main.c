#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lst{
    int value;
    struct lst *next;
}LST;


LST *creatLST(int num);

int main()
{
    LST *start = NULL;
    start = creatLST(1);
    start->next = creatLST(4);
}

LST *creatLST(int num)
{
    LST *temp =(LST*)malloc(sizeof(LST));
    temp->value = num;
    temp->next = NULL;
    return temp;
}

LST *addtofirst(LST *head, int num)
{
    LST *temp = creatLST(num);
    temp->next = head;
    return temp;
    
}

// p = p->next;

//Recusrive way to free a list.

void freeLIst( LST *head)
{
    if(head == NULL)
        return;
    freeLIst(head->next);
    free(head);
}
