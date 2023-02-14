#include "jogo.h"


int Inicializa_Arquivo(FILE* arquivo, Jogo* jog, Palavra* palav, Forca* forc){
    Categoria(palav, forc);
    arquivo = fopen(palav->texto, "r");
    if(arquivo == NULL){
        printf("\033[1;31m**** FALHA AO ABRIR ARQUIVO ****\n\033[m");
        return 0;
    }
    Sorteia_Palavra(arquivo,palav);
    Inicializa_Tracinho(jog, palav);
    fclose(arquivo);
    return 1;
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
    printf("\033[1;37m\t%s \n\n\033[m", jog->tracinho);
    printf("\033[1;33mLetras Ja Escolhidas: \033[m");
    for(i=0; i<strlen(jog->letras);i++){
        if(i==strlen(jog->letras)-1) printf("\033[1m%c\033[m", jog->letras[i]);
        else printf("\033[1m%c - \033[m", jog->letras[i]);
    }
    printf("\n\n");
}


int Tenta_Letra(Jogo* jog, Palavra* palav, Forca* forc, char letra){
    if(Ja_foi_Letra(jog, letra)){
        if(Letra_ja_Aberta(jog, letra) && Existe_Letra(jog, palav, letra)){
            Adiciona_Letra(jog, letra);
            printf("\n\033[1;31m****** NAO POSSUI A LETRA %c ******\n\033[m", letra);
            Adiciona_Corpinho(forc);
        }
        return 1;
    }
    return 0;
}
 
int Tenta_Jogo(Jogo* jog, Palavra* palav, char* string, Forca* forc){
    Elinima_Final(string);
    if(Palavra_Certa(palav, string)){
        Revela_Jogo(jog, palav);
        Ganhou(jog);
        return 1;
    }
    else printf("\n\033[1;31m**** VOCE ERROU !!! ****\033[m\n");
    Adiciona_Corpinho(forc);
    return 0;
}
void Revela_Letra(Jogo* jog, Palavra* palav, int i){
    jog->tracinho[i] = palav->palavra[i];
}

void Revela_Jogo(Jogo* jog, Palavra* palav){
    strcpy(jog->tracinho, palav->palavra);
}

int Ja_foi_Letra(Jogo* jog, char letra){
    int i;
    for(i=0; i<strlen(jog->letras); i++){
        if(toupper(jog->letras[i]) == toupper(letra)){
            printf("\n\033[1;31m****** LETRA JA ESCOLHIDA !!! *******\033[m\n");
            return 0;
        }
    }
    return 1;
}

int Letra_ja_Aberta(Jogo* jog, char letra){
    int i;
    for(i=0; i<strlen(jog->tracinho); i++){
        if(toupper(jog->tracinho[i]) == toupper(letra)){
            printf("\n\033[1;31m****** LETRA JA ABERTA !!! ******\n\033[m");
            return 0;
        } 
    }
    return 1;
    
}

int Ganhou(Jogo* jog){
    int i, cont=0;
    for(i=0; i<strlen(jog->tracinho); i++){
        if(jog->tracinho[i] != '-') cont++;
    }
    if(cont == strlen(jog->tracinho)) {
        printf("\n\033[1;32m****** VOCE GANHOU !!!! *****\033[m\n");
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