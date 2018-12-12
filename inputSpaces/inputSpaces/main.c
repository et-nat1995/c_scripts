//
//  main.c
//  inputSpaces
//
//  Created by Tamir Natanov on 8/1/18.
//  Copyright © 2018 Tamir Natanov. All rights reserved.
//

void inputSpaces(char *, char *, int*);

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int spacesAdded;
    
    inputSpaces("inPutFile.txt", "outPutFile.txt", &spacesAdded);
    printf("Spaces Added: %d\n", spacesAdded);
    return 0;
}

void inputSpaces(char *inFile, char *outFile, int *spaces)
{
    FILE *f_IN = fopen(inFile, "r"),
            *f_OUT = fopen(outFile, "w");
    char point;
    
    point = fgetc(f_IN);
    
    while(point != EOF)
    {
        if(point == ',') {
            fputc(point, f_OUT);
            fputc(' ', f_OUT);
            (*spaces)++;
        }
        else
            fputc(point, f_OUT);
        point = fgetc(f_IN);
        
    }
    
    fclose(f_OUT);
    fclose(f_IN);
}
