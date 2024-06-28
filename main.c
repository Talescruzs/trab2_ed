#include "heap.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXN 100

int main(){
    Heap h = cria_heap();
    int op, n;
    while(1){
        printf("1 - inserir\n2- remover\n3 - imprimir heap\n");
        scanf("%d", &op);
        if(op==1){
            printf("Digite valor:\n");
            scanf("%d", &n);
            printf("Inserir %d\n", n);
            insere(h, n);
        }
        else if(op==2){
            printf("Remover %d\n", h->dados[0]);
            remove_heap(h);
        }
        else if(op==3){
            printf("Imprimir heap\n");
            imprime(h);
        }
        else{
            break;
        }
    }
    
    return 0;
}