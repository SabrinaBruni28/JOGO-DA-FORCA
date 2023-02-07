#include "palavra.h"


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
int main(){
    Forca forc;
    Palavra palav;
    int estado;
    char letra;
    char palavra1[WORD] = {"Melancia e bom"};
    char palavra2[WORD];
    scanf("%s",palavra2);
    printf("%d\n", strcmp(palavra1, palavra2));
    FILE* arquivo;
   /* estado = Comeco();
    while(estado){
        switch (estado){
            case 1:
                Inicia_Forca(&forc);
                Inicializa_Arquivo(arquivo,&palav);
                Print_Forca(&forc);
                Print_Palavra(&palav);
                estado = 3;
                break;
            case 2:
                getchar();
                printf("# Escolha uma letra: ");
                scanf("%c", &letra);
                Tenta_Letra(&palav, &forc, letra);
                if(Perdeu(&forc) || Ganhou(&palav)){
                    estado = 4;
                    Revela_Palavra(&palav);
                }
                Print_Forca(&forc);
                Print_Palavra(&palav);
                break;
            case 3:
                //getchar();
                printf("# Qual e a Palavra: ");
                scanf("%s", palavra);
                if(Tenta_Palavra(&palav, palavra)) estado = 4;
                Print_Forca(&forc);
                Print_Palavra(&palav);
                break;
            case 4:
                estado = Final();
                break;
        }
    }*/
    return 0;
}