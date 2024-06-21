#ifndef HEAP_H
#define HEAP_H

int pai(int i);
int esquerda(int i);
int direita(int i);

void heapify_up(int v);
void heapify_down(int v);

void insere(int valor);
void deleta(int posicao);

#endif