#include <stdio.h>
#include <stdlib.h>
#include "acesso.h"

void acesso_sequencial(int quantidade_itens){
    FILE *arquivo;
    Indice *tabela = malloc(quantidade_itens * sizeof(Indice));


    if((arquivo = fopen("arquivo_gerado.bin", "rb")) == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n\n");
        return;
    }




}