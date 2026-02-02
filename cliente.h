#ifndef CLIENTE_H
#define CLIENTE_H

//----------- STRUCT ------------------

typedef struct Cliente {
    char *cpf;
    char *nome;
    char *email;
    char *telefone;

    struct Cliente *next;

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





















#endif