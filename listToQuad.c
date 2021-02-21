#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listToQuad.h"

void transformaListaFormas(listaCidade listaF, QuadTree qtF){
    listaPonto listapontos = criaLista();
    double x, y;
    tipo elemento;
    for(Node i = getFirst(listaF); i != NULL; i = getNext(i)){
        x = getXFormas(getElemento(i));
        y = getYFormas(getElemento(i));
        elemento = criaPonto(x, y);
        insertElemento(listapontos, elemento);
    }

    listaPonto listaenvoltoria;
    listaStruct stackenvoltoria = criaLista();

    while(tamanhoLista(listapontos) > 3){
        listaenvoltoria = envoltoriaConvexa(listapontos);
        if(listaenvoltoria != NULL){
            for(Node i = getFirst(listaenvoltoria); i != NULL; i = getNext(i)){
                for(Node j = getFirst(listaF); j != NULL; j = getNext(j)){
                    if( (getXPonto(getElemento(i)) == getXFormas(getElemento(j))) && (getYPonto(getElemento(i)) == getYFormas(getElemento(j))) ){
                        tipo elemento1 = getElemento(j);
                        insertElemento(stackenvoltoria, elemento);
                        break;
                    }
                }
            }
            printf("\n--\n");
            imprimeLista(stackenvoltoria, 'p');
            printf("\n--\n");

             for(Node i = getFirst(listaenvoltoria); i != NULL; i = getNext(i)){
                for(Node j = getFirst(listapontos); j != NULL; j = getNext(j)){
                    if( (getXPonto(getElemento(i)) == getXPonto(getElemento(j))) && (getYPonto(getElemento(i)) == getYPonto(getElemento(j))) ){
                        tipo elemento1 = getElemento(j);
                        removeNode(listapontos, elemento1);
                    }
                }
            }
            liberaListaNaoTotal(listaenvoltoria);
        }
    }
}