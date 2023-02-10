#include "Jogo/jogo.h"

/*Funcao que printa uma sequencia de asteriscos.*/
void Asterisco(){
    printf("\033[1;33m**********************************************************************************\n\033[m");
}

/*Funcao que comeca o jogo e pergunta se quer jogar ou sair.
  Retorna 1 caso o usuario queira jogar e 0 caso contrario.*/
int Comeco(){
    int i;
    Asterisco();
    printf("\t\033[1;35m######### FORCA ##########\n\033[m");
    printf("\n\033[1m1- Jogar\n2- Sair\n\033[m");
    scanf("%d",&i);
    if(i==1) return 1;
    Asterisco();
    return 0;
}

/*Funcao que finaliza o jogo e pergunta se quer jogar novamente ou sair.
  Retorna 1 caso o usuario queira jogar novamente e 0 caso contrario.*/
int Final(){
    int i;
    printf("\n\033[1;35m**** FIM DE JOGO ****\n\033[m");
    printf("\n\033[1m1- Jogar Novamente\n2- Sair\n\033[m");
    scanf("%d",&i);
    if(i==1) return 1;
    Asterisco();
    return 0;
}

/*Funcao que pergunta se quer escrever uma letra ou a plavra se uma de vez.
  Retorna a opcao +1 ou 4 caso seja um numero invalido, finalizando a jogada.*/
int Opcao(){
    int i; 
    printf("\033[1;34m1- Letra  2- Palavra\n\033[m");
    scanf("%d",&i);
    if(i==1 || i==2) return i+1;
    else printf("\n\033[1;31mNumero invalido\n\033[m");
    return 4;
}

/*Funcao principal que interage com o usuario, conectando tudo.*/
int main(){
    Jogo jog;
    Forca forc;
    Palavra palav;
    FILE* arquivo;
    int estado;
    char letra, palavra[WORD];
    estado = Comeco();
    /*Looping que mantem o jogo ativo ate que se queira sair.*/
    while(estado){
        /*Estrutura condicional que entra em qual estado o jogo se encontra.*/
        switch (estado){
            case 1:
            /*Inicio do jogo.*/
                Inicia_Forca(&forc);
                if(!Inicializa_Arquivo(arquivo,&jog, &palav, &forc)){
                    Asterisco();
                    return 1;
                }
                Print_Forca(&forc);
                Print_Jogo(&jog);
                estado = Opcao();
                break;
            /*Esolher uma letra.*/
            case 2:
                getchar();
                printf("\033[1;4;37m# Escolha uma letra: \033[m");
                scanf("%c", &letra);
                Tenta_Letra(&jog, &palav, &forc, letra);
                if(Perdeu(&forc) || Ganhou(&jog)){
                    estado = 4;
                    Revela_Jogo(&jog, &palav);
                }
                Print_Forca(&forc);
                Print_Jogo(&jog);
                if(estado!=4) estado = Opcao();
                break;
            /*Escolher uma palavra.*/
            case 3:
                getchar();
                printf("\033[1;4;37m# Qual e a Palavra: \033[m");
                fgets(palavra, WORD, stdin);
                if(Tenta_Jogo(&jog, &palav, palavra)) estado = 4;
                Print_Forca(&forc);
                Print_Jogo(&jog);
                if(estado!=4) estado = Opcao();
                break;
            /*Final do jogo.*/
            case 4:
                estado = Final();
                break;
        }
    }
    return 0;
}