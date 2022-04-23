#include <stdio.h>
#include <stdlib.h>
#include "acesso.h"

int pesquisa_as(Indice *tabela, int tamanho, Registro *item, FILE *arquivo){
    Registro pagina[ITENSPAGINA];
    int quantidade_itens, i = 0;
    long long int deslocamento;

    while(i < tamanho && tabela[i].chave <= item->chave)
        i++;

    if (i == 0)
        return 0;
    else{
        fseek(arquivo, 0, SEEK_END);
        quantidade_itens = (int) (ftello64(arquivo))/ sizeof(Registro) % ITENSPAGINA;

        if(i < tamanho || quantidade_itens == 0)
            quantidade_itens = ITENSPAGINA;
    }

    deslocamento = (i -1) * ITENSPAGINA * sizeof(Registro);
    fseeko64(arquivo, 0, SEEK_SET);
    fread(&pagina, sizeof(Registro), quantidade_itens, arquivo);
    
    for(i = 0; i < quantidade_itens; i++){
        if(pagina[i].chave == item->chave){
            *item = pagina[i];
            return 1;
        }
    }
    return 0;
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

    if(pesquisa_as(tabela, posicao,&dado, arquivo))
        printf("A CHAVE %d FOI ENCONTRADA!", dado.chave);
    else
        printf("A CHAVE %d NAO FOI ENCONTRADA!", dado.chave);

    fclose(arquivo);
    free(memoria_principal);
    free(tabela);
}