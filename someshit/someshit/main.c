#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Ex1();
int *createArray(int *n);
void printArray(int *arr,int n);
void makeItProper(int *arr,int length);

void Ex2();
int subtractSections(int a, int b);

void Ex3();
void pascalTriagnel(int n);
void lineCalculation(int i);
void print_pascal_line(int i, int n);

void Ex4();
void calculateBetrothedNumbers(int Number);
int dividorsSum(int Number);

void Ex5();
double Newton_Raphson (double x, double n);

int main()
{
    int select=0, i, all_Ex_in_loop=0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enterother number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do
        {
            for (i=1; i<=5; i++)
                printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select=0;
                printf("please select 0-5 : ");
                scanf("%d",&select);
            } while ((select<0)||(select>5));
            switch (select) {
                case 1:
                {
                    Ex1();
                    break;
                }
                case 2:
                {
                    Ex2();
                    break;
                }
                case 3:
                {
                    Ex3();
                    break;
                }
                case 4:
                {
                    Ex4();
                    break;
                }
                case 5:
                {
                    Ex5();
                    break;
                }
            }
        } while (all_Ex_in_loop && select);
    return 0;
}

void Ex1()
{
    int *arr,length;
    arr = createArray(&length);
    printArray(arr,length);
    makeItProper(arr,length);
    printArray(arr,length);
    free(arr);
}
int *createArray(int *n)
{
    int *arr, i;
    printf ("Insert array length: ");
    scanf ("%d",n);
    arr = (int*)malloc((*n)*sizeof(int));
    for (i = 0; i < *n; i++)
    {
        printf ("Insert value to array at location '%d': ",i);
        scanf ("%d",&arr[i]);
    }
    return arr;
}
void printArray(int *arr,int n)
{
    int i;
    for (i=0;i<n;i++)
        printf ("[%d] ",arr[i]);
    printf ("\n\n");
}
void makeItProper(int *arr,int length)
{
    int i, Sum;
    Sum = 0;
    for (i=0;i<length;i++)
    {
        Sum = Sum + arr[i];
        arr[i] = Sum;
    }
}


void Ex2()
{
    int a, b, result;
    printf ("Insert value for 'A': ");
    scanf ("%d",&a);
    printf ("Insert value for 'B': ");
    scanf ("%d",&b);
    if (a<b)
    {
        result = subtractSections(a, b);
        printf ("Result is: %d.\n",result);
    }
    else
        printf ("Wrong parameters.\n");
}
int subtractSections(int a, int b)
{
    int sequenceNumbers, Counter1, Counter2, Equation;
    Counter1 = 0;
    Counter2 = 0;
    Equation = (a+b)/2;
    printf ("Insert numbers, to stop insert '-1'.\n");
    printf ("Insert number: ");
    scanf ("%d",&sequenceNumbers);
    while (sequenceNumbers != -1)
    {
        if ( (Equation < sequenceNumbers) && (sequenceNumbers < b) )
            Counter1 = Counter1 + sequenceNumbers;
        if ( (a < sequenceNumbers) && (sequenceNumbers < Equation) )
            Counter2 = Counter2 + sequenceNumbers;
        printf ("Insert number: ");
        scanf ("%d",&sequenceNumbers);
    }
    return Counter1 - Counter2;
}



void Ex3()
{
    int Number;
    printf ("Insert number: ");
    scanf ("%d",&Number);
    pascalTriagnel(Number);
}
//The funcation gets parameter and builds pascal tringle (parameter lines).
void pascalTriagnel(int n)
{
    int i;
    print_pascal_line(0,n);
    printf ("1\n\n\n");
    for (i=1;i<=n;i++)
    {
        print_pascal_line(i,n);
        printf ("1    ");
        lineCalculation(i);
        printf ("\n\n\n");
    }
}
//The funcation is calculating the exact number it should get at pascal_tringle.
void lineCalculation(int i)
{
    int num=1, j;
    for (j=1;j<=i;j++)
    {
        num=num*(i-(j-1))/j;
        printf ("%d     ",num);
    }
}
//The funcation is making pascal tringle to lNk better by using spaces.
void print_pascal_line(int i, int n)
{
    int j;
    for(j=i;j<=n;j++)
    {
        printf("   ");
    }
}



void Ex4()
{
    int Number;
    printf ("Insert number: ");
    scanf ("%d",&Number);
    calculateBetrothedNumbers(Number);
}
void calculateBetrothedNumbers(int Number)
{
    int i, Calculate1, Calculate2, Temp=0;
    for (i=1;i<=Number;i++)
    {
        Calculate1 = dividorsSum(i);
        Calculate2 = dividorsSum(Calculate1-1);
        if (i == Calculate2-1)
        {
            printf ("(%d,%d)\n",Calculate2-1, Calculate1-1);
        }
        
    }
}
int dividorsSum(int Number)
{
    int i, Sum;
    Sum = 0;
    for (i=1;i<Number;i++)
    {
        if (Number%i==0)
            Sum = Sum + i;
    }
    return Sum;
}


void Ex5()
{
    double x, n, result;
    printf ("Insert 'x' value: ");
    scanf ("%lf",&x);
    printf ("Insert 'n' value: ");
    scanf ("%lf",&n);
    result = Newton_Raphson(x,n);
    printf ("Result: %lf.\n",result);
}
double Newton_Raphson (double x, double n)
{
    double insideEquation, Temp;
    insideEquation = x*x;
    insideEquation = insideEquation - n;
    insideEquation = insideEquation / (2*x);
    insideEquation = x - insideEquation;
    Temp = fabs(insideEquation - x);
    if (Temp<=0.00001)
        return insideEquation;
    return Newton_Raphson(insideEquation,n);
}
