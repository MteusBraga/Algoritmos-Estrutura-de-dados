/* 1) desempilhar N vezes - implemente uma função capaz de receber uma pilha como argumento e um valor N e, caso a pilha não esteja vazia, deve-se efetuar N desempilhamentos sucessivos; Cuidado quando o argumento N for maior que a quantidade de elementos da pilha;
2) consultar topo - implemente uma função capaz de receber uma pilha como argumento e retornar o elemento que se encontra no topo da pilha; */
#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct {
    int vet[MAXTAM];
    int Topo;
}Pilha;
int ConsultarTopo(Pilha *p){
    if(IsEmpty(p)==1){
        return 0;
    }
    else{
        int aux;
        aux=p->vet[p->Topo];
        return aux;
    }
    
}

void MultiPop(Pilha *p, int x){
    int tam=Size(p);
    for (int i=0;i < x;i++){
        if(IsEmpty(p)==1){
            printf("ERRO:Pilha vazia!");
            break;
        }
        else if(tam<x){
            printf("ERRO:Voce quer remover elementos demais!");
            break;
        }
        else if(tam==x){
            p->Topo--;
        }
        else{
            p->Topo--;
        }
    }
}
int Size(Pilha *p){
    int tamanho;
    tamanho=p->Topo+1;
    return tamanho;
}

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
    Push(p, 40);
    Push(p, 50);
    MultiPop(p, 6);
    int topo;
    topo =ConsultarTopo(p);
    printf("\nTopo da pilha: %d", topo);
    int tam;
    tam=Size(p);
    printf("\nTamanho da pilha: %d", tam);
    return 0;
}

