#include <string.h>
#include <stdlib.h>
#include "acesso.h"
#include "gerador.h"

void ler_arquivo(){
   FILE *arquivo = fopen("arquivo_gerado.bin", "rb");
    Registro item;

    //verificação de abertura do arquivo
    if((arquivo = fopen("arquivo_gerado.bin", "rb")) == NULL){
        printf("\nERRO AO ABRIR O ARQUIVO\n\n");
        return;
    }
        // //leitura do arquivo
    // while(fread(&item, sizeof(item), 1, arquivo) == 1){
    //     printf("chave: %d\n", item.chave);
    //     printf("Dado 01: %ld\n", item.dado01);
    //     printf("Dado 02: %s\n\n", item.dado02);
    // }

    fclose(arquivo);
}


void gerador_arquivo(int quantidade_arquivo){
    FILE *arquivo = fopen("arquivo_gerado.bin", "wb");
    Registro item;

    // verificando se o arquivo foi criado ou não
    if(arquivo != NULL){
        printf("\nARQUIVO CRIADO COM SUCESSO!\n\n");
    }else{
        printf("\nNAO FOI POSSIVEL ABRIR O ARQUIVO.\n\n");
        exit(0);
    }

    //gravando os dados no arquivo
    for(int i = 0; i < quantidade_arquivo; i++){
        item.chave = i;
        item.dado01 = i+1000;
        strcpy(item.dado02, "Vamo rancar essa cadeira maldita");

        fwrite(&item, sizeof(item), 1, arquivo);
    }
    fclose(arquivo);
    //chama função de ler o arquivo
    ler_arquivo();
}

