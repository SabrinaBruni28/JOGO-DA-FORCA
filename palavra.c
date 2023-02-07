#include "palavra.h"

int Inicializa_Arquivo(FILE* arquivo, Palavra* palav){
    arquivo = fopen("filmes.txt", "r");
    if(arquivo == NULL) return 0;
    Sorteia_Palavra(arquivo,palav);
    fclose(arquivo);
}


void Sorteia_Palavra(FILE* arquivo, Palavra* palav){
    int numero, cont=1;
    srand( (unsigned)time(NULL) );
    numero = rand()%TAM;
    printf("%d ",numero);
    while(cont < numero){
        fgets(arquivo, WORD, stdin);
        cont++;
    }
    strcpy(&palav->palavra, fgets(arquivo, WORD, stdin));
    printf("%s ", palav->palavra);
}