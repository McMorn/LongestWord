#include "resolution.h"



Words analyzeWords()
{
    char word[256];
    Words properties;

    properties.amount = 0;
    properties.length = 0;

    fseek(inputFile, 0, SEEK_SET);

    while(fscanf(inputFile, "%s", word) != EOF) /**< Petla przeszukujaca plik do jego konca */
    {
        if(strlen(word) > properties.length) /**< Jezeli znajdzie nowe dluzsze slowo */
        {
            properties.length = strlen(word);
            properties.amount = 1;
        }
        else if(strlen(word)==properties.length) /**< Jezeli znajdzie slowo o takiej samej dlugosci */
        {
            properties.amount++;
        }
    }

    return properties;
}



Words findWords(Words words)
{
    int i,j,cmp;
    char word[256];


    words.enumeration = malloc(words.amount * sizeof(char*));
    for(i=0; i<words.amount; i++)
        words.enumeration[i] = malloc((words.length + 1) * sizeof(char*)); /**< Utworzenie tablicy dla znalezionych slow */

    fseek(inputFile, 0, SEEK_SET);
    i = 0;

    while(fscanf(inputFile, "%s", word) != EOF)
    {
        if(strlen(word) == words.length) /**<  Warunek wpisania slowa do tablicy */
        {
            strcpy(words.enumeration[i], word);
            i++;
        }
    }

    /* Sortowanie tablicy */
    for(j=0; j<words.amount; j++)
        for(i=0; i<words.amount - 1; i++)
    {
        cmp = strcmp(words.enumeration[i],words.enumeration[i+1]);
        if(cmp > 0)
        {
            strcpy(word, words.enumeration[i+1]);
            strcpy(words.enumeration[i+1], words.enumeration[i]);
            strcpy(words.enumeration[i], word);
        }
    }

    return words;
}
