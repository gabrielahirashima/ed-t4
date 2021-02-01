#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

typedef struct no{
    QuadTreeInfo elemento;
    int nivel;
    struct no *sudeste; /*se*/
    struct no *sudoeste; /*so*/
    struct no *nordeste; /*ne*/
    struct no *noroeste; /*no*/
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

QuadTree insereElemento(QuadTree qt, QuadTreeInfo elemento, No *pai, char *quadrante){
    Arvore *quadtree = (Arvore*)qt;

    No* node = (No*)malloc(sizeof(No));
    No* inicio = quadtree->raiz;

    int nivel;

    node->elemento = elemento;

        if((quadtree->raiz == NULL) && (node->ant == NULL)){
            quadtree->niveis = 1;
            node->sudoeste = NULL;
            node->sudeste = NULL;
            node->nordeste = NULL;
            node->noroeste = NULL;
            quadtree->raiz = node;
            nivel = 2;
                if(quadtree->niveis < nivel){
                    quadtree->niveis = nivel;
                }
        }
        else{
            if(strcmp(quadrante, "se") == 0){
                if(inicio->sudeste == NULL){
                    node->ant = pai;
                    node->sudeste = node;
                }
                else{

                }
            }
            else if(strcmp(quadrante, "so") == 0){
                node->ant = pai;
                node->sudoeste = node;
            }
            else if(strcmp(quadrante, "ne") == 0){
                node->ant = pai;
                node->nordeste = node;
            }
            else if(strcmp(quadrante, "no") == 0){
                node->ant = pai;
                node->noroeste = node;
            }
        }

    return quadtree;
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

