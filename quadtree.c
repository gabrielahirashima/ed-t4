#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quadtree.h"

typedef struct ponto{
    double x;
    double y;
}Ponto;

typedef struct node{
    QuadTreeElemento elemento;
    struct ponto p;
    struct node *sudeste; /*se*/
    struct node *sudoeste; /*so*/
    struct node *nordeste; /*ne*/
    struct node *noroeste; /*no*/
    struct node *ant; 
}NoStruct;

typedef struct arvore{
    NoStruct *raiz;
    NoStruct *raizAtual;
    char *key;
}QuadTreeStruct;

QuadTree criaQuadTree(char *key){
    QuadTreeStruct *qt = (QuadTreeStruct*)malloc(sizeof(QuadTreeStruct));
    qt->raiz = NULL;
    qt->key = key;
    return qt;
}

QuadTreeNo criaNoQT(){
    NoStruct* node = (NoStruct*)malloc(sizeof(NoStruct));
    node->sudeste = NULL;
    node->sudoeste = NULL;
    node->nordeste = NULL;
    node->noroeste = NULL;

    return node;
}

QuadTree insereElementoQT(QuadTree qt, QuadTreeElemento elemento, double px, double py){
    QuadTreeStruct *arvoreQt = (QuadTreeStruct*)qt; 
    NoStruct* pai = NULL;
    char *quadrante;

        if(arvoreQt->raiz == NULL){
            NoStruct* node = criaNoQT();
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
                NoStruct* node = criaNoQT();
                   arvoreQt->raizAtual = node;
                    node->p.x = px;
                    node->p.y = py;
                    node->ant = qtAux;
                    setFilho(qtAux, node, quadrante);
            }

        }
    return arvoreQt;
}

/*QuadTree removeElementoQT(){

}*/

void liberaNoQuadTree(QuadTreeNo no){
    NoStruct* node = (NoStruct*)no;

    if(node == NULL){
        return;
    }

    if(node->nordeste != NULL){
        liberaNoQuadTree(node->nordeste);
    }
    else if(node->noroeste != NULL){
        liberaNoQuadTree(node->noroeste);
    }
    else if(node->sudeste != NULL){
        liberaNoQuadTree(node->sudeste);
    }
    else if(node->sudoeste != NULL){
        liberaNoQuadTree(node->sudoeste);
    }

    free(node->elemento);
    free(node);  
}

void liberaQuadTree(QuadTree qt){
    QuadTreeStruct *arvoreQt = (QuadTreeStruct*)qt; 
    liberaNoQuadTree(arvoreQt->raiz);
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
    return NULL;
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
    return NULL;
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

double getXQuadTree(QuadTreeNo no){
    NoStruct* node = (NoStruct*)no;

    return node->p.x;
}

double getYQuadTree(QuadTreeNo no){
    NoStruct* node = (NoStruct*)no;

    return node->p.y;
}

QuadTreeElemento getQuadTreeElemento(QuadTreeNo no){
     NoStruct* node = (NoStruct*)no;

     return node->elemento;
}
