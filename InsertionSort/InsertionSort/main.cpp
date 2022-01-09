#include <iostream>
#include <stdio.h>

using namespace std;



void troca(int *v, int i, int j);
void imprimeVetor(int *v, int tam);
void insertionSort(int *v, int tam);
//void insertionSort(int *v, int tam);

int main()
{
    int tam = 8;
    int v[tam] = {7, 6, 5, 4, 3, 3, 2, 1};



    insertionSort(v,tam);
    imprimeVetor(v,tam);





    return 0;
}

void imprimeVetor(int *v, int tam)
{
    cout << "[ ";
    for(int i=0; i<tam; i++)
    {
        cout << v[i] << " ";
    }
    cout << "]";
}

void troca(int *v, int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
/*
void insertionSort(int *v, int tam){
    int elemento_selecionado;
    int i,j;

    for(i=1; i<tam; i++){
        elemento_selecionado = v[i];
        for(j = i - 1; j >= 0 && v[j] > elemento_selecionado; j--){
            v[j+1] = v[j];
        }
        v[j+1] = elemento_selecionado;

    }
}
*/

void insertionSort(int *v, int tam){
    int valor;// valor selecionado que será ordenado
    int i,j;// indices para percorrer o vetor

    for(i=1;i<tam;i++){// a iteração começa a partir da segunda posição, indo até a ultima posição
        int valor = v[i];// o valor que será ordenado é armazenado na variavel valor
        j = i - 1;// a variavel j armazena o indice do elemento anterior ao elemento que sera ordenado


/* Supoe o vetor v[8] = {7, 6, 5, 4, 3, 3, 2, 1}
Seu tamanho é 8 , na primeira iteração do for a variavel i começa com 1
e a variavel valor irá armazenar o valor na posição v[1] = 6, e j será j = 1 - 1, ou seja, j = 0 ,logo valor=v[i]=v[1]=6 e v[j]=v[0]=7,
a condição (j>=0 e v[j]>valor) será verdadeira, e o laço será executado, v[j+1]=v[0+1]=v[1]=7 e j=-1, como j é menor do que 0
o laço será encerrado e v[j+1] será v[-1+1] = v[0] = valor = 7, o vetor ficará assim v[8] = {6, 7, 5, 4, 3, 3, 2, 1}.


Na segunda iteração do for
Primeiro -> i = 2, j = 1, v[2]=5 logo valor = 5.
a condição é verdadeira e o laço é executado
segundo -> v[2] = v[1] logo v[2] = 7 e j = 0

a condição ainda é verdadeira  e o laço é executado novamente
primeiro -> j = 0 e v[1] = v[0] logo v[1] = 6 , j sera decrementado novamente, j = -1
o laço é encerrado.
e v[0] = 5
o vetor ficará assim v[8] = {5, 6, 7, 4, 3, 3, 2, 1}

Assim que o valor a ser ordenado for maior que o valor a sua esquerda, ou seja, valor > v[j], o laço não é executado, e o valor é armazenado naquela posicao
e os elementos a sua direita são deslocados




*/




        while(j >= 0 && v[j] > valor){
            v[j + 1] = v[j];
            j--;
        }
        v[j+1] = valor;
    }

}

