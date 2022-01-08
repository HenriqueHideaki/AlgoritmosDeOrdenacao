#include<iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

void troca(int *v, int i, int j)
{
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void selectionSorIP(int *v, int tamanho)// recebe um vetor e o seu tamanho
{
    int aux;// variavel auxiliar para realizar a troca do menor elemento
    for(int i=0; i<tamanho-1; i++) // esse for começa de 0 e vai até sua posição final(indice=tamanho -1)
    {
        int indice_menor = i;// variável para armazenar o indice do menor elemento
        for(int j = i+1; j<tamanho; j++) // esse for começa na posição seguinte a posição i (indice=j), indo ate sua posição final, comparando os elementos seguintes e verificando se o elemento é menor
        {
            if(v[j] < v[indice_menor])  // se o menor elemento é encontrado seu indice é armazenado na variavel indice_menor
            {
                indice_menor = j;
            }
            troca(v,i,indice_menor);// assim que o indice do menor elemento é encontrado é realizado a troca de posição desse elemento com o elemento atual
        }
        /*if(i != indice_menor){
            troca(v,i,indice_menor);
        }*/

    }



}

void printV(int* v, int tamanho)
{
    cout << "[";
    for (int i = 0; i < tamanho - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[tamanho - 1] << "]";
}

int main()
{

    int tam = 8;
    int a[tam] = {3,6,2,5,4,3,7,1};
    selectionSorIP(a,tam);
    printV(a,tam);




    return 0;
}


