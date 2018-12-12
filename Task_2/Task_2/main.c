

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void EX_1();
char **Matrix_String(char *str,int *size,char letter);
void freeString(char **matSTR,int size);
void printMatStr(char **matSTR, int size);

void EX_2();
char *removeStuff(char *str);

void EX_3();
char commonLetter(char *filename);

void EX_4();
void lowerLetter(char *str);

void EX_5();
void SizeCalc(char *key , int multi , char *filename);
void string_splitter(char *str , char *filename);
void printFile(char *filename);

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
                case 1: EX_1(); break;
                case 2: EX_2(); break;
                case 3: EX_3(); break;
                case 4: EX_4(); break;
                case 5: EX_5(); break;
            }
        } while (all_Ex_in_loop && select);
}

void EX_1()
{
    char str[] = "Rony Goodman got a good mark"; // str[120] if using gets
    char **matStr;
    char ch;
    int  size = 0;
    /*
     printf("Please enter a string: ");
     gets(str);
     */
//    flushall();
    printf("Please enter a letter: ");
    ch = getchar();
    
    matStr = Matrix_String(str, &size, ch);
    printMatStr(matStr, size);
    freeString(matStr, size);
    
}

char **Matrix_String(char *str,int *size,char letter)
{
    int  count   = 0;
    int  i       = 0;
    int  j       = 0;
    int  k       = 0;
    int  temp;
    char **arr, Capital, LowerC;
    
    if(letter >= 'A' && letter <= 'Z')
    {
        Capital     = letter;
        LowerC      = letter + 32;
    }
    if(letter >= 'a' && letter <= 'z')
    {
        Capital     = letter - 32;
        LowerC      = letter;
    }
    
    if(str[0] == LowerC || str[0] == Capital)
    {
        count++;
    }
    
    while(str[i] != '\0')
    {
        if((str[i] == LowerC || (str[i] == Capital)) && str[i-1] == ' ')
            count++;
        i++;
    }
    
    (*size)         = count;
    i               = 0;
    arr             = (char**)malloc(count*sizeof(char*));
    
    if(str[0] == LowerC || str[0] == Capital)
    {
        while(str[i] != ' ')
        {
            j++;
            i++;
        }
        
        arr[k]      = (char*)malloc((j+1)*sizeof(char));
        j           = 0;
        i           = 0;
        
        while(str[i] != ' ')
        {
            arr[k][j] = str[i];
            j++;
            i++;
        }
        arr[k][j] = '\0';
        k++;
    }
    
    while(str[i] != '\0')
    {
        if((str[i] == LowerC || (str[i] == Capital)) &&str[i-1] == ' ')
        {
            j       = 0;
            temp    = i;
            
            while(str[i] != ' ')
            {
                j++;
                i++;
            }
            
            arr[k] = (char*)malloc((j+1)*sizeof(char));
            i      = temp;
            j      = 0;
            
            while(str[i] != ' ')
            {
                arr[k][j] = str[i];
                j++;
                i++;
            }
            arr[k][j] = '\0';
            k++;
            
        }
        i++;
    }
    return arr;
}
void freeString(char **matSTR,int size)
{
    int i;
    
    for(i=0;i<size;i++)
        free(matSTR[i]);
    
    free(matSTR);
}

void printMatStr(char **matSTR, int size)
{
    int i;
    for(i = 0; i < size; i++)
        puts(matSTR[i]);
    
}


void EX_2()
{
    char str[50];
    char *newstr;
    
//    flushall();
    
    printf("Please enter a string:\n");
    gets(str);
    
    newstr = removeStuff(str);
    
    puts(newstr);
    free(newstr);
}
//function that removes everything excepts letters

char *removeStuff(char *str)
{
    int  temp;
    int  i;
    int  j		= 0;
    int  count	= 0;
    char *str_new;
    
    str_new		= (char*)malloc(strlen(str) * sizeof(char));
    
    for(i = 0; i < strlen(str); i++)
    {
        if ((str[i]== ' ') || ((str[i]>47) && (str[i]<58)))
            count++;
        else
        {
            str_new[j]=str[i];
            j++;
        }
        
    }
    
    str_new[j]	= '\0';
    temp		= strlen(str) + 1 - count;
    str_new		= (char*)realloc(str_new,sizeof(char)*temp);
    
    return str_new;
}

void EX_3()
{
    char ch;
    
    ch = commonLetter("filename.txt");
    
    printf("The most common letter in the file is: %c\n", ch);
}
//takes in a file and starts an array counteer and each iteration get another letter from the file and counts it, then finds the max and returns the letter that appears the most amount of times.
char commonLetter(char *filename)
{
    FILE  *f_IN         = fopen(filename, "r");
    int   count[26]     = {0};
    int   max           =  0;
    int   i, letter;
    char  ch;
    
    assert(f_IN);
    
    ch = fgetc(f_IN);
    
    while(ch != EOF)
    {
        if( ch >= 'a' && ch <= 'z')
        {
            count[ch - 'a']++;
        }
        else if( ch >= 'A' && ch <= 'Z')
        {
            count[ch - 'A']++;
        }
        ch = fgetc(f_IN);
    }
    
    max = count[0];
    
    for(i = 0; i < 26; i++)
    {
        if(max <= count[i])
        {
            max     = count[i];
            letter  = i;
        }
    }
    
    fclose(f_IN);
    
    return letter + 'A';
}

void EX_4()
{
    char str[] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";
    puts(str);
    lowerLetter(str);
    puts(str);
}
//Function that takes in a string and each time its not a ' ' it will minus that counter from that possition in the string if it is a space then reset the counter.
void lowerLetter(char *str)
{
    int i       = 0;
    int counter = 1;
    
    while(str[i] != '\0')
    {
        if(str[i] == ' ')
            counter = 1;
        else
        {
            str[i] = str[i] - counter;
            counter++;
        }
        
        i++;
    }
    
}

void EX_5()
{
    char str[120];
    char *f_IN = "Ex5.txt";
    
//    flushall();
    
    printf("Please define your variables:\n");
    gets(str);
    puts(str);
    
    string_splitter(str, f_IN);
    printFile(f_IN);
}

// fucntion that checks what the paramater type is, int, long, double, char, etc. Then sends it to a different function to find the proper size.
void string_splitter(char *str , char *filename)
{
    char *key;
    int  i;
    int  num        = 0;
    char Thelong[6] = "long " ;
    
    key = strtok (str, " ,");
    
    switch (*key)
    {
        case 'i' :	num     = sizeof(int);
            break ;
            
        case 's' :	num     = sizeof(short);
            break ;
            
        case 'c' :	num     = sizeof(char);
            break ;
            
        case 'l' :	num     = sizeof(long long);
            
            for(i=5;str[i-1] != ' ' && str[i] != '*' ;i++)
            {
                if(Thelong[i-5] != str[i] )
                {
                    num     = sizeof(long);
                    key     = key - 5;
                    i       = -2;
                    break;
                }
            }
            i != -2 ? key = strtok(NULL," ,[];") : 0 ;
            key = key + 5;
            break ;
            
        case 'f' :	num = sizeof(float);
            break ;
            
        case 'd' : 	num = sizeof(double);
            break ;
            
    }
    
    SizeCalc (key ,num ,filename);
    return;
}

void SizeCalc(char *key , int multi , char *filename)
{
    int i;
    int num = 1 , flag = 0;
    int ans = multi * num;
    FILE *f_IN;
    
    //  asserting that the file opened if it didnt open then to exit the function.
    f_IN = fopen (filename,"w");
    assert(f_IN);
    
    for (i = 0 ; key[i] != ' ' && key[i] != '\0' ;i++)
        if (key[i] == '*')
            flag = 1 ;
    
    key = strtok(NULL," *,[];");
    
    while( key != NULL )
    {
        fprintf(f_IN," %-6s requires ",key);
        //        Looks for a pointer and sets off a flag if one is found
        for(i = -1; (key[i] <= 'a' || key[i] >= 'z' ) && (key[i] <= 'A' || key[i] >= 'Z') && ( key[i] <= '0' || key[i] >= '9' ); i--)
            if(key[i] == '*')
            {
                flag = 1;
                break;
            }
        
        key = strtok(NULL," *,[];");
        //        Checks to see if there are [] and if so what number is between then then converts it to an int with atoi
        if ((key != NULL) && (flag == 0))
        {
            if(*key >= '0' && *key <= '9' )
            {
                num     = atoi(key);
                key     = strtok(NULL," *,[];");
            }
        }
        //      If flag = 0 then the current variable isnt a pointer.
        if (flag == 0)
            ans         = multi*num;
        else
            ans         = 4;
        
        fprintf(f_IN,"%d bytes \n", ans);
        flag    = 0;
        num     = 1;
        ans     = multi * num;
    }
    
    fclose(f_IN);
    
}

//Helper function to print whats in the file so you wont have to open it you could if you want to.
void printFile(char *filename)
{
    FILE *f_IN;
    char ch;
    
    f_IN    = fopen(filename,"r");
    
    assert(f_IN);
    
    ch      = fgetc(f_IN);
    
    while(ch  != EOF)
    {
        printf("%c",ch);
        ch  = fgetc(f_IN);
    }
    
    fclose (f_IN);
    return;
    
}
