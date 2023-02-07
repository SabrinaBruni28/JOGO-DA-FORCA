#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD 50
#define TAM 21

typedef struct{
    char palavra[WORD];
}Palavra;

int Inicializa_Arquivo(FILE* arquivo, Palavra* palav);
void Sorteia_Palavra(FILE* arquivo, Palavra* palav);