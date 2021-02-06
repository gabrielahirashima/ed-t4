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
                   arvoreQt->raizAtual = node;
                    node->p.x = px;
                    node->p.y = py;
                    node->ant = qtAux;
                    setFilho(qtAux, node, quadrante);
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

void setFilho(Node pai, Node filho, char *quadrante){
    No* nodePai = (No*)pai;
    No* nodeFilho = (No*)filho;

    if(strcmp("SE", quadrante) == 0){
         nodePai->sudeste = nodeFilho;
    }
    else if(strcmp("SO", quadrante) == 0){
         nodePai->sudoeste = nodeFilho;
    }
    else if(strcmp("NE", quadrante) == 0){
         nodePai->nordeste = nodeFilho;
    }
    else if(strcmp("NO", quadrante) == 0){
         nodePai->noroeste = nodeFilho;
    } 
}

Node getNoQt(Node raiz, double x, double y){
    No* node = (No*)raiz;

    if(node == NULL){
        return NULL;
    }
    else{ 
        if(node->p.x == x && node->p.y == y){
            return node;
        }
        else{
            char *quadrante = getQuadrante(x, y, node->p.x, node->p.y);
            No* filho;


        }
    }
}