#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include "cliente.h"
#include <string.h>

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

void imprimirTodosClientes(Cliente *cabeça) {
    if (cabeça == NULL){
        printf("Erro: Lista nao iniciada\n");
        return;
    }

    Cliente *atual = cabeça -> next;
    int contador = 1;

    if (atual == NULL){
        printf("Lista vazia\n");
        return;
    }

    printf("\n ---------Todos dos Clientes --------\n");

    while (atual != NULL){
        printf("\n---Cliente %d---\n", contador++);
        printf("CPF: %s\n" , atual->cpf);
        printf("Nome: %s\n" , atual->nome);
        printf("Email: %s\n" , atual->email);
        printf("Telefone: %s\n" , atual->telefone);
        atual = atual->next;

    }
}

void menuClientes(Cliente *cabeça) {

    int opcao;
    do {
        printf("\n=== MENU CLIENTES ===\n");
        printf("1. Adicionar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Remover cliente\n");
        printf("4. Voltar\n");
        printf("Escolha: ");
        scanf(" %d", &opcao);


        if (opcao == 1) {

            char cpf_temp[12];
            char nome_temp[100];
            char email_temp[100];
            char telefone_temp[15];

            printf("Digite o cpf: ");
            scanf(" %11s", cpf_temp); 


            printf("\nDigite o nome: ");
            scanf(" %99[^\n]" , nome_temp);


            printf("\nDigite o email: ");
            scanf(" %99s" , email_temp);


            printf("\nDigite o telefone: ");
            scanf(" %14s" , telefone_temp);


            inserirClienteInicio(cabeça , cpf_temp, nome_temp, email_temp, telefone_temp);

            
        } else if (opcao == 2) {
            imprimirTodosClientes(cabeça);
        }
        else if (opcao == 3){

            char cpf_remover[12];
            printf("Digite o cpf do cliente que deseja remover: ");
            scanf(" %11s" , cpf_remover);

            removerCliente(cpf_remover , cabeça);



        } else if (opcao == 4) {
            printf("Voltando ao menu principal...\n");
        } else {
            printf("Opção inválida\n");
        }
    } while (opcao != 4);
}


void removerCliente(const char *cpf , Cliente *cabeça){
    Cliente *anterior = cabeça;
    Cliente *atual = cabeça -> next;

    while( atual != NULL && strcmp(atual->cpf , cpf) != 0 ){
        anterior = atual;
        atual = atual -> next;
    }

    if (atual != NULL ){
        anterior -> next = atual->next;

        free(atual->cpf);
        free(atual->nome);
        free(atual->email);
        free(atual->telefone);

        free(atual);

        printf("Cliente com cpf %s foi removido com sucesso" , cpf);
    } 
    else{
        printf("Cliente com cpf %s nao foi encontrado" , cpf);
    }
}