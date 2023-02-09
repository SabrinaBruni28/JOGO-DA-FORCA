#include "forca.h"

#define FILME 80
#define ANIMAIS 80
#define OBJETOS 21
#define FRUTAS_VEGETAIS 80
#define SERIES 80

typedef struct{
    char palavra[WORD];
    char texto[WORD];
    int tamanho;
}Palavra;

void Categoria(Palavra* palav, Forca* forc);
void Inicializa_Palavra(Palavra* palav);
void Sorteia_Palavra(FILE* arquivo, Palavra* palav);
void Elinima_Final(char*  vetor);
char* Toupper_Vetor(char* string, int tam);
int Palavra_Certa(Palavra* palav, char* string);
void Printa_Palavra(Palavra* palav);