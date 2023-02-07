#include "palavra.h"


int Comeco(){
    int i;
    printf("1- Jogar\n2- Sair\n");
    scanf("%d",&i);
}
int main(){
    Forca forc;
    Palavra palav;
    int i;
    char letra;
    FILE* arquivo;
   
    switch (i){
        case 1:
            Inicia_Forca(&forc);
            Inicializa_Arquivo(arquivo,&palav);
            break;
        
        default:
            break;
    }
    while(1){
        printf("Escolha uma letra: ");
        scanf("%c", &letra);
        Tenta_Letra(&palav,&forc, letra);
        Print_Forca(&forc);
        Print_Palavra(&palav);
        getchar();
    }
    return 0;
}