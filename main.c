#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("%s\t%s\n%s\t%s\n\n", argv[1],argv[2],argv[3],argv[4]);

    /***
      * Wykrycie podanych sciezek plikow
      **/
    int i;
    char in[100], out[100];

    for(i=1; i<argc; i++)
    {
        if(strcmp(argv[i],"-i")==0)
            strcpy(in,argv[i+1]);
        if(strcmp(argv[i],"-o")==0)
            strcpy(out,argv[i+1]);
    }
    printf("%s\t%s\n\n", in, out);    /**< Wypisuje odczytane sciezki */

    /***
      * Pliki
      **/
    FILE *input, *output;

    if((input=fopen(in,"rt"))==NULL)
        printf("Blad otwarcia pliku!\n");

    if((output=fopen(out,"wt"))==NULL)
        printf("Blad otwarcia pliku!\n");


    char napis[256];
    int ile = 0;
    int dlugosc = 0;


    while(feof(input)==0)
    {
        fscanf(input, "%s", napis);

        if(strlen(napis) > dlugosc)
        {
            dlugosc = strlen(napis);
            ile = 1;
        }
        else if (strlen(napis) == dlugosc)
        {
            ile++;
        }
        printf("%s\t%d\n", napis, strlen(napis));
    }
    printf("\n%d\t%d\n\n", ile, dlugosc);

    fseek(input, 0, SEEK_SET);

    char tab[ile][256];
    i = 0;

    while(feof(input)==0)
    {
        fscanf(input, "%s", napis);

        if(strlen(napis) == dlugosc)
        {
            strcpy(tab[i],napis);
            i++;
        }
    }

    for(i=0; i<ile; i++)
        printf("%s\n", tab[i]);

    int j,cmp;
    char temp[1][256];

    for(j=0; j<ile; j++)
        for(i=0; i<ile-1; i++)
        {
            cmp = strcmp(tab[i],tab[i+1]);
            if(cmp>0)
            {
                strcpy(temp[0],tab[i+1]);
                strcpy(tab[i+1],tab[i]);
                strcpy(tab[i],temp[0]);
            }
        }


    for(i=0; i<ile; i++)
        fprintf(output, "%s\n", tab[i]);


    fclose(input);
    fclose(output);


    return 0;
}
