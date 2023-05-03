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

void copyvetayToList(int vet[], int tamanho, Noh *&inicio)
{
    for (int i = 0; i < tamanho; i++)
    {
        insert(inicio, vet[i]);
    }
}

void copyListTovetay(Noh *inicio, int vet[], int &tamanho)
{
    Noh *atual = inicio;
    int i = 0;

    while (atual != NULL)
    {
        vet[i] = atual->numero;
        atual = atual->proximo;
        i++;
    }
    tamanho = i;
}

int menu()
{
    int opcao;
    system("color 0A");
    cout << "----------------------------------------" << endl;
    cout << "|                 MENU                 |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "| 1 - Inserir valor na Lista           |" << endl;
    cout << "| 2 - Imprimir Lista                   |" << endl;
    cout << "| 3 - Copiar vetor para Lista          |" << endl;
    cout << "| 4 - Copiar Lista para vetor          |" << endl;
    cout << "| 5 - Sair                             |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Digite a opcao desejada: ";
    cin >> opcao;
    return opcao;
}

int main()
{
    Noh *inicio = NULL;
    int vet[100], tamanho = 0;
    int opcao, valor;

    do
    {
        system("cls");
        opcao = menu();
        switch (opcao)
        {
        case 1:
            cout << "Digite o valor a ser inserido na Lista: ";
            
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
            copyvetayToList(vet, tamanho, inicio);
            break;
        case 4:
            copyListTovetay(inicio, vet, tamanho);
            cout << "Vetor criado: ";
            for (int i = 0; i < tamanho; i++)
            {
                cout << vet[i] << " ";
            }
            cout << endl;
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
