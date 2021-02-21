#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <chrono>
#define SIZE 5
using namespace std;

int numero[SIZE];
double contadorBubble, contadorQuick, contadorMerge = 0;

// Cronômetro
clock_t t0, tf;
double tempo_gasto;

int quickSortExec();
void quickSort(int *a, int menor, int maior);

int bubbleSort();
void telaBubble();

// Métodos Merge Sort
void trocaElementosMerge(int &a, int &b);        // trocaElementosMerge de elementos
void telaMerge(int *array, int tamanho);         // Impressão de telaMerge
void mergesort(int *array, int l, int m, int r); // Método de ordenação
void mergeSortRecursivo(int *array, int l, int r);        // Método que chama a recursividade
int mergeSortExec();                                 // Chamada do método

int main()
{

    clock_t t0, tf;
    double tempo_gasto;

    setlocale(LC_ALL, "Portuguese"); // Setando Linguagem em Portugues

    int opcao;

    while (opcao != 5)
    {
        printf(" ------------------------------- \n");
        printf("|    Escolha a opcao desejada:  |\n");
        printf("| 1. Bubble Sort.               |\n");
        printf("| 2. Quick Sort.                |\n");
        printf("| 3. Merge Sort.                |\n");
        printf("| 4. Mostrar Tempo.             |\n");
        printf("| 5. Sair.                      |\n");
        printf(" ------------------------------- \n");
        
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            bubbleSort();
            break;
        case 2:
            quickSortExec();
            break;
        case 3:
            mergeSortExec();
            break;
        case 4:
            if (contadorBubble == 0)
            {
                printf("\nMetodo de Ordenacao BUBBLE SORT nao inicializado!!!\n");
            }
            else
            {
                printf("\nTempo de ordenacao Bubble Sort: %lf segundos\n", contadorBubble);
            }
            if (contadorQuick == 0)
            {
                printf("\nMetodo de Ordenacao QUICK SORT nao inicializado!!!\n");
            }
            else
            {
                printf("\nTempo de ordenacao Quick Sort: %lf segundos\n", contadorQuick);
            }
            if (contadorMerge == 0)
            {
                printf("\nMetodo de Ordenacao MERGE SORT nao inicializado!!!\n");
            }
            else
            {
                printf("\nTempo de ordenacao Merge Sort: %lf segundos\n", contadorMerge);
            }
            break;
        case 5:
            cout << "\n[....Encerrando Aplicacao....]\n"
                 << endl;
            exit(0);
        default:
            cout << "Opcao Invalida" << endl;
        }
    }
    return 0;
}

int quickSortExec()
{

    int i, arr[SIZE];
    printf("\n[....Q U I C K  S O R T....]\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("\n[ Vetor numero: %d ] [ Digite um numero ]: ", i);
        scanf("%d%*c", &arr[i]);
    }

    // Inicialização do cronômetro
    t0 = clock();

    quickSort(arr, 0, SIZE - 1);

    printf("\n Valores ordenados \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("\n[ Vetor numero: %d ] [ Elemento ]: %d ", i, arr[i]);
    }

    // Finalizando temporizador
    tf = clock();
    tempo_gasto = ((double)(tf - t0)) / CLOCKS_PER_SEC; // tempo gasto = tempo final menos tempo inicial
    contadorQuick = tempo_gasto;                        // Contador Quick Sort = tempo gasto
    printf("\n--------------------------------------------");
    printf("\nTempo de ordenacao Quick Sort: %lf segundos\n", tempo_gasto);
    printf("\n");
    return contadorQuick;
}

void quickSort(int *a, int menor, int maior)
{
    int i, j, pivot, y;

    i = menor;
    j = maior;
    pivot = a[(menor + maior) / 2];

    while (i <= j)
    {
        while (a[i] < pivot && i < maior)
        {
            i++;
        }
        while (a[j] > pivot && j > menor)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > menor)
    {
        quickSort(a, menor, j);
    }
    if (i < maior)
    {
        quickSort(a, i, maior);
    }
}

void telaBubble()
{
    printf("\n--------------------------------------------");
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n[ Vetor numero: %d ] [ Elemento ]: %d ", i, numero[i]);
    }
}

int bubbleSort()
{

    int i, aux, bandeira;

    printf("\n[....B U B B L E  S O R T....]\n");
    printf("\nInserindo valores no Array\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("\n[ Vetor numero: %d ] [ Digite um numero ]: ", i);
        scanf("%d%*c", &numero[i]);
    }

    printf("\nValores armazenados no array");
    telaBubble();
    printf("\n");

    t0 = clock();

    printf("\n...Ordenando o Array...\n");
    bandeira = 1;
    while (bandeira == 1)
    {
        bandeira = 0;
        for (i = 0; i <= 3; i++)
        {
            if (numero[i] > numero[i + 1])
            {
                bandeira = 1;
                aux = numero[i];
                numero[i] = numero[i + 1];
                numero[i + 1] = aux;
            }
        }
    }

    printf("\n...Array Ordenado...");
    telaBubble();

    tf = clock();
    tempo_gasto = ((double)(tf - t0)) / CLOCKS_PER_SEC;
    contadorBubble = tempo_gasto;
    printf("\n--------------------------------------------");
    printf("\nTempo de ordenacao Bubble Sort: %lf segundos\n", tempo_gasto);
    printf("\n");

    return contadorBubble;
}

// Método de trocaElementosMerge de conteúdo do Merge Sort de a para b
void trocaElementosMerge(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Display onde será impresso o algoritmo Merge Sort
void telaMerge(int *array, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n[ Vetor numero: %d ] [ Elemento]: %d ", i, array[i]);
    }
    printf("\n");
}

// Método de Ordenação do Merge Sort
void mergesort(int *array, int l, int m, int r)
{
    int i, j, k, numEsq, numDir;

    // tamanhos dos sub-arrays da esquerda e da direita
    numEsq = m - l + 1; // tamanho do subvetor esquerdo
    numDir = r - m;     // tamanho do subvetor direito
    int arrEsq[numEsq], arrDir[numDir];
    // Preenchendo os sub-arrays da esquerda e da direita
    for (i = 0; i < numEsq; i++)
        arrEsq[i] = array[l + i]; // elementos do subvetor esquerdo
    for (j = 0; j < numDir; j++)
        arrDir[j] = array[m + 1 + j]; // elementos do subvetor direito
    i = 0;
    j = 0;
    k = l;
    //Arrays temporários
    while (i < numEsq && j < numDir)
    {
        if (arrEsq[i] <= arrDir[j])
        {
            array[k] = arrEsq[i];
            i++;
        }
        else
        {
            array[k] = arrDir[j];
            j++;
        }
        k++;
    }
    while (i < numEsq)
    {
        array[k] = arrEsq[i];
        i++;
        k++;
    }
    while (j < numDir)
    {
        array[k] = arrDir[j];
        j++;
        k++;
    }
}

// Método de chamada de recursividade do Merge Sort
void mergeSortRecursivo(int *array, int esq, int dir)
{
    int m;

    if (esq < dir)
    {
        int m = esq + (dir - esq) / 2; // Calcula o meio do vetor
        // Ordenando os sub-arrays que serão divididos
        mergeSortRecursivo(array, esq, m);      // Ordenando o subvetor esquerdo
        mergeSortRecursivo(array, m + 1, dir);  // Ordenando o subvetor direito
        mergesort(array, esq, m, dir); // fusão dos subvetores esquerdo e direito
    }
}

int mergeSortExec()
{

    int arr[SIZE];
    printf("\n[....M E R G E  S O R T....]\n");

    printf("\nInserindo valores no Array\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n[ Vetor numero: %d ] [ Digite um numero ]: ", i);
        scanf("%d%*c", &arr[i]);
    }

    printf("\nValores Armazenados no array: \n");
    telaMerge(arr, SIZE);

    t0 = clock();

    mergeSortRecursivo(arr, 0, SIZE - 1); //(n-1) para o último índice

    printf("\n");

    printf("\n...Array Ordenado...\n ");
    telaMerge(arr, SIZE);

    tf = clock();
    tempo_gasto = ((double)(tf - t0)) / CLOCKS_PER_SEC;
    contadorMerge = tempo_gasto;
    printf("\n--------------------------------------------");
    printf("\nTempo de ordenacao Merge Sort: %lf segundos\n", tempo_gasto);

    return contadorMerge;
}