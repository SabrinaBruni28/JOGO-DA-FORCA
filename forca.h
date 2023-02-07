#include <stdio.h>
#include <stdlib.h>

#define TAM 7 

typedef struct{
    char matriz[TAM][TAM];
}Forca;

void Inicia_Forca(Forca* forc);
void Print_Forca(Forca* forc);
void Adiciona_Corpinho(Forca* forc);
void Perdeu(Forca* forc);