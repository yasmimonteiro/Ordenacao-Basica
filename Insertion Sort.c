#include<stdio.h>
#include<stdlib.h>

//PARTE 1
void imprimeVet (int *V, int n){
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

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

void terminal_parte1(){
    int n = 6;
    int a[] = {5, 2, 4, 6, 1, 3};
    int b[] = {1, 2, 3, 4, 5, 6};
    int c[] = {6, 5, 4, 3, 2, 1};

    printf("Vetor A original\n");
    imprimeVet(a, n);
    insertionSort(a, n);
    printf("\nVetor A ordenado\n");
    imprimeVet(a, n);

    printf("\n\n");

    printf("Vetor B original\n");
    imprimeVet(b, n);
    insertionSort(b, n);
    printf("\nVetor B ordenado\n");
    imprimeVet(b, n);

    printf("\n\n");

    printf("Vetor C original\n");
    imprimeVet(c, n);
    insertionSort(c, n);
    printf("\nVetor C ordenado\n");
    imprimeVet(c, n);

    printf("\n");
}



//PARTE 2
void insertionSortPassoaPasso (int *V, int n) {
    int i, j, chave;

    for (i = 1; i < n; i++) {
        chave = V[i];

        printf("i = %d, chave = %d | antes: ", i, chave);
        imprimeVet(V, n);

        j = i;

        while (j > 0 && chave < V[j - 1]) {
            V[j] = V[j - 1];
            j--;
        }
        V[j] = chave;

        printf("i = %d, chave = %d | depois: ", i, chave);
        imprimeVet(V, n);
    }
}



//PARTE 3
typedef struct{
    long comparacoes;
    long movimentacoes;
} Metrics;

void insertionSortMetrics (int *V, int n, Metrics *m) {
    int i, j, chave;
    m->comparacoes = 0;
    m->movimentacoes = 0;

    for (i = 1; i < n; i++) {
        chave = V[i];
        j = i;

        while (j > 0) {
            m->comparacoes++;

            if (chave < V[j - 1]){
                V[j] = V[j - 1];
                m->movimentacoes++;
                j--;

            }else {
                break;
            }
        }
        V[j] = chave;
        m->movimentacoes++;
    }
}

void terminal_parte3(){
    int n = 6;
    Metrics m;
    int a[] = {5, 2, 4, 6, 1, 3};
    int b[] = {1, 2, 3, 4, 5, 6};
    int c[] = {6, 5, 4, 3, 2, 1};

    insertionSortMetrics(a, n, &m);
    printf("Caso A (aleatorio): comparacoes = %ld, movimentacoes = %ld\n", m.comparacoes, m.movimentacoes);

    insertionSortMetrics(b, n, &m);
    printf("\nCaso B (ordenado):  comparacoes = %ld, movimentacoes = %ld\n", m.comparacoes, m.movimentacoes);

    insertionSortMetrics(c, n, &m);
    printf("\nCaso C (invertido): comparacoes = %ld, movimentacoes = %ld\n", m.comparacoes, m.movimentacoes);

    printf("\n");
}



//PARTE 4
void insertionSortMetricsDecrescente (int *V, int n, Metrics *m) {
    int i, j, chave;
    m->comparacoes = 0;
    m->movimentacoes = 0;

    for (i = 1; i < n; i++) {
        chave = V[i];
        j = i;

        while (j > 0) {
            m->comparacoes++;

            if (chave > V[j - 1]){
                V[j] = V[j - 1];
                m->movimentacoes++;
                j--;

            }else {
                break;
            }
        }
        V[j] = chave;
        m->movimentacoes++;
    }
}

void terminal_parte4(){
    int n = 6;
    Metrics m;
    int a[] = {5, 2, 4, 6, 1, 3};
    int b[] = {1, 2, 3, 4, 5, 6};
    int c[] = {6, 5, 4, 3, 2, 1};

    printf("Vetor A original\n");
    imprimeVet(a, n);
    insertionSortMetricsDecrescente(a, n, &m);
    printf("\nVetor A ordenado decrescente\n");
    imprimeVet(a, n);

    printf("\n\n");

    printf("Vetor B original\n");
    imprimeVet(b, n);
    insertionSortMetricsDecrescente(b, n, &m);
    printf("\nVetor B ordenado decrescente\n");
    imprimeVet(b, n);

    printf("\n\n");

    printf("Vetor C original\n");
    imprimeVet(c, n);
    insertionSortMetricsDecrescente(c, n, &m);
    printf("\nVetor C ordenado decrescente\n");
    imprimeVet(c, n);

    printf("\n");

    printf("\nCaso A (aleatorio): comparacoes = %ld, movimentacoes = %ld\n", m.comparacoes, m.movimentacoes);
    printf("\nCaso B (ordenado):  comparacoes = %ld, movimentacoes = %ld\n", m.comparacoes, m.movimentacoes);
    printf("\nCaso C (invertido): comparacoes = %ld, movimentacoes = %ld\n", m.comparacoes, m.movimentacoes);

    printf("\n");
}



int main(){
    int n = 6;
    int a[] = {5, 2, 4, 6, 1, 3};
    int b[] = {1, 2, 3, 4, 5, 6};
    int c[] = {6, 5, 4, 3, 2, 1};

    printf("========== PARTE 1 ==========\n\n");
    terminal_parte1();
    printf("-------------------------------------------------------------");

    printf("\n\n========== PARTE 2 ==========\n\n");
    insertionSortPassoaPasso(a, n);
    printf("-------------------------------------------------------------");

    printf("\n\n========== PARTE 3 ==========\n\n");
    terminal_parte3();
    printf("-------------------------------------------------------------");

    printf("\n\n========== PARTE 4 ==========\n\n");
    terminal_parte4();
    printf("-------------------------------------------------------------");

    return 0;
}










