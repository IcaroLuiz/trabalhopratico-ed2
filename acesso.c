#include <stdio.h>
#include <stdlib.h>
#include "acesso.h"

void acesso_sequencial(int quantidade_itens){
    FILE *arquivo;
    int total_seila = (quantidade_itens+100) / ITENSPAGINA;
    Indice *tabela = malloc(total_seila * sizeof(Indice));
    Registro *memoria_principal = malloc(ITENSPAGINA * sizeof(Registro));
    
    int posicao = 0, contador = 0;


    if((arquivo = fopen("arquivo_gerado.bin", "rb")) == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n\n");
        return;
    }

    while(fread(memoria_principal, sizeof(Registro), 4, arquivo) == 4){
        tabela[posicao].chave = memoria_principal[0].chave;
        posicao++;
    }

    for(int i = 0; i < total_seila;i++){

    }





}