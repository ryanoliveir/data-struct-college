#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

typedef struct Noh
{
    int numero;
    Noh *proximo;
} Noh;

void insert(Noh *&inicio, int valor)
{
    Noh *novoNoh = new Noh;
    novoNoh->numero = valor;
    novoNoh->proximo = NULL;

    if (inicio == NULL)
    {
        inicio = novoNoh;
    }
    else
    {
        Noh *atual = inicio;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novoNoh;
    }
}

void printList(Noh *inicio)
{
    Noh *atual = inicio;

    cout << "Lista:" << endl;
    while (atual != NULL)
    {
        cout << atual->numero << " ";
        atual = atual->proximo;
    }
    cout << endl
         << endl;
}

void CopyArrayToList(int vet[], int tamanho, Noh *&inicio)
{
    if (tamanho == 0)
    {
        return;
    }

    insert(inicio, vet[0]);
    CopyArrayToList(vet + 1, tamanho - 1, inicio);
}

void copyListToArrayAux(Noh *current, int arr[], int &index)
{
    if (current == NULL)
    {
        return;
    }

    copyListToArrayAux(current->proximo, arr, index);
    arr[index] = current->numero;
    index++;
}

void copyListToArray(Noh *inicio, int vet[], int &tamanho, int i = 0)
{
    if (inicio == NULL)
    {
        return;
    }

    vet[i] = inicio->numero;
    tamanho++;
    copyListToArray(inicio->proximo, vet, tamanho, i + 1);
}

int menu()
{
    int opcao;
    system("color 0A");
    cout << "1 - Inserir elemento na lista" << endl;
    cout << "2 - Exibir lista" << endl;
    cout << "3 - Copiar vetor para lista" << endl;
    cout << "4 - Copiar lista para vetor" << endl;
    cout << "5 - Sair" << endl;
    cout << "Digite a opcao desejada: " << endl;
    cin >> opcao;
    return opcao;
}

int main()
{
    Noh *inicio = NULL;
    int opcao, valor, tamanho = 0;
    int vet[100];

    do
    {
        system("cls");
        opcao = menu();
        switch (opcao)
        {
        case 1:
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            insert(inicio, valor);
            break;
        case 2:
            printList(inicio);
            getch();
            break;
        case 3:
            cout << "Digite o tamanho do vetor: ";
            cin >> tamanho;
            cout << "Digite os valores do vetor: ";
            for (int i = 0; i < tamanho; i++)
            {
                cin >> vet[i];
            }
            CopyArrayToList(vet, tamanho, inicio);
            break;
        case 4:
            tamanho = 0; // inicializa size com 0
            copyListToArray(inicio, vet, tamanho);
            cout << "Vetor criado: ";
            for (int i = 0; i < tamanho; i++)
            {
                cout << vet[i] << " ";
            }
            cout << endl
                 << endl;
            getch();
            break;
        case 5:
            cout << "Saindo..." << endl;
            getch();
            break;
        default:
            cout << "Opcao invalida!" << endl;
            getch();
            break;
        }
    } while (opcao != 5);

    return 0;
}
