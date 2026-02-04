#ifndef STRUCTS_H
#define STRUCTS_H


typedef struct carrinho Carrinho;
typedef struct Cliente Cliente;



typedef struct _produto{
    char nome[50];
    int quantidade;
    int codigo;
    float preco;
}Produto;

typedef struct estoque_completo{
    Produto *produto;
    struct estoque_completo *prev;
    struct estoque_completo *prox;
}Estoque;

typedef struct Cliente {
    char *cpf;
    char *nome;
    char *email;
    char *telefone;
    struct Cliente *next;

    Carrinho *carrinho;   
} Cliente;


typedef struct carrinho {
    Produto *produto;
    int qtd;
    struct carrinho *next;
} Carrinho;

typedef struct Cliente Cliente;




#endif