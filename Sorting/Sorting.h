#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

void troca(int *v, int i, int j);
void imprimeVetor(int *v, int tam);

void bubbleSort(int *v, int tamanho);
void insertionSort(int *v, int tam);
void merge(int *v, int meio, int esquerda, int direita);
void mergeSort(int *v, int tam, int esquerda, int direita);
void quickSort(int *v, int tam, int inicio, int fim);
void quickSort1(int *v, int tam, int inicio, int fim);// Com pivotemento aleatório
int particao(int *v, int tam, int esquerda, int direita);
void selectionSorIP(int *v, int tamanho);// recebe um vetor e o seu tamanho

#endif // SORTING_H_INCLUDED
