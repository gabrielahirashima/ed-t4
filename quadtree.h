#ifndef QUADTREE_H_
#define QUADTREE_H_

#include "lista.h"
#include "listaCidades.h"

typedef void *QuadTree;
typedef void *QuadTreeNo;
typedef void *QuadTreeElemento;

QuadTree criaQuadTree(char *key);

QuadTreeNo criaNoQT();

QuadTree insereElementoQT(QuadTree qt, QuadTreeElemento elemento, double px, double py);

/*QuadTree removeElementoQT(){

}*/

void liberaNoQuadTree(QuadTreeNo no);

void liberaQuadTree(QuadTree qt);

char *getQuadrante(double pAtualX, double pAtualY, double pRaizX, double pRaizY);

int comparaPonto(double pAtualX, double pAtualY, double pRaizX, double pRaizY);

QuadTreeNo getFilho(QuadTreeNo no, char* quadrante);

void setFilho(QuadTreeNo pai, QuadTreeNo filho, char *quadrante);

QuadTreeNo getNoQt(QuadTreeNo raiz, double x, double y);

double getXQuadTree(QuadTreeNo no);

double getYQuadTree(QuadTreeNo no);

QuadTreeElemento getQuadTreeElemento(QuadTreeNo no);

#endif
