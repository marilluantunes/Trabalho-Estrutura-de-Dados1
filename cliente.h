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
                           const char *cpf,
                           const char *nome,
                           const char *email,
                           const char *telefone);

void imprimirTodosClientes(Cliente *cabeca);

void menuClientes(Cliente *cabeca);

void removerCliente(const char *cpf , Cliente *cabeca);





















#endif