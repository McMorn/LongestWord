/* structs.h */
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inputFile, *outputFile;


typedef struct
{
    int amount; /**< przechowuje ilosc znalezionych slow */
    int length; /**< przechowuje dlugosc najdluzszego slowa */
    char **enumeration; /**< tablica 2D do ktorej zostana zapisane znalezione slowa */
} Words;


#endif /* STRUCTS_H_INCLUDED */
