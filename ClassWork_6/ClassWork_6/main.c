#include <stdio.h>
#include <stdlib.h>

#define N 10


typedef struct list
{
    int             value;
    struct list     *next;
}list;

int creat_odd_even(list **odd_head, list **even_head);
void printList(list *head);
void freeLIst(list *head);

/*
int creatList(list **Even, list **Odd)
{
    
    
}
*/
/*
int main()
{
    int i;
    
    list *head = NULL, *curr = NULL;
    list *Even = NULL, *Odd = NULL;
    
//    creatList(&Even, &Odd);
    
    for(i = 0; i < N; i++)
    {
 
        curr = (list*)malloc(sizeof(list));
        curr->next = head;
        curr-> value = i+1;
        head = curr;
        
 
        if( head == NULL)
        {
            head = (list*)malloc(sizeof(list));
            curr = head;
        }
        else
        {
            curr->next = (list*)malloc(sizeof(list));
            curr = curr->next;
        }
        
        curr->value = i+1;
        curr->next = NULL;
        
    }
    
    printList(head);
    
    
    return 0;
}
 */

int main()
{
    list *odd  = NULL;
    list *even = NULL;
    int count;
    
    printf("The amount of enteries for the list is: %d \n", count = creat_odd_even(&odd, &even));
    
    printf("Odd List: ");
    printList(odd);
    printf("Even List: ");
    printList(even);
    
    freeLIst(odd);
    freeLIst(even);
    
    return 0;
}


int creat_odd_even(list **odd_head, list **even_head)
{
    list *odd_cur = NULL, *even_cur = NULL;
    int num, counter = 0;
    
    *odd_head   = (list *)malloc(sizeof(list));
    odd_cur     = *odd_head;
    *even_head  = (list *)malloc(sizeof(list));
    even_cur    = *even_head;
    
    printf("Please enter a value for the list:\n");
    scanf("%d", &num);
    
    while(num != -1)
    {
        if(num % 2 != 0)
        {
            odd_cur->next   = (list *)malloc(sizeof(list));
            odd_cur         = odd_cur->next;
            odd_cur->value  = num;
        }
        else
        {
            even_cur->next   = (list *)malloc(sizeof(list));
            even_cur         = even_cur->next;
            even_cur->value  = num;
        }
        
        scanf("%d", &num);
        
        counter++;
    }
    
    odd_cur->next    = NULL;
    even_cur->next   = NULL;
    
    odd_cur   = *odd_head;
    *odd_head = (*odd_head)->next;
    free(odd_cur);
    
    even_cur   = *even_head;
    *even_head = (*even_head)->next;
    free(even_cur);
    
    return counter;
    
}

void printList(list *head)
{
    while(head != NULL)
    {
        printf("[%d]-> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
    
}

void freeLIst(list *head)
{
    if(head == NULL)
        return;
    freeLIst(head->next);
    free(head);
}




