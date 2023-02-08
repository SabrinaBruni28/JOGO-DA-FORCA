#include "forca.h"

#define FILME 21
#define ANIMAIS 22
#define OBJETOS 21
#define FRUTAS 21
#define SERIES 22
#define VEGETAIS 13

typedef struct{
    char palavra[WORD];
    char texto[WORD];
    int tamanho;
}Palavra;

void Categoria(Palavra* palav, Forca* forc);
void Inicializa_Palavra(Palavra* palav);
void Sorteia_Palavra(FILE* arquivo, Palavra* palav);
void Elinima_Final(char*  vetor);
int Palavra_Certa(Palavra* palav, char* string);
void Printa_Palavra(Palavra* palav);