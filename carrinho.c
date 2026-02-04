#include "funcoes.h"


void adicionar_item_cliente(Cliente *cliente , Estoque *estoque){
    if(cliente == NULL){
        printf("Cliente invalido\n");
        return;
    }

    int codigo;
    int quantidade_desejada;

    printf("Digite o codigo do produto que deseja adicionar ao carrinho: ");
    scanf(" %d" , &codigo);

    Produto *item_estoque; 
    item_estoque = busca_pelo_codigo(codigo, estoque); 


    if(item_estoque == NULL){
        printf("Item invalido\n");
        return;
    }

    printf("\n--------  Produto encontrado! ---------\n");
    //dados
    printf("--------------------------------------");
    printf("\nCodigo: %d\n" , item_estoque->codigo);
    printf("Nome: %s\n" , item_estoque->nome);
    printf("quantidade: %d" , item_estoque->quantidade);
    printf("\n--------------------------------------\n");
   

    printf("\nDigite a quantidade que deseja adicionar ao carrinho: ");
    scanf(" %d" ,&quantidade_desejada);

    //--------------------------------------------------------------------------------

    //verificar se item ja tem no carrinho;

    Carrinho *item_carrinho = cliente->carrinho->next;


    while(item_carrinho != NULL){
        if (item_carrinho->produto->codigo == codigo){
            
            int quantidade_total = item_carrinho->qtd + quantidade_desejada;
            
            // verifica se a quantidade total não ultrapassa o estoque
            if(quantidade_total <= item_carrinho->produto->quantidade){
                item_carrinho->qtd = quantidade_total;  // Atualiza a quantidade
                printf("\n-------------Produto adicionado!!!----------------\n");
                printf("Quantidade atual no carrinho: %d\n", item_carrinho->qtd);
                return;
            } 
            else {
                printf("\n---------------Erro ao adicionar----------------------\n");
                printf("Quantidade desejada ultrapassa o limite de produtos disponiveis\n");
                printf("Quantidade no carrinho: %d\n", item_carrinho->qtd);
                printf("Quantidade desejada: %d\n", quantidade_desejada);
                printf("Quantidade total solicitada: %d\n", quantidade_total);
                printf("Itens disponiveis em estoque: %d\n", item_carrinho->produto->quantidade);
                return;
            }
        }
        item_carrinho = item_carrinho->next;
    }
    //verificar novamente
    // para produtos que nao estao no carrinho
    if (quantidade_desejada > item_estoque->quantidade) {
        printf("\n-------------------------------------------------------------------\n");
        printf("Erro: Quantidade desejada (%d) maior que estoque disponivel (%d)!\n", quantidade_desejada, item_estoque->quantidade);
        printf("\n-------------------------------------------------------------------\n");
        return;
    }

    Carrinho *novo_item = (Carrinho*)malloc(sizeof(Carrinho));
    if (novo_item == NULL){
        printf("erro alocacao carrinho\n");
        return;
    }

    //adicionar novo item ao carrinho
    // adicao no inicio 

    novo_item->produto = item_estoque;
    novo_item->qtd = quantidade_desejada;
    novo_item->next = cliente->carrinho->next;
    cliente->carrinho->next = novo_item;


    printf("\n-------------Produto adicionado!!!----------------\n");
    

}


void listarItemCliente(Cliente*cabeca){
    Carrinho *carrinho_do_cliente = cabeca->carrinho->next;
    int total_itens = 0;
    float valor_total = 0.00;

    if (carrinho_do_cliente == NULL) {
        printf("O carrinho esta vazio.\n");
        return;
    }
    
    Carrinho *calcular = carrinho_do_cliente;
    // contar itens total do carrinho e valor total;
    while(calcular != NULL){
        total_itens++;
        valor_total += carrinho_do_cliente->qtd * calcular->produto->preco;
        calcular = calcular->next;
    }
    printf("\n------------------------------------------------------\n");
    printf("Total de Produtos: %-15d | Preco total: %.2f", total_itens, valor_total);

  //  printf("\n-----Total de itens do carrinho: %d------\n" , total_itens);
   // printf("--------Preco total do carrinho: %.2f" , valor_total);

    while(carrinho_do_cliente != NULL){

        printf("\n------------------------------------------------------");
        printf("\nProduto: %s\n" , carrinho_do_cliente->produto->nome);
        printf("Codigo : %d\n" , carrinho_do_cliente->produto->codigo);
        printf("Quantidade: %d\n", carrinho_do_cliente->qtd);
        printf("------------------------------------------------------\n");
        carrinho_do_cliente = carrinho_do_cliente->next;
}

}


void menuCarrinho(Cliente *cliente, Estoque *estoque) {
    int opcao;
    do {
        printf("\n=== CARRINHO ===\n");
        printf("1. Adicionar item\n");
        printf("2. Listar carrinho\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf(" %d", &opcao);
        
        switch (opcao) {
            case 1:
                adicionar_item_cliente(cliente, estoque);
                break;
            case 2:
                listarItemCliente(cliente);
                break;
        }
    } while (opcao != 0);
}

