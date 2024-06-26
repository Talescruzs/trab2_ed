#include "heap.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// codigo de https://noic.com.br/materiais-informatica/curso/aula-16-estruturas-de-dados-iii-heap-fila-de-prioridade/
#define MAXN 100

int main(){
    int heap[MAXN];
    int tamanho_heap = 0;

    int op, n;
    while(1){
        printf("1 - inserir\n2- remover\n3 - imprimir heap\n");
        scanf("%d", &op);
        if(op==1){
            printf("Digite valor:\n");
            scanf("%d", &n);
            printf("Inserir %d\n", n);
            insere(heap, n, tamanho_heap);
        }
        else if(op==2){
            printf("Digite valor:\n");
            scanf("%d", &n);
            printf("Remover %d\n", n);
            deleta(heap, n, tamanho_heap);
        }
        else if(op==3){
            for(int i = 0; i<tamanho_heap; i++){
                printf("%d ", heap[i]);
            }
            printf("\n");
            printf("Imprimir heap\n");
        }
        else{
            break;
        }
    }
    // for(int i = 1;i <= n;i++){
    //     char operacao;
    //     scanf(" %c", &operacao);
    //     if(operacao == 'I'){ // inserir um número
    //         int valor;
    //         scanf("%d", &valor);
    //         insere(valor);
    //     }
    //     if(operacao == 'D'){
    //         printf("%d\n", heap[1]); // imprime o valor do topo
    //         deleta(1);
    //     }
    // }
    
    return 0;
}