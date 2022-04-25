#ifndef PE_ACESSOSEQUENCIAL_H
#define PE_ACESSOSEQUENCIAL_H
#include <stdio.h>
#define ITENSPAGINA 4
#define MAXTABELA 100

typedef struct{
    int chave;
}Indice;

typedef struct{
    int chave;
    long int dado01;
    char dado02[5000];
}Registro;

int preprocessamento(FILE *arquivo, int tabela[], int quantidade_itens, int *transferencia, double *tempo);
int pesquisa_as(FILE *arquivo, Registro* item, int tabela[], int tamanho, int *comparacoes, int *transferencias, double *tempo);
void acesso_sequencial(int situacao, int chave, int quantidade);

#endif