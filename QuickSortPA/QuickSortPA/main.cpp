#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


using namespace std;

void printV(int* v, int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d, ", v[i]);
    }
    printf("%d]", v[tamanho - 1]);
}

void troca(int* v, int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int particao(int *v, int tam, int esquerda, int direita)
{
    srand(time(NULL)); // Função responsavel para gerar numeros aleatorios
    int indice_pivo = esquerda + (rand() % (direita - esquerda)); // O indice pivo irá armazenar um valor aleatorio entre as posições exitentes no vetor
    int aux = v[indice_pivo];
    v[indice_pivo] = v[direita];
    v[direita] = aux;

    int i = esquerda - 1;
    int j;
    int pivo = v[direita];

    for(j=esquerda; j<direita; j++)
    {
        if(v[j] <= pivo)
        {
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    aux = v[i + 1];
    v[i + 1] = v[direita];
    v[direita] = aux;
    return i + 1;

}
void quickSort1(int *v, int tam, int inicio, int fim){
    if(inicio < fim){
        int pivo = particao(v,tam,inicio,fim);
        quickSort1(v, tam, inicio, pivo-1);
        quickSort1(v,tam,pivo+1,fim);
    }
 }

int main()
{
    int tam = 15;
    int vetorA[tam] = {3,6,2,5,4,3,7,1,11,9,0,-2,4,14,10};
    int vetorB[tam] = {7,6,5,4,3,3,2,1,8,0,-4,7,21,-8,9};
    int inicio = 0;
    int fim = tam - 1;


    cout << "******** QUICKSORT COM PIVOTEMANETO ALEATORIO *********\n\n\n";
    cout << "Vetor A desordenado\n";
    printV(vetorA, tam);

    quickSort1(vetorA, tam, inicio, fim);
    cout << "\nVetor A ordenado\n";
    printV(vetorA, tam);

    cout << "\n\nVetor B desordenado\n";
    printV(vetorB, tam);

    quickSort1(vetorB, tam, inicio, fim);
    cout << "\nVetor B ordenado\n";
    printV(vetorB, tam);


    return 0;
}
