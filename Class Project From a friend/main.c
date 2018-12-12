
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "forEx1.h"
#include "forEx2.h"
#include "forEx3.h"
#include "forEx4.h"



void Ex1(); 
void Ex2(); 
void Ex3(); 
void Ex4(); 

 





void main() 
{ 
	int select = 0, i, all_Ex_in_loop = 0; 
	printf("Run menu once or cyclically?\nOnce - enter 0, cyclically - enter other number\n"); 
	if (scanf("%d", &all_Ex_in_loop) == 1) 
		do 
		{ 
			printf("Ex 1-----(Array of power 2)------------->1\nEx 2-----(multiplication matrix)-------->2\nEx 3-----(amount of i and j)------------>3\nEx 4-----(list odd/even)---------------->4\n"); 
		
			do 
			{ 
				select = 0; 
				printf("please select 0-4 : "); 
				scanf("%d", &select); 
			} 
			while ((select<0) || (select>6)); 
			switch (select) { 
			case 1: Ex1(); break; 
			case 2: Ex2(); break; 
			case 3: Ex3(); break; 
			case 4: Ex4(); break;  
			} 
		} while (all_Ex_in_loop && select); 
} 

///////////////////////////////////Ex1


void Ex1 ()
{
	int *arry=NULL,n;
	
		printf("enter the size of arry\n");
		scanf("%d",&n);
		arry=two_power(n);
		if(arry!=NULL)
	    printf("the arr of power 2 is:"); 
	    printarr(arry,n);
		free(arry);
		printf("\nend of Ex1\n"); 

} 
	

//////////////////////////////////////////////////////////////////EX2

void Ex2  ()
{


	int matrixA[N][M],matrixB[W][T],**matrixC;
	fullmatrixA(matrixA);
	fullmatrixB(matrixB);
	print_matrixA(matrixA);
	print_matrixB(matrixB);
	matrixC=multimatrix(matrixA,matrixB);
	printf("matrix c is:\n");
	printMatrix(matrixC,N,T);
	freematrix(matrixC,N);
	printf("\nend of Ex2\n");



	
}

///////////////////////////////////////////////////////EX3

void Ex3() 
{ 
	int **matrix,count,i;
	three *arr=NULL;
	threenode*list;
	list=creat_list();
	matrix=full_madematrix(F,R);
	printf("the matrix is:\n");
	printMatrix(matrix,F,R);
	count=matchmatrix(matrix,F,R,list,&arr);
	print_threelist(list);
	print_arrthree(arr,count);
	freematrix(matrix,F);
	freelistthree(list);
	free(arr);
	printf("\nend of Ex3\n"); 
} 



///////////////////// Ex4  

void Ex4 () 
{ 
	 Data *list,*list_odd;
	list=creat_listData();
	list_untilminus1(list);
	printf("the list is:\n");
	print_listData(list);
	list_odd=odd_even(list);
	printf("the list even is:\n");
	print_listData(list);
	printf("the list odd is:\n");
	print_listData(list_odd);
	freelistData(list);
	freelistData(list_odd);
	printf("\nend of Ex4\n"); 
} 

