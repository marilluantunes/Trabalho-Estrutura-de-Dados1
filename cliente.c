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

void inserirClienteInicio(Cliente *head, const char *cpf_parametro, const char *nome_parametro, 
    const char *email_parametro , const char *telefone_parametro ){

    if (head == NULL || cpf_parametro == NULL  || nome_parametro == NULL ||
         email_parametro == NULL || telefone_parametro == NULL ){
            
        printf("Erro de alocacao de memoria");
        return;
    }

    Cliente *novo = malloc(sizeof(Cliente));
    if (novo == NULL){
        printf("Eroo de alocacao de memoria\n");
        return;
    }


    novo->cpf = malloc(strlen(cpf_parametro) + 1); 
    strcpy(novo->cpf,cpf_parametro);

    novo->nome = malloc(strlen(nome_parametro) + 1) ;
    strcpy(novo->nome,nome_parametro);

    novo->email = malloc(strlen(email_parametro) +1);
    strcpy(novo->email, email_parametro);

    novo->telefone = malloc(strlen(telefone_parametro) +1 );
    strcpy(novo->telefone, telefone_parametro);

    novo->next = head->next;
    head->next = novo;

    printf("Cliente adicionado com sucesso!\n");

}

void imprimirTodosClientes(Cliente *cabeca) {
    if (cabeca == NULL){
        printf("Erro: Lista nao iniciada\n");
        return;
    }

    Cliente *atual = cabeca -> next;
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

void editarCliente(const char *cpf_parametro , Cliente *cabeca){

    Cliente *atual = cabeca->next;

    while (atual != NULL) {
        if (strcmp(atual->cpf , cpf_parametro) == 0){
            int opcao;
            char temporario[100];

            do {
                printf("\n-----------CLIENTE ENCONTRADO----------\n");
                printf("CPF: %s\n" , atual->cpf);
                printf("---------------------------------------\n");
                printf("---------------Opcoes:-----------------\n");
                printf("1. Editar nome: %s\n" , atual->nome);
                printf("2. Editar email: %s\n" , atual->email);
                printf("3. Editar telefone: %s\n" , atual->telefone);
                printf("4. finalizar edicao\n");
                printf("---------------------------------------\n");
                printf("Escolha o que deseja editar: ");
                scanf(" %d" , &opcao);

                switch (opcao) {
                    case 1:
                    printf("Novo nome: ");
                    scanf(" %99[^\n]" , temporario);

                    if (strlen(temporario) > 0) {

                        char *novo_nome = realloc(atual->nome , strlen(temporario)+1);
                        if (novo_nome == NULL){
                            printf("Falha na realocação\n");
                            printf("Mantendo o nome antigo");
                        }
                        else {
                            atual->nome = novo_nome;
                            strcpy(atual->nome , temporario);
                            printf("-------------------------------");
                            printf("Nome atualizado com sucesso!\n");
                            printf("-------------------------------");
                        }
                    }

                    break;

                    case 2:
                    printf("Novo email: ");
                    scanf(" %99s" , temporario);

                    if (strlen(temporario) > 0) {

                        char *novo_email = realloc(atual->email , strlen(temporario)+1);
                        if (novo_email == NULL){
                            printf("Falha na realocação\n");
                            printf("Mantendo o email antigo");
                        }
                        else {
                            atual->email = novo_email;
                            strcpy(atual->email , temporario);
                            printf("-------------------------------");
                            printf("Email atualizado com sucesso!\n");
                            printf("-------------------------------");
                        }
                        break;
                    }

                    case 3:
                    printf("Novo telefone: ");
                    scanf(" %20[^\n]" , temporario);

                    if (strlen(temporario) > 0){
                        char *novo_telefone = realloc(atual->telefone , strlen(temporario)+1);
                        if (novo_telefone == 0){
                            printf("Erro de realocação de memoria\n");
                            printf("Mantendo o email antigo");
                        }

                        else{
                            atual->telefone = novo_telefone;
                            strcpy(atual->telefone, temporario);
                            printf("----------------------------------");
                            printf("Telefone atualizado com sucesso!\n");
                            printf("----------------------------------");
                        }
                    }
                    break;

                    case 4:
                    printf("Voltando\n");
                    break;

                    default:
                    printf("Opção invalida\n");
                    break;
                }

            }

            while (opcao != 4);

            return; 
        }

        atual = atual->next;
    }

    printf("Cliente com CPF %s não encontrado.\n" , cpf_parametro);

}

void removerCliente(const char *cpf , Cliente *cabeca){
    Cliente *anterior = cabeca;
    Cliente *atual = cabeca -> next;

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

void menuClientes(Cliente *cabeca) {

    int opcao;
    do {
        printf("\n=== MENU CLIENTES ===\n");
        printf("1. Adicionar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Remover cliente\n");
        printf("4. Editar Cliente\n");
        printf("5. Voltar\n");
        printf("Escolha: ");
        scanf(" %d", &opcao);


        if (opcao == 1) {

            char cpf_temp[15];
            char nome_temp[100];
            char email_temp[100];
            char telefone_temp[20];

            printf("Digite o cpf: ");
            scanf(" %14s", cpf_temp); 


            printf("\nDigite o nome: ");
            scanf(" %99[^\n]" , nome_temp);


            printf("\nDigite o email: ");
            scanf(" %99s" , email_temp);


            printf("\nDigite o telefone: ");
            scanf(" %19s" , telefone_temp);


            inserirClienteInicio(cabeca , cpf_temp, nome_temp, email_temp, telefone_temp);

            
        } else if (opcao == 2) {
            imprimirTodosClientes(cabeca);
        }
        else if (opcao == 3){

            char cpf_remover[15];
            printf("Digite o cpf do cliente que deseja remover: ");
            scanf(" %14s" , cpf_remover);

            removerCliente(cpf_remover , cabeca);
        } 
        
        else if (opcao == 4) {

            printf("\nDigite o CPF do cliente que deseja editar: ");
            char cpf_editar[15];
            scanf(" %14s" , cpf_editar);
            editarCliente(cpf_editar , cabeca);

        }

        else if (opcao == 5) {
            printf("Voltando ao menu principal...\n");
        }
        
        else {
            printf("Opção inválida\n");
        }
    } 
    
    while (opcao != 4);
}

