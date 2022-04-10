#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100
/* 1) desempilhar N vezes - implemente uma função capaz de receber uma pilha como argumento e um valor N e, caso a pilha não esteja vazia, deve-se efetuar N desempilhamentos sucessivos; Cuidado quando o argumento N for maior que a quantidade de elementos da pilha;
2) consultar topo - implemente uma função capaz de receber uma pilha como argumento e retornar o elemento que se encontra no topo da pilha; */
typedef struct {
    int vet[MAXTAM];
    int Topo;
}Pilha;

int IsEmpty(Pilha *p){
    if(p->Topo == -1){
        return 1;
    }
    else {
        return 0;
    }
}

int IsFull(Pilha *p){
    if(p->Topo== MAXTAM-1){
        return 1;
    }
    else{
        return 0;
    }
}

void Push(Pilha *p, int x){
    if(IsFull(p)==1){
        printf("\nERRO: Pilha cheia!");
    }
    else{
        p->Topo++;
        p->vet[p->Topo] = x;
    }
    
}

int Pop(Pilha *p){
    int aux;
    if(IsEmpty(p)==1){
        printf("\nERRO: Pilha vazia!");
    }
    else{
        aux = p->vet[p->Topo];
        p->Topo--;
        return aux;
    }

}

int main(){
    Pilha *p=(Pilha*)malloc(sizeof(Pilha));
    p->Topo=-1;
    Push(p, 10);
    Push(p, 20);
    Push(p, 30);
    Pop(p);
    return 0;
}

