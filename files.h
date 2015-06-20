#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include "structs.h"

/**
 * Inicjacja programu:
 * Proba otwarcia plikow lub wyswietlenie pomocy
 */
void initProgram(int paramSize, char* param[]);


/**
 * Zapisanie slow z tablicy do pliku wyjsciowego
 */
void writeToFile(Words words);


/**
 * Zamkniecie plikow przed koncem pracy programow
 */
int closeFiles();

#endif /* FILES_H_INCLUDED */
