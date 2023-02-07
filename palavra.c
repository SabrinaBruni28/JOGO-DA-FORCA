#include "palavra.h"

void Categoria(){
    int i;
    printf("Qual tema?\n");
    printf("1- Filme  2- Animais  3- Objetos\n4- Series  5- Frutas\n");
    scanf("%d",&i);
    switch (i){
        case 1:
            strcpy(texto,"filmes.txt");
            qual = FILME;
            break;
        case 2:
            strcpy(texto,"filmes.txt");
            qual = FILME;
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

void Inicializa_Tracinho(Palavra* palav){
    int i;
    for(i=0;i<strlen(palav->palavra);i++){
        if(palav->palavra[i] == ' ')
            palav->tracinho[i] = ' ';
        else if(palav->palavra[i] == '\n'){
            palav->tracinho[i] = '\0';
            palav->palavra[i] = '\0';
        }
        else 
            palav->tracinho[i] = '-';
    }
    palav->palavra[i] = '\0';
    palav->tracinho[i] = '\0';
    palav->letras[0] = '\0';
    palav->i = 0;
    Print_Palavra(palav);
}

void Sorteia_Palavra(FILE* arquivo, Palavra* palav){
    int numero=0, cont=0;
    char string[WORD];
    srand( (unsigned)time(NULL) );
    while(numero==0){
        numero = rand()%qual;
        printf("%d ",numero);
    }
    fflush(arquivo);
    while(cont < numero){
        fgets(string,WORD, arquivo);
        //fscanf(arquivo, "%s ", string);
        cont++;
    }
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
    printf("%s \n", palav->palavra);
    printf("%s \n", palav->tracinho);
    printf("%s \n", palav->letras);
}

int Tenta_Letra(Palavra* palav,Forca* forc, char letra){
    if((Ja_foi_Letra(palav, letra)) && (Existe_Letra(palav, letra))){
        if(Letra_ja_Aberta(palav, letra)){
            Adiciona_Letra(palav, letra);
            printf("\nNAO POSSUI A LETRA %c\n", letra);
            Adiciona_Corpinho(forc);
        }
        return 1;
    }
    return 0;
}
 
int Tenta_Palavra(Palavra* palav, char string[WORD]){
    if(Palavra_Certa(palav, string)){
        Revela_Palavra(palav);
        printf("\nVOCE ACERTOU !!!!\n");
    }
    else printf("\nVOCE ERROU !!!\n");
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

int Palavra_Certa(Palavra* palav, char string[WORD]){
    if(strcmp(palav->palavra, string) == 0) return 1;
    return 0;
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
    printf("\nLETRA JA ESCOLHIDA !!!\n");
    return 0;
}

int Letra_ja_Aberta(Palavra* palav, char letra){
    int i, cont=0;
    for(i=0; i<strlen(palav->tracinho); i++){
        if(toupper(palav->tracinho[i]) == toupper(letra)) cont++;
    }
    if(cont==0) return 1;
    printf("\nLETRA JA ABERTA !!!\n");
    return 0;
}