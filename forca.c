#include "forca.h"

void Inicia_Forca(Forca* forc){
    int i,j;
    forc->estado = 0;
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
                forc->matriz[i][j] = ' ';
                forc->matriz[i][0] = '|';
        }
    }

    forc->matriz[1][4] = '|'; // acima da cabeca
    forc->matriz[0][0] = '_'; /*topo da forca*/
    forc->matriz[0][1] = '_';
    forc->matriz[0][2] = '_';
    forc->matriz[0][3] = '_';
    forc->matriz[0][4] = '_';
}

void Print_Forca(Forca* forc){
    int i,j;
    printf("\n\n");
    printf("\033[1;35m----\033[m \033[1;4m%s\033[m \033[1;35m-----\n\033[m", forc->tema);
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            if(forc->matriz[i][j] == '@') printf("\033[1;31m%c \033[m", forc->matriz[i][j]);
            else if(forc->matriz[i][j] == '_' || forc->matriz[i][j] == '|' && j==0 || j==4 && i==1) printf("\033[1;34m%c \033[m", forc->matriz[i][j]);
            else if(forc->matriz[i][j] == 'O' || forc->matriz[i][j] == '/' || forc->matriz[i][j] == '\\' || forc->matriz[i][j] == '|') printf("\033[1m%c \033[m", forc->matriz[i][j]);
            else  printf("%c ", forc->matriz[i][j]);
        }
        printf("\n");
    }

}

void Adiciona_Corpinho(Forca* forc){
    if(forc->estado==0){
        forc->matriz[2][4] = 'O'; // cabeca
        forc->estado+=1;
    }
    else if(forc->estado==1){
        forc->matriz[3][4] = '|'; // corpo1
        forc->estado+=1;
    }
    else if(forc->estado==2){
        forc->matriz[4][4] = '|'; // corpo2
        forc->estado+=1;
    }
    else if(forc->estado==3){
        forc->matriz[3][3] = '/'; // braco esquerdo
        forc->estado+=1;
    }
    else if(forc->estado==4){
        forc->matriz[3][5] = '\\'; // braco direito
        forc->estado+=1;
    }
    else if(forc->estado==5){
        forc->matriz[5][3] = '/'; // perna esquerda
        forc->estado+=1;
    }
    else if(forc->estado==6){
        forc->matriz[5][5] = '\\'; // perna direita
        forc->estado+=1;
    }
    else if(forc->estado==7){
        forc->matriz[2][4] = '@'; // morreu
        forc->estado=0;
    }
}

int Perdeu(Forca* forc){
    if(forc->matriz[2][4] == '@'){
        printf("\n\033[1;31m***** VOCE PERDEU *****\033[m\n");
        return 1;
    }
    return 0;
}

