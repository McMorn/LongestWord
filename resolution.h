#ifndef RESOLUTION_H_INCLUDED
#define RESOLUTION_H_INCLUDED

#include "structs.h"


/**
 * Funkcja analizuje s³owa znalezione w pliku, poszukuje najdluzszego oraz ilosci jego wystapien
 */
Words analyzeWords();

/**
 * Funkcja tworzy tablice o wymiarach najdluzsze slowo na ilosc wystapien
 * Wymiary otrzymuje w strukturze przekazanej w parametrze
 * Zapisuje do utworzonej tablicy znalezione slowa i sortuje
 */
Words findWords(Words words);


#endif /* RESOLUTION_H_INCLUDED */
