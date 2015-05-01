#include "files.h"


void initProgram(int paramSize, char* param[])
{
    int i;

    for (i=0; i<paramSize; i++)
    {
        if(strcmp(param[i],"-i") == 0)
            if((inputFile = fopen(param[i+1],"rt")) == NULL)
            {
                printf("Blad otwarcia pliku %s!\n", param[i+1]);
                exit(0);
            };

        if(strcmp(param[i],"-o") == 0)
            if((outputFile = fopen(param[i+1],"wt")) == NULL)
            {
                printf("Blad otwarcia pliku %s!\n", param[i+1]);
                exit(0);
            }
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
