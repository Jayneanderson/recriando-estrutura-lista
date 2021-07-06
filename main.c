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

void erase(List* list, int indice);
void exchangeNodes(List * list, Node* a, Node* b);

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

//Função para retornar o índice de um nó

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
	
	//pegando nó anterior ao nó B
	Node* vizinhoB = findNode(list, indexB - 1);
	
	if(a == list->head) {
		//pego a cabeça da lista e digo que recebe o nó B
		list->head = b;
	}
	
	else {
		//Devolve o vizinho da esquerda de A
		Node* vizinhoA = findNode(list, indexA - 1);
		
		//o vinzinho a esquerda aponta para o nó B
		vizinhoA->next = b;
	}
	
	//alterando o anterior do B, ou seja aponta para A
	vizinhoB->next = a;
	
	//Estou salvando antes de perder a referência
	Node* temp = a->next;
	
	a->next = b->next;
	b->next = temp;
	
}

//Função para excluir o nó do índice desejado

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
	
	
	exchangeNodes(lista, lista->head->next, lista->head->next->next);
	
	printList(lista);
	return 0;
}

