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
    int valor;// valor selecionado que ser� ordenado
    int i,j;// indices para percorrer o vetor

    for(i=1;i<tam;i++){// a itera��o come�a a partir da segunda posi��o, indo at� a ultima posi��o
        int valor = v[i];// o valor que ser� ordenado � armazenado na variavel valor
        j = i - 1;// a variavel j armazena o indice do elemento anterior ao elemento que sera ordenado


/* Supoe o vetor v[8] = {7, 6, 5, 4, 3, 3, 2, 1}
Seu tamanho � 8 , na primeira itera��o do for a variavel i come�a com 1
e a variavel valor ir� armazenar o valor na posi��o v[1] = 6, e j ser� j = 1 - 1, ou seja, j = 0 ,logo valor=v[i]=v[1]=6 e v[j]=v[0]=7,
a condi��o (j>=0 e v[j]>valor) ser� verdadeira, e o la�o ser� executado, v[j+1]=v[0+1]=v[1]=7 e j=-1, como j � menor do que 0
o la�o ser� encerrado e v[j+1] ser� v[-1+1] = v[0] = valor = 7, o vetor ficar� assim v[8] = {6, 7, 5, 4, 3, 3, 2, 1}.


Na segunda itera��o do for
Primeiro -> i = 2, j = 1, v[2]=5 logo valor = 5.
a condi��o � verdadeira e o la�o � executado
segundo -> v[2] = v[1] logo v[2] = 7 e j = 0

a condi��o ainda � verdadeira  e o la�o � executado novamente
primeiro -> j = 0 e v[1] = v[0] logo v[1] = 6 , j sera decrementado novamente, j = -1
o la�o � encerrado.
e v[0] = 5
o vetor ficar� assim v[8] = {5, 6, 7, 4, 3, 3, 2, 1}

Assim que o valor a ser ordenado for maior que o valor a sua esquerda, ou seja, valor > v[j], o la�o n�o � executado, e o valor � armazenado naquela posicao
e os elementos a sua direita s�o deslocados




*/




        while(j >= 0 && v[j] > valor){
            v[j + 1] = v[j];
            j--;
        }
        v[j+1] = valor;
    }

}

