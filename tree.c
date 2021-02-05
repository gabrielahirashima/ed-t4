#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

typedef struct ponto{
    double x;
    double y;
}Ponto;

typedef struct no{
    QuadTreeInfo elemento;
    int nivel;
    struct ponto p;
    struct no *sudeste; /*se*/
    struct no *sudoeste; /*so*/
    struct no *nordeste; /*ne*/
    struct no *noroeste; /*no*/
    struct no *ant; 
}No;

typedef struct arvore{
    No *raiz;
    No *raizAtual;
    int niveis;
}Arvore;

QuadTree criaQuadTree(){
    Arvore *qt = (Arvore*)malloc(sizeof(Arvore));
    qt->raiz = NULL;
    qt->niveis = 0;

    return qt;
}

QuadTree insereElemento(QuadTree qt, QuadTreeInfo elemento, Ponto p){
    Arvore *arvoreQt = (Arvore*)qt; 
    char *quadrante = getQuadrante(p, arvoreQt->raizAtual->p); 

    No* node = (No*)malloc(sizeof(No));
    node->elemento = elemento;

        if(arvoreQt->raiz == NULL){
            arvoreQt->raiz = node;
            node->p = p;
        }
        else{
            No* qtAux = arvoreQt->raizAtual; 
        }
}

char *getQuadrante(Ponto pAtual, Ponto pRaiz){
    if(pRaiz.x > pAtual.x){
        if(pRaiz.y > pAtual.y){
            return "SE"; /*Sudeste*/
        }
        else{
            return "NE"; /*Nordeste*/
        }
    }
    else if(pRaiz.x < pAtual.x){
        if(pRaiz.y < pAtual.y){
            return "NO"; /*Noroeste*/
        }
        else{
            return "SO"; /*Sudoeste*/
        }
    }
}

Node getPrevious(Node no){
    No* node = (No*)no;

    return node->ant;
}

Node getNextSudeste(Node no){
    No *node = (No*)no;

    return node->sudeste;
}

Node getNextSudoeste(Node no){
    No *node = (No*)no;

    return node->sudoeste;
}

Node getNextNordeste(Node no){
    No *node = (No*)no;

    return node->nordeste;
}

Node getNextNoroeste(Node no){
    No *node = (No*)no;

    return node->noroeste;
}


tipo getElemento(Node no){
    No *node = (No*)no;

    return node->elemento;
}

