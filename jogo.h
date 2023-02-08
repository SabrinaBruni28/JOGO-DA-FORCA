#include "palavra.h"


typedef struct{
    char tracinho[WORD];
    char letras[26];
    int i;
}Jogo;


int Inicializa_Arquivo(FILE* arquivo, Jogo* jog, Palavra* palav, Forca* forc);
void Inicializa_Letras(Jogo* jog);
void Zera_Tracinho(Jogo* jog);
void Inicializa_Tracinho(Jogo* jog, Palavra* palav);
void Print_Jogo(Jogo* jog);
void Adiciona_Letra(Jogo* jog, char letra);
int Tenta_Letra(Jogo* jog, Palavra* palav, Forca* forc,char letra);
int Tenta_Jogo(Jogo* jog, Palavra* palav, char* string);
void Revela_Letra(Jogo* jog, Palavra* palav, int i);
void Revela_Jogo(Jogo* jog, Palavra* palav);
int Ja_foi_Letra(Jogo* jog, char letra);
int Letra_ja_Aberta(Jogo* jog, char letra);
int Ganhou(Jogo* jog);
int Existe_Letra(Jogo* jog, Palavra* palav, char letra);