#ifndef HEAP_H
#define HEAP_H

typedef struct heap{
    int tam;
    int pos;
    int *dados;
} *Heap;

Heap cria_heap();

void imprime(Heap h);
void insere(Heap h, int v);
int remove_heap(Heap h);

#endif