#include "jogo.h"


int Comeco(){
    int i;
    printf("**********************************************************************************\n");
    printf("\t######### FORCA ##########\n");
    printf("\n1- Jogar\n2- Sair\n");
    scanf("%d",&i);
    if(i==1) return 1;
    printf("**********************************************************************************\n");
    return 0;
}
int Final(){
    int i;
    printf("\n1- Jogar Novamente\n2- Sair\n");
    scanf("%d",&i);
    if(i==1) return 1;
    printf("**********************************************************************************\n");
    return 0;
}

int Opcao(){
    int i; 
    printf("1- Letra  2- Palavra\n");
    scanf("%d",&i);
    return i+1;
}


int main(){
    Jogo jog;
    Forca forc;
    Palavra palav;
    FILE* arquivo;
    int estado;
    char letra, palavra[WORD];
    estado = Comeco();
    while(estado){
        switch (estado){
            case 1:
                Inicia_Forca(&forc);
                Inicializa_Arquivo(arquivo,&jog, &palav, &forc);
                Print_Forca(&forc);
                Print_Jogo(&jog);
                estado = Opcao();
                break;
            case 2:
                getchar();
                printf("# Escolha uma letra: ");
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
            case 3:
                getchar();
                printf("# Qual e a Palavra: ");
                fgets(palavra, WORD, stdin);
                Elinima_Final(palavra);
                if(Tenta_Jogo(&jog, &palav, palavra)) estado = 4;
                Print_Forca(&forc);
                Print_Jogo(&jog);
                if(estado!=4) estado = Opcao();
                break;
            case 4:
                estado = Final();
                break;
        }
    }
    return 0;
}