#include <stdio.h>

int Fact(int n)
{
    if(n <= 1)
        return 1;
    return n * Fact(n-1);
}

double power(double base, int Pow)
{
    if(Pow == 0)
        return 1;
    return base * power(base, Pow - 1);
}

void UpDown(int sides)
{
    printf("%d\t", sides);
    if(sides == 1)
        printf("%d\t", sides);
    else
    {
        printf("%d\t", sides);
        UpDown(sides-1);
        printf("%d\t", sides);
    }
    
}



int main()
{
    int n, Pow, up;
    double base;
    printf("Give me a numebr a mate\n");
    scanf("%d", &n);
    printf("%d\n", Fact(n));
    
    printf("Give mw another bumber and what power you want it to...\n");
    scanf("%lf %d", &base, &Pow);
    printf("%.0lf\n", power(base, Pow));
    
    printf("Give me a number to count down to\n");
    scanf("%d", &up);
    if(up == 0)
        printf("0 \n");
    if(up < 0)
        printf("no good mate \n");
    else{
        UpDown(up);
    }
    
}
