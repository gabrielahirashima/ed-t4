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

No* criaNo(){
    No* node = (No*)malloc(sizeof(No));
    node->sudeste = NULL;
    node->sudoeste = NULL;
    node->nordeste = NULL;
    node->noroeste = NULL;

    return node;
}

QuadTree insereElemento(QuadTree qt, QuadTreeInfo elemento, double px, double py){
    Arvore *arvoreQt = (Arvore*)qt; 
    No* pai;
    char *quadrante;

        if(arvoreQt->raiz == NULL){
            No* node = criaNo();
            node->elemento = elemento;
            arvoreQt->raiz = node;
            arvoreQt->raizAtual = node;
            node->p.x = px;
            node->p.y = py;
            node->ant = NULL;
        }
        else{
            No* qtAux = arvoreQt->raizAtual;
            while (qtAux != NULL && (comparaPonto(px, py, qtAux->p.x, qtAux->p.y) == 0)){
                pai = qtAux;
                quadrante = getQuadrante(px, py, qtAux->p.x, qtAux->p.y);
            	qtAux = getFilho(qtAux, quadrante);
            }
            if(qtAux == NULL){
                 No* node = criaNo();
            }

        }
}

char *getQuadrante(double pAtualX, double pAtualY, double pRaizX, double pRaizY){
    if(pRaizX > pAtualX){
        if(pRaizY > pAtualY){
            return "SE"; /*Sudeste*/
        }
        else{
            return "NE"; /*Nordeste*/
        }
    }
    else if(pRaizX < pAtualX){
        if(pRaizY < pAtualY){
            return "NO"; /*Noroeste*/
        }
        else{
            return "SO"; /*Sudoeste*/
        }
    }
}

int comparaPonto(double pAtualX, double pAtualY, double pRaizX, double pRaizY){
    if(pRaizX == pAtualX  && pRaizY == pAtualY){
        return 1;
    }
    else
        return 0;
}

Node getFilho(Node no, char* quadrante){
    No* node = (No*)no;

    if(strcmp("SE", quadrante) == 0){
        return node->sudeste;
    }
    else if(strcmp("SO", quadrante) == 0){
        return node->sudoeste;
    }
    else if(strcmp("NE", quadrante) == 0){
        return node->nordeste;
    }
    else if(strcmp("NO", quadrante) == 0){
        return node->noroeste;
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

