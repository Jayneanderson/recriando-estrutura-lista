#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct elemento { //Estrutura datanode
	int id; //identificador de cada n�
	char programName[50];
	
} Elemento;

typedef struct node { //definindo n�
	Elemento elemento;
	struct node* next; //aqui est� assim porque o apelido (Node) ainda n�o foi dado. Refer�ncia para o pr�ximo n�
} Node;

typedef struct list {
	int size;
	Node* head;
} List;

void erase(List* list, int indice);
void exchangeNodes(List * list, Node* a, Node* b);

//<----------Fun��es------------->

List * createLista() {
	//Criando um ponteiro para a lista
	List* list = (List*) malloc(sizeof(List));
	
	//atribuindo tamanho zero a lista
	list->size = 0;
	
	//a cabe�a do n� aponta para null
	list->head = NULL;
	return list;
}

//Fun��o para criar n�

Node* newNode() {
	return (Node*) malloc(sizeof(Node));
}

//Fun��o para inserir no come�o da lista

void insertBegin(List* list, Elemento elemento) {
	Node* n = newNode();
	
	//dizendo que o novo n� � a informa��o que passamos no par�metro, ou seja, criando uma c�pia
	n->elemento = elemento; 
	
	//agora vamos ligar ele na lista e dizer que ele � o cabe�ss
	n->next = list->head;
	
	//dizemos que o n� cabe�a ser� nosso n�
	list->head = n; 
	list->size++;
}

//Fun��o para verificar se est� vazia
bool isEmpty(List* list) {
	return (list->size == 0);
}

//Fun��o para Remover do in�cio

void removeBegin(List* list) {
	
	if(!isEmpty(list)) {
		Node* aux = list->head;
		
		//trocando do primeiro para o segundo n�
		list->head = aux->next;
		
		//apagando n� da estrutura
		free(aux);
		list->size--;
	}
	
}

//Imprimir lista

void printList(List * list) {
	
	if(isEmpty(list)) {//se a lista for vazia, retorna o print
		printf("Lista vazia\n");
		return;
	}
	
	Node* aux = list->head; //uma vari�vel que apontar para a cabe�a da lista, mas ele n�o altera o valor da cabe�a e sim da pr�pria vari�vel
	
	while(aux != NULL) {//enquanto a lista n�o estiver vazia, passe para o pr�ximo
		printf("%d: %s\n", aux->elemento.id, aux->elemento.programName);
		aux = aux->next; //passe para o pr�ximo
	}
	
}

//Fun��o para retornar um n� ao passar o �ndice

Node* findNode(List* list, int index) {
	
	//se o �ndice estiver entre 0 e o tamanho da lista a condi��o se torna verdadeira
	if(index >= 0 && index < list->size) {
		Node* aux = list->head;
		
		int i;
		//percorre at� achar o index
		for(i = 0; i < index; i++) {
			aux = aux-> next;
		}
		
		//sai do la�o e retorna o index encontrado
		return aux;
	}
	
	return NULL;
}

//Fun��o para retornar o �ndice de um n�

int findIndice(List* list, Node* n) {
	if(n != NULL) {
		Node* aux = list->head;
		
		int cont = 0;
		
		while(aux != n && n != NULL) {
			aux = aux-> next;
			cont++;
		}
		
		if(aux != NULL) {
			return cont;
		}
		
	}
	
	printf("No nao pertence a lista\n");
	return -1;
}

void exchangeNodes(List * list, Node* a, Node* b) {
	
	if(a == b) {
		return;
	}
	
	int indexA = findIndice(list, a);
	int indexB = findIndice(list, b);
	
	
	if(indexA > indexB) {
		Node* aux;
		a = b;
		b = findNode(list, indexA);
		
		
		indexA = indexB;
		indexB = findIndice(list, b);
	}//fim if index
	
	//pegando n� anterior ao n� B
	Node* vizinhoB = findNode(list, indexB - 1);
	
	if(a == list->head) {
		//pego a cabe�a da lista e digo que recebe o n� B
		list->head = b;
	}
	
	else {
		//Devolve o vizinho da esquerda de A
		Node* vizinhoA = findNode(list, indexA - 1);
		
		//o vinzinho a esquerda aponta para o n� B
		vizinhoA->next = b;
	}
	
	//alterando o anterior do B, ou seja aponta para A
	vizinhoB->next = a;
	
	//Estou salvando antes de perder a refer�ncia
	Node* temp = a->next;
	
	a->next = b->next;
	b->next = temp;
	
}

//Fun��o para excluir o n� do �ndice desejado

/* OBS: a FLECHA � utilizada para ponteiros e PONTO para vari�veis */

int main(int argc, char *argv[]) {
	
	List* lista = createLista();
	
	Elemento processo;
	
	processo.id = 5;
	strcpy(processo.programName, "Excel");
	
	insertBegin(lista, processo);
	
	processo.id = 4;
	strcpy(processo.programName, "Word");
	
	insertBegin(lista, processo);

	printList(lista);
	printf("\n");
	
	
	exchangeNodes(lista, lista->head->next, lista->head->next->next);
	
	printList(lista);
	return 0;
}

