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






















#endif