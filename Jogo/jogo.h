#include "../Palavra/palavra.h"

/*TAD que armazena os tracinho da adivinhacao, uma lista das letras ja escolhidas erradas e a posicao dessa lista.*/
typedef struct{
    char tracinho[WORD];
    char letras[26];
    int i;
}Jogo;

/*Funcao que abre o arquivo escolhido e chama as outras funcoes que compoem o jogo.
  Retorna 1 caso der certo e 0 caso de erro no arquivo.*/
int Inicializa_Arquivo(FILE* arquivo, Jogo* jog, Palavra* palav, Forca* forc);
/*Funcao que inicializa a lista de letras escolhidas erradas.*/
void Inicializa_Letras(Jogo* jog);
/*Funcao que zera a string de tracinho dos jogo.
  Para nao sobrepor um sobre o outro e der erro de palavra.*/
void Zera_Tracinho(Jogo* jog);
/*Funcao que onde da palavra possue letra fique um tracinho e chama a inicializa letras.*/
void Inicializa_Tracinho(Jogo* jog, Palavra* palav);
/*Funcao que printa o jogo em acao jogo, ou seja, os tracinho e as letras ja escolhidas.*/
void Print_Jogo(Jogo* jog);
/*Funcao que adiciona uma letra na lista de letras ja escolhidas.*/
void Adiciona_Letra(Jogo* jog, char letra);
/*Funcao que testa se a letra escolhida ja foi na lista, ja foi nos tracinho e se ela existe na palavra a ser adivinhada.
  Retorna 1 caso a letra nao tenha sido escolhida e zero caso ja.*/
int Tenta_Letra(Jogo* jog, Palavra* palav, Forca* forc,char letra);
/*Funcao em que o usuario tenta adivinha a palavra direto.
  Coferindo se a palavra e a certa ou nao.
  Retorna 1 caso seja a palavra certa e 0 caso nao seja.*/
int Tenta_Jogo(Jogo* jog, Palavra* palav, char* string, Forca* forc);
/*Funcao que iguala o tracinho de uma posicao a palavra.
  Revelando a letra.*/
void Revela_Letra(Jogo* jog, Palavra* palav, int i);
/*Funcao que iguala os tracinhos a palavra.
  Revelando a palavra.*/
void Revela_Jogo(Jogo* jog, Palavra* palav);
/*Funcao que confere se a letra ja existe na lista de letras ja escolhidas.
  Ou seja, o usuario ja escolheu e era errada.
  Retorna 1 caso nao exista e 0 caso exista.*/
int Ja_foi_Letra(Jogo* jog, char letra);
/*Funcao que confere a letra escolhida ja foi aberta nos tracinhos.
  Retorna 0 caso tenha aberto e 1 caso contrario.*/
int Letra_ja_Aberta(Jogo* jog, char letra);
/*Funcao que confere se todos os tracinhos foram revelados e a pessoas ganhou.
  Retorna 1 caso tenha ganhado e 0 caso contrario.*/
int Ganhou(Jogo* jog);
/*Funcao que confere se existe determinada letra na palavra.
  Se houver ela revela todas as letras e retorna 0.
  Se nao houver retorna 1.*/
int Existe_Letra(Jogo* jog, Palavra* palav, char letra);