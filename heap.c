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

void swap(int *v1, int *v2){
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void heapify_up(Heap h, int pos){
    
    if(pos == 0) return;

    int p = pai(pos);
    if(h->dados[pos] > h->dados[p]){
        swap(&h->dados[pos], &h->dados[p]);
        heapify_up(h, p);
    }
}

void heapify_down(Heap h, int pos){

    int d = direita(pos);
    int e = esquerda(pos);
    
    int maior = pos; // no fim, maior terá a maior das posições
    
    // comparamos com cada um dos filhos.
    // temos que checar, também, se os filhos existem
    if(d < h->pos && h->dados[d] > h->dados[pos]) maior = d;
    if(e < h->pos && h->dados[e] > h->dados[maior]) maior = e;
    
    if(maior != pos){ 
        // se v não for o maior, temos que trocar com o maior dos filhos
        // e chamamos a função para ele
        swap(&h->dados[pos], &h->dados[maior]);
        // swap(&heap[v], &heap[maior]);
        heapify_down(h, maior);
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
        // printf("filho esq: %d, filho dir: %d\n", h->dados[i], h->dados[esquerda(i)], h->dados[direita(i)]);
    }
    // for(int i = 0; i<h->pos; i++){
        // printf("%d ", h->dados[i]);
    // }
}

void insere(Heap h, int v){
    // atualizamos o tamanho da heap e inserimos no fim do array
    if(h->pos>=h->tam){
        dobra_heap(h);
    }
    h->dados[h->pos] = v;
    
    heapify_up(h, h->pos);
    h->pos++;
}

int remove_heap(Heap h){
    
    // trocamos com o número do fim e atualizamos o tamanho
    int removido = h->dados[0];
    h->pos--;
    printf("%d %d\n", h->dados[h->pos], h->dados[0]);
    swap(&h->dados[h->pos], &h->dados[0]);
    printf("%d %d\n", h->dados[h->pos], h->dados[0]);
    
    // chamamos a heapify_down
    heapify_down(h, 0);
    return removido;
}