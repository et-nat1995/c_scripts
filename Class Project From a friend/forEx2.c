#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "forEx2.h"

void fullmatrixA(int matrix[N][M])
{
	int i,j;
	printf("insert matrix A:\n");

	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			//scanf("%d",&matrix[i][j]);
			matrix[i][j]=rand()%10;
		}
		//printf("\n new line");
	}
}



void fullmatrixB(int matrix[M][T])
{
	int i,j;
	printf("insert matrix B:\n");

	for(i=0;i<M;i++)
	{
		for(j=0;j<T;j++)
		{
			//scanf("%d",&matrix[i][j]);
			matrix[i][j]=rand()%10;
		}
		//printf("\n new line");
	}
}


void print_matrixB(int matrix[M][T])
{
	int i,j;
	printf("matrix B is:\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<T;j++)
		{
			printf("%5d",matrix[i][j]);
		}
		printf("\n");

	}

	printf("\n\n\n\n");
}


void print_matrixA(int matrix[N][M])
{
	int i,j;
	printf("matrix A is:\n");

	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%5d",matrix[i][j]);
		}
		printf("\n");

	}
	printf("\n\n\n\n");
}

int ** multimatrix(int matrixA[N][M],int matrixB[W][T])
{
	
	int ** calc,i,j,sum=0,k;
	if(M!=W)
	{
		printf("invalid operration\n");
		calc=NULL;
		return calc;
	}
	calc=(int**)malloc(N*sizeof(int*));
	for(i=0;i<N;i++)
	{
		calc[i]=(int*)malloc(sizeof(int)*T);
	}
	for(i=0;i<N;i++)
	{
		for(k=0;k<T;k++)
		{
			for(j=0;j<M;j++)
			{
				sum=sum+(matrixA[i][j]*matrixB[j][k]);
			}
			calc[i][k]=sum;
			sum=0;
		}
	}
	return calc;
}

void printMatrix(int **arr,int row, int cal)
{
	int i,j;
	if(arr==NULL)
	{
		printf("no matrix\n");
		return;
	}
	  for(i=0;i<row;i++)
	  {
		  for(j=0;j<cal;j++)
		  {
			  printf("%5d  ",arr[i][j]);
			 
		  }
		   printf("\n");
	  }
	  printf("\n\n\n\n");
}

void freematrix(int **matrix ,int row)
{
	int i;
	if(matrix!=NULL)
	{
		for(i=0;i<row;i++)
		{
			free(matrix[i]);
		}
		free(matrix);
		printf("matrix is free\n");
	}
	else
	{
		printf("no matrix to free\n");
	}
}
