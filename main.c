#include "forca.h"
#include "palavra.h"


int main(){
    Forca forc;
    int i, j;
    Inicia_Forca(&forc);
    Print_Forca(&forc);
    j=0;
    for(i=0;i<8;i++){
        Adiciona(&forc, &j);
        Print_Forca(&forc);
    }
    return 0;
}