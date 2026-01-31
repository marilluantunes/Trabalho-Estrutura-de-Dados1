#include <stdio.h>
#include "cliente.h"


int main(){
    Cliente *cabeça = criarHeadCliente();

    if (cabeça == NULL) {
        printf("Erro: Não foi possível inicializar o sistema de clientes\n");
        return 1;
    }

    int opcao;

    do{
        printf("\n -------- MENU PRINCIPAL ------\n");
        printf("1. Sistema dos Clientes\n");
        printf("2. Sistemas dos Produtos\n");
        printf("3. Modo Compra\n");
        printf("4. Sair\n");
        scanf(" %d" , &opcao);

        switch(opcao){
            case 1:
            menuClientes(cabeça);
            break;

            case 2:
            printf("\nSistema de produtos em andamento...\n");
            break;

            case 3:
            printf("\nSistema de Modo Compras em andamento....\n");
            break;

            case 4:
            printf("Encerrando o programa\n");
            break;

            default:
            printf("\nOpção Inválida\n");


        }
    
    } while(opcao!= 4);

    //----------------------------------------------------------------------------
    // !!!!!! LEMBRAR DE COLOCAR FUNCAO PARA LIBERAR MEMORIA ALOCADA AQUI !!!!!! 
    //----------------------------------------------------------------------------

    printf("Sistema encerrado com sucesso\n");
}

