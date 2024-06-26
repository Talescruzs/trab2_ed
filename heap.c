#include "heap.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// codigo de https://noic.com.br/materiais-informatica/curso/aula-16-estruturas-de-dados-iii-heap-fila-de-prioridade/

int pai(int i){
    return i/2;
}

int esquerda(int i){
    return 2*i;
}

int direita(int i){
    return 2*i+1;
}

void swap(int *v1, int *v2){
    int temp = *v1;
    *v2 = *v1;
    *v1 = temp;
}

void heapify_up(int *heap, int v){
    
    if(v == 1) return; // se estivermos no topo, fazemos mais nada
    
    int p = pai(v);
    if(heap[v] > heap[p]){
        
        // se o valor da posição v for maior que o de seu pai,
        // temos que fazer a troca dos dois e chamar a função em p
        
        swap(&heap[v], &heap[p]);
        heapify_up(heap, p);
    }
}

void heapify_down(int *heap, int v, int tam){

    int d = direita(v);
    int e = esquerda(v);
    
    int maior = v; // no fim, maior terá a maior das posições
    
    // comparamos com cada um dos filhos.
    // temos que checar, também, se os filhos existem
    if(d <= tam && heap[d] > heap[v]) maior = d;
    if(e <= tam && heap[e] > heap[maior]) maior = e;
    
    if(maior != v){ 
        // se v não for o maior, temos que trocar com o maior dos filhos
        // e chamamos a função para ele
        
        swap(&heap[v], &heap[maior]);
        heapify_down(heap, maior, tam);
    }
}

void imprime(int *heap, int pos, int tam, int espacos){
    int d = direita(pos+1);
    int e = esquerda(pos+1);
    // printf("%d %d\n", e, d);
    if(pos<=tam){
        for(int i=0; i<espacos; i++){
            printf("    ");
        }
        imprime(heap, e, tam, espacos+1);
        printf("%d\n", heap[pos]);
        for(int i=0; i<espacos; i++){
            printf("    ");
        }
        imprime(heap, d, tam, espacos+1);
        printf("\n");
    }
}

void insere(int *heap, int valor, int *tam){
    
    // atualizamos o tamanho da heap e inserimos no fim do array
    heap[*tam] = valor;
    *tam = (*tam)+1;
    
    // agora, chamamos o heapify_up
    heapify_up(heap, *tam);
}

void deleta(int *heap, int posicao, int *tam){
    
    // esta função deleta um número e qualquer
    // posição da heap, porém, na prática, só
    // irá ser usada para remover o topo da heap
    
    // trocamos com o número do fim e atualizamos o tamanho
    swap(&heap[posicao], &heap[*tam]);
    *tam = (*tam)-1;
    
    // chamamos a heapify_down
    heapify_down(heap, posicao, *tam);
}