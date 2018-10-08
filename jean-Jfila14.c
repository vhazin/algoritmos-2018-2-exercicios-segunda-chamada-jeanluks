#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
 int valor;
 struct lista *proximo;


}lista;


typedef struct Fila{

    lista *inicio;
    lista *fim;
    int tamanho;
    
}Fila;

    Fila *new();
    void add(Fila *fila,int dado);
    void remover(Fila *fila, int info);
    void print(Fila *fila);
int main(){
        Fila *fila = new();
    int nmrColocarPessoas,nmrTirarPessoas,colocarPessoas,tirarPessoas;

    printf("Digite o numero de pessoas que vai estar na fila: ");
    scanf("%d",&nmrColocarPessoas);
    printf("\n");
    for(int i=0;i<nmrColocarPessoas;i++){
        printf("Digite a %d pessoa da fila ",i+1);
        scanf("%d",&colocarPessoas);
        add(fila,colocarPessoas);
        
    }
    printf("Digite quantas pessoas vai sair da fila: ");
    scanf("%d",&nmrTirarPessoas);
    for(int i=0;i<nmrTirarPessoas;i++){
        printf("Escolha uma das pessoas para sair da file: ");
        scanf("%d",&tirarPessoas);
        remover(fila, tirarPessoas);
    }
    print(fila);
    printf("\n");

    return 0;
}


Fila *new(){
    Fila *fila = malloc(sizeof(fila));
    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;


}

void add(Fila *fila,int dado){
    lista  *novo = malloc(sizeof(novo));
    novo->valor = dado;
    
    if(fila-> inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;
        novo->proximo = NULL;
    }
    
    else{
        fila->fim->proximo = novo;
        fila->fim = novo;
        novo->proximo = NULL;
    }
    return;
}

void remover(Fila *fila, int info){
    lista *novo, *anterior;
    novo = fila->inicio;

    if (novo == NULL){
        return;
    }
    if (novo->valor == info){
        fila->inicio = novo->proximo;
        free(novo);
        return;
    }
    while(novo->valor != info){
        anterior = novo;
        novo = novo->proximo;
    }

    anterior->proximo = novo->proximo;
    free(novo);


}

void print(Fila *fila){
    while (fila->inicio != NULL){
        printf("%d ", fila->inicio->valor);
        fila->inicio = fila->inicio->proximo;
    }



}
