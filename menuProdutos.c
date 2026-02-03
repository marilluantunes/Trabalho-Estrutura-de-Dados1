

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

void menuProdutos(Estoque *estoque) {
    int opcao;
    
    do {
        printf("\n=== MENU PRODUTOS ===\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Listar todos os produtos\n");
        printf("3. Buscar produto por codigo\n");
        printf("4. Editar produto\n");
        printf("5. Remover produto\n");
        printf("0. Voltar ao menu principal\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        
        switch (opcao) {
            case 1:
                cadastrar_produto(estoque);
                break;
            case 2:
                exibir_lista_de_estoque(estoque);
                break;
            case 3: {
                int codigo;
                printf("Digite o codigo do produto: ");
                scanf(" %d", &codigo);
                Produto *produto = busca_pelo_codigo(codigo, estoque);
                if (produto) {
                    printf("\n=== PRODUTO ENCONTRADO ===\n");
                    printf("Nome: %s\n", produto->nome);
                    printf("Codigo: %d\n", produto->codigo);
                    printf("Quantidade: %d\n", produto->quantidade);
                    printf("Preco: R$ %.2f\n", produto->preco);
                } else {
                    printf("Produto nao encontrado!\n");
                }
                break;
            }
            case 4:
                editar_dados_do_produto(estoque);
                break;
            case 5:
                retirar_produtos(estoque);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\n....Pressione enter para continuar");
            getchar();
        }
        
    } while (opcao != 0);
}