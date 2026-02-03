
#ifndef PRODUTOS_H
#define PRODUTOS_H

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


Produto* busca_pelo_codigo(int x, Estoque *ptr);
Produto* criar_struct(Estoque *primeiro);
Estoque* busca_recursiva(Estoque *ptr);
Estoque* busca_recursiva_anterior(int i, Estoque *ptr, Estoque *ptr1);
Estoque* busca_recursiva_anterior_especifica(Estoque *ptr, int i);
Estoque* criar_estoque();
void cadastrar_produto(Estoque *ptr);
void exibir_lista_de_estoque(Estoque *ptr);
void editar_dados_do_produto(Estoque* ptr);
Estoque* retirar_produtos(Estoque* ptr);









#endif