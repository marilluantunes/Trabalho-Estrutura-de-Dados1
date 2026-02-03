#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
Produto* busca_pelo_codigo(int x, Estoque *ptr);
Produto* criar_struct(Estoque *primeiro);
Estoque* busca_recursiva(Estoque *ptr);
Estoque* busca_recursiva_anterior(int i, Estoque *ptr, Estoque *ptr1);
Estoque* busca_recursiva_especifica(Estoque *ptr, int i);
Estoque* criar_estoque();
void cadastrar_produto(Estoque *ptr);
void exibir_lista_de_estoque(Estoque *ptr);
void editar_dados_do_produto(Estoque *ptr);
Estoque* remocao(Estoque *ptr, Estoque *novo);
Estoque* retirar_produtos(Estoque *ptr);
#endif
