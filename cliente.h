#ifndef CLIENTE_H
#define CLIENTE_H

//----------- STRUCT ------------------

typedef struct carrinho Carrinho;

typedef struct Cliente {
    char *cpf;
    char *nome;
    char *email;
    char *telefone;
    struct Cliente *next;

    Carrinho *carrinho;   //comentar

} Cliente;


//--------------------- FUNÇÕES ----------------

Cliente* criarHeadCliente();
void inserirClienteInicio(Cliente *head,
                           const char *cpf_parametro,
                           const char *nome_parametro,
                           const char *email_parametro,
                           const char *telefone_parametro);

void imprimirTodosClientes(Cliente *cabeca);

void menuClientes(Cliente *cabeca);

void removerCliente(const char *cpf , Cliente *cabeca);

void editarCliente(const char *cpf_parametro , Cliente *cabeca);

Cliente* buscar_cliente(Cliente* cabeca);
Cliente* processar_resultados(Cliente* resultados[], int count, int tipo_busca);
Cliente* pedir_confirmacao_exata(Cliente* resultados[], int count);
void mostrar_cliente_completo(Cliente* cliente);


















#endif