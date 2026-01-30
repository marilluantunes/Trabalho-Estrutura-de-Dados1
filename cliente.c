#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include "cliente.h"

// ------------------------FUNCOES------------------------- 
Cliente* criarHeadCliente(){
    Cliente *head;
    head = malloc(sizeof(Cliente));

    if (head == NULL){
        printf("Erro de alocacao de memoria\n");
        return NULL;
    }

    head->next = NULL;
    return head;
}

void inserirClienteInicio(Cliente *head, const char *cpf, const char *nome, const char *email , const char *telefone ){

    if (head == NULL || cpf == NULL  || nome == NULL || email == NULL || telefone == NULL ){
        printf("Erro de alocacao de memoria");
        return;
    }

    Cliente *novo = malloc(sizeof(Cliente));
    if (novo == NULL){
        printf("Eroo de alocacao de memoria\n");
        return;
    }


    novo->cpf = malloc(strlen(cpf) + 1); 
    strcpy(novo->cpf,cpf);

    novo->nome = malloc(strlen(nome) + 1) ;
    strcpy(novo->nome,nome);

    novo->email = malloc(strlen(email) +1);
    strcpy(novo->email, email);

    novo->telefone = malloc(strlen(telefone) +1 );
    strcpy(novo->telefone, telefone);

    novo->next = head->next;
    head->next = novo;

    printf("Cliente adicionado com sucesso!\n");

}




