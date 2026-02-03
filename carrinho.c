#include <stdio.h>
#include "cliente.h"
#include <stdlib.h>
#include <string.h>   
#include <string.h>
#include <ctype.h>
#include "carrinho.h"
#include "produtos.h"



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

    printf("Produto encontrado!");
    //dados
    printf("Codigo: %d\n" , item_estoque->codigo);
    printf("Nome: %s\n" , item_estoque->nome);
   

    printf("\nDigite a quantidade que deseja adicionar ao carrinho: ");
    scanf(" %d" ,&quantidade_desejada);

    // verificar se a quantidade desejada eh inferior ou igual a quantidade do estoque

    //if ( estoque < quantidade desejada  ) {
    //     dr return
     // }

    //--------------------------------------------------------------------------------


    // ADICIONAR 

    //verificar se item ja tem no carrinho;

    Carrinho *item_carrinho = cliente->carrinho->next;


    while(item_carrinho != NULL){
        if (item_carrinho->produto->codigo == codigo){
            // verificar se ja existe no carrnho , se existir adicionar na qantidade 
            //verificar se a quantidad nn ultrapassa a quantidade do produto
            // da return se ultrapassar

            item_carrinho->qtd += quantidade_desejada;

            //atualizar o estoque ? nao! apenas quando efetuarem a compra
            
            return; // codigo encontrado
        }
        item_carrinho = item_carrinho->next;

    }

    // se o produto nn estiver no carrinho ,v amos adicionar 

    Carrinho *novo_item = (Carrinho*)malloc(sizeof(Carrinho));
    if (novo_item == NULL){
        printf("erro alocacao carrinho\n");
        return;
    }

    //adicionar novo item ao carrinho
    // adicao no inicio 

    novo_item->produto = item_estoque;
    novo_item->qtd = quantidade_desejada;
    novo_item->next = cliente->carrinho;
    cliente->carrinho = novo_item;


    printf("\nProduto adicionado!!!\n");
    

}


void listarItemCliente(Cliente*cabeca){
    Carrinho *carrinho_do_cliente = cabeca->carrinho->next;

    if (carrinho_do_cliente == NULL) {
        printf("O carrinho esta vazio.\n");
        return;
    }

    while(carrinho_do_cliente != NULL){
        printf("Nome Item: %s\n" , carrinho_do_cliente->produto->nome);
        printf("Codigo Item: %d\n" , carrinho_do_cliente->produto->codigo);
        printf("Quantidade de Itens: %d\n", carrinho_do_cliente->qtd);
        carrinho_do_cliente = carrinho_do_cliente->next;
}

}

