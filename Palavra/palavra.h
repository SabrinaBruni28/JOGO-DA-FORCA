#include "../Forca/forca.h"

/*Quantidade de palavras no arquivo de cada categoria.*/
#define FILME 80
#define ANIMAIS 80
#define OBJETOS 21
#define FRUTAS_VEGETAIS 80
#define SERIES 80

/*TAD que possue a palavra sorteada, o arquivo de texto e o quantidade de palavra.*/
typedef struct{
    char palavra[WORD];
    char texto[WORD];
    int tamanho;
}Palavra;

/*Funcao que o usuario escolhe o tema/categoria do jogo.*/
void Categoria(Palavra* palav, Forca* forc);
/*Funcao que zera a palavra, para nao ocorrer erro na hora de sobrepor.*/
void Zera_Palavra(Palavra* palav);
/*Funcao que sorteia um numero e percorre o arquivo do tema escolhida ate esse numero, sendo a palavra nessa linha a escolhida.
  Atribuindo a palavra escolhida o TAD.*/
void Sorteia_Palavra(FILE* arquivo, Palavra* palav);
/*Funcao que elimina o \n do final das strings e substitui por \0.*/
void Elinima_Final(char*  vetor);
/*Funcao que deixa um vetor todo em maiusculo.
  Retornando a nova string maiuscula.*/
char* Toupper_Vetor(char* string, int tam);
/*Funcao que confere se uma palavra e igual a palavra sorteada.
  Ou seja, se o usuario acertou ou nao.
  Retorna 1 caso seja igual e 0 caso contrario.*/
int Palavra_Certa(Palavra* palav, char* string);
/*Funcao que printa a palvra.
  Usada somente para teste.*/
void Printa_Palavra(Palavra* palav);