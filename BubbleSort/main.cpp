#include <iostream>

using namespace std;

void troca(int *v, int i, int j){// essa função recebe um vetor e dois indices, e realiza a troca de posição dos elementos que corresponde a esses indices.
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
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

void imprimeVetor(int *v, int tam){//essa função imprime o vetor
    cout << "\n[ ";
    for(int i=0;i<tam;i++){
        cout << v[i] << " ";
    }
    cout << "]";

}

int main()
{
    int tam = 8;
    int v[tam] = {3, 6, 2, 5, 4, 3, 7, 1};
    cout << "\nVetor Desordenado";
    imprimeVetor(v,tam);
    bubbleSort(v,tam);

    cout << "\nVetor Ordenado";
    imprimeVetor(v,tam);

    return 0;
}
