
#ifndef CARRINHO_H
#define CARRINHO_H
#include "produtos.h"
#include "cliente.h"

typedef struct carrinho {
    Produto *produto;
    int qtd;
    struct carrinho *next;
} Carrinho;


void adicionar_item_cliente(Cliente *cliente , Estoque *estoque){






#endif