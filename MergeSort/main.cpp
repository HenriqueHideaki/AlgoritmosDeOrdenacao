#include <iostream>

using namespace std;

void imprimeVetor(int *v, int tam)
{
    cout << "\n[ ";
    for(int i=0; i<tam; i++)
    {
        cout << v[i] << " ";
    }
    cout << "]\n";
}


void merge(int *v, int meio, int esquerda, int direita)
{

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

// mergeSort recebe um vetor, a posicao mais a esquerda do vetor e a posicao mais a direita do vetor.
void mergeSort(int *v, int tam, int esquerda, int direita)
{
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



int main()
{
    int tam = 10;
    int vetor[tam] = {2,1,6,4,1,7,8,9,2,4};
    mergeSort(vetor,tam,0,tam-1);
    imprimeVetor(vetor,tam);







    return 0;
}
