#include "heap.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

Heap cria_heap(){
    Heap h = malloc(sizeof(struct heap));
    h->tam = 10;
    h->dados = malloc(sizeof(int)*h->tam);
    h->pos = 0;
    return h;
}
void dobra_heap(Heap h){
    h->tam = h->tam*2;
    h->dados = realloc(h->dados, sizeof(int)*h->tam);
}
void corta_heap(Heap h){
    h->tam = h->tam/2;
    h->dados = realloc(h->dados, sizeof(int)*h->tam);
}
int pai(int i){
    return i/2;
}
int esquerda(int i){
    return 2*i+1;
}
int direita(int i){
    return 2*i+2;
}
void troca(int *v1, int *v2){
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}
void baixo_cima(Heap h, int pos){

    if(pos == 0) return;
    int p = pai(pos);
    if(h->dados[pos] > h->dados[p]){
        troca(&h->dados[pos], &h->dados[p]);
        baixo_cima(h, p);
    }
}

void cima_baixo(Heap h, int pos){

    int d = direita(pos);
    int e = esquerda(pos);
    int maior = pos; 
    if(d < h->pos && h->dados[d] > h->dados[pos]) maior = d;
    if(e < h->pos && h->dados[e] > h->dados[maior]) maior = e;
    
    if(maior != pos){ 
        troca(&h->dados[pos], &h->dados[maior]);
        cima_baixo(h, maior);
    }
}
void imprime(Heap h){
    for(int i=0; i<h->pos; i++){
        printf("esq %d dir %d pos %d\n", esquerda(i), direita(i), i);

        printf("Nó %d: ", h->dados[i]);
        if(esquerda(i)>=h->pos){
            printf("filho esq: vazio, ");
        }
        else{
            printf("filho esq: %d, ", h->dados[esquerda(i)]);
        }
        if(direita(i)>=h->pos){
            printf("filho dir: vazio\n");
        }
        else{
            printf("filho dir: %d\n", h->dados[direita(i)]);
        }
    }
}
void insere(Heap h, int v){
    if(h->pos>=h->tam){
        dobra_heap(h);
    }
    h->dados[h->pos] = v;
    
    baixo_cima(h, h->pos);
    h->pos++;
}

int remove_heap(Heap h){
    if(h->pos<=0){
        printf("Heap vazia\n");
        return 0;
    }
    int removido = h->dados[0];
    h->pos--;
    troca(&h->dados[h->pos], &h->dados[0]);
    
    cima_baixo(h, 0);
    return removido;
}