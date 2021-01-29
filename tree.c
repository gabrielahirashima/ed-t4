#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

typedef struct no{
    QuadTreeInfo elemento;
    int nivel;
    struct no *sudeste;
    struct no *sudoeste;
    struct no *nordeste;
    struct no *noroeste;
    struct no *ant;
}No;

typedef struct arvore{
    No *raiz;
    int niveis;
}Arvore;

QuadTree criaQuadTree(){
    Arvore *qt = (Arvore*)malloc(sizeof(Arvore));
    qt->raiz = NULL;
    qt->niveis = 0;

    return qt;
}

QuadTree iniciaArvore(QuadTree qt, QuadTreeInfo elemento, No *pai){
    Arvore *quadtree = (Arvore*)qt;

    No* node = (No*)malloc(sizeof(No));

    node->elemento = elemento;

        if((quadtree->raiz == NULL) && (pai == NULL)){
            quadtree->niveis = 1;
            quadtree->raiz = node;
        }

    return quadtree;
}

