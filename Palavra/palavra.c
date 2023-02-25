#include "palavra.h"

void Categoria(Palavra* palav, Forca* forc){
    int i;
    getchar();
    printf("\n\033[1;4m# Qual tema?\n\033[m");
    printf("\n\033[1m1- Filme  2- Animais  3- Objetos\n4- Series  5- Frutas e Vegetais\n\033[m");
    scanf("%d",&i);
    switch (i){
        case 1:
            strcpy(palav->texto,"Categorias/filmes.txt");
            palav->tamanho = FILME;
            strcpy(forc->tema, "FILME");
            break;
        case 2:
            strcpy(palav->texto,"Categorias/animais.txt");
            palav->tamanho = ANIMAIS;
            strcpy(forc->tema, "ANIMAIS");
            break;
        case 3:
            strcpy(palav->texto,"Categorias/objetos.txt");
            palav->tamanho = OBJETOS;
            strcpy(forc->tema, "OBJETOS");
            break;
        case 4:
            strcpy(palav->texto,"Categorias/series.txt");
            palav->tamanho = SERIES;
            strcpy(forc->tema, "SERIES");
            break;
        case 5:
            strcpy(palav->texto,"Categorias/frutas_vegetais.txt");
            palav->tamanho = FRUTAS_VEGETAIS;
            strcpy(forc->tema, "FRUTAS e VEGETAIS");
            break;
        default:
             printf("\n\033[1;31mDigite um numero valido nas opcoes\n\033[m");
             Categoria(palav, forc);
            break;
    }
}

void Zera_Palavra(Palavra* palav){
    int i;
    for(i=0; i<WORD; i++)
        palav->palavra[i] = '\0';
}

void Sorteia_Palavra(FILE* arquivo, Palavra* palav){
    int numero=0, cont=0;
    char string[WORD];
    Zera_Palavra(palav);
    srand( (unsigned)time(NULL) );
    while(numero==0){
        numero = rand()%palav->tamanho;
    }
    fflush(arquivo);
    while(cont < numero){
        fgets(string,WORD, arquivo);
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

char* Toupper_Vetor(char* string, int tam){
    int i;
    char* vetor= (char*)malloc(sizeof(char)*tam);
    strcpy(vetor, string);
    for(i=0;i<tam;i++){
        vetor[i] = toupper(string[i]);
    }
    return vetor;
}

int Palavra_Certa(Palavra* palav, char* string){
    int i;
    if(strcmp(Toupper_Vetor(palav->palavra, strlen(palav->palavra)), Toupper_Vetor(string, strlen(string))) == 0) return 1;
    return 0;
}


void Printa_Palavra(Palavra* palav){
    printf("%s \n", palav->palavra);
}
