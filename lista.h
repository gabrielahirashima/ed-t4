#ifndef LISTA_H_
#define LISTA_H_

/*define listaStruct como ponteiro void*/
typedef void *listaStruct;

/*define tipo como ponteiro void*/
typedef void *tipo;

/*define Node como ponteiro void*/
typedef void *Node;

/*inicia a lista apontado para NULL*/
listaStruct criaLista();

/*Insere elemento ao final da lista encadeada*/
listaStruct insertElemento(listaStruct lista, tipo elemento);

/*Insere elemento antes do elemento_2 na lista encadeada*/
listaStruct insertBefore(listaStruct lista, tipo elemento, tipo elemento_2);

/*Insere elemento após elemento_2 na lista encadeada*/
listaStruct insertAfter(listaStruct lista, tipo elemento, tipo elemento_2);

/*apenas remove o node e nao o elemento*/
void removeNode(listaStruct l, Node elemento);

/*remove o node e o elemento da lista encadeada*/
void removeElemento(listaStruct lista, Node elemento);

/*libera lista encadeada removendo os elementos*/
void liberaLista(listaStruct lista);

/*libera lista encadeada sem remover os elementos*/
void liberaListaNaoTotal(listaStruct lista);

/*retorna o primeiro elemento da lista*/
Node getFirst(listaStruct lista);

/*retorna o ultimo elemento da lista*/
Node getLast(listaStruct lista);

/*retorna elemento anterior ao elemento passado*/
Node getPrevious(Node elemento);

/*retorna o próximo elemento ao elemento passado*/
Node getNext(Node elemento);

/*retorna elemento*/
tipo getElemento(Node elemento);

/*retorna o tamanho da lista*/
int tamanhoLista(listaStruct lista);

/*imprime lista*/
void imprimeLista(listaStruct l, char c);

double getXLista(Node no);

double getYLista(Node no);

void quicksort(listaStruct lista, Node first, Node last);

Node partition(listaStruct lista, Node first, Node last);

void swap(listaStruct lista, int pos);

void swapElemento(Node *node1, Node *node2);
#endif
