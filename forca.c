#include "forca.h"

void Inicia_Forca(Forca* forc){
    int i,j;
    q = 0;
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
    printf("---- %s -----\n", nome);
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            printf("%c ", forc->matriz[i][j]);
    }
        printf("\n");
    }

}

void Adiciona_Corpinho(Forca* forc){
    if(q==0){
        forc->matriz[2][4] = 'O'; // cabeca
        q+=1;
    }
    else if(q==1){
        forc->matriz[3][4] = '|'; // corpo1
        q+=1;
    }
    else if(q==2){
        forc->matriz[4][4] = '|'; // corpo2
        q+=1;
    }
    else if(q==3){
        forc->matriz[3][3] = '/'; // braco esquerdo
        q+=1;
    }
    else if(q==4){
        forc->matriz[3][5] = '\\'; // braco direito
        q+=1;
    }
    else if(q==5){
        forc->matriz[5][3] = '/'; // perna esquerda
        q+=1;
    }
    else if(q==6){
        forc->matriz[5][5] = '\\'; // perna direita
        q+=1;
    }
    else if(q==7){
        forc->matriz[2][4] = '@'; // morreu
        q=0;
    }
}

int Perdeu(Forca* forc){
    if(forc->matriz[2][4] == '@'){
        printf("\n***** VOCE PERDEU *****\n");
        return 1;
    }
    return 0;
}

