#include <stdio.h>
#include "cliente.h"

//------------------------------- TESTE DE INSERCAO ----------------------------------------

int main() {
    
    Cliente *cabeca = criarHeadCliente();

    char cpf_temp[15];
    char nome_temp[100];
    char email_temp[100];
    char telefone_temp[15];

    printf("--------CADASTRO CLIENTE-------\n");
    printf("Digite o cpf: ");
    scanf(" %14s", cpf_temp); 


    printf("\nDigite o nome: ");
    scanf(" %99[^\n]" , nome_temp);


    printf("\nDigite o email: ");
    scanf(" %99s" , email_temp);


    printf("\nDigite o telefone: ");
    scanf(" %14s" , telefone_temp);


    inserirClienteInicio(cabeca , cpf_temp, nome_temp, email_temp, telefone_temp);

    Cliente *c = cabeca->next;

    printf("\n--- CLIENTE NA LISTA ---\n");
    printf("CPF: %s\n", c->cpf);
    printf("Nome: %s\n", c->nome);
    printf("Email: %s\n", c->email);
    printf("Telefone: %s\n", c->telefone);



}