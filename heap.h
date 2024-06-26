#ifndef HEAP_H
#define HEAP_H

int pai(int i);
int esquerda(int i);
int direita(int i);

void heapify_up(int *heap, int v);
void heapify_down(int *heap, int v, int tam);

void imprime(int *heap, int pos, int tam, int espacos);
void insere(int *heap, int valor, int *tam);
void deleta(int *heap, int posicao, int *tam);

#endif