#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// codigo de https://noic.com.br/materiais-informatica/curso/aula-16-estruturas-de-dados-iii-heap-fila-de-prioridade/
#define MAXN 1000100
int heap[MAXN];
int tamanho_heap;
int pai(int i){
    return i/2;
}

int esquerda(int i){
    return 2*i;
}

int direita(int i){
    return 2*i+1;
}

void heapify_up(int v){
    
    if(v == 1) return; // se estivermos no topo, fazemos mais nada
    
    int p = pai(v);
    if(heap[v] > heap[p]){
        
        // se o valor da posição v for maior que o de seu pai,
        // temos que fazer a troca dos dois e chamar a função em p
        
        int temp = heap[v];
        heap[v] = heap[p];
        heap[p] = temp;
        heapify_up(p);
    }
}

void heapify_down(int v){

    int d = direita(v);
    int e = esquerda(v);
    
    int maior = v; // no fim, maior terá a maior das posições
    
    // comparamos com cada um dos filhos.
    // temos que checar, também, se os filhos existem
    if(d <= tamanho_heap && heap[d] > heap[v]) maior = d;
    if(e <= tamanho_heap && heap[e] > heap[maior]) maior = e;
    
    if(maior != v){ 
        // se v não for o maior, temos que trocar com o maior dos filhos
        // e chamamos a função para ele
        int temp = heap[v];
        heap[v] = heap[maior];
        heap[maior] = temp;
        heapify_down(maior);
    }
}

void insere(int valor){
    
    // atualizamos o tamanho da heap e inserimos no fim do array
    tamanho_heap++;
    heap[tamanho_heap] = valor;
    
    // agora, chamamos o heapify_up
    heapify_up(tamanho_heap);
}

void deleta(int posicao){
    
    // esta função deleta um número e qualquer
    // posição da heap, porém, na prática, só
    // irá ser usada para remover o topo da heap
    
    // trocamos com o número do fim e atualizamos o tamanho
    int temp = heap[posicao];
    heap[posicao] = heap[tamanho_heap];
    heap[tamanho_heap] = temp;
    
    tamanho_heap--;
    
    // chamamos a heapify_down
    heapify_down(posicao);
}


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
