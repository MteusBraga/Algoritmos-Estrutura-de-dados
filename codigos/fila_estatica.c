#include <stdio.h>
#include <stdlib.h>
#define N 3


typedef struct Fila{
    int dados[N];
    int fim;
}Fila;
//tentando criar o clone por um vetor
int ClonaFila_vetor(Fila *f){
    int vet[N];
    for(int i=0;i<f->fim;i++){
        vet[i] = f->dados[i];
    }
    return vet;
}
//tentando criar o clone por uma fila
Fila* ClonaFila_fila(Fila *f){
    Fila *f1=(Fila*)malloc(sizeof(Fila));
    for(int i=0;i<f->fim;i++){
        f1->dados[i] = f->dados[i];
    }
    return f1;
}


void IniciaFila(Fila *f){
    for (int i=0; i<N;i++){
        f->dados[i] = 0;
    }
    f->fim = 0;
}

void Enfileira(int x, Fila *f){
    if(f->fim == N){
        printf("Fila cheia!\n");
        return;
    }
    else{
        f->dados[f->fim] = x;
        f->fim++;
    }
}

int Desenfileira(Fila *f){
    int aux;
    if(f->fim ==0){
        printf("Fila vazia!\n");
        return;
    }
    else{
        aux = f->dados[0];
        for (int i=0;i<N;i++){
            f->dados[i]= f->dados[i + 1];
        }
        f->fim --;
        return aux;
    }
}

void PrintFila(Fila *f){
    printf("imprimindo a Fila\nINICIO -> ");
    for (int i=0; i<f->fim;i++){
        printf("%d ", f->dados[i]);
    }
    printf("<-FIM\n\n");
}

int main(){
    Fila *f=(Fila*)malloc(sizeof(Fila));
    Fila *clonef;
    
    IniciaFila(f);
    Enfileira(10, f);
    Enfileira(20, f);
    Enfileira(30, f);
    Enfileira(40, f);
    PrintFila(f);
    clonef=ClonaFila_fila(f);
    PrintFila(clonef);
    return 0;
}
