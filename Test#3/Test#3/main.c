#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void swap(int *, int *);

void Ex1();

int *input_array(int *);
void print_array(int *, int);
void arr_Seg(int *, int);

void Ex2();

int digits(int num);
int alt_sum(int num);
void check_eleven(int num);

int main()
{
    Ex1();
    printf("\n");
    Ex2();
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Ex1()
{
    int *arr, size;
    
    arr = input_array(&size);
    
    printf("Array Before: ");
    print_array(arr, size);
    
    printf("Array After: ");
    arr_Seg(arr, size);
    
    free(arr);
}

int *input_array(int *size)
{
    int i, *arr;
    
    printf("Please enter the size of the Array: ");
    scanf("%d", size);
    
    arr = (int*)malloc(*size*sizeof(int));
    
    for(i = 0; i < *size; i++) {
        printf("Enter value for Array postion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
        
    return arr;
}

void print_array(int *arr, int size)
{
    int i;
    
    for(i = 0; i < size; i++)
        printf("[%d] ", arr[i]);
    printf("\n");
}

void arr_Seg(int *arr, int size)
{
    int left = 0, right = size - 1;
    
    while( left < right ) {
        
        while(arr[left] %2 != 0 && left < right)
            left++;
        
        while(arr[right]%2 == 0 && left < right)
            right--;
        
        if(left < right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
    print_array(arr, size);
}

void Ex2()
{
    int num, sum;
    
    printf("Please enter a number: ");
    scanf("%d", &num);
    if(num <= 0)
        printf("Wrong Input.\n");
    else {
        sum = abs(alt_sum(num));
        check_eleven(sum);
    }
    
}

int digits(int num)
{
    int count = 0;
    
    while(num) {
        count++;
        num /= 10;
    }
    return count;
}

int alt_sum(int num)
{
    int expo, sum = 0;
    
    expo = digits(num) - 1;
    
    if(expo >= 0)
        sum += (pow(-1, expo-1)*(num%10) + alt_sum(num/10));
    return sum;
}

void check_eleven(int num)
{
    int check;
    
    if(num > 10 || num == 0) {
        check = alt_sum(num);
        if(check == 0)
            printf("The Number is divisable by 11.\n");
        else
            printf("The Number is not divisable by 11.\n");
    }
    if(num <= 10 && num > 0)
        printf("The Number is not divisable by 11.\n");
}



