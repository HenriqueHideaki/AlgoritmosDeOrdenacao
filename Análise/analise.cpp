#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"


using namespace std;


int main(){
    int i;
    int tam = 100000;
    int inicio = 0;
    int fim = tam - 1;
    srand(time(NULL));

    double tempo;
    double t_clock;

    time_t t_ini;
    time_t t_fim;

    clock_t ck_ini;
    clock_t ck_fim;




    //Vetor Aleatório
    int vetorA[tam];
    for(int i=0; i<tam; i++)
    {
        vetorA[i] = rand() % 1000;
    }


    //Vetor Ordenado de forma crescente
    int vetorB[tam];
    quickSort(vetorA,tam,inicio,fim);
    for(int i=0; i<tam; i++)
    {
        vetorB[i] = vetorA[i];
    }


    //Vetor Ordenado de forma decrescente
    int vetorC[tam];
    for(int i=tam; i>=0; i--)
    {
        vetorC[i] = vetorA[i];
    }


    //Resultados


    //Análise para vetor aleatório
    t_ini = time(NULL);
    ck_ini = clock();

    for(int j=0;j<50;j++)
        quickSort1(vetorA,tam,inicio,fim);

    ck_fim = clock();
    t_fim = time(NULL);

    t_clock = (double )(ck_fim - ck_ini)/CLOCKS_PER_SEC;
    t_clock /= 50;

    tempo = difftime(t_fim,t_ini);
    tempo /= 50;

    printf("******QuickSort com Selecao Aleatoria de Pivo******");
    printf("\nVetor de tamanho: %i\n\n",tam);

    printf("\nVetor Aleatorio\n");
    printf("CLOCK: %.9lf segundos\n",t_clock);
    printf("TEMPO: %.9lf segundos",tempo);


    //Análise para vetor crescente
    t_ini = time(NULL);
    ck_ini = clock();

    for(int j=0;j<50;j++)
        quickSort1(vetorB,tam,inicio,fim);

    ck_fim = clock();
    t_fim = time(NULL);

    t_clock = (double )(ck_fim - ck_ini)/CLOCKS_PER_SEC;
    t_clock /= 50;

    tempo = difftime(t_fim,t_ini);
    tempo /= 50;

    printf("\n\nVetor Crescente\n");
    printf("CLOCK: %.9lf segundos\n",t_clock);
    printf("TEMPO: %.9lf segundos",tempo);


    //Análise para vetor Decrescente
    t_ini = time(NULL);
    ck_ini = clock();

    for(int j=0;j<50;j++)
        quickSort1(vetorC,tam,inicio,fim);

    ck_fim = clock();
    t_fim = time(NULL);

    t_clock = (double )(ck_fim - ck_ini)/CLOCKS_PER_SEC;
    t_clock /= 50;

    tempo = difftime(t_fim,t_ini);
    tempo /= 50;


    printf("\n\nVetor Decrescente\n");
    printf("CLOCK: %.9lf segundos\n",t_clock);
    printf("TEMPO: %.9lf segundos",tempo);





























    return 0;
}
