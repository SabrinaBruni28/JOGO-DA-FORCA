#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define WORD 50
#define TAM 7 

int q;
char texto[50];
int qual;
char nome[20];

typedef struct{
    char matriz[TAM][TAM];
}Forca;

void Inicia_Forca(Forca* forc);
void Print_Forca(Forca* forc);
void Adiciona_Corpinho(Forca* forc);
int Perdeu(Forca* forc);