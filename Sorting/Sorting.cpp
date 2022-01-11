#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include"Sorting.h"


using namespace std;

void troca(int *v, int i, int j){// essa função recebe um vetor e dois indices, e realiza a troca de posição dos elementos que corresponde a esses indices.
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void imprimeVetor(int *v, int tam){//essa função imprime o vetor
    cout << "\n[ ";
    for(int i=0;i<tam;i++){
        cout << v[i] << " ";
    }
    cout << "]";

}

void bubbleSort(int *v, int tamanho){// recebe um vetor e o seu tamanho
    for(int i=0;i<tamanho-1;i++){// percorre o vetor inteiro, indo de 0 ate o ultimo indice( tamanho - 1)
        for(int j=i+1;j<tamanho;j++){// percorre o vetor sempre na posicao seguinte ao vetor(v[i]) , se v[i=0] entao v[j=1], se v[i=1] entao v[j=2]
            if(v[i]>v[j]){// se um elemento numa determinada posicao i for maior que o elemento na posicão seguinte j, a função troca é chamada, e seus elementos trocam de posição
                troca(v,i,j);
            }
        }
    }

}

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

void merge(int *v, int meio, int esquerda, int direita){

    int tam1 = meio - esquerda + 1;
    int tam2 = direita - meio;
    int i;
    int j;
    int k;


    int vetor1[tam1], vetor2[tam2];
    for(i=0; i<tam1; i++)
    {
        vetor1[i] = v[esquerda + i];
    }
    for(j=0; j<tam2; j++)
    {
        vetor2[j] = v[meio + 1 + j];
    }

    i = 0, j = 0;
    k = esquerda;

    while(i < tam1 && j < tam2)
    {

        if(vetor1[i] <= vetor2[j]){
            v[k] = vetor1[i];
            i++;
        }else{
            v[k] = vetor2[j];
            j++;
        }
        k++;
    }
    while(i < tam1){
        v[k] = vetor1[i];
        i++;
        k++;
    }
    while(j < tam2){
        v[k] = vetor2[j];
        j++;
        k++;
    }

}

void mergeSort(int *v, int tam, int esquerda, int direita){
    /* A função mergeSort recebe um vetor(*v), o tamanho desse vetor(tam), uma variavel do tipo int
     que irá armazenar o indice do elemento mais a esquerda desse vetor(esquerda), e outra também do tipo int que irá armazenar o indice do elemento mais
     a direita do vetor*/

    if(esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda)/2; // meio rebe o indice da posição do meio do vetor
        mergeSort(v, tam, esquerda,meio);
        mergeSort(v, tam, meio+1, direita);
        merge(v, meio, esquerda, direita);

    }


}

void quickSort(int *v, int tam, int inicio, int fim){
    // A função quickSort rebe um vetor que sera ordenado, o seu tamanho, o elemento do inicio do vetor e o elemento do final do vetor
    int esquerda;
    int direita;
    int pivo;
    int meio;
    int aux;
    esquerda = inicio; // O elemento mais a esquerda do vetor é o primeiro elemento
    direita = fim;// O elemento mais a direita é o ultimo elemento
    meio = (int)(esquerda + direita) / 2; // meio recebe a posição que corresponde a metade do vetor, um cast converte esse valor para um inteiro caso esse valor seja um float
    pivo = v[meio];



    while(direita > esquerda)
    {
        while(v[esquerda] < pivo) esquerda++;
        /* todos os valores a esquerda do meu pivo devem ser menores do que ele ou
        seja ,caso o valor que está a esquerda do meu pivo seja menor que ele isso
        significa que ele esta no lugar correto, mas nao necessariamente ele estará
        ordenado, o laço é executado e a proxima posição, ainda a esquerda
        do vetor será analisada.*/

        while(v[direita] > pivo) direita--;
        /* Todos os valore a direita do meu pivo devem ser maiores do que ele ou seja,
        caso o valor que esta a direita do meu pivo seja maior do que ele, isso significa que
        ele está no local correto, mas novamente, isso não significa que ele estará ordenado, o
        laço é executado e outro elemento outro elemento é analisado vindo da direita a esquerda, por
        isso a variavel direita é decrementada.s
        */


        if(esquerda <= direita)
        {
            aux = v[esquerda];
            v[esquerda] = v[direita];
            v[direita] = aux;

            esquerda++;
            direita--;
        }
        /*Caso um valor maior que o pivo esteja a sua esquerda, ou seja, o valor se encontra na posição
        incorreta, esse valor será trocado por um valor que está a direita que também esta na posição
        incorreta (valor a direita menor que o pivo),
        */
    }

    /* Essas recursões permite que a função continue ordenando
    */
    if(inicio < direita)
        quickSort(v, tam,inicio, direita);

    if(esquerda < fim)
        quickSort(v, tam, esquerda, fim);





}

void quickSort1(int *v, int tam, int inicio, int fim){
    if(inicio < fim){
        int pivo = particao(v,tam,inicio,fim);
        quickSort1(v, tam, inicio, pivo-1);
        quickSort1(v,tam,pivo+1,fim);
    }
 }

int particao(int *v, int tam, int esquerda, int direita){
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

void selectionSorIP(int *v, int tamanho){// recebe um vetor e o seu tamanho

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
