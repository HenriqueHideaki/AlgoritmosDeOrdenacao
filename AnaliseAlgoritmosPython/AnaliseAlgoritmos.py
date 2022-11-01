import random
import sys
import time

def criarListas(num_elementos, ordenacao):
    elementos = []

    for x in range(num_elementos):
        tmp = random.randint(0, num_elementos)
        elementos.append(tmp)

    if ordenacao=="ASC":
        elementos.sort()
    elif ordenacao=="DESC":
        elementos.sort(reverse=True)

    #salvarArquivo(elementos, num_elementos, ordenacao)

    return elementos


# def salvarArquivo(arr, size, ordenacao = ''):
#     filename = "n"+str(size) + ordenacao
#     with open("inputs/"+filename, 'w') as f:
#         for item in arr:
#             f.write("%s\n" % item)


def analiseAlgoritmo(elementos, algorithm):
 
    global operacoes
    operacoes = 0
    inicio = time.time()
 
 
    if algorithm=="insertion":
        ordenacao = insertionSort(elementos,0,len(elementos)-1)
    elif algorithm=="merge":
        ordenacao = mergeSort(elementos,0,len(elementos)-1)
    elif algorithm=="tim":
        ordenacao = timSort(elementos)
 
    tempo_segundos = time.time() - inicio
 
    print (algorithm)
    print ("tempo: "+str(tempo_segundos)+"s | "+str(operacoes)+" comparacões")
    print ("-----------------------------")
 
    # filename="n"+''.join(sys.argv[1:])
 
    # with open("outputs/"+algorithm+" "+filename, "a") as f:
    #     f.write("%ss\t%sc\n" % (tempo_segundos, operacoes))

# try:
 
#     try:
#         ordenacao = sys.argv[2]
#     except IndexError:
#         ordenacao = ""
 
#     elementos = gerar_entradas.criarListas(int(sys.argv[1]), ordenacao)
#     if int(sys.argv[1]) < 1000000:
#         analiseAlgoritmo(elementos[:], "insertion")
#     analiseAlgoritmo(elementos[:], "merge")
#     analiseAlgoritmo(elementos[:], "tim")
 
# except:
#     print ("ERRO")


def insertionSort(arr, left, right):
    global operacoes
    for i in range(left + 1, right + 1):
        j = i
        #O indice j volta pela sub-lista ordenada, buscando a posição onde o elemento deve ser inserido para que a sub-lista mantenha-se ordenada
        while j > left and arr[j] < arr[j - 1]:
            operacoes+=1
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            j -= 1

    return arr 
 


def merge(lista, i_esquerda, i_meio, i_direita):
 
    global operacoes
 
    #índices para subdividir a lista
    index1 = i_meio - i_esquerda + 1
    index2 = i_direita - i_meio
 
    #inicializando arrays temporários
    temp_esquerda = [0] * (index1)
    temp_direita = [0] * (index2)
 
    #copiando os dados da lista pros arrays
    for i in range(0 , index1):
        operacoes+=1
        temp_esquerda[i] = lista[i_esquerda + i]
    for j in range(0 , index2):
        operacoes+=1
        temp_direita[j] = lista[i_meio + 1 + j]
 
 
    #os índices i e j iteram pelos arrays subdivididos, enquanto k itera pela lista principal
    i, j, k = 0, 0, i_esquerda
 
    #merge
    while i < index1 and j < index2 :
        operacoes+=1
        if temp_esquerda[i] <= temp_direita[j]:
            lista[k] = temp_esquerda[i]
            i += 1
        else:
            lista[k] = temp_direita[j]
            j += 1
        k += 1
 
 
    #quando a comparação entre as duas sublistas acabar, copiar elementos restantes da primeira ou da segunda
    while i < index1:
        lista[k] = temp_esquerda[i]
        i += 1
        k += 1
    while j < index2:
        lista[k] = temp_direita[j]
        j += 1
        k += 1
 
def mergeSort(lista,i_esquerda,i_direita):
 
    global operacoes
 
    if i_esquerda < i_direita:
        operacoes+=1
        meio = (i_esquerda+i_direita)/2
        mergeSort(lista, i_esquerda, meio)
        mergeSort(lista, meio+1, i_direita)
        merge(lista, i_esquerda, meio, i_direita)
    return lista

def timSort(arr):
    global operacoes
    n = len(arr)
    minRun = 32 #Tamanho mínimo do run, segundo recomendações do autor
 
    #Ordenando os subarrays individuais de tamanho minRun
    for inicio in range(0, n, minRun):
        fim = min(inicio + minRun - 1, n - 1)
        insertionSort(arr, inicio, fim)
 
    # Começando a mesclagem a partir do tamanho mínimo da run (32)
    tamanho = minRun
    while tamanho < n:
 
        # escolhendo o ponto de partida do array à esquerda
        # as sub-listas que serão mescladas são arr[esuerda..esquerda+tamanho-1]
        # e arr[esquerda+tamanho, esquerda+2*tamanho-1]
        # depois de mesclar, fazemos o salto em 2*tamanho
        for esquerda in range(0, n, 2 * tamanho):
 
            # Encontrando o ponto de divisão entre as sub-listas
            meio = min(n - 1, esquerda + tamanho - 1)
            direita = min((esquerda + 2 * tamanho - 1), (n - 1))
 
            # Mesclando as sublistas arr[esquerda..meio] e arr[meio+1..direita]
            merge(arr, esquerda, meio, direita)
 
        tamanho = 2 * tamanho
    return arr

lista1 = criarListas(100,"ASC")
analiseAlgoritmo(lista1[0:100],"insertion")
