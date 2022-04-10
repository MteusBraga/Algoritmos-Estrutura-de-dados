#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct Pilha{
    NO *topo
}Pilha;

void IniciarPilha(Pilha *p){
    p->topo=NULL;
}

void Push(int dado, Pilha *p){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr ==NULL){
        printf("erro de alocacao de novo nó\n");
        return;
    }
    else{
        ptr->dado=dado;
        ptr->prox=p->topo;
        p->topo=ptr;
    }
}

int Pop(Pilha *p){
    NO* ptr=p->topo;
    int dado;
    if(ptr==NULL){
        printf("Pilha vazia\n");
        return;
    }
    else{
        p->topo=ptr->prox;
        ptr->prox=NULL;
        dado=ptr->dado;
        free(ptr);
        return dado;
    }
}

void printPilha(Pilha *p){
    NO *ptr=p->topo;
    if(ptr==NULL){
        printf("Pilha vazia\n");
    }
    else{
        while(ptr!=NULL){
            printf("%d\n", ptr->dado);
            ptr=ptr->prox;

        }
        printf("\n");
    }
}
int main(){
    Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
    if(p1==NULL){
        printf("Erro de alocacao\n");
        exit(0);
    }
    else{
        IniciarPilha(p1);
        Push(10, p1);
        Push(20, p1);
        Push(30, p1);
        Push(40, p1);
        printPilha(p1);
        printf("Tentando desempilhar - resultado: %d\n ", Pop(p1));
        printPilha(p1);
        printf("Tentando desempilhar - resultado: %d\n ", Pop(p1));
        printPilha(p1);
        printf("Tentando desempilhar - resultado: %d\n ", Pop(p1));
        printPilha(p1);
    }
    return 0;
}