#include "produtos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include <string.h>

Produto* busca_pelo_codigo(int x, Estoque *ptr){
    printf("teste0\n");
    if(ptr->produto == NULL) return NULL;
    printf("teste1\n");
    if(ptr->produto->codigo == x) {
        printf("teste2\n");
        return ptr->produto;}
    printf("testeabc");
    if (ptr->prox == NULL){printf("teste3\n");
        return NULL;
    }
    else{printf("teste4\n");
    return busca_pelo_codigo(x, ptr->prox);
    }
    }

Produto* criar_struct(Estoque *primeiro)
{
    int i;
    Produto *ptr = (Produto*)malloc(sizeof(Produto));
    if (ptr == NULL) {printf("Erro de alocacao da memoria\n");
        return NULL;}
    else{
        printf("Digite o codigo unico:\n--> ");
        scanf("%d", &ptr -> codigo); //limpar buffer??
            Produto *k = busca_pelo_codigo(ptr->codigo, primeiro);
            if (k != NULL){ //se o codigo ja estiver armazenado no estoque, este caso vai acrescentar mais produtos
                printf("Produto ja existente no sitema.\nQuantos deseja acrescentar?\n--> ");
                scanf("%d", &i);
                k-> quantidade += i;
                printf("Produto incrementado com sucesso!\n");
                free(k);
                return NULL;
            }
        getchar();
        printf("Nome do produto:\n--> ");
        scanf("%50[^\n]", ptr -> nome);
        printf("Quantos desse produto voce gostaria de armazenar?\n--> ");
        scanf("%d", &ptr -> quantidade);
        printf("Qual o preco do produto?\n--> "); //recursao infinita ao retornar apos terceiro caso
        scanf("%f", &ptr -> preco);
        getchar();
        printf("\n");
        return ptr;}
}

Estoque* busca_recursiva(Estoque *ptr){  //alertando ser tipo produto
    if (ptr->prox == NULL) return ptr;
    else return busca_recursiva(ptr->prox);
}

//este eh para buscar o penultimo para conseguirmos implementar uma struct dupla no estoque
Estoque* busca_recursiva_anterior(int i, Estoque *ptr, Estoque *ptr1){ //int i sempre ser zero ao chamar
    if (ptr->prox == NULL) return ptr1;
    i ++;
    if (i>1) return busca_recursiva_anterior(i, ptr->prox,ptr1->prox);
    else return busca_recursiva_anterior(i, ptr->prox, ptr1);
}

Estoque* busca_recursiva_anterior_especifica(Estoque *ptr, int i){
    while (ptr->prox != NULL)
    {
        if (ptr->produto->codigo == i){
            return ptr;
        }
        else ptr = ptr->prox;
    }
    return NULL;
    
}


/*Estoque* busca_recursiva_anterior_especifica(int j, int i, int k, Estoque *ptr, Estoque *ptr1){ //int i sempre ser zero ao chamar
    if (ptr->produto->codigo == j){
        if (k == 0) return ptr1;
        else return ptr;
    }
    i ++;
    if (i>1) return busca_recursiva_anterior_especifica(j,i,k, ptr->prox,ptr1->prox);
    else return busca_recursiva_anterior_especifica(j,i,k, ptr->prox, ptr1);
}*/



Estoque* criar_estoque(){
    Estoque *ptr = (Estoque*)malloc(sizeof(Estoque));
    if (ptr == NULL) {printf("Erro ao criar estoque\n");
    return NULL;}
    else {
        ptr-> produto = NULL;
        ptr-> prev = NULL;
        ptr-> prox = NULL;
        return ptr; //linkar esta funcao com o cadastrar_produto
    }
}

void cadastrar_produto(Estoque *ptr){                 //o *head deve ser no inicio o ptr -> prox = NULL do criar_estoque e *novo 
    int quantidade;
    printf("Quantos produtos serao cadastrados?\n--> ");
    scanf("%d", &quantidade);
    for (int i = 0; i < quantidade; i++){             //deve ser o ptr -> produto = NULL
    if (i !=0) printf("Proximo produto:\n");
    if (ptr-> produto == NULL){
    ptr-> produto = criar_struct(ptr);}
    else{
        Estoque *novo = criar_estoque();           //criar mais um node e acrescentar produto ao estoque
        if (novo == NULL) return; //caso falhe, retornara null e assim a funcao cadastrar_produto acaba
        novo -> produto = criar_struct(ptr);  
            if (novo ->produto == NULL){ //caso o produto a ser acrescentado ja exista entao eh incrementado a esse produto e o novo estoque
                free(novo);
                continue;}             
        Estoque *maisum = busca_recursiva(ptr);     //achar o ultimo valor do estoque e associar a um ponteiro
        Estoque *maisdois = busca_recursiva_anterior(0, ptr, ptr);
        maisum->prox = novo; 
        maisum->prev = maisdois;
        free(novo);                   //associar a nova struct de estoque(com o produto) com o final do estoque
    }                              
}
}

void exibir_lista_de_estoque(Estoque *ptr){
    if (ptr == NULL)
        return;

    if (ptr->produto != NULL){
        Produto *p = ptr->produto;
        printf("Produto: %s\n", p->nome);
        printf("Quantidade: %d\n", p->quantidade);
        printf("Preco: R$%.2f\n", p->preco);
        printf("Codigo: %d\n\n", p->codigo);
    }

    exibir_lista_de_estoque(ptr->prox);
}


void editar_dados_do_produto(Estoque* ptr)
{
    int i, j;
    printf("Digite o cogido do produto\n");
    scanf("%d", &i);
    Produto* n = busca_pelo_codigo(i, ptr);
    if (n==NULL){
        printf("Produto nao encontrado\n");
        editar_dados_do_produto(ptr);
    }
    while(1){
    printf("O que voce gostaria de editar?\n::[1] -- Nome\n::[2] -- Quantidade\n::[3] -- Codigo\n::[4] -- Preco\n"); 
    scanf("%d", &j);
    getchar();
    if (j == 1){            //fazer case defaut
        printf("Digite o novo nome\n-->");
        /*
        char s[50];
        char c;
        scanf("%s", novo_nome);
        printf("Gostaria de mudar %s para %s?\nS/N", ptr->nome, novo_nome);
        scanf(" %c", c);
        if(c == 'S') novo->nome = novo_nome;
        */
        scanf("%50[^\n]", n->nome);
        printf("\n");
        return;
    }
    if(j == 2){;
        printf("Digite a nova quantidade\n-->");
        scanf("%d", &n->quantidade);
        printf("\n");
        return;
    }
    if(j == 3){
        printf("Digite o novo codigo\n-->");
        scanf("%d", &n->codigo);
        printf("\n");
        return;
    }
    if(j == 4){
        printf("Digite o novo preco\n-->");
        scanf("%f", &n->preco);
        printf("\n");
        return;
    }
    else {printf("Numero invalido\n");
    }
}
}
Estoque* retirar_produtos(Estoque* ptr)
{
    int quantidade, x;
    char c;
    printf("Quantos produtos voce deseja retirar?\n");
    scanf("%d", &quantidade);
    for(int i = 0; i<quantidade; i++)
    {
        printf("Digite o codigo do produto\n");
        scanf("%d", &x);
        Produto *P = busca_pelo_codigo(x, ptr);
        if (!P){
            printf("Produto nao encontrado\n");
            continue;
        }
        printf("Produto: %s\n", P->nome);
        printf("Quantidade: %d\n", P->quantidade);
        printf("Preco: R$%.2f\n", P-> preco);
        printf("Codigo: %d\n", P-> codigo);
        printf("Gostaria de deletar?\nS/N\n");
        scanf(" %c", &c);
        if (c == 'S' || c == 's'){ //uso de lista dupla para apagar o atual
            printf("teste1\n");
            Estoque* novo = busca_recursiva_anterior_especifica(ptr, x);
            printf("testea");
            if (novo->prev==NULL) {
                ptr = novo->prox;
            }
            Estoque* nov1 = novo->prev;
            printf("testeb");
            Estoque* nov2 = novo->prox;
            printf("testec");
            nov1->prox = nov2->prox; //lembrar de checar se a lista tambem funciona caso acrescentemos no inicio ou no final -- nao feito
            printf("teste2\n"); //perguntar se isto nao apaga os ponteiros anteriores mas so o ponteiro atual
            free(novo);
            printf("Produto deletado com sucesso!\n");
            
        }
        else{
            printf("Ainda desejaria deletar algum produto?\nS/N"); 
            scanf(" %c", &c);
            if(c == 'S') return retirar_produtos(ptr);
            else NULL;
        }
    }
}

/* 
int main(){
    Estoque *ptr = criar_estoque(); //este deve estar na main e devera conversar com as funcoes subsequentes
    cadastrar_produto(ptr);
    printf("testando\n");
    exibir_lista_de_estoque(ptr);
   // retirar_produtos(ptr);
   // exibir_lista_de_estoque(ptr); //este sempre vai devolver a nova cabeca ou NULL
    
    return 0;
}

*/

/* 

int main() {
    Estoque *e1 = criar_estoque();
    Estoque *e2 = criar_estoque();
    Estoque *e3 = criar_estoque();

    Produto *p1 = malloc(sizeof(Produto));
    Produto *p2 = malloc(sizeof(Produto));
    Produto *p3 = malloc(sizeof(Produto));

    strcpy(p1->nome, "arroz");
    p1->codigo = 1;
    p1->quantidade = 10;
    p1->preco = 22.0;

    strcpy(p2->nome, "feijao");
    p2->codigo = 2;
    p2->quantidade = 30;
    p2->preco = 32.0;

    strcpy(p3->nome, "acucar");
    p3->codigo = 3;
    p3->quantidade = 15;
    p3->preco = 18.0;

    e1->produto = p1;
    e2->produto = p2;
    e3->produto = p3;

    e1->prox = e2;
    e2->prev = e1;
    e2->prox = e3;
    e3->prev = e2;

    Produto *r1 = busca_pelo_codigo(1, e1);
    if (r1) printf("-----ACHOU-------%s\n", r1->nome);
    else printf("Nao achou\n");

    Produto *r2 = busca_pelo_codigo(2, e1);
    if (r2) printf("-----ACHOU-------%s\n", r2->nome);
    else printf("Nao achou\n");

    Produto *r3 = busca_pelo_codigo(3, e1);
    if (r3) printf("------ACHOU--------%s\n", r3->nome);
    else printf("Nao achou\n");

    Produto *r4 = busca_pelo_codigo(999, e1);
    if (r4) printf("-----achou------=%s\n", r4->nome);
    else printf("------NAO ACHOU--------\n");

    return 0;
}

*/

