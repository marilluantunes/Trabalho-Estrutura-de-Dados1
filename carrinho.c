#include <stdio.h>
#include "carrinho.h"
#include "produtos.h"
#include "cliente.h"

#include <stdlib.h>
#include <string.h>   
#include <string.h>
#include <ctype.h>

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

    Carrinho *item_carrinho = cliente->carrinho;


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

