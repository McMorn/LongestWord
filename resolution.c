#include "resolution.h"


PropertiesWords analyzeWords()
{
    char word[256];
    PropertiesWords properties;

    properties.howMany = 0;
    properties.length = 0;

    fseek(inputFile, 0, SEEK_SET);

    while(feof(inputFile) == 0)
    {
        fscanf(inputFile, "%s", word);

        if(strlen(word) > properties.length)
        {
            properties.length = strlen(word);
            properties.howMany = 1;
        }
        else if(strlen(word)==properties.length)
        {
            properties.howMany++;
        }
    }

    return properties;
}


char** findWords(PropertiesWords prop)
{
    int i,j,cmp;
    char word[256];
    char **listOfWords;

    listOfWords = malloc(prop.howMany * sizeof(char*));
    for(i=0; i<prop.howMany; i++)
        listOfWords[i] = malloc((prop.length+1) * sizeof(char*));

    fseek(inputFile, 0, SEEK_SET);
    i = 0;

    while(feof(inputFile) == 0)
    {
        fscanf(inputFile, "%s", word);

        if(strlen(word) == prop.length)
        {
            strcpy(listOfWords[i], word);
            i++;
        }
    }

    /* Sorting */

    for(j=0; j<prop.howMany; j++)
        for(i=0; i<prop.howMany-1; i++)
        {
            cmp = strcmp(listOfWords[i],listOfWords[i+1]);
            if(cmp > 0)
            {
                strcpy(word, listOfWords[i+1]);
                strcpy(listOfWords[i+1], listOfWords[i]);
                strcpy(listOfWords[i], word);
            }
        }

    return listOfWords;
}
