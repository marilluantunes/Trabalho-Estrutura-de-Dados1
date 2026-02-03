#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include "cliente.h"
#include "carrinho.h"
#include "produtos.h"  //comentar
#include <string.h>
#include <ctype.h> //para o tolower


//========================CRIAR CACEÇA DA LISTA=================================
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

//===================INSERIR CLIENTE NO INICIO DA LISTA=========================

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

// ----------CRIA CARRINHO VAZIO PARA O NOVO CLIENTE -------------

    novo->carrinho = malloc(sizeof(Carrinho));
    if (novo->carrinho == NULL){
        printf("Erro ao alocar memoria\n");
        free(novo);
        return;
    }

    novo->carrinho->produto = NULL;
    novo->carrinho->qtd = 0;
    novo->carrinho->next = NULL;

    novo->next = head->next;
    head->next = novo;

    printf("\n---------------------------------\n");
    printf("Cliente adicionado com sucesso!\n");
    printf("---------------------------------\n\n");
}


//======================LISTAR TODOS OS CLIENTES==============================

void imprimirTodosClientes(Cliente *cabeca) {
    if (cabeca == NULL){
        printf("Erro: Lista nao iniciada\n");
        return;
    }

    Cliente *atual = cabeca -> next;
    int contador = 1;
    int total = 0;

    if (atual == NULL){
        printf("Lista vazia\n");
        return;
    }
    
    // conta o total de clientes
    Cliente *t = atual;
    while (t != NULL){
        total++;
        t = t->next;
    }

    printf("\n========== %d Cliente%s Cadastrado%s=========\n" ,total, total == 1 ? "" : "s", total == 1 ? "" : "s" );

    while (atual != NULL){
        printf("\n-------Cliente %d----------\n", contador++);
        printf("\n|      CPF: %s\n" , atual->cpf);
        printf("|      Nome: %s\n" , atual->nome);
        printf("|      Email: %s\n" , atual->email);
        printf("|      Telefone: %s\n" , atual->telefone);
        printf("-------------------------\n");
        atual = atual->next;

    }
}

//===========================EDITAR CLIENTE=====================================

void editarCliente(const char *cpf_parametro , Cliente *cabeca){

    Cliente *atual = cabeca->next;

    while (atual != NULL) {
        if (strcmp(atual->cpf , cpf_parametro) == 0){
            int opcao;
            char temporario[100];

            printf("\n-----------CLIENTE ENCONTRADO----------\n");
            printf("CPF: %s\n" , atual->cpf);
            printf("---------------------------------------\n");

            do {

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
                            printf("-------------------------------\n");
                            printf("Nome atualizado com sucesso!\n");
                            printf("-------------------------------\n");
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
                            printf("-------------------------------\n");
                            printf("Email atualizado com sucesso!\n");
                            printf("-------------------------------\n");
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
                            printf("----------------------------------\n");
                            printf("Telefone atualizado com sucesso!\n");
                            printf("----------------------------------\n");
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

    printf("\nCliente com CPF %s nao encontrado.\n" , cpf_parametro);

}

//===========================REMOVER CLIENTE====================================

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

        printf("\nCliente com cpf %s foi removido com sucesso!" , cpf);
    } 
    else{
        printf("\nCliente com cpf %s nao foi encontrado!" , cpf);
    }
}

//-------------------------=---BUSCAR CLIENTE-----------------------------------

Cliente* buscar_cliente(Cliente* cabeca) { //a funcoo retorna um ponteiro para um nó da lista encadeada de clientes
    int tipo;
    char termo[100];
    
    printf("\n-------OPCOES DE BUSCA-------\n");
    printf("1. Por nome\n");
    printf("2. Por email\n");
    printf("3. Por CPF\n");
    printf("\nEscolha: ");
    scanf(" %d", &tipo);

    switch (tipo) {
    case 1:
    printf("\nDigite o nome (ou parte dele): ");
    getchar();
    scanf("%99[^\n]" , termo);
    break;

    case 2:
    printf("\nDigite o e-mail (ou parte dele): ");
    scanf(" %99s" , termo);
    break;

    case 3:
    printf("\nDigite o CPF: ");
    scanf(" %99s" , termo);
    break;

    default:
        printf("\nOpção inválida.\n");
        return NULL;
}

    
    // vetor de ponteiros, cada posicao apontara pra uma cecula(struct cliente) na lista de clientes
    Cliente* resultados[100];
    int count = 0;
    
    // converte termo para minúsculas para nome e email 
    char termo_lower[100];
    if (tipo == 1 || tipo == 2) {
        for (int i = 0; termo[i] != '\0'; i++) {
            termo_lower[i] = tolower(termo[i]);
        }
        termo_lower[strlen(termo)] = '\0'; //coloca o caracter '\0' no fim da 
    }
        
    //percorre lista
    Cliente* atual = cabeca->next;

    while (atual != NULL) {
        int encontrou = 0;
  //----------------------------------------------------------------------------      
        switch (tipo) {
            case 1: 
                {   //converte o nome na struckt para minusculo 
                    char nome_lower[100];
                    for (int i = 0; atual->nome[i]; i++) {
                        nome_lower[i] = tolower(atual->nome[i]);
                    }
                    nome_lower[strlen(atual->nome)] = '\0'; //coloca o caractere '\0' no fim da string
                    
                    if (strstr(nome_lower, termo_lower)) {
                        encontrou = 1;
                    }
                }
                break;
                
            case 2: 
                {
                    char email_lower[100];
                    for (int i = 0; atual->email[i]; i++) {
                        email_lower[i] = tolower(atual->email[i]);
                    }
                    email_lower[strlen(atual->email)] = '\0';
                    
                    if (strstr(email_lower, termo_lower) != NULL) {
                        encontrou = 1;
                    }
                }
                break;
                
            case 3: // CPF (substring, mas geralmente busca exata)
                if (strstr(atual->cpf, termo) != NULL) {
                    encontrou = 1;
                }
                break;
        }
 //-----------------------------------------------------------------------------       
        if (encontrou) {
            //vetor de ponteiros
            resultados[count] = atual;
            count=count+1;
        }
        
        atual = atual->next;
    }
    
    // funcao que processa os resultados
    return processar_resultados(resultados, count, tipo);
}


Cliente* processar_resultados(Cliente* resultados[], int count, int tipo_busca) {
    if (count == 0) {
        printf("\n Nenhum cliente encontrado.\n");
        return NULL;
    }
    
    printf("\nEncontrados %d cliente(s):\n", count);
    
    // mostra lista de encontrados
    for (int i = 0; i < count; i++) {
        printf("%2d. ", i + 1);
        
        switch (tipo_busca) {
            case 1: // buscou por nome
                printf("Nome: %-20s | CPF: %s\n", resultados[i]->nome, resultados[i]->cpf);
                break;
            case 2: // buscou por email
                printf("Email: %-20s | CPF: %s\n", resultados[i]->email, resultados[i]->cpf);
                break;
            case 3: // buscou por CPF
                printf("CPF: %-15s | Nome: %s\n", resultados[i]->cpf, resultados[i]->nome);
                break;
        }
    }
    
    // se so tem 1, mostra direto
    if (count == 1) {
        printf("\nMostrando o unico cliente encontrado:\n");
        mostrar_cliente_completo(resultados[0]);
        return resultados[0];
    }
    
    // se tiver maais de um, pede confirmacao EXATA
    return pedir_confirmacao_exata(resultados, count);
}


Cliente* pedir_confirmacao_exata(Cliente* resultados[], int count) { //count = quants (posicoes)ponteiros existem no vetor
    char confirmacao[100];

    printf("\nDigite o CPF EXATO do cliente que deseja visualizar: ");
    scanf(" %99s" , confirmacao);

    for (int i = 0; i < count; i++) {
        if (strcmp(resultados[i]->cpf, confirmacao) == 0) {
            printf("\nCliente confirmado! Mostrando dados:\n");
            mostrar_cliente_completo(resultados[i]);
            return resultados[i];
        }
    }

    printf("\nNenhum cliente possui o CPF '%s'.\n", confirmacao);
    return NULL;
}


void mostrar_cliente_completo(Cliente* cliente) {
    if (!cliente) {
        printf("Cliente inválido!\n");
        return;
    }
    
    printf("\n-----------------DADOS DO CLIENTE-----------------\n");
    printf("--------------------------------------------------\n");
    printf("NOME: %s\n", cliente->nome);
    printf("CPF: %s\n", cliente->cpf);
    printf("E-MAIL: %s\n", cliente->email);
    printf("TELEFONE: %s\n", cliente->telefone);
    printf("--------------------------------------------------\n");

    
    printf("\nPressione ENTER para continuar...");
    getchar(); 

}





//--------------------------------  MENU CLIENTE ===============================

void menuClientes(Cliente *cabeca) {

    int opcao;
    do {

        printf("\n===================================\n");
        printf("           MENU CLIENTES           \n");
        printf("===================================\n");
        printf("1.  Adicionar\n");
        printf("2.  Listar\n");
        printf("3.  Remover\n");
        printf("4.  Editar\n");
        printf("5.  Buscar\n");
        printf("0.  Voltar\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao);


        if (opcao == 1) {

            char cpf_temp[15];
            char nome_temp[100];
            char email_temp[100];
            char telefone_temp[20];

            printf("\nDigite o cpf: ");
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
            printf("\nDigite o cpf do cliente que deseja remover: ");
            scanf(" %14s" , cpf_remover);

            removerCliente(cpf_remover , cabeca);
        } 
        
        else if (opcao == 4){  

            printf("\nDigite o CPF do cliente que deseja editar: ");
            char cpf_editar[15];
            scanf(" %14s" , cpf_editar);
            editarCliente(cpf_editar , cabeca);

        }

        else if (opcao == 5){ //buscar cliente

            buscar_cliente(cabeca);
        } 

        else if (opcao == 0) {
            printf("Voltando ao menu principal...\n");
        }
        
        else {
            printf("Opcao invalida\n");
        }
    } 
    
    while (opcao != 0);
}

