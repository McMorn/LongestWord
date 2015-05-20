/* structs.h */
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inputFile, *outputFile;


typedef struct
{
    int amount;
    int length;
    char **enumeration;
} Words;


#endif /* STRUCTS_H_INCLUDED */
