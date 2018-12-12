#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int key;
    struct Node *next;
}node;

void createList(node **head)
{
    srand((unsigned int) time(NULL));
    
    node *temp = NULL;
    int   num;
    int   stop = 0;
    
    *head           = (node *)malloc(sizeof(node));
    temp            = *head;
    
//    printf("Enter a value for the list (To exit enter -1): ");
//    scanf("%d", &num);
    
    while(stop < 10)
    {
        temp->next  = (node *)malloc(sizeof(node));
        temp        = temp->next;
        temp->key   = rand()%10;
        
//        printf("Enter a value for the list (To exit enter -1): ");
//        scanf("%d", &num);
        stop++;
    }
    
    temp->next      = NULL;
    
    temp            = *head;
    *head           =(*head)->next;
    free(temp);
    
}

void printList(node *head)
{
    while(head != NULL)
    {
        printf("[%d]->", head->key);
        head = head->next;
    }
    
    printf("NULL\n");
    
}
void freeList(node *head)
{
    if(head == NULL)
        return;
    freeList(head->next);
    free(head);
}

void main()
{
    node *head = NULL;
    
    createList(&head);
    printList(head);
    freeList(head);
    
}
