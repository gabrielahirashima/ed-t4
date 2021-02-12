#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

typedef struct ponto{
    double x;
    double y;
}Ponto;

typedef struct node{
    QuadTreeInfo elemento;
    struct ponto p;
    struct no *sudeste; /*se*/
    struct no *sudoeste; /*so*/
    struct no *nordeste; /*ne*/
    struct no *noroeste; /*no*/
    struct no *ant; 
}NoStruct;

typedef struct arvore{
    NoStruct *raiz;
    NoStruct *raizAtual;
    int niveis;
}ArvoreStruct;

QuadTreeQT criaQuadTree(){
    ArvoreStruct *qt = (ArvoreStruct*)malloc(sizeof(ArvoreStruct));
    qt->raiz = NULL;
    qt->niveis = 0;

    return qt;
}

QuadTreeNo criaNo(){
    NoStruct* node = (NoStruct*)malloc(sizeof(NoStruct));
    node->sudeste = NULL;
    node->sudoeste = NULL;
    node->nordeste = NULL;
    node->noroeste = NULL;

    return node;
}

QuadTreeQT insereElemento(QuadTreeQT qt, QuadTreeInfo elemento, double px, double py){
    ArvoreStruct *arvoreQt = (ArvoreStruct*)qt; 
    NoStruct* pai;
    char *quadrante;

        if(arvoreQt->raiz == NULL){
            NoStruct* node = criaNo();
            node->elemento = elemento;
            arvoreQt->raiz = node;
            arvoreQt->raizAtual = node;
            node->p.x = px;
            node->p.y = py;
            node->ant = NULL;
        }
        else{
            NoStruct* qtAux = arvoreQt->raizAtual;
            while (qtAux != NULL && (comparaPonto(px, py, qtAux->p.x, qtAux->p.y) == 0)){
                pai = qtAux;
                quadrante = getQuadrante(px, py, qtAux->p.x, qtAux->p.y);
            	qtAux = getFilho(qtAux, quadrante);
            }
            if(qtAux == NULL){
                 NoStruct* node = criaNo();
                   arvoreQt->raizAtual = node;
                    node->p.x = px;
                    node->p.y = py;
                    node->ant = qtAux;
                    setFilho(qtAux, node, quadrante);
            }

        }
    return arvoreQt;
}

QuadTreeQT removeElemento(){

}

void liberaNoQuadTree(QuadTreeNo no){
    NoStruct* node = (NoStruct*)no;

    if(node == NULL){
        return;
    }

    if(node->nordeste != NULL){
        freeNoQuadtree(node->nordeste);
    }
    else if(node->noroeste != NULL){
        freeNoQuadtree(node->noroeste);
    }
    else if(node->sudeste != NULL){
        freeNoQuadtree(node->sudeste);
    }
    else if(node->sudoeste != NULL){
        freeNoQuadtree(node->sudoeste);
    }

    free(node->elemento);
    free(node);  
}

void liberaQuadTree(QuadTreeQT qt){
    ArvoreStruct *arvoreQt = (ArvoreStruct*)qt; 
    freeNoQuadTree(arvoreQt);
    free(arvoreQt);
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

QuadTreeNo getFilho(QuadTreeNo no, char* quadrante){
    NoStruct* node = (NoStruct*)no;

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

void setFilho(QuadTreeNo pai, QuadTreeNo filho, char *quadrante){
    NoStruct* nodePai = (NoStruct*)pai;
    NoStruct* nodeFilho = (NoStruct*)filho;

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

QuadTreeNo getNoQt(QuadTreeNo raiz, double x, double y){
    NoStruct* node = (NoStruct*)raiz;

    if(node == NULL){
        return NULL;
    }
    else{ 
        if(node->p.x == x && node->p.y == y){
            return node;
        }
        else{
            char *quadrante = getQuadrante(x, y, node->p.x, node->p.y);
            NoStruct* filho;

            filho = getFilho(node, quadrante);

            return getNoQt(filho, x, y);
        }
    }
}

double getNoPx(QuadTreeNo no){
    NoStruct* node = (NoStruct*)no;

    return node->p.x;
}

double getNoPy(QuadTreeNo no){
    NoStruct* node = (NoStruct*)no;

    return node->p.y;
}

QuadTreeInfo getQuadTreeElemento(QuadTreeNo no){
     NoStruct* node = (NoStruct*)no;

     return node->elemento;
}