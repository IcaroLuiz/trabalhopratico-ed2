#include <stdio.h>
#include <time.h>
#include "acesso.h"

//gerando tabela de indices
int preprocessamento(FILE *arquivo, int tabela[], int quantidade_itens, int *transferencia, double *tempo){

    Registro pagina[ITENSPAGINA];
    int posicao = 0, contador = 0;

    //variaveis para medir tempo de execução 
    clock_t fim, inicio = clock();
    double tempo_cpu;

    //leitura dos itens da pagina (feito de 4 em 4)
    while((fread(pagina, ITENSPAGINA * sizeof(Registro), 1, arquivo)) == 1){
        contador++;

        if (contador > quantidade_itens) break;

        //insersão do primeiro nro de cada pagina na tabela
        tabela[posicao] = pagina[0].chave;
        posicao++;
    }

    //contando o numero de transferencias entre memoria secundaria e principal
    *transferencia = contador;

    //O clock para e o tempo de execução retorna em double
    fim = clock();
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    *tempo = tempo_cpu;

// Imprimindo tabela de índices
    int i;
    for(i = 0; i < quantidade_itens / ITENSPAGINA; i++) {
        printf("\n%2d | %-8d", i, tabela[i]);
    }
    printf("\n");

    fflush(stdout);
    return posicao;
}

int pesquisa_as(FILE *arquivo, Registro* item, int tabela[], int tamanho, int *comparacoes, int *transferencias, double *tempo){
    Registro pagina[ITENSPAGINA];
    int i = 0, quantidade_itens;
    long long int deslocamento;

    *comparacoes = 0;

    //variaveis para medir tempo de execução 
    clock_t fim, inicio = clock();
    double tempo_cpu;

    while (i < tamanho && tabela[i] <= item->chave){
        printf("\nCOMPARACAO NA TABELA: %d", tabela[i]); 
        i++;

        *comparacoes += 1;
    }
    printf("\n\n");

    if(i == 0) return 0;

    else{
        if(i < tamanho)
            quantidade_itens = ITENSPAGINA;

        else{
            fseek(arquivo, 0, SEEK_END);
            quantidade_itens = (ftell(arquivo)/sizeof(Registro))%ITENSPAGINA;

            if(quantidade_itens == 0)
                quantidade_itens = ITENSPAGINA;
        }
        
        deslocamento = (i-1) * ITENSPAGINA * sizeof(Registro);

        fseek(arquivo, deslocamento, SEEK_SET);
        fread(&pagina,sizeof(Registro), quantidade_itens, arquivo);

        *transferencias += 1;

        for(i = 0; i < quantidade_itens; i++){
            *comparacoes += 1;

            if (pagina[i].chave == item->chave){
                *item = pagina[i];

               //O clock para e o tempo de execução retorna em double
                fim = clock();
                tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
                *tempo = tempo_cpu; 
                return 1;
            }
        }

        //O clock para e o tempo de execução retorna em double
        fim = clock();
        tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        *tempo = tempo_cpu; 
        
        return 0;
    }
}

void acesso_sequencial(int situacao, int chave, int quantidade){
    FILE *arquivo;
    int tabela[MAXTABELA];
    int posicao, resultado; double tempo;
    int comparacoes = 0, transferencia = 0; 

    Registro x; x.chave = chave;

    if((arquivo = fopen("arquivo_gerado.bin", "rb")) == NULL){
        printf("\nERRO AO ABRIR O ARQUIVO.");
        return;
    }
    posicao = preprocessamento(arquivo, tabela, quantidade, &transferencia, &tempo);
    resultado = pesquisa_as(arquivo, &x, tabela, posicao, &comparacoes, &transferencia, &tempo); 

    if (resultado){
        printf("\nREGISTRO ENCONTRADO!\n\n");
        printf("ITEM: %d | %ld, %s\n", x.chave, x.dado01, x.dado02);
    } else{
        printf("\nREGISTRO NAO ENCONTRADO!\n\n");
    }

    fclose(arquivo);
}
