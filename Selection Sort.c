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

void questao_1(){
    int n = 5, n0 = 0, n1 = 1;
    int v_vazio[] = {};
    int v_um[] = {7};
    int v_ordenado[] = {1, 2, 3, 4, 5};
    int v_inverso[] = {5, 4, 3, 2, 1};
    int v_repetido[] = {3, 1, 3, 2, 3};

    printf("\n====Vetores orginais====\n");
    printf("Vetor vazio: [ ]\n");
    printf("Vetor unitario: [7]\n");
    printf("Vetor ordenado: [1, 2, 3, 4, 5]\n");
    printf("Vetor inverso: [5, 4, 3, 2, 1]\n");
    printf("Vetor repetido: [3, 1, 3, 2, 3]\n");

    printf("\n\n====Vetores após ordenacao====\n");

    selectionSort(v_vazio, n0);
    printf("\nVetor vazio\n");
    imprimeVet(v_vazio, n0);

    selectionSort(v_um, n1);
    printf("\nVetor unitario\n");
    imprimeVet(v_um, n1);

    selectionSort(v_ordenado, n);
    printf("\nVetor ordenado\n");
    imprimeVet(v_ordenado, n);

    selectionSort(v_inverso, n);
    printf("\nVetor inverso\n");
    imprimeVet(v_inverso, n);

    selectionSort(v_repetido, n);
    printf("\nVetor repetido\n");
    imprimeVet(v_repetido, n);

    printf("\n\n");
}



//QUESTÃO 2
void selectionSortContadores (int *V, int n) {
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
    printf("-----------------------------");
    printf("\n\nComparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}

void questao_2(){
    int n = 5, n0 = 0, n1 = 1;
    int v_vazio[] = {};
    int v_um[] = {7};
    int v_ordenado[] = {1, 2, 3, 4, 5};
    int v_inverso[] = {5, 4, 3, 2, 1};
    int v_repetido[] = {3, 1, 3, 2, 3};

    printf("\n====Vetores orginais====\n");
    printf("Vetor vazio: [ ]\n");
    printf("Vetor unitario: [7]\n");
    printf("Vetor ordenado: [1, 2, 3, 4, 5]\n");
    printf("Vetor inverso: [5, 4, 3, 2, 1]\n");
    printf("Vetor repetido: [3, 1, 3, 2, 3]\n");

    printf("\n\n====Vetores após ordenacao====\n");

    selectionSortContadores(v_vazio, n0);
    printf("\nVetor vazio\n");
    imprimeVet(v_vazio, n0);

    selectionSortContadores(v_um, n1);
    printf("\nVetor unitario\n");
    imprimeVet(v_um, n1);

    selectionSortContadores(v_ordenado, n);
    printf("\nVetor ordenado\n");
    imprimeVet(v_ordenado, n);

    selectionSortContadores(v_inverso, n);
    printf("\nVetor inverso\n");
    imprimeVet(v_inverso, n);

    selectionSortContadores(v_repetido, n);
    printf("\nVetor repetido\n");
    imprimeVet(v_repetido, n);

    printf("\n\n");
}



//DESAFIO EXTRA LETRA A
void selectionSortDecrescente (int *V, int n) {
    int i, j, menor, temp;
    int comparacoes = 0, trocas = 0;

    for (i = 0; i < n-1; i++) {
            menor = i;
            for (j = i+1; j < n; j++) {
                comparacoes++;
                if (V[j] > V[menor]){
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
    printf("-----------------------------");
    printf("\n\nComparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}

void desafio_extraA(){
    int n = 5, n0 = 0, n1 = 1;
    int v_vazio[] = {};
    int v_um[] = {7};
    int v_ordenado[] = {1, 2, 3, 4, 5};
    int v_inverso[] = {5, 4, 3, 2, 1};
    int v_repetido[] = {3, 1, 3, 2, 3};

    printf("\n====Vetores orginais====\n");
    printf("Vetor vazio: [ ]\n");
    printf("Vetor unitario: [7]\n");
    printf("Vetor ordenado: [1, 2, 3, 4, 5]\n");
    printf("Vetor inverso: [5, 4, 3, 2, 1]\n");
    printf("Vetor repetido: [3, 1, 3, 2, 3]\n");

    printf("\n\n====Vetores após ordenacao====\n");

    selectionSortDecrescente(v_vazio, n0);
    printf("\nVetor vazio\n");
    imprimeVet(v_vazio, n0);

    selectionSortDecrescente(v_um, n1);
    printf("\nVetor unitario\n");
    imprimeVet(v_um, n1);

    selectionSortDecrescente(v_ordenado, n);
    printf("\nVetor ordenado\n");
    imprimeVet(v_ordenado, n);

    selectionSortDecrescente(v_inverso, n);
    printf("\nVetor inverso\n");
    imprimeVet(v_inverso, n);

    selectionSortDecrescente(v_repetido, n);
    printf("\nVetor repetido\n");
    imprimeVet(v_repetido, n);

    printf("\n");
}



//DESAFIO EXTRA LETRA B
void selectionSortOrdem (int *V, int n, int ordem) {
    int i, j, menor, temp;
    int comparacoes = 0, trocas = 0;

    if (ordem == 1){
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
    }
    if (ordem == -1){
        for (i = 0; i < n-1; i++) {
            menor = i;
            for (j = i+1; j < n; j++) {
                comparacoes++;
                if (V[j] > V[menor]){
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
    }
    printf("-----------------------------");
    printf("\n\nComparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}

void desafio_extraB(){
    int n = 5, n0 = 0, n1 = 1;
    int v_vazio[] = {};
    int v_um[] = {7};
    int v_ordenado[] = {1, 2, 3, 4, 5};
    int v_inverso[] = {5, 4, 3, 2, 1};
    int v_repetido[] = {3, 1, 3, 2, 3};

    printf("\n====Vetores orginais====\n");
    printf("Vetor vazio: [ ]\n");
    printf("Vetor unitario: [7]\n");
    printf("Vetor ordenado: [1, 2, 3, 4, 5]\n");
    printf("Vetor inverso: [5, 4, 3, 2, 1]\n");
    printf("Vetor repetido: [3, 1, 3, 2, 3]\n");

    printf("\n\n====Vetores após ordenacao====\n");

    selectionSortOrdem(v_vazio, n0, 1);
    printf("\nVetor vazio crescente\n");
    imprimeVet(v_vazio, n0);

    selectionSortOrdem(v_vazio, n0, -1);
    printf("\nVetor vazio decrescente\n");
    imprimeVet(v_vazio, n0);



    selectionSortOrdem(v_um, n1, 1);
    printf("\nVetor unitario crescente\n");
    imprimeVet(v_um, n1);

    selectionSortOrdem(v_um, n1, -1);
    printf("\nVetor unitario decrescente\n");
    imprimeVet(v_um, n1);



    selectionSortOrdem(v_ordenado, n, 1);
    printf("\nVetor ordenado crescente\n");
    imprimeVet(v_ordenado, n);

    selectionSortOrdem(v_ordenado, n, -1);
    printf("\nVetor ordenado decrescente\n");
    imprimeVet(v_ordenado, n);



    selectionSortOrdem(v_inverso, n, 1);
    printf("\nVetor inverso crescente\n");
    imprimeVet(v_inverso, n);

    selectionSortOrdem(v_inverso, n, -1);
    printf("\nVetor inverso decrescente\n");
    imprimeVet(v_inverso, n);



    selectionSortOrdem(v_repetido, n, 1);
    printf("\nVetor repetido crescente\n");
    imprimeVet(v_repetido, n);

    selectionSortOrdem(v_repetido, n, -1);
    printf("\nVetor repetido decrescente\n");
    imprimeVet(v_repetido, n);

    printf("\n\n");

}



int main(){
    printf("\n============== QUESTAO 1 (Selection Sort) ==============\n");
    questao_1();

    printf("\n\n============== QUESTAO 2 (Selection Sort Contadores) ==============\n");
    questao_2();

    printf("\n\n============== DESAFIO EXTRA (Letra A) ==============\n");
    desafio_extraA();

    printf("\n\n============== DESAFIO EXTRA (Letra B) ==============\n");
    desafio_extraB();

    return 0;

}










