#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include "structs.h"


Paths findPaths(int paramSize, char* param[]);

void openFiles(Paths path);

void writeToFile(char** listOfWords);

int closeFiles();

#endif /* FILES_H_INCLUDED */
