#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include"Sorting.h"


using namespace std;

void troca(int *v, int i, int j){// essa fun��o recebe um vetor e dois indices, e realiza a troca de posi��o dos elementos que corresponde a esses indices.
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void imprimeVetor(int *v, int tam){//essa fun��o imprime o vetor
    cout << "\n[ ";
    for(int i=0;i<tam;i++){
        cout << v[i] << " ";
    }
    cout << "]";

}

void bubbleSort(int *v, int tamanho){// recebe um vetor e o seu tamanho
    for(int i=0;i<tamanho-1;i++){// percorre o vetor inteiro, indo de 0 ate o ultimo indice( tamanho - 1)
        for(int j=i+1;j<tamanho;j++){// percorre o vetor sempre na posicao seguinte ao vetor(v[i]) , se v[i=0] entao v[j=1], se v[i=1] entao v[j=2]
            if(v[i]>v[j]){// se um elemento numa determinada posicao i for maior que o elemento na posic�o seguinte j, a fun��o troca � chamada, e seus elementos trocam de posi��o
                troca(v,i,j);
            }
        }
    }

}

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
    /* A fun��o mergeSort recebe um vetor(*v), o tamanho desse vetor(tam), uma variavel do tipo int
     que ir� armazenar o indice do elemento mais a esquerda desse vetor(esquerda), e outra tamb�m do tipo int que ir� armazenar o indice do elemento mais
     a direita do vetor*/

    if(esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda)/2; // meio rebe o indice da posi��o do meio do vetor
        mergeSort(v, tam, esquerda,meio);
        mergeSort(v, tam, meio+1, direita);
        merge(v, meio, esquerda, direita);

    }


}

void quickSort(int *v, int tam, int inicio, int fim){
    // A fun��o quickSort rebe um vetor que sera ordenado, o seu tamanho, o elemento do inicio do vetor e o elemento do final do vetor
    int esquerda;
    int direita;
    int pivo;
    int meio;
    int aux;
    esquerda = inicio; // O elemento mais a esquerda do vetor � o primeiro elemento
    direita = fim;// O elemento mais a direita � o ultimo elemento
    meio = (int)(esquerda + direita) / 2; // meio recebe a posi��o que corresponde a metade do vetor, um cast converte esse valor para um inteiro caso esse valor seja um float
    pivo = v[meio];



    while(direita > esquerda)
    {
        while(v[esquerda] < pivo) esquerda++;
        /* todos os valores a esquerda do meu pivo devem ser menores do que ele ou
        seja ,caso o valor que est� a esquerda do meu pivo seja menor que ele isso
        significa que ele esta no lugar correto, mas nao necessariamente ele estar�
        ordenado, o la�o � executado e a proxima posi��o, ainda a esquerda
        do vetor ser� analisada.*/

        while(v[direita] > pivo) direita--;
        /* Todos os valore a direita do meu pivo devem ser maiores do que ele ou seja,
        caso o valor que esta a direita do meu pivo seja maior do que ele, isso significa que
        ele est� no local correto, mas novamente, isso n�o significa que ele estar� ordenado, o
        la�o � executado e outro elemento outro elemento � analisado vindo da direita a esquerda, por
        isso a variavel direita � decrementada.s
        */


        if(esquerda <= direita)
        {
            aux = v[esquerda];
            v[esquerda] = v[direita];
            v[direita] = aux;

            esquerda++;
            direita--;
        }
        /*Caso um valor maior que o pivo esteja a sua esquerda, ou seja, o valor se encontra na posi��o
        incorreta, esse valor ser� trocado por um valor que est� a direita que tamb�m esta na posi��o
        incorreta (valor a direita menor que o pivo),
        */
    }

    /* Essas recurs�es permite que a fun��o continue ordenando
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
    srand(time(NULL)); // Fun��o responsavel para gerar numeros aleatorios
    int indice_pivo = esquerda + (rand() % (direita - esquerda)); // O indice pivo ir� armazenar um valor aleatorio entre as posi��es exitentes no vetor
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
    for(int i=0; i<tamanho-1; i++) // esse for come�a de 0 e vai at� sua posi��o final(indice=tamanho -1)
    {
        int indice_menor = i;// vari�vel para armazenar o indice do menor elemento
        for(int j = i+1; j<tamanho; j++) // esse for come�a na posi��o seguinte a posi��o i (indice=j), indo ate sua posi��o final, comparando os elementos seguintes e verificando se o elemento � menor
        {
            if(v[j] < v[indice_menor])  // se o menor elemento � encontrado seu indice � armazenado na variavel indice_menor
            {
                indice_menor = j;
            }
            troca(v,i,indice_menor);// assim que o indice do menor elemento � encontrado � realizado a troca de posi��o desse elemento com o elemento atual
        }
        /*if(i != indice_menor){
            troca(v,i,indice_menor);
        }*/

    }



}
