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

void bubbleSortInstrumentadoEarlyStop (int v[], int n) {
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

void vetores_bubbleSortInstrumentado (){
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

void vetores_bubbleSortInstrumentadoEarlyStop (){
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

    bubbleSortInstrumentadoEarlyStop(v_ordenado, n2);

    printf("\nVetor ordenado:\n");
    imprimeVet(v_ordenado, n2);

    printf("\n\n");

    printf("==== VETOR REVERSO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_reverso , n2);

    bubbleSortInstrumentadoEarlyStop(v_reverso, n2);

    printf("\nVetor ordenado:\n");
    imprimeVet(v_reverso, n2);

    printf("\n\n");

    printf("==== VETOR ALEATÓRIO ====\n");
    printf("Vetor original:\n");
    imprimeVet (v_aleatorio , n2);

    bubbleSortInstrumentadoEarlyStop(v_aleatorio, n2);

    printf("\nVetor ordenado:\n");
    imprimeVet(v_aleatorio, n2);
}

void conclusao(){
    printf("\n\n");
    printf("As ordenações feitas com o Bubble Sort sem early stop geraram mais operações\n");
    printf("em comparação com as feitas com o uso de early stop. Em todos os vetores do\n");
    printf("bubble sort que não possui early stop foram feitas 190 comparações, mas o vetor\n");
    printf("ordenado fez 0 trocas, sendo a menor quantidade, enquanto no vetor reverso\n");
    printf("foram feitas 190 trocas, sendo o pior caso. Já com o early stop, o pior caso\n");
    printf("foi o vetor reverso, que precisou serem feitas 190 comparações e trocas, e o\n");
    printf("melhor caso foi com o vetor ordenado, com apenas 19 comparações e 0 trocas.\n");
    printf("\n\n");
}



//QUESTÃO 3
void bubbleSortSimplesDecrescente (float v[], int n){
    int i, j;
    float temp;

    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-1-i; j++){
            if (v[j] < v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void questao_3(){
    float notas[] = {1.2, 5.7, 9.8, 7.5, 8.2};
    float media, soma = 0;
    int n = 5, i;

    printf("Notas: \n");

    for (i = 0; i < n; i++) {
        printf("%.2f ", notas[i]);
    }
    printf("\n");


    for (int i = 0; i < n; i++) {
        soma += notas[i];
    }
    media = soma / n;
    printf("\nMedia das notas: %.2f", media);


    bubbleSortSimplesDecrescente(notas, n);
    printf("\nAs maiores notas são: ");
    for (i = 0; i < 3; i++) {
        printf("%.2f| ", notas[i]);
    }

    printf("\n");
}



//QUESTÃO 4
void bubbleSortOrdem (int v[], int n, int ordem) {
    int i, j, temp, houveTroca;

    if (ordem == 1){
        for (i = 0; i < n-1; i++) {
            houveTroca = 0;
            for (j = 0; j < n-1-i; j++) {
                if (v[j] > v[j+1]) {
                    temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                    houveTroca = 1;
                }
            }

            if (houveTroca == 0) {
            break;
            }
        }

    }if (ordem == -1){
        for (i = 0; i < n-1; i++) {
            houveTroca = 0;
            for (j = 0; j < n-1-i; j++) {
                if (v[j] < v[j+1]) {
                    temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                    houveTroca = 1;
                }
            }
            if (houveTroca == 0) {
                break;
            }
        }
    }
}

void questao_4 (){
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

    printf("\n\n====Vetores após ordenacao====\n");

    bubbleSortOrdem(v_vazio, n0, 1);
    printf("\nVetor vazio\n");
    imprimeVet(v_vazio, n0);

    bubbleSortOrdem(v_um, n1, 1);
    printf("\nVetor unitario\n");
    imprimeVet(v_um, n1);

    bubbleSortOrdem(v_misturado, n, 1);
    printf("\nVetor positivo e negativo (crescente)\n");
    imprimeVet(v_misturado, n);

    bubbleSortOrdem(v_misturado, n, -1);
    printf("\nVetor positivo e negativo (decrescente)\n");
    imprimeVet(v_misturado, n);

    bubbleSortOrdem(v_repetido, n, 1);
    printf("\nVetor repetido (crescente)\n");
    imprimeVet(v_repetido, n);

    bubbleSortOrdem(v_repetido, n, -1);
    printf("\nVetor repetido (decrescente)\n");
    imprimeVet(v_repetido, n);

    printf("\n");
}



int main(){
    printf("\n============== QUESTAO 2 (Bubble Sort Instrumentado) ==============\n");
    printf("\n\n============ Bubble Sort Instrumentado ============\n\n");
    vetores_bubbleSortInstrumentado();

    printf("\n\n============ Bubble Sort Instrumentado com Early Stop ============\n\n");
    vetores_bubbleSortInstrumentadoEarlyStop();

    conclusao();

    printf("\n\n============== QUESTAO 3 (Bubble Sort Notas) ==============\n");
    questao_3();

    printf("\n\n============== QUESTAO 4 (Bubble Sort Ordem) ==============\n");
    questao_4();

    return 0;

}





