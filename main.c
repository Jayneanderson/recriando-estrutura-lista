#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct elemento { //Estrutura datanode
	int id; //identificador de cada nó
	char programName[50];
	
} Elemento;

typedef struct node { //definindo nó
	Elemento elemento;
	struct node* next; //aqui está assim porque o apelido (Node) ainda não foi dado. Referência para o próximo nó
} Node;

typedef struct list {
	int size;
	Node* head;
} List;


//<----------Funções------------->

List * createLista() {
	//Criando um ponteiro para a lista
	List* list = (List*) malloc(sizeof(List));
	
	//atribuindo tamanho zero a lista
	list->size = 0;
	
	//a cabeça do nó aponta para null
	list->head = NULL;
	return list;
}

//Função para criar nó

Node* newNode() {
	return (Node*) malloc(sizeof(Node));
}

//Função para inserir no começo da lista

void insertBegin(List* list, Elemento elemento) {
	Node* n = newNode();
	
	//dizendo que o novo nó é a informação que passamos no parâmetro, ou seja, criando uma cópia
	n->elemento = elemento; 
	
	//agora vamos ligar ele na lista e dizer que ele é o cabeçss
	n->next = list->head;
	
	//dizemos que o nó cabeça será nosso nó
	list->head = n;
	list->size++;
}

//Função para verificar se está vazia
bool isEmpty(List* list) {
	return (list->size == 0);
}

//Função para Remover do início

void removeBegin(List* list) {
	
	if(!isEmpty(list)) {
		Node* aux = list->head;
		
		//trocando do primeiro para o segundo nó
		list->head = aux->next;
		
		//apagando nó da estrutura
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
//		//trocando do primeiro para o segundo nó
//		list->head = aux->next;
//		
//		//apagando nó da estrutura
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
	
	Node* aux = list->head; //uma variável que apontar para a cabeça da lista, mas ele não altera o valor da cabeça e sim da própria variável
	
	while(aux != NULL) {//enquanto a lista não estiver vazia, passe para o próximo
		printf("%d: %s\n", aux->elemento.id, aux->elemento.programName);
		aux = aux->next; //passe para o próximo
	}
	
	
}

//Função para retornar um nó ao passar o índice

Node* findNode(List* list, int index) {
	
	//se o índice estiver entre 0 e o tamanho da lista a condição se torna verdadeira
	if(index >= 0 && index < list->size) {
		Node* aux = list->head;
		
		int i;
		//percorre até achar o index
		for(i = 0; i < index; i++) {
			aux = aux-> next;
		}
		
		//sai do laço e retorna o index encontrado
		return aux;
	}
	
	return NULL;
}

/* OBS: a FLECHA é utilizada para ponteiros e PONTO para variáveis */

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

