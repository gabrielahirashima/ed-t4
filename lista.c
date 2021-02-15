#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaEnvoltoria.h"
#include "listaQuadras.h"

typedef struct no{
    void *elemento;
    struct no *ant;
    struct no *prox;
}No;

typedef struct lista{
    No *primeiro;
    No *ultimo;
}Lista;

listaStruct criaLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}

listaStruct insertElemento(listaStruct lista, tipo elemento){
    Lista *list = (Lista*)lista;
    
    No* node = (No*)malloc(sizeof(No));
    node->elemento = elemento;
        if(list->primeiro == NULL){ /*se a lista esta vazia*/
            node->ant = NULL; /*o anterior aponta para null*/
            list->primeiro = node; /*o primeiro elemento da lista é node*/
        }
        else{ /*senao*/
            list->ultimo->prox = node; /*o prox do ultimo elemento adicionado aponta para o novo node*/
            node->ant = list->ultimo; /*o ponteiro de anterior aponta pro ultimo elemento adicionado*/
        }

        node->prox = NULL;
        list->ultimo = node;
    return list; 
}

listaStruct insertBefore(listaStruct lista, tipo elemento, tipo elemento_2){
    Lista *list = (Lista*)lista;

    No* node = (No*)malloc(sizeof(No));
    node->elemento = elemento;

    No* inicio = list->primeiro;
    No *aux_1;
    No *aux_2;

        while (inicio != NULL){
                    if(inicio == elemento_2){
                            if(inicio == list->primeiro){
                                aux_1 = inicio;
                                aux_1->ant = node;
                                node->prox = aux_1;
                                node->ant = NULL;
                                list->primeiro = node;
                                return list; 
                            }
                        else if(inicio!= list->primeiro){
                                aux_1 = inicio;
                                aux_2 = inicio->ant;
                                node->ant = aux_2;
                                node->prox = aux_1;
                                aux_1->ant = node;
                                aux_2->prox = node;
                                return list; 
                        }
                    }
                    inicio = inicio->prox;
        }
    return NULL;
}

listaStruct insertAfter(listaStruct lista, tipo elemento, tipo elemento_2){
     Lista *list = (listaStruct)lista;
    
         No* node = (No*)malloc(sizeof(No));
         node->elemento = elemento;
         
         No *inicio = list->primeiro;
         No *aux_1; 
         No *aux_2;
            while(inicio != NULL){
                if(inicio == elemento_2){
                        if(inicio == list->ultimo){
                            aux_1 = inicio;
                            aux_1->prox = node;
                            node->prox = NULL;
                            node->ant = aux_1;
                            list->ultimo = node;
                            return list; 
                        }
                        else if(inicio!= list->ultimo){
                            aux_1 = inicio;
                            aux_2 = inicio->prox;
                            aux_1->prox = node;
                            aux_2->ant = node;
                            node->ant = aux_1;
                            node->prox = aux_2;
                            return list; 
                        }
                }
                inicio = inicio->prox;
            }
    return NULL;
}

void removeElemento(listaStruct l, Node elemento){
   Lista* lista = (Lista*) l;
    No *aux, *aux2;
    aux = lista->primeiro;
    
    while (aux!=NULL){
        if(aux->elemento == elemento){
            if (aux == lista->primeiro){
                lista->primeiro = aux->prox;
                lista->primeiro->ant = NULL;
            }
            if(aux == lista->ultimo){
                lista->ultimo = aux->ant;
                lista->ultimo->prox = NULL;
            }

            aux2 = aux->prox;
            aux2->ant = aux->ant;

            if(aux->ant!=NULL){
                aux->ant->prox = aux2;
            }
            
            free(aux->elemento);
            free(aux);
            break;
         }
        aux = aux->prox;
    }
}

void liberaLista(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->primeiro;
    No *aux;
        while(node != NULL){
            aux = node->prox;
                free(node->elemento);
                free(node);
            node = aux;
        }
    free(lista);
}

Node getFirst(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->primeiro;
    return node;
}

Node getLast(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->ultimo;
    return node;
}

Node getPrevious(Node elemento){
    No* node = (No*)elemento;

    return node->ant;
}

Node getNext(Node elemento){
    No* node = (No*)elemento;

    return node->prox;
}

tipo getElemento(Node elemento){
    No *node = (No*)elemento;

    return node->elemento; 
}

int tamanhoLista(listaStruct lista){
 Lista *list = (Lista*)lista;
 int tamanho = 0;
    No *node = list->primeiro;
        while(node != NULL){
            tamanho += 1;
            node = node->prox;
        }
    return tamanho;
}

void quicksort(listaStruct lista, int tamanho, int inicio){
    int i = inicio;
    int j = tamanho - 1;
    tipo *elementoPivo, *elemento1, *elemento2;

    No *aux1, *aux2, *aux3, *pivo;

    pivo = getFirst(lista);
    for(int k = 0; k < (i + tamanho)/2 ; k++){
        pivo = getNext(lista);
    }
        elementoPivo = getElemento(pivo);

    while(i <= j) { 
        aux1 = getFirst(lista);
        for(int k = 0; k < i; k++){
            aux1 = getNext(aux1);
        }
        elemento1 = getElemento(aux1);

        while(comparaPontosEnvoltoria((getFirst(lista)), pivo, aux1) > 0 && i < tamanho){
            aux1 = getNext(aux1);
            elemento1 = getElemento(aux1);
            i++;
        }

        aux1 = getFirst(lista);
           for (int k = 0; k < j; k++){
            aux1 = getNext(aux1);
        }
        elemento1 = getInfo(aux1);

        while(compare((getFirst(lista)), pivo, aux1) > 0 && j > inicio){
                aux1 = getPrevious(aux1);
                elemento1 = getElemento(aux1);

                j--;
        }
        
        if (i <= j){
            aux2 = getFirst(lista);
            for (int k = 0; k < j; k++){
                aux2 = getNext(aux2);
            }

            aux1 = getFirst(lista);

            for (int k = 0; k < i; k++){
                aux1 = getNext(aux1);
            }

            aux3->elemento = aux1->elemento;
            aux1->elemento = aux2->elemento;
            aux2->elemento = aux3->elemento;
            j--;
            i++;
        }
        
    }
    if (inicio < j){
        quickSort(lista, inicio, j+1);
    }if (tamanho > i){
        quickSort(lista, i, tamanho);
    }

}

void swap(Node no1, Node no2){
    No *node1 = (No*)no1;
    No *node2 = (No*)no2;
    No *aux;

    aux->elemento = node1->elemento;
    node1->elemento = node2->elemento;
    node2->elemento = aux->elemento;

}