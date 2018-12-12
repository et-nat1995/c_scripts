#include <stdio.h>
#include <math.h>

#define PI 3.14

void remove_spaces (char *, char *);
int  countlines    (char *);
int  letter_freq   (char *, int count[26]);

int main()
{
    int count;
    int cnt[26] = {0};
    int i, max;
    
    printf("%d", '^'+'^');
    
    
    double in;
    double (*pf)(double);
    
    scanf("%lf", &in);
    
    if(in == 0)
        pf = sin;
    else
        pf = cos;
    
    for(in = 0; in <= PI; in+=0.1)
        printf("%lf\n", (*pf)(in));
    
    remove_spaces("input.txt", "output.txt");
    
    printf("The amount lines in the file is: %d\n", count = countlines("input.txt"));
    
    max = letter_freq("input.txt", cnt);
    
    printf("The letter %c Appears the most amount of times.\n", (char)max + 'A');
    for(i = 0; i < 26; i++)
    {
        printf("%c Aprears: %d\n", (char)i + 'A', cnt[i]);
    }
        
    
    return 0;
}

void remove_spaces(char *infile, char *outfile)
{
    FILE *f_IN  = fopen(infile, "r");
    FILE *f_OUT = fopen(outfile, "w");
    char ch;
    
    ch = fgetc(f_IN);
    
    while(ch != EOF)
    {
        if(ch != ' ')
            fputc(ch, f_OUT);
        ch = fgetc(f_IN);
    }
    
    fclose(f_IN);
    fclose(f_OUT);
    
}

int countlines(char *file)
{
    int     counter = 0;
    FILE    *f_OPEN = fopen(file, "r");
    char    ch;
    
    ch = fgetc(f_OPEN);
    
    while(ch != EOF)
    {
        if(ch == '\n')
            counter++;
        
        ch = fgetc(f_OPEN);
    }
    
    fclose(f_OPEN);
    
    return counter;
}

int letter_freq(char *file, int count[26])
{
    FILE *f_IN = fopen(file, "r");
    char ch;
    int max, i;
    
    ch = fgetc(f_IN);
    
    while(ch != EOF)
    {
        if( ch >= 'a' && ch <= 'z')
        {
            count[ch - 'a']++;
        }
        else
        {
            count[ch - 'A']++;
        }
        ch = fgetc(f_IN);
    }
    
    max = count[0];
    
    for(i= 0; i < 26; i++)
    {
        if( max < count[i])
            max = i;
    }
    
    
    fclose(f_IN);
    
    return max;
}

