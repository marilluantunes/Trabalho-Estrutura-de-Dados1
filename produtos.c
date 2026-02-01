#include "funcoes.h"

typedef struct _produto{
    char nome[50];
    int quantidade;
    int codigo;
    float preco;
}Produto;

typedef struct estoque_completo{
    Produto *produto;
    Produto *prev;
    Produto *prox;
}Estoque;

typedef struct carrinho{
    Produto *produto;
    Produto *prox;
}Carrinho;

//funcao para criar uma struct para o produto singular e, caso o produto sendo acrescentado ja exista, somente eh incrementada a quantidade
Produto* criar_struct(Estoque *primeiro)
{
    int i;
    Produto *ptr = (Produto*)malloc(sizeof(Produto));
    if (ptr == NULL) {printf("Erro de alocacao da memoria\n");
        return NULL;}
    else{
        printf("Comece digitando o codigo unico:\n--> ");
        scanf("%d", &ptr -> codigo); //limpar buffer??
            Produto *k = busca_pelo_codigo(ptr->codigo, primeiro);
            if (k != NULL){ //se o codigo ja estiver armazenado no estoque, este caso vai acrescentar mais produtos
                printf("Produto já existente no sitema.\nQuantos deseja acrescentar?\n--> ");
                scanf("%d", &i);
                k-> quantidade += i;
                printf("Produto incrementado com sucesso!\n");
                free(k);
                return NULL;
            }
        printf("Nome do produto:\n--> ");
        scanf("%50[^\n]", &ptr -> nome);
        printf("Quantos desse produto voce gostaria de armazenar?\n--> ");
        scanf("%d", &ptr -> quantidade);
        printf("Qual o preco do produto?\n--> ");
        scanf("%f", &ptr -> preco);
        return ptr;}
}

Estoque* busca_recursiva(Estoque *ptr){
    if (ptr->prox == NULL) return ptr;
    else busca_recursiva(ptr->prox);
}


//este eh para buscar o penultimo para conseguirmos implementar uma struct dupla no estoque
Estoque* busca_recursiva_anterior(int i, Estoque *ptr, Estoque *ptr1){ //int i sempre ser zero ao chamar
    if (ptr->prox == NULL) return ptr1;
    i ++;
    if (i>1) busca_recursiva_anterior(i, ptr->prox,ptr1->prox);
    else busca_recursiva_anterior(i, ptr->prox, ptr1);
}

Produto* busca_pelo_codigo(int x, Estoque *ptr){ //lembrar de linkar este --feito
    Produto *ptr2 = ptr->produto;
    if(ptr2 -> codigo == x) return ptr2;
    else{
        if (ptr->prox == NULL) return NULL;
        else{
        return busca_pelo_codigo(x, ptr);}
    }
}



//ao iniciar o sistema, o programa deve fazer isso imediatamente
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
    if (ptr-> produto == NULL){
    ptr-> produto = criar_struct(ptr);}
    else{
        Estoque *novo = criar_estoque();           //acrescentar produto ao estoque
        novo -> produto = criar_struct(ptr);  
            if (novo == NULL){
                free(ptr->produto);
                free(ptr->prox);
                free(ptr->prev);
                free(ptr);
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
    if (ptr-> produto == NULL){printf("Estoque vazio\n");
        exit(1);
    }
    else{
        Produto *ptr2 = ptr->produto;
        printf("Produto: %s\n", ptr2->nome);
        printf("Quantidade: %d\n", ptr2->quantidade);
        printf("Preco: %f\n", ptr2-> preco);
        printf("Codigo: %d\n", ptr2-> codigo);
        if(ptr->prox != NULL) exibir_lista_de_estoque(ptr->prox);
        }
    }


void editar_dados_do_produto(Estoque* ptr)
{
    int i, j;
    printf("Digite o cogido do produto\n");
    scanf("%d", &i);
    Produto* n = busca_pelo_codigo(i, ptr);
    printf("O que você gostaria de editar?\n::[1] -- Nome\n::[2] -- Quantidade\n::[3] -- Codigo\n::[4] -- Preco\n");
    scanf("%d", &j);
    if (j == 1){            //fazer case defaut
        scanf("%50[^\n]", n->nome);
        return;
    }
    if(j == 2){;
        scanf("%d", n->quantidade);
        return;
    }
    if(j == 3){
        scanf("%d", n->codigo);
        return;
    }
    if(j == 4){
        scanf("%d", n->preco);
        return;
    }
    else printf("Numero invalido\n");
}

void retirar_produtos(Estoque* ptr)
{
    int quantidade, x;
    char c;
    printf("Quantos produtos voce deseja retirar?\n");
    scanf("%d", quantidade);
    for(int i = 0; i<quantidade; i++);
    {
        printf("Digite o codigo do produto\n");
        scanf("%d", x);
        Produto *P = busca_pelo_codigo(x, ptr);
        printf("Produto: %s\n", P->nome);
        printf("Quantidade: %d\n", P->quantidade);
        printf("Preco: %f\n", P-> preco);
        printf("Codigo: %d\n", P-> codigo);
        printf("Gostaria de deletar?\nS/N");
        c = getchar();
        if (c == 'S'){ //uso de lista dupla para apagar o atual
            Estoque* novo = ptr->prev;
            novo->prox = ptr->prox;
            free(ptr->produto); //perguntar se isto nao apaga os ponteiros anteriores mas so o ponteiro atual
            free(ptr->prox);
            free(ptr->prev);
            printf("Produto deletado com sucesso!\n");
        }
        else{
            printf("Ainda desejaria deletar algum produto?\nS/N");
            c = getchar();
            if(c == 'S') return retirar_produtos(ptr);
            else exit(1);
        }
    }
}

// simulacao de um menu
int main(){
    int i;
    Estoque *ptr = criar_estoque(); //este deve estar na main e devera conversar com as funcoes subsequentes
    cadastrar_produto(ptr);
    scanf("%d", &i);
    busca_pelo_codigo(i, ptr->produto);
    editar_dados_do_produto(ptr);
    retirar_produtos(ptr);

}

// Produto *inicio = NULL;

/*void cadastrar_produto()
{   
    char nome_do_produto[50];
    
    printf("::::Quantos produtos serao cadastrados?\n--> ");
    scanf("%d", &quantidade);
    //ultimo();
    for(int i = 0; i<quantidade; i++){
        Produto *ptr = criar()
        if (ptr == NULL){
            printf("falha")
            continue; //fazer direito
        }
        
        
    
    }
}
*/
/*funcao para descobrir o ultimo item dos produtos
int ultimo(){
    while(1){
        if (inicio == NULL) return NULL;
        else return 0; 
    }
}
*/
