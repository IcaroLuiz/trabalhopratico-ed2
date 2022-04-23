#include <stdio.h>
#include <stdlib.h>
#include "acesso.h"

int pesquisa_as(Indice *tabela, int tamanho, Registro *item, FILE *arquivo){
    Registro pagina[ITENSPAGINA];
    int quantidade_itens, i = 0;
}


void acesso_sequencial(int quantidade_itens){
    FILE *arquivo;
    int total_seila = (quantidade_itens+100) / ITENSPAGINA;
    Indice *tabela = malloc(total_seila * sizeof(Indice));
    Registro *memoria_principal = malloc(ITENSPAGINA * sizeof(Registro));
    Registro dado;
    int posicao = 0, contador = 0;


    if((arquivo = fopen("arquivo_gerado.bin", "rb")) == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n\n");
        return;
    }

    while(fread(memoria_principal, sizeof(Registro), 4, arquivo) == 4){
        tabela[posicao].chave = memoria_principal[0].chave;
        posicao++;
    }

    for(int i = 0; i < total_seila; i++){
        printf("(chave %d: %d\n", i, tabela[i].chave);
    }

    fflush(stdout); //limpar o buffer
    print("\nDIGITE A CHAVE DE PESQUISA:");
    scanf("%d", &dado.chave);

    if("função de pesquisa do acesso")
        printf("A CHAVE %d FOI ENCONTRADA!", dado.chave);
    else
        printf("A CHAVE %d NAO FOI ENCONTRADA!", dado.chave);

    fclose(arquivo);
    free(memoria_principal);
    free(tabela);
}