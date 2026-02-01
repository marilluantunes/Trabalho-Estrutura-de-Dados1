#include "funcoes.h"

typedef struct _produto{
    char nome[50];
    int quantidade;
    int codigo;
    int preco;
}Produto;

typedef struct estoque_completo{
    Produto *produto;
    Produto *prox;
}Estoque;

typedef struct carrinho{
    Produto *produto;
    Produto *prox;
}Carrinho;




//funcao para criar uma struct para o produto singular
Produto* criar_struct()
{
    Produto *ptr = (Produto*)malloc(sizeof(Produto));
    if (ptr == NULL) {printf("Erro de alocacao da memoria");
        return NULL;}
    else{
        printf("Comece digitando o codigo unico:\n--> ");
        scanf("%d", &ptr -> codigo); //limpar buffer??
        printf("Nome do produto:\n--> ");
        scanf("%50[^\n]", &ptr -> nome);
        printf("Quantos desse produto voce gostaria de armazenar?\n--> ");
        scanf("%d", &ptr -> quantidade);
        printf("Qual o preco do produto?\n--> ");
        scanf("%d", &ptr -> preco);
        return ptr;}
}

Estoque* busca_recursiva(Estoque *ptr){
    if (ptr->prox == NULL) return ptr;
    else busca_recursiva(ptr->prox);
}

//ao iniciar o sistema, o programa deve fazer isso imediatamente
Estoque* criar_estoque(){
    Estoque *ptr = (Estoque*)malloc(sizeof(Estoque));
    if (ptr == NULL) {printf("Erro ao criar estoque");
    return NULL;}
    else {
        ptr-> produto = NULL;
        ptr-> prox = NULL;
        return ptr; //linkar esta funcao com o cadastrar_produto
    }
}
void cadastrar_produto(Estoque *ptr){                 //o *head deve ser no inicio o ptr -> prox = NULL do criar_estoque e *novo 
    int quantidade;
    printf("Quantos produtos serao cadastrados?");
    scanf("%d", &quantidade);
    for (int i = 0; i < quantidade; i++){             //deve ser o ptr -> produto = NULL
    if (ptr-> produto == NULL){
    ptr-> produto = criar_struct();}
    else{
        Estoque *novo = criar_estoque();
        novo -> produto = criar_struct();              //acrescentar produto ao estoque
        Estoque *maisum = busca_recursiva(ptr);     //achar o ultimo valor do estoque e associar a um ponteiro
        maisum->prox = novo;                        //associar a nova struct de estoque(com o produto) com o final do estoque
    }                              
}
}


void exibir_lista_de_estoque(Estoqu *ptr){

}


void alterar_quantidade_do_produto_no_estoque(){

}


// simulacao de um menu
int main(){
    Estoque *ptr = criar_estoque();
    cadastrar_produto(&ptr);

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