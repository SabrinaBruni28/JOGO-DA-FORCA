#include "forca.h"

typedef struct{
    char palavra[WORD];
    char tracinho[WORD];
    char letras[26];
    int i;
}Palavra;

void Categoria();
int Inicializa_Arquivo(FILE* arquivo, Palavra* palav);
void Inicializa_Tracinho(Palavra* palav);
void Sorteia_Palavra(FILE* arquivo, Palavra* palav);
void Print_Palavra(Palavra* palav);
void Adiciona_Letra(Palavra* palav, char letra);
int Tenta_Letra(Palavra* palav, Forca* forc,char letra);
int Tenta_Palavra(Palavra* palav, char* string);
int Existe_Letra(Palavra* palav, char letra);
void Revela_Letra(Palavra* palav, int i);
int Palavra_Certa(Palavra* palav, char* string);
void Revela_Palavra(Palavra* palav);
int Ja_foi_Letra(Palavra* palav, char letra);
int Letra_ja_Aberta(Palavra* palav, char letra);