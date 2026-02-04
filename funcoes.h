#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include <ctype.h> //para o tolower
#include "structs.h"

// ============== PRODUTOS ==============
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
void menuProdutos(Estoque *estoque);

// ============== CARRINHO ==============
void adicionar_item_cliente(Cliente *cliente, Estoque *estoque);
Cliente* listarItemCliente(Cliente *cabeca);
void menuCarrinho(Cliente *cliente, Estoque *estoque);

// ============== CLIENTE ==============
Cliente* criarHeadCliente();
void inserirClienteInicio(Cliente *head,
                           const char *cpf_parametro,
                           const char *nome_parametro,
                           const char *email_parametro,
                           const char *telefone_parametro,
                        int dia, int mes, int ano);
void imprimirTodosClientes(Cliente *cabeca);
void menuClientes(Cliente *cabeca);
void removerCliente(const char *cpf, Cliente *cabeca);
void editarCliente(const char *cpf_parametro, Cliente *cabeca);
Cliente* buscar_cliente(Cliente* cabeca);
Cliente* processar_resultados(Cliente* resultados[], int count, int tipo_busca);
Cliente* pedir_confirmacao_exata(Cliente* resultados[], int count);
void mostrar_cliente_completo(Cliente* cliente);

#endif