//
//  main.c
//  LIsts1
//
//  Created by Tamir Natanov on 10/22/17.
//  Copyright © 2017 Tamir Natanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Struct Declorations

typedef struct Node{
    int value;
    struct Node *next;
}Node;

//Function Declorations

void creat_node(Node **head);
void printList(Node *head);
void FreeList(Node *head);

int main() {
    Node *head;
    
    srand((unsigned int) time(NULL));
    creat_node(&head);
    printList(head);
    FreeList(head);
    return 0;
}

void creat_node(Node **head)
{
    Node *temp = NULL;
    int  stop = 0;
    
    *head   = (Node*)malloc(sizeof(Node));
    temp    = *head;
    
    while(stop < 10)
    {
        temp->next  = (Node*)malloc(sizeof(Node));
        temp        = temp->next;
        temp->value = rand()%100 + 1;
        stop++;
    }
    
    temp->next = NULL;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void printList(Node *head)
{
    while(head != NULL)
    {
        printf("[%d]->", head->value);
        head    = head->next;
    }
    printf("NULL\n");
}

void FreeList(Node *head)
{
    if(head == NULL)
        return;
    FreeList(head->next);
    free(head);
}
