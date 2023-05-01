#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
	int number;
	Node *next;
} Node;


typedef struct List {
	Node *start, *end;
	int size;
} List;

bool emptyCheck(List* list);
void headInsert(List *list, int number);
void tailInsert(List *list, int number);
void showList(List *list);

int menu(){
	int opcao;

	do
	{
		cout << endl << "MENU OPTIONS" << endl;
		cout << "1 - Inserir no inicio da lista" << endl;
		cout << "2 - Inserir no fim da lista" << endl;
		cout << "3 - Imprimir toda lista" << endl;
		cout << "4 - Remover da lista" << endl;
		cout << "5 - Esvaziar a Lista" << endl;
		cout << "6 - Sair" << endl;


		cout << "Digite sua escolha: ";
		cin >> opcao;

		if(opcao < 1 || opcao > 6)
			cout << "\tEscolha invalida!" << endl;

	}while(opcao < 1 || opcao > 6);

	return opcao;

}

int main(){

	List list;

	list.start = NULL;
	list.end = NULL;
	list.size = 0;

	int chose, number;

	do {
		chose = menu();

		switch (chose){
			case 1:
				system("cls");
				cout << "Digite o numero a ser inserido no inicio na Lista: " << endl;
				cin >> number;
				headInsert(&list, number);
			break;

			case 2:
				system("cls");
				cout << "Digite o numero a ser inserido no final na Lista: " << endl;
				cin >> number;
				tailInsert(&list, number);
			break;

			case 3:
				system("cls");
				cout << "Imprimindo lista..." << endl;
				showList(&list);
			break;

			case 4:
				system("cls");
				cout << "Digite o numero a ser removido: " << endl;
				cin >> number;
				
			break;

			case 5:
				cout << "Digite o numero a ser inserido no inicio na Lista: " << endl;
			break;

			default:
				cout << "Digite o numero a ser inserido no inicio na Lista: " << endl;

		}
	} while(chose != 6);

	return 0;
}


bool emptyCheck(List* list){

	if (list->start == NULL) {
  		return true;
	}
	return false;

}


void headInsert(List *list, int number){

	Node *new_node = new Node();
	new_node->number = number;


	if(emptyCheck(list)){
		new_node->next = NULL;
		list->start = new_node;
		list->end = new_node;
	}else {
		new_node->next = list->start;
		list->start = new_node;
	}

	list->size++;
}




void tailInsert(List *list, int number){

	Node *new_node = new Node();
	new_node->number = number;
	new_node->next = NULL;


	if(emptyCheck(list)){
		list->start = new_node;
		list->end = new_node;
	} else {

		list->end->next = new_node;
		list->end = new_node;
	}

	list->size++;
}


void showList(List *list){

	if(emptyCheck(list)){
		cout << "List empty" << endl;
		return;
	}

	Node *auxNode = list->start;
	
	while (auxNode != NULL){
		cout << auxNode->number << " " << endl; 
		auxNode = auxNode->next;
	}

	cout << "List size: " << list->size << endl;
	cout << endl;


}


void pop(List *list, int value_remove){
	
	Node *auxNode = list->start;
	Node *removedNode = NULL;

	if(!emptyCheck(list)){

		if(auxNode != NULL && list->start->number == value_remove){
			removedNode = list->start;
			list->start = removedNode->next;

			if(list->start == NULL)
				list->end = NULL;
		} else {

			while(auxNode != NULL && auxNode->next != NULL && auxNode->next->number != value_remove){
				auxNode = auxNode->next;
			}

			if(auxNode != NULL && auxNode->next != NULL){
				removedNode = auxNode->next;
				auxNode->next = removedNode->next;  

				if(auxNode->next != NULL)
					list->end = auxNode;
			}
		}

		if(removedNode){
			delete(removedNode);
			list->size--;
		} else {
			system("cls");
			cout << "Lista vazia" << endl;
			system("pause");
		}


	} else {
		system("cls");
		return;
	}
}
