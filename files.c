#include "files.h"


void initProgram(int paramSize, char* param[])
{
    int i;

    for (i=0; i<paramSize; i++)
    {
        if(strcmp(param[i],"-h") == 0) /**< Wywolanie programu z opcja -h (help) */
        {
            printf("Porogram powinien byc wywolany z opcjami\n");
            printf("program.exe -i <sciezka do pliku wejsciowego> -o <sciezka do pliku wyjsciowego>\n");
            exit(0);
        }

        if(strcmp(param[i],"-i") == 0) /**< Opcja do podania pliku wejsciowego */
            if((inputFile = fopen(param[i+1],"rt")) == NULL)
            {
                printf("Blad otwarcia pliku %s!\n", param[i+1]);
                exit(0);
            };

        if(strcmp(param[i],"-o") == 0) /**< Opcja do podania pliku wyjsciowego */
            if((outputFile = fopen(param[i+1],"wt")) == NULL)
            {
                printf("Blad otwarcia pliku %s!\n", param[i+1]);
                exit(0);
            }
    }

    if(paramSize < 5)
    {
        printf("Wpisz \"<program.exe> -h\" aby uzyskac pomoc.\n");
        exit(0);
    }
}


void writeToFile(Words words)
{
    int i;

    for(i=0; i<words.amount; i++) /**< Petla zapisujaca do pliku wyjsciowego slowa z posortowanej tablicy */
        fprintf(outputFile, "%s\n", words.enumeration[i]);
}


int closeFiles()
{
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
