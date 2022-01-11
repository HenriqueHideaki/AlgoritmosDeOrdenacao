#include <iostream>

using namespace std;

void imprimeVetor(int *v, int tam) //essa função imprime o vetor
{
    cout << "\n[ ";
    for(int i=0; i<tam; i++)
    {
        cout << v[i] << " ";
    }
    cout << "]";

}


// A função quickSort rebe um vetor que sera ordenado, o seu tamanho, o elemento do inicio do vetor e o elemento do final do vetor
void quickSort(int *v, int tam, int inicio, int fim)
{
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



int main()
{
    int tam = 8;
    int vetor[tam] = {7, 6, 5, 4, 3, 3, 2, 1};

    quickSort(vetor, tam, 0, tam);
    imprimeVetor(vetor,tam);




    return 0;
}
