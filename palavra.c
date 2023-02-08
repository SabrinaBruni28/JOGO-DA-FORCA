#include "palavra.h"

void Categoria(Palavra* palav, Forca* forc){
    int i;
    printf("\n# Qual tema?\n");
    printf("\n1- Filme  2- Animais  3- Objetos\n4- Series  5- Frutas  6- Vegetais\n");
    scanf("%d",&i);
    switch (i){
        case 1:
            strcpy(palav->texto,"Categorias/filmes.txt");
            palav->tamanho = FILME;
            strcpy(forc->nome, "FILME");
            break;
        case 2:
            strcpy(palav->texto,"Categorias/animais.txt");
            palav->tamanho = ANIMAIS;
            strcpy(forc->nome, "ANIMAIS");
            break;
        case 3:
            strcpy(palav->texto,"Categorias/objetos.txt");
            palav->tamanho = OBJETOS;
            strcpy(forc->nome, "OBJETOS");
            break;
        case 4:
            strcpy(palav->texto,"Categorias/series.txt");
            palav->tamanho = SERIES;
            strcpy(forc->nome, "SERIES");
            break;
        case 5:
            strcpy(palav->texto,"Categorias/frutas.txt");
            palav->tamanho = FRUTAS;
            strcpy(forc->nome, "FRUTAS");
            break;
        case 6:
            strcpy(palav->texto,"Categorias/vegetais.txt");
            palav->tamanho = VEGETAIS;
            strcpy(forc->nome, "VEGETAIS");
            break;
        default:
            break;
    }
}

void Inicializa_Palavra(Palavra* palav){
    int i;
    for(i=0; i<WORD; i++)
        palav->palavra[i] = '\0';
}

void Sorteia_Palavra(FILE* arquivo, Palavra* palav){
    int numero=0, cont=0;
    char string[WORD];
    Inicializa_Palavra(palav);
    srand( (unsigned)time(NULL) );
    while(numero==0){
        numero = rand()%palav->tamanho;
    }
    fflush(arquivo);
    while(cont < numero){
        fgets(string,WORD, arquivo);
        //fscanf(arquivo, "%s ", string);
        cont++;
    }
    Elinima_Final(string);
    strcpy(palav->palavra, string);
}

void Elinima_Final(char*  vetor){
    int i;
    for(i=0; vetor[i]; i++) 
        if(vetor[i]=='\n') 
            vetor[i]='\0';
}


int Palavra_Certa(Palavra* palav, char* string){
    int i;
    for(i=0; i<strlen(palav->palavra); i++){
        if(palav->palavra[i] != string[i]) return 0;
    }
    return 1;
}


void Printa_Palavra(Palavra* palav){
    printf("%s \n", palav->palavra);
}