#ifndef PE_GERADORARQUIVO_H
#define PE_GERADORARQUIVO_H
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

#endif