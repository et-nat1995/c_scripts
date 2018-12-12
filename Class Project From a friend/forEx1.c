#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "forEx1.h"


int* two_power(int n)
{
	int *arry,i;
	arry=(int*)malloc(n*sizeof(int));
	if(arry)
	{
		arry[0]=1;
		for(i=1;i<n;i++)
			arry[i]=2*arry[i-1];

		return arry;
	}
	else
	{
		printf("not found memory pleas enter smaller number\n");
		return arry;
	}
}


void printarr(int *arr,int sizearr)
{
	int i;
	for (i=0;i<sizearr;i++)
	{
		printf("% 2d",arr[i]);
	}
	printf("\n");
}
