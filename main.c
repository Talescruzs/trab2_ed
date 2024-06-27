#include "heap.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// codigo de https://noic.com.br/materiais-informatica/curso/aula-16-estruturas-de-dados-iii-heap-fila-de-prioridade/
#define MAXN 100

int main(){
    // int heap[MAXN];
    // int tamanho_heap = 0;
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
            // printf("Tamanho do heap = %d\n", tamanho_heap);
        }
        else if(op==2){
            // printf("Digite valor:\n");
            // scanf("%d", &n);
            printf("Remover %d\n", h->dados[0]);
            remove_heap(h);
            // printf("Tamanho do heap = %d\n", tamanho_heap);
        }
        else if(op==3){
            // for(int i = 0; i<tamanho_heap; i++){
            //     printf("%d ", heap[i]);
            // }
            // printf("\n");
            printf("Imprimir heap\n");
            imprime(h);
        }
        else{
            break;
        }
    }
    
    return 0;
}