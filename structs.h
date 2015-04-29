/* structs.h */
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inputFile, *outputFile;

typedef struct
{
    char *inputFilePath;
    char *outputFilePath;
} Paths;

typedef struct
{
    int howMany;
    int length;
} PropertiesWords;


#endif /* STRUCTS_H_INCLUDED */
