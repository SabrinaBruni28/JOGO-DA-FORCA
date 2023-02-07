#include "palavra.h"

void Categoria(){
    int i;
    printf("\n# Qual tema?\n");
    printf("\n1- Filme  2- Animais  3- Objetos\n4- Series  5- Frutas  6- Vegetais\n");
    scanf("%d",&i);
    switch (i){
        case 1:
            strcpy(texto,"Categorias/filmes.txt");
            qual = FILME;
            strcpy(nome, "FILME");
            break;
        case 2:
            strcpy(texto,"Categorias/animais.txt");
            qual = ANIMAIS;
            strcpy(nome, "ANIMAIS");
            break;
        case 3:
            strcpy(texto,"Categorias/objetos.txt");
            qual = OBJETOS;
            strcpy(nome, "OBJETOS");
            break;
        case 4:
            strcpy(texto,"Categorias/series.txt");
            qual = SERIES;
            strcpy(nome, "SERIES");
            break;
        case 5:
            strcpy(texto,"Categorias/frutas.txt");
            qual = FRUTAS;
            strcpy(nome, "FRUTAS");
            break;
        case 6:
            strcpy(texto,"Categorias/vegetais.txt");
            qual = VEGETAIS;
            strcpy(nome, "VEGETAIS");
            break;
        default:
            break;
    }
}

int Inicializa_Arquivo(FILE* arquivo, Palavra* palav){
    Categoria();
    arquivo = fopen(texto, "r");
    if(arquivo == NULL) return 0;
    Sorteia_Palavra(arquivo,palav);
    Inicializa_Tracinho(palav);
    fclose(arquivo);
}

void Inicializa_Letras(Palavra* palav){
    palav->letras[0] = '\0';
    palav->i = 0;
}

void Inicializa_Tracinho(Palavra* palav){
    int i;
    for(i=0;i<strlen(palav->palavra);i++){
        if(palav->palavra[i] == ' ')
            palav->tracinho[i] = ' ';
        /*else if(palav->palavra[i] == '\n'){
            palav->tracinho[i] = '\0';
            palav->palavra[i] = '\0';
        }*/
        else 
            palav->tracinho[i] = '-';
    }
    //palav->palavra[i] = '\0';
    //palav->tracinho[i] = '\0';
    Inicializa_Letras(palav);
}

void Sorteia_Palavra(FILE* arquivo, Palavra* palav){
    int numero=0, cont=0;
    char string[WORD];
    srand( (unsigned)time(NULL) );
    while(numero==0){
        numero = rand()%qual;
    }
    fflush(arquivo);
    while(cont < numero){
        fgets(string,WORD, arquivo);
        //fscanf(arquivo, "%s ", string);
        cont++;
    }
    string[strlen(string)-1] = '\0';
    strcpy(palav->palavra, string);
}

void Adiciona_Letra(Palavra* palav, char letra){
    if(Ja_foi_Letra(palav, letra)){
        palav->letras[palav->i] = letra;
        palav->i++;
        palav->letras[palav->i] = '\0';
    }
}


void Print_Palavra(Palavra* palav){
    int i;
    printf("%s \n", palav->palavra);
    printf("\t%s \n\n", palav->tracinho);
    printf("Letras Ja Escolhidas: ");
    for(i=0; i<strlen(palav->letras);i++){
        if(i==strlen(palav->letras)-1) printf("%c", palav->letras[i]);
        else printf("%c - ", palav->letras[i]);
    }
    printf("\n\n");
}

int Tenta_Letra(Palavra* palav,Forca* forc, char letra){
    if((Ja_foi_Letra(palav, letra)) && (Existe_Letra(palav, letra))){
        if(Letra_ja_Aberta(palav, letra)){
            Adiciona_Letra(palav, letra);
            printf("\n****** NAO POSSUI A LETRA %c ******\n", letra);
            Adiciona_Corpinho(forc);
        }
        return 1;
    }
    return 0;
}
 
int Tenta_Palavra(Palavra* palav, char* string){
    if(Palavra_Certa(palav, string)){
        Revela_Palavra(palav);
        Ganhou(palav);
        return 1;
    }
    else printf("\nVOCE ERROU !!!\n");
    return 0;
}

int Existe_Letra(Palavra* palav, char letra){
    int i, cont = 0;
    for(i=0; i<strlen(palav->palavra); i++){
        if((toupper(palav->palavra[i])) == (toupper(letra))){
            Revela_Letra(palav, i);
            cont++;
        }
    }
    if(cont==0) return 1;
    return 0;
}

void Revela_Letra(Palavra* palav, int i){
    palav->tracinho[i] = palav->palavra[i];
}

int Palavra_Certa(Palavra* palav, char* string){
    int i;
    for(i=0; i<strlen(palav->tracinho); i++){
        if(palav->palavra[i] != string[i]) return 0;
    }
    //if(strcmp(palav->palavra, string)) return 1;
    return 1;
}

void Revela_Palavra(Palavra* palav){
    strcpy(palav->tracinho, palav->palavra);
}

int Ja_foi_Letra(Palavra* palav, char letra){
    int i, cont=0;
    for(i=0; i<strlen(palav->letras); i++){
        if(toupper(palav->letras[i]) == toupper(letra)) cont++;
    }
    if(cont==0) return 1;
    printf("\n****** LETRA JA ESCOLHIDA !!! *******\n");
    return 0;
}

int Letra_ja_Aberta(Palavra* palav, char letra){
    int i, cont=0;
    for(i=0; i<strlen(palav->tracinho); i++){
        if(toupper(palav->tracinho[i]) == toupper(letra)) cont++;
    }
    if(cont==0) return 1;
    printf("\n****** LETRA JA ABERTA !!! ******\n");
    return 0;
}

int Ganhou(Palavra* palav){
    int i, cont=0;
    for(i=0; i<strlen(palav->tracinho); i++){
        if(palav->tracinho[i] != '-') cont++;
    }
    if(cont == strlen(palav->tracinho)) {
        printf("\n****** VOCE GANHOU !!!! *****\n");
        return 1;
    }
    return 0;
}