#include <stdio.h>
#include <stdlib.h>
#include "gerador.h"
#include "acesso.h"

int main() {
    int quantidade_itens = 100;
    int situacao, chave;

    gerador_arquivo(quantidade_itens);
    acesso_sequencial( situacao,  chave, quantidade_itens);

    return 0;
}