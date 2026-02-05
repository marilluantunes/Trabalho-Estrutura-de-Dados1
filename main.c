#include "funcoes.h"



int main(){
    Cliente *cabeca = criarHeadCliente();
    Estoque *head = criar_estoque();
    Cliente *escolhido;

    if (cabeca == NULL) {
        printf("Erro: Não foi possível inicializar o sistema de clientes\n");
        return 1;
    }

    int opcao;

    do{
        printf("\n -------- MENU PRINCIPAL ------\n");
        printf("1. Sistema Clientes\n");
        printf("2. Sistemas Produtos\n");
        printf("3. Modo Compra\n");
        printf("4. Sair\n");
        printf("\nEscolha: ");
        scanf(" %d" , &opcao);

        switch(opcao){
            case 1:
            menuClientes(cabeca);
            break;

            case 2:
            menuProdutos(head,escolhido);
            break;

            case 3:
            escolhido = buscar_cliente(cabeca);
            if (escolhido != NULL) {  //volta para menu princial se nenhum cliente for achado
                menuCarrinho(escolhido, head);
            }
            break;

            case 4:
            printf("Encerrando o programa\n");
            break;

            default:
            printf("\nOpcao Invalida\n");


        }
    
    } while(opcao!= 4);

    //----------------------------------------------------------------------------
    // Liberacao da memoria alocada
    //---------------------------------------------------------------------------

    int clientes = liberarListaCliente(cabeca);
    int produtos = liberarEstoque(head);

    printf("\n--------------Liberacao concluida----------------\n");
    printf("\n     %-5d cliente(s) liberado(s)\n", clientes);
    printf("     %-5d produto(s) liberado(s)\n", produtos);
    printf("------------------------------------------------\n");

    printf("\n------------Sistema encerrado------------------\n");


}

