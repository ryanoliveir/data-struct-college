#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Noh {
    int numero;
    Noh *proximo;
}Noh;

typedef struct Lista {
    Noh *inicio, *fim;
    int tamanho;
} Lista;

bool eVazia (Lista *lst) {
	if(lst->inicio == NULL)
		return true;
	return false;
}

void inserirInicio(Lista *lst, int numero) {
	Noh *novo = new Noh();
	novo->numero = numero;
	
	if(eVazia(lst)){
		novo->proximo = NULL;
		lst->inicio = novo;
		lst->fim = novo;
	} 
	else{
		novo->proximo = lst->inicio;
		lst->inicio = novo;
	}
	lst->tamanho++;
}

void inserirFim(Lista *lst, int numero) {
	Noh *novo = new Noh();
	novo->numero = numero;
	novo->proximo = NULL;
	
	if(eVazia(lst)){
		lst->inicio = novo;
		lst->fim = novo;
	}
	else{
		lst->inicio->proximo = novo;
		lst->fim = novo; 
	}
	
	lst->tamanho++;
	
}

void imprime(Lista *lst) {
	if(!eVazia(lst)) {
		Noh *pAux = lst->inicio;
		
		while(pAux != NULL) {
			cout<<pAux->numero<<endl;
			pAux = pAux->proximo; 
		}
	}
	else
		cout<<"Lista vazia..."<<endl<<endl;
	
}

void remover(Lista *lst, int valor) {
	
	Noh *pAux = lst->inicio;
	Noh *pApagar = NULL;
	
	if(!eVazia(lst)) {
		if(pAux != NULL && lst->inicio->numero == valor) {
			pApagar = lst->inicio;
			lst->inicio = pApagar->proximo;
			if(lst->inicio == NULL)
				lst->fim = NULL;
		}
		else {
			//Existe ; Existe proximo; 
			while(pAux != NULL && pAux->proximo != NULL && pAux->proximo->numero !=valor)
				pAux = pAux->proximo; 
			if(pAux != NULL && pAux->proximo != NULL){
				pApagar = pAux->proximo; 
				pAux->proximo = pApagar->proximo;
				if(pAux->proximo == NULL)
					lst->fim = pAux;
			}
		}
		if(pApagar) {
			delete(pApagar);
			lst->tamanho--;
		} 
		else {
			system("cls");
			cout<<endl<<"Valor nao encontrado!"<<endl<<endl;
			system("pause");
		}
	} 
	else {
		system("cls");
		cout<<"Lista vazia..."<<endl<<endl;
		system("pause");
	}
		
}

int menu() {
    int opcao;

    do{
    	system("cls");
        cout<<endl<<"--- MENU DE OPCOES ----------------------"<<endl<<endl;
        cout<<"[1] Inserir no inicio"<<endl;
        cout<<"[2] Inserir no fim da lista"<<endl;
        cout<<"[3] Imprimir lista"<<endl;
        cout<<"[4] Remover a lista"<<endl;
        cout<<"[5] Esvaziar a lista"<<endl;
        cout<<"[6] Sair"<<endl<<endl;

        cout<<"Entrada: ";
        cin>>opcao;

        if(opcao < 1 || opcao > 6)
            cout<<"Escolha invalida!"<< endl;
    }while(opcao < 1 || opcao > 6);

    return opcao;
}

int main() {
	
	Lista lista;
	
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tamanho = 0;
	int i;
	bool flag = true;
	int numero;
	
	while(flag) {
	    switch (menu())
	    {
	    case 1:
	    	system("cls");
	        cout<<"--- Inserir na Lista -----------------------------"<<endl;
	        cout<<"Numero: ";
			cin>>numero;
			inserirInicio(&lista, numero);
	        break;
	    case 2:
	    	system("cls");
	    	cout<<"--- Inserir no fim da lista ----------------------"<<endl;
	    	cout<<"Numero: ";
			cin>>numero;
			inserirFim(&lista, numero);
	        break;
	    case 3:
	    	system("cls");
	        cout<<"--- Lista Impressa -------------------------------"<<endl;
	        imprime(&lista);
			cout<<endl;
			system("pause");
	        break;
	    case 4:
	    	system("cls");
	        cout<<"--- Remover a Lista ------------------------------"<<endl;
	        cout<<"Numero: ";
	        cin>>numero;
	        remover (&lista, numero);
	        break;
	    case 5:
	    	system("cls");
	        cout<<"--- Esvaziar a Lista -----------------------------"<<endl;
	        break;
	    case 6:  
	        cout<<endl<<"Saindo..."<<endl;
	        flag = false;
	        break;
	    default:
	        break;
	    }
	}
    return 0;
}

/*

*/
