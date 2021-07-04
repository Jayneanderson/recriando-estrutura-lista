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
	
//	if(!isEmpty(list)) {
//		printf()
//	}
//	if(!isEmpty(list)) {
//		
//		Node* aux = list->head;
//		
//		//trocando do primeiro para o segundo n�
//		list->head = aux->next;
//		
//		//apagando n� da estrutura
//		free(aux);
//		list->size--;
//	}
	
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
	
	printf("%d\n", findNode(lista, 1)->elemento.id);
	return 0;
}

