#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Ex1();
int *CreateArray(int *Length);
void DisplayIntegerArray(int *Array, int Length);
void Swap(int *First, int *Second);
void ArrangeOddEven(int *Array, int Length);

void Ex2();
int Recursion(int Number);

void Ex3();
int *MergeArrays(int *FirstArray, int *SecondArray, int FirstLength, int SecondLength,int *Length);
void MergeSort(int *Array,int First, int Last);
void Merge(int *Array,int p,int q,int r);

void Ex4();
int Permutation(int *FirstArray, int *SecondArray, int FirstLength, int SecondLength);

void Ex5();
char *CreateString();
void RemoveCharFunction(char *String, char CharToCheckOn);

void main()
{
	int select=0, i, all_Ex_in_loop=0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically -enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do {
			for (i=1; i<=5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select=0;
				printf("please select 0-5 : ");
				scanf("%d",&select);
			} while ((select<0)||(select>5));
			switch (select) {
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
}

void Ex1()
{
	int *Array, Length;
	Array = CreateArray(&Length);
	DisplayIntegerArray(Array, Length);
	ArrangeOddEven(Array, Length);
	DisplayIntegerArray(Array, Length);
	free(Array);
}
int *CreateArray(int *Length)
{
	int *Array, i;
	printf ("Insert array size: ");
	scanf ("%d", Length);
	Array = (int*)malloc((*Length)*sizeof(int));
	for (i=0 ; i<(*Length) ; i++)
	{
		printf ("Insert value in %d location in array: ", i);
		scanf ("%d" , &Array[i]);
	}
	return Array;
}
void DisplayIntegerArray(int *Array, int Length)
{
	int i;
	for (i=0 ; i<Length ; i++)
		printf ("[%d] ", Array[i]);
	printf ("\n\n");
}
void Swap(int *First, int *Second)
{
	int Temporarily = *First;
	*First = *Second;
	*Second = Temporarily;
}
void ArrangeOddEven(int *Array, int Length)
{
	int Left, Right;
	Left = 0;
	Right = Length - 1;
	while (Left < Right)
	{
		while (((Array[Left]%2) != 0) && (Left < Right))
			Left++;

		while (((Array[Right]%2) == 0) && (Left < Right))
			Right--;

		if (Left < Right)
		{
			Swap(&Array[Left], &Array[Right]);
			Left++;
			Right--;
		}
	}
}


void Ex2()
{
	int Number;
	printf("Insert number to check if it's divisible by '11': ");
	scanf("%d", &Number);
	if(Number < 1)
		printf("Bad parameters, try again.\n");
	else 
	{
		while (Number > 9)
			Number = abs(Recursion(Number));
		if(Number == 0)
			printf("The Number is divisable by 11.\n");
		else
			printf("The Number is not divisable by 11.\n");
	}
}
int Recursion(int Number)
{
	if (abs(Number) < 10)
		return Number;
	return Number%10 + Recursion((Number/10) * (-1));
}



void Ex3()
{
	int *FirstArray, *SecondArray, *ThirdArray, FirstLength, SecondLength, ThirdLength;
	FirstArray = CreateArray(&FirstLength);
	SecondArray = CreateArray(&SecondLength);

	printf ("First array: ");
	DisplayIntegerArray(FirstArray, FirstLength);

	printf ("Second array: ");
	DisplayIntegerArray(SecondArray, SecondLength);

	MergeSort(FirstArray, 0, FirstLength-1);
	MergeSort(SecondArray, 0, SecondLength-1);

	ThirdArray = MergeArrays(FirstArray,SecondArray,FirstLength,SecondLength,&ThirdLength);

	printf ("Third array: ");
	DisplayIntegerArray(ThirdArray, ThirdLength);

	free(FirstArray);
	free(SecondArray);
	free(ThirdArray);
}
int *MergeArrays(int *FirstArray, int *SecondArray, int FirstLength, int SecondLength,int *Length)
{
	int i, j;
	int *New_Array, *Temporarily;
	int Minimum;
	*Length=0;//the number of common numbers
	i = j = 0;
	if(FirstLength>SecondLength)
		Minimum=SecondLength;
	else
		Minimum=FirstLength;
	Temporarily = (int*)malloc(Minimum*sizeof(int));//array whith the maxsimum common numbers that can be
	while((i<FirstLength)&&(j<SecondLength))
	{
		if(FirstArray[i]==SecondArray[j])
		{
			Temporarily[*Length]=FirstArray[i];
			i++;
			j++;
			*Length = *Length + 1;
		}
		else
		{
			if(FirstArray[i] < SecondArray[j])
				i++;
			else
				j++;
		}
	}

	New_Array = (int*)malloc((*Length)*sizeof(int));//array in the exact number of common numbers
	for(i=0 ; i< *Length ; i++)
		New_Array[i]=Temporarily[i];
	free(Temporarily);
	return New_Array;
}
void MergeSort(int *Array,int First, int Last)
{
	int Middle;
	if(First < Last)
	{
		Middle=(First+Last)/2;
		MergeSort(Array,First,Middle);
		MergeSort(Array,Middle+1,Last);
		Merge(Array,First,Middle,Last);
	}
}
void Merge(int *Array,int p,int q,int r)
{
	int i=p,j=q+1,k=0;
	int* Temporarily=(int*)calloc(r-p+1, sizeof(int));
	while ((i<=q)&& (j<=r))
		if(Array[i]<Array[j])
			Temporarily[k++]=Array[i++];
		else
			Temporarily[k++]=Array[j++];
	while(j<=r) // if( i>q )
		Temporarily[k++]=Array[j++];
	while(i<=q) // j>r
		Temporarily[k++]=Array[i++];

	for(i=p,k=0;i<=r;i++,k++) // copy Temporarily[] to Array[]
		Array[i]=Temporarily[k];
	free(Temporarily);
}

void Ex4()
{
	int *FirstArray, *SecondArray, FirstLength, SecondLength, Result;
	FirstArray = CreateArray(&FirstLength);
	SecondArray = CreateArray(&SecondLength);

	printf ("First array: ");
	DisplayIntegerArray(FirstArray, FirstLength);

	printf ("Second array: ");
	DisplayIntegerArray(SecondArray, SecondLength);

	MergeSort(FirstArray, 0, FirstLength-1);
	MergeSort(SecondArray, 0, SecondLength-1);

	if (FirstLength != SecondLength)
		Result = 0;
	else
		Result = Permutation(FirstArray, SecondArray, FirstLength); //We check if second array is permutation of the first array.

	if (Result == 1)
		printf ("First array is permutation of Second array.\n");
	else
		printf ("First array is NOT permutation of Second array.\n");

l
    free(FirstArray);
	free(SecondArray);
}

int Permutation(int *FirstArray, int *SecondArray, int FirstLength)
{
	int i;
	for (i=0 ; i<FirstLength ; i++)
		if (FirstArray[i] != SecondArray[i])
			return 0;
	return 1;
}

void Ex5()
{
	char *String, c;
	String = CreateString();

	printf ("Insert char: ");
	scanf ("%c", &c);

	printf ("String before change: ");
	puts(String);

	RemoveCharFunction(String, c);

	printf ("String after change: ");
	puts(String);

	free(String);
}
char *CreateString()
{
	char *String, *Temporarily;
	printf ("Insert string: ");
	Temporarily = (char*)malloc(256*sizeof(char));
	flushall();
	gets(Temporarily);
	String = (char*)malloc((strlen(Temporarily)+1)*sizeof(char));
	strcpy(String, Temporarily);
	free(Temporarily);
	return String;
}
void RemoveCharFunction(char *String, char CharToCheckOn)
{
	int i,j;
	i = 0;
	while(String[i] != '\0')
	{
		if (String[i] == CharToCheckOn) 
		{ 
			j = i;
			while (String[j] != '\0')
			{
				String[j] = String[j+1];   
				j++;
			}
		} 
		else 
			i++;
	}
}
