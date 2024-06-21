#include "heap.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// codigo de https://noic.com.br/materiais-informatica/curso/aula-16-estruturas-de-dados-iii-heap-fila-de-prioridade/
#define MAXN 1000100
int heap[MAXN];
int tamanho_heap;

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i = 1;i <= n;i++){
        
        char operacao;
        scanf(" %c", &operacao);
        
        if(operacao == 'I'){ // inserir um número
            int valor;
            scanf("%d", &valor);
            
            insere(valor);
        }
        
        if(operacao == 'D'){
            printf("%d\n", heap[1]); // imprime o valor do topo
            deleta(1);
        }
        
    }
    
    return 0;
}