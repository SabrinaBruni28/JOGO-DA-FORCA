#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/*Tamanho das palavras.*/
#define WORD 50
/*Tamanho da matriz da forca.*/
#define TAM 7 

/*TAD que armazena a matriz da forca, o estado em que se encontra o boneco e o tema da forca.*/
typedef struct{
    char matriz[TAM][TAM];
    int estado;
    char tema[20];
}Forca;

/*Funcao que inicializa a forca quanto a parte em que o boneco fica pendurado.*/
void Inicia_Forca(Forca* forc);
/*Funcao que Printa a Forca.*/
void Print_Forca(Forca* forc);
/*Funcao que adiciona uma parte do corpinho cada vez que se era uma letra.*/
void Adiciona_Corpinho(Forca* forc);
/*Funcao que confere se o boneco foi enforcado e o usuario perdeu.
  Retorna 1 se perdeu e 0 caso contrario.*/
int Perdeu(Forca* forc);