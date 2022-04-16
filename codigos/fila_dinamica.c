#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int dado;
    struct NO *prox;
}No;

typedef struct Fila{
    No *ini;
    No *fim;
}fila;

void inicializaFila(fila *f){
    f->ini=NULL;
    f->fim=NULL;
}
void enfileira(int dado, fila *f){
    No *ptr = (No*)malloc(sizeof(No));
    if(ptr==NULL){
        printf("Erro de alocacao!\n");
        return;
    }else{
        ptr->dado = dado;
        ptr->prox = NULL;
        if (f->ini == NULL){
            f->ini = ptr;
            
        }else{
            f->fim->prox=ptr;
        }
        f->fim = ptr;
    }
}

int desenfileira(fila *f){
    No *ptr= f->ini;
    int dado;
    if(ptr!=NULL){
        f->ini =ptr->prox;
        ptr->prox=NULL;
        dado=ptr->dado;
        free(ptr);
        if(f->ini == NULL){
            f->fim = NULL;
        }
        return dado;
    }else{
        printf("Fila vazia!\n");
        return;
    }
}

void imprimeFila(fila *f){
    No *ptr = f->ini;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("%d ", ptr->dado);
            ptr= ptr->prox;
        }
        printf("\n");
    }else {
        printf("Fila vazia!\n");
    }

}
int main(){
    fila *f = (fila*) malloc(sizeof(fila));
    if(f == NULL){
        printf("Erro de alocacao!");
        exit(-1);
    }else{
        inicializaFila(f);

        enfileira(10, f);
        enfileira(20, f);
        enfileira(30, f);
        enfileira(40, f);
        enfileira(50, f);

        imprimeFila(f);

        printf("Tentando desenfileirar - resultado %d\n", desenfileira(f));
        imprimeFila(f);
        printf("Tentando desenfileirar - resultado %d\n", desenfileira(f));
        imprimeFila(f);
        printf("Tentando desenfileirar - resultado %d\n", desenfileira(f));
        imprimeFila(f);
        printf("Tentando desenfileirar - resultado %d\n", desenfileira(f));
        imprimeFila(f);
        printf("Tentando desenfileirar - resultado %d\n", desenfileira(f));
        imprimeFila(f);
        
    }
    return 0;
}