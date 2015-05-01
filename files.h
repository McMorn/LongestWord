#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include "structs.h"


void initProgram(int paramSize, char* param[]);

void writeToFile(char** listOfWords);

int closeFiles();

#endif /* FILES_H_INCLUDED */
