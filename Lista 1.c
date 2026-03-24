#include<stdio.h>
#include<stdlib.h>

//FUNÇÃO PARA MOSTRAR VETOR
void imprimeVet (int v[], int n){
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}



//QUESTÃO 1
void bubbleSort (int v[], int n) {
    int i, j, temp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (v[j] > v[j+1]) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void questao_1 () {
    int v[] = {5, 3, 2, 4, 1};
    int n = 5;

    printf("Vetor original:\n");
    imprimeVet (v, n);

    bubbleSort(v, n);

    printf("\nVetor ordenado:\n");
    imprimeVet (v, n);
}



//QUESTÃO 2
void bubbleSortInstrumentado (int v[], int n){
    int i, j, temp;
    int trocas = 0, comparacoes = 0;

    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-1-i; j++){
            comparacoes++;

            if (v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                trocas++;
            }
        }
    }
    printf("\nComparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}

void questao_2(){
    int v[] = {5, 3, 2, 4, 1};
    int n = 5;

    printf("Vetor original:\n");
    imprimeVet (v, n);

    bubbleSortInstrumentado(v, n);

    printf("\nVetor ordenado:\n");
    imprimeVet (v, n);
}



//QUESTÃO 3
void bubbleSortOptimizado (int v[], int n) {
    int i, j, temp, houveTroca;
    int trocas = 0, comparacoes = 0;

    for (i = 0; i < n-1; i++) {
        houveTroca = 0;
        for (j = 0; j < n-i-1; j++) {
            comparacoes++;

            if (v[j] > v[j+1]) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                houveTroca = 1;
                trocas++;
            }
        }
        if (houveTroca == 0) {
            break;
        }
    }

    printf("\nComparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}
//Usar a flag melhora o desempenho pois, se o vetor ja estiver ordenado (melhor caso),
//o algoritmo nao ira realizar o bloco de ordenacao sem necessidade.

void questao_3(){
    int v[] = {5, 3, 2, 4, 1};
    int n = 5;

    printf("Vetor original:\n");
    imprimeVet (v , n);

    bubbleSortOptimizado(v, n);

    printf("\nVetor ordenado:\n");
    imprimeVet (v , n);
}



//QUESTÃO 4
void vetores_bubbleSortNormal (){
    int n2 = 20, i;
    int v_ordenado[n2];
    int v_reverso[n2];
    int v_aleatorio[] = {2, 5, 4, 7, 82, 65, 24, 13, 98, 130, 1, 10, 28, 34, 57, 15, 9, 3, 48, 100};

    for (i = 0; i < n2; i++){
        v_ordenado[i] = i + 1;
        v_reverso[i] = n2 - i;
    }

    printf("\n==== VETOR ORDENADO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_ordenado , n2);

    bubbleSortInstrumentado(v_ordenado, n2);

    printf("\nVetor ordenado:\n");
    imprimeVet(v_ordenado, n2);

    printf("\n\n");

    printf("==== VETOR REVERSO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_reverso , n2);

    bubbleSortInstrumentado(v_reverso, n2);

    printf("\nVetor ordenado:\n");
    imprimeVet(v_reverso, n2);

    printf("\n\n");

    printf("==== VETOR ALEATÓRIO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_aleatorio , n2);

    bubbleSortInstrumentado(v_aleatorio, n2);

    printf("\nVetor ordenado:\n");
    imprimeVet(v_aleatorio, n2);

    printf("\n\n");
}

void vetores_bubbleSortEarlyStop (){
    int n2 = 20, i;
    int v_ordenado[n2];
    int v_reverso[n2];
    int v_aleatorio[] = {2, 5, 4, 7, 82, 65, 24, 13, 98, 130, 1, 10, 28, 34, 57, 15, 9, 3, 48, 100};

    for (i = 0; i < n2; i++){
        v_ordenado[i] = i + 1;
        v_reverso[i] = n2 - i;
    }

    printf("==== VETOR ORDENADO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_ordenado , n2);

    bubbleSortOptimizado(v_ordenado, n2);

    printf("\nVetor ordenado:\n");
    imprimeVet(v_ordenado, n2);

    printf("\n\n");

    printf("==== VETOR REVERSO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_reverso , n2);

    bubbleSortOptimizado(v_reverso, n2);

    printf("\nVetor ordenado:\n");
    imprimeVet(v_reverso, n2);

    printf("\n\n");

    printf("==== VETOR ALEATÓRIO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_aleatorio , n2);

    bubbleSortOptimizado(v_aleatorio, n2);

    printf("\nVetor ordenado:\n");
    imprimeVet(v_aleatorio, n2);
}

void questao_4 (){
    printf("\n\n============ Bubble Sort Normal ============\n\n");
    vetores_bubbleSortNormal();

    printf("\n\n============ Bubble Sort Early Stop ============\n\n");
    vetores_bubbleSortEarlyStop();
}



//QUESTÃO 5
void bubbleSortOrdem (int v[], int n, int ordem) {
    int i, j, temp;

    if (ordem == 1){
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-1-i; j++) {
                if (v[j] > v[j+1]) {
                    temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
            }
        }

    }if (ordem == -1){
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-1-i; j++) {
                if (v[j] < v[j+1]) {
                    temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
            }
        }
    }
}

void questao_5 (){
    int n = 5, n0 = 0, n1 = 1;
    int v_vazio[] = {};
    int v_um[] = {2};
    int v_misturado[] = {5, -4, 3, -2, -1};
    int v_repetido[] = {3, 1, 3, 2, 3};

    printf("\n====Vetores orginais====\n");
    printf("Vetor vazio: [ ]\n");
    printf("Vetor unitario: [2]\n");
    printf("Vetor positivo e negativo: [5, -4, 3, -2, -1]\n");
    printf("Vetor repetido: [3, 1, 3, 2, 3]\n");

    printf("\n\n====Vetores após ordenção====\n");
    
    printf("\nVetor vazio\n");
    bubbleSortOrdem(v_vazio, n0, 1);
    imprimeVet(v_vazio, n0);

    printf("\nVetor unitario\n");
    bubbleSortOrdem(v_um, n1, 1);
    imprimeVet(v_um, n1);

    printf("\nVetor positivo e negativo (crescente)\n");
    bubbleSortOrdem(v_misturado, n, 1);
    imprimeVet(v_misturado, n);

    printf("\nVetor positivo e negativo (decrescente)\n");
    bubbleSortOrdem(v_misturado, n, -1);
    imprimeVet(v_misturado, n);

    printf("\nVetor repetido (crescente)\n");
    bubbleSortOrdem(v_repetido, n, 1);
    imprimeVet(v_repetido, n);

    printf("\nVetor repetido (decrescente)\n");
    bubbleSortOrdem(v_repetido, n, -1);
    imprimeVet(v_repetido, n);
    
    printf("\n");
}



//QUESTÃO 6
void selectionSort (int *V, int n) {
    int i, j, menor, temp;

    for (i = 0; i < n-1; i++) {
        menor = i;

        for (j = i+1; j < n; j++) {
            if (V[j] < V[menor]){
                menor = j;
            }
        }
        temp = V[i];
        V[i] = V[menor];
        V[menor] = temp;
    }

}

void questao_6(){
    int v[] = {5, 3, 2, 4, 1};
    int n = 5;

    printf("Vetor original:\n");
    imprimeVet (v , n);
    selectionSort(v, n);
    printf("\nVetor ordenado:\n");
    imprimeVet (v , n);
}



//QUESTÃO 7
void questao_7 (){
    printf("\nSelection Sort ('*' indica o menor elemento a ser trocado de posição em cada iteração, ignorando o que já foi ordenado)\n");
    printf("\nVetor original [64, 25, 12, 22, 11]\n\n");

    printf("(i = 0) Iteração 1: [64, 25, 12, 22, 11*]  => [11, 25, 12, 22, 64]\n");
    printf("(i = 1) Iteração 2: [11, 25, 12*, 22, 64]  => [11, 12, 25, 22, 64]\n");
    printf("(i = 2) Iteração 3: [11, 12, 25, 22*, 64]  => [11, 12, 22, 25, 64]\n");
    printf("(i = 3) Iteração 4: [11, 12, 22, 25*, 64]  => [11, 12, 22, 25, 64]\n");

}



//QUESTÃO 8
void selectionSortMetricas (int *V, int n) {
    int i, j, menor, temp;
    int comparacoes = 0, trocas = 0;

    for (i = 0; i < n-1; i++) {
        menor = i;

        for (j = i+1; j < n; j++) {
            comparacoes++;
            if (V[j] < V[menor]){
                menor = j;
            }
        }

        if (i != menor){
            temp = V[i];
            V[i] = V[menor];
            V[menor] = temp;
            trocas++;
        }
    }

    printf("\nComparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}

void questao_8(){
    int n = 5;
    int v[] = {5, 3, 2, 4, 1};
    int u[] = {1, 2, 3, 4, 5};

    printf("Vetor V original:\n");
    imprimeVet (v , n);

    selectionSortMetricas(v, n);

    printf("\nVetor ordenado:\n");
    imprimeVet (v , n);

    printf("\n\n");

    printf("Vetor U original:\n");
    imprimeVet (u , n);

    selectionSortMetricas(u, n);

    printf("\nVetor ordenado:\n");
    imprimeVet (u , n);
}



//QUESTÃO 9
void questao_9(){
    printf("\nNo Selection Sort, o fato de o vetor estar ordenado ou não, estar em ordem inversa ou aleatória,\n");
    printf("não altera o número de comparações. O Selection Sort possui dois laços for que são independentes do\n");
    printf("que está dentro do vetor na definição de quantas vezes vão rodar, ou seja, mesmo que todo o vetor já\n");
    printf("esteja ordenado, o algoritmo ainda irá analisar elemento por elemento até achar o menor valor.\n");
}



//QUESTÃO 10
void selectionSortOrdem (int *V, int n, int ordem) {
    int i, j, menor, temp;

    if (ordem == 1){
        for (i = 0; i < n-1; i++) {
            menor = i;
            for (j = i+1; j < n; j++) {
                if (V[j] < V[menor]){
                    menor = j;
                }
            }
            if (i != menor){
                temp = V[i];
                V[i] = V[menor];
                V[menor] = temp;
            }
        }
    }
    if (ordem == -1){
        for (i = 0; i < n-1; i++) {
            menor = i;
            for (j = i+1; j < n; j++) {
                if (V[j] > V[menor]){
                    menor = j;
                }
            }
            if (i != menor){
                temp = V[i];
                V[i] = V[menor];
                V[menor] = temp;
            }
        }
    }
}

void questao_10(){
    int n = 5;
    int v[] = {5, 3, 2, 4, 1};

    printf("\nVetor original\n");
    imprimeVet(v, n);

    printf("\nVetor em ordem crescente\n");
    selectionSortOrdem(v, n, 1);
    imprimeVet(v, n);

    printf("\nVetor em ordem decrescente\n");
    selectionSortOrdem(v, n, -1);
    imprimeVet(v, n);
}



//QUESTÃO 11
void insertionSort (int *V, int n) {
    int i, j, chave;

    for (i = 1; i < n; i++) {
        chave = V[i];
        j = i;

        while (j > 0 && chave < V[j - 1]) {
            V[j] = V[j - 1];
            j--;
        }
        V[j] = chave;
    }
}

void questao_11(){
    int n = 5;
    int v[] = {5, 3, 2, 4, 1};

    printf("Vetor original:\n");
    imprimeVet (v , n);
    insertionSort(v, n);
    printf("\nVetor ordenado:\n");
    imprimeVet (v , n);
}



//QUESTÃO 12
void questao_12 (){
    printf("\nInsertion Sort ('*' indica a 'chave' sendo inserida na parte ordenada à esquerda)\n");
    printf("\nVetor original [5, 3, 4, 1, 2]\n\n");

    printf("(i = 1) Iteração 1: [5, 3*, 4, 1, 2]  => [3, 5, 4, 1, 2]\n");
    printf("(i = 2) Iteração 2: [3, 5, 4*, 1, 2]  => [3, 4, 5, 1, 2]\n");
    printf("(i = 3) Iteração 3: [3, 4, 5, 1*, 2]  => [1, 3, 4, 5, 2]\n");
    printf("(i = 4) Iteração 4: [1, 3, 4, 5, 2*]  => [1, 2, 3, 4, 5]\n");
}



//QUESTÃO 13
void insertionSortInstrumentado (int *V, int n) {
    int i, j, chave;
    int comparacoes = 0, movimentacoes = 0;

    for (i = 1; i < n; i++) {
        chave = V[i];
        j = i;

        while (j > 0) {
            comparacoes++;

            if (chave < V[j - 1]){
                V[j] = V[j - 1];
                movimentacoes++;
                j--;

            }else {
                break;
            }
        }
        V[j] = chave;
        movimentacoes++;
    }

    printf("\nComparações = %d\n", comparacoes);
    printf("Movimentações = %d\n", movimentacoes);
    printf("\nVetor apos ordenação\n");

}

void questao_13(){
    int n2 = 20, i;
    int v_ordenado[n2];
    int v_reverso[n2];
    int v_aleatorio[] = {2, 5, 4, 7, 82, 65, 24, 13, 98, 130, 1, 10, 28, 34, 57, 15, 9, 3, 48, 100};
    int v_quaseOrdenado[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 20, 18};

    for (i = 0; i < n2; i++){
        v_ordenado[i] = i + 1;
        v_reverso[i] = n2 - i;
    }

    printf("\n==== VETOR ORDENADO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_ordenado , n2);
    insertionSortInstrumentado(v_ordenado, n2);
    imprimeVet(v_ordenado, n2);

    printf("\n\n");

    printf("==== VETOR REVERSO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_reverso , n2);
    insertionSortInstrumentado(v_reverso, n2);
    imprimeVet(v_reverso, n2);

    printf("\n\n");

    printf("==== VETOR ALEATÓRIO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_aleatorio , n2);
    insertionSortInstrumentado(v_aleatorio, n2);
    imprimeVet(v_aleatorio, n2);

    printf("\n\n");

    printf("==== VETOR QUASE ORDENADO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_quaseOrdenado , n2);
    insertionSortInstrumentado(v_quaseOrdenado, n2);
    imprimeVet(v_quaseOrdenado, n2);
}



//MAIN
int main() {

    printf("\n============== QUESTAO 1 (Bubble Sort) ==============\n");
    questao_1();
    printf("\n\n");

    printf("\n============== QUESTAO 2 (Bubble Sort Instrumentado) ==============\n");
    questao_2();
    printf("\n\n");

    printf("\n============== QUESTAO 3 (Bubble Sort Optimizado) ==============\n");
    questao_3();
    printf("\n\n");

    printf("\n============== QUESTAO 4 (Bubble Sort Normal vs Optimizado) ==============\n");
    questao_4();
    printf("\n\n");

    printf("\n============== QUESTAO 5 (Bubble Sort Ordem) ==============\n");
    questao_5();
    printf("\n\n");

    printf("\n============== QUESTAO 6 (Selection Sort) ==============\n");
    questao_6();
    printf("\n\n");

    printf("\n============== QUESTAO 7 (Selection Sort Traçado) ==============\n");
    questao_7();
    printf("\n\n");

    printf("\n============== QUESTAO 8 (Selection Sort Metrica) ==============\n");
    questao_8();
    printf("\n\n");


    printf("\n============== QUESTAO 9 (Selection Sort Resposta Escrita) ==============\n");
    questao_9();
    printf("\n\n");


    printf("\n============== QUESTAO 10 (Selection Sort Crescente/Descrescente) ==============\n");
    questao_10();
    printf("\n\n");

    printf("\n============== QUESTAO 11 (Insertion Sort) ==============\n");
    questao_11();
    printf("\n\n");

    printf("\n============== QUESTAO 12 (Insertion Sort Traçado) ==============\n");
    questao_12();
    printf("\n\n");

    printf("\n============== QUESTAO 13 (Insertion Sort Instrumentado) ==============\n");
    questao_13();
    printf("\n\n");

    return 0;
}
