#include "files.h"


Paths findPaths(int paramSize, char* param[])
{
    int i;
    Paths path;

    for(i=0; i<paramSize; i++)
    {
        if(strcmp(param[i],"-i")==0)
        {
            path.inputFilePath = malloc(strlen(param[i+1]));
            path.inputFilePath = param[i+1];
        }
        if(strcmp(param[i],"-o")==0)
        {
            path.outputFilePath = malloc(strlen(param[i+1]));
            path.outputFilePath = param[i+1];
        }
    }

    return path;
}


void openFiles(Paths path)
{
    if((inputFile=fopen(path.inputFilePath,"rt"))==NULL)
    {
        printf("Blad otwarcia pliku!\n");
        exit(0);
    };

    if((outputFile=fopen(path.outputFilePath,"wt"))==NULL)
    {
        printf("Blad otwarcia pliku!\n");
        exit(0);
    }
}


void writeToFile(char** listOfWords)
{
    int i;
    unsigned howMany = sizeof(listOfWords) / sizeof(char);

    for(i=0; i<howMany; i++)
        fprintf(outputFile, "%s\n", listOfWords[i]);
}


int closeFiles()
{
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
