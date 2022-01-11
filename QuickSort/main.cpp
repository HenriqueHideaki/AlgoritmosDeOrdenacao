#include <iostream>

using namespace std;

void imprimeVetor(int *v, int tam) //essa fun��o imprime o vetor
{
    cout << "\n[ ";
    for(int i=0; i<tam; i++)
    {
        cout << v[i] << " ";
    }
    cout << "]";

}


// A fun��o quickSort rebe um vetor que sera ordenado, o seu tamanho, o elemento do inicio do vetor e o elemento do final do vetor
void quickSort(int *v, int tam, int inicio, int fim)
{
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



int main()
{
    int tam = 8;
    int vetor[tam] = {7, 6, 5, 4, 3, 3, 2, 1};

    quickSort(vetor, tam, 0, tam);
    imprimeVetor(vetor,tam);




    return 0;
}
