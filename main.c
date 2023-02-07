#include "forca.h"
#include "palavra.h"


int main(){
    Forca forc;
    int i;
    Inicia_Forca(&forc);
    Print_Forca(&forc);
    for(i=0;i<8;i++){
        Adiciona_Corpinho(&forc);
        Print_Forca(&forc);
    }
    return 0;
}