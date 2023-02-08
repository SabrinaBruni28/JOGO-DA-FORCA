#include "jogo.h"


int Inicializa_Arquivo(FILE* arquivo, Jogo* jog, Palavra* palav, Forca* forc){
    Categoria(palav, forc);
    arquivo = fopen(palav->texto, "r");
    if(arquivo == NULL) return 0;
    Sorteia_Palavra(arquivo,palav);
    Inicializa_Tracinho(jog, palav);
    fclose(arquivo);
}

void Inicializa_Letras(Jogo* jog){
    jog->letras[0] = '\0';
    jog->i = 0;
}

void Zera_Tracinho(Jogo* jog){
    int i;
    for(i=0; i<WORD; i++)
        jog->tracinho[i] = '\0';
}

void Inicializa_Tracinho(Jogo* jog, Palavra* palav){
    int i;
    Zera_Tracinho(jog);
    for(i=0;i<strlen(palav->palavra);i++){
        if(palav->palavra[i] == ' ')
            jog->tracinho[i] = ' ';
        else 
            jog->tracinho[i] = '-';
    }
    Elinima_Final(palav->palavra);
    Elinima_Final(jog->tracinho);
    Inicializa_Letras(jog);
}


void Adiciona_Letra(Jogo* jog, char letra){
    if(Ja_foi_Letra(jog, letra)){
        jog->letras[jog->i] = letra;
        jog->i++;
        jog->letras[jog->i] = '\0';
    }
}


void Print_Jogo(Jogo* jog){
    int i;
    printf("\t%s \n\n", jog->tracinho);
    printf("Letras Ja Escolhidas: ");
    for(i=0; i<strlen(jog->letras);i++){
        if(i==strlen(jog->letras)-1) printf("%c", jog->letras[i]);
        else printf("%c - ", jog->letras[i]);
    }
    printf("\n\n");
}


int Tenta_Letra(Jogo* jog, Palavra* palav, Forca* forc, char letra){
    if((Ja_foi_Letra(jog, letra)) && (Existe_Letra(jog, palav, letra))){
        if(Letra_ja_Aberta(jog, letra)){
            Adiciona_Letra(jog, letra);
            printf("\n****** NAO POSSUI A LETRA %c ******\n", letra);
            Adiciona_Corpinho(forc);
        }
        return 1;
    }
    return 0;
}
 
int Tenta_Jogo(Jogo* jog, Palavra* palav, char* string){
    if(Palavra_Certa(palav, string)){
        Revela_Jogo(jog, palav);
        Ganhou(jog);
        return 1;
    }
    else printf("\nVOCE ERROU !!!\n");
    return 0;
}
void Revela_Letra(Jogo* jog, Palavra* palav, int i){
    jog->tracinho[i] = palav->palavra[i];
}

void Revela_Jogo(Jogo* jog, Palavra* palav){
    strcpy(jog->tracinho, palav->palavra);
}

int Ja_foi_Letra(Jogo* jog, char letra){
    int i, cont=0;
    for(i=0; i<strlen(jog->letras); i++){
        if(toupper(jog->letras[i]) == toupper(letra)) cont++;
    }
    if(cont==0) return 1;
    printf("\n****** LETRA JA ESCOLHIDA !!! *******\n");
    return 0;
}

int Letra_ja_Aberta(Jogo* jog, char letra){
    int i, cont=0;
    for(i=0; i<strlen(jog->tracinho); i++){
        if(toupper(jog->tracinho[i]) == toupper(letra)) cont++;
    }
    if(cont==0) return 1;
    printf("\n****** LETRA JA ABERTA !!! ******\n");
    return 0;
}

int Ganhou(Jogo* jog){
    int i, cont=0;
    for(i=0; i<strlen(jog->tracinho); i++){
        if(jog->tracinho[i] != '-') cont++;
    }
    if(cont == strlen(jog->tracinho)) {
        printf("\n****** VOCE GANHOU !!!! *****\n");
        return 1;
    }
    return 0;
}

int Existe_Letra(Jogo* jog, Palavra* palav, char letra){
    int i, cont = 0;
    for(i=0; i<strlen(palav->palavra); i++){
        if((toupper(palav->palavra[i])) == (toupper(letra))){
            Revela_Letra(jog, palav, i);
            cont++;
        }
    }
    if(cont==0) return 1;
    return 0;
}