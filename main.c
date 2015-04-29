#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "resolution.h"
#include "files.h"


int main(int argc, char *argv[])
{
    openFiles(findPaths(argc, argv));

    writeToFile(findWords(analyzeWords()));


    return 0;
}
