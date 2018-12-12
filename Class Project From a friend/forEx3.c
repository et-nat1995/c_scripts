#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "forEx3.h"



threenode* creat_list()
{
	threenode *head;
	head=(threenode*)malloc(sizeof(threenode));
	head->next=NULL;
	return head;
}

threenode* made_item(int i,int j ,int value)
{
	threenode *item;
	item=(threenode*)malloc(sizeof(threenode));
	(item->data).i=i;
	(item->data).j=j;
	(item->data).value=value;
	item->next=NULL;
	return item;
}

void insert_item(threenode (*list),threenode (*item))
{
	item->next=list->next;
	list->next=item;
	return;
}
void insertlisttoarr(threenode *list,three **arr,int count)
{
	int i;
	list=list->next;
	*arr=(three*)malloc(count*sizeof(three));
	for(i=0;i<count;i++)
	{
		(*arr)[i].i=list->data.i;
		(*arr)[i].j=list->data.j;
		(*arr)[i].value=list->data.value;
		list=list->next;
	}
}


int matchmatrix(int **matrix,int row,int cal,threenode (*list),three **arr)
{
	int i,j,count=0;
	threenode *temp;

	for(i=0;i<row;i++)
	{
		for(j=0;j<cal;j++)
		{
			if(j+i==matrix[i][j])
			{
		      count++;
			  temp=made_item(i,j,matrix[i][j]);
			  insert_item(list,temp);
			}
		}

	}
	insertlisttoarr(list,arr,count);
	
	return count ;
}


int** full_madematrix(int n,int m)
{
	int **row,i,j;
	row=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		row[i]=(int*)malloc(m*sizeof(int));
		for(j=0;j<m;j++)
		{
	     row[i][j]=rand()%(n+m);
		}
	}
	return row;
}


void print_threelist(threenode *list)
{
	if(list->next==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		printf("list is:\n");
		list=list->next;
		while(list->next!=NULL)
		{
			printf("[i=%2d ,j=%2d ,value=%2d]--->",(list->data).i,(list->data).j,(list->data).value);
			list=list->next;

		}
		printf("[i=%2d ,j=%2d ,value=%2d]--->NULL \n",(list->data).i,(list->data).j,(list->data).value);
		
	}

}

void print_arrthree(three *arr,int size)
{
	int i;
	if (size==0)
	{
		printf("arr is empty");
	}
	else
	{
		printf("the arr is:\n");
		for (i=0;i<size;i++)
		{
		
			printf("|i=%2d ,j=%2d ,value=%2d|,",(arr[i]).i,arr[i].j,arr[i].value);
		}

		printf("\n");
	}
	
}
void freelistthree(threenode *list)
{
	threenode *temp;
	while(list!=NULL)
	{
		temp=list;
		list=list->next;
		free(temp);
	}
	printf("list is free \n");
}

