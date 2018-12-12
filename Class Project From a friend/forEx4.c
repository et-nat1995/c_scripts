#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "forEx4.h"



Data* creat_listData()
{
	Data *head;
	head=(Data*)malloc(sizeof(Data));
	head->next=NULL;
	return head;
}

void insert_listData(Data *list,int num )
{
	Data *new_item;
	new_item =(Data*)malloc(sizeof(Data));
	new_item->data=num;
	/*new_item->next=list->next;                     הרבה יותר יעיל הכנסה כזו אולם היא מכניסה כל איבר לראש הרשימה ולא לסופה 
	list->next=new_item;*/

	while(list->next!=NULL)
		list=list->next;

	new_item->next=NULL;
	list->next=new_item;

}

void full_list(Data *list,int num)
{
	int i,number;
	for(i=0;i<num;i++)
	{
		scanf("%d",&number);
		insert_listData(list,number);
	}
}

void print_listData(Data *list)
{
	if(list->next==NULL)
		printf("the list is empty\n");
	else
	{
		list=list->next;
		while(list->next!=NULL)
		{
			printf("[%d]->",list->data);
			list=list->next;
		}
			printf("[%d]->NULL \n",list->data);
	}
}

void insert_listData_item(Data *list,Data *item)
{
	/*item->next=list->next;                    // יותר יעיל בהרבה אולם הוא מכניס כל איבר לראש הרשימה ולא לסופה  
	list->next=item;*/
	while(list->next!=NULL)
		list=list->next;

	item->next=NULL;
	list->next=item;
}

Data * odd_even(Data *list)
{
	Data *list_odd,*list_even,*temp;
	list_even=list;
	list_odd=creat_listData();

	list=list->next;
	list_even->next=NULL;

	while (list!=NULL)
	{
		temp=list;
		list=list->next;
		if((temp->data)%2==0)
			{
          		insert_listData_item(list_even,temp);
			}
		else
			{
				insert_listData_item(list_odd,temp);
			}
	}
	list=list_even;
	return list_odd;
}

void list_untilminus1(Data* list)
{
	int new_num;
	printf("enter your num until-1\n");
	scanf("%d",& new_num);
	while (new_num!=-1)
	{
	  insert_listData(list,new_num);
	
	  scanf("%d",& new_num);
	}
    return ;
}

void freelistData(Data *list)
{
	Data *temp;
	while(list!=NULL)
	{
		temp=list;
		list=list->next;
		free(temp);
	}
	printf("list is free \n");
}


	
