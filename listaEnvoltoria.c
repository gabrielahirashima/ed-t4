#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaEnvoltoria.h"
#include "tree.h"
#include "listaCidades.h"
#include "lista.h"

typedef struct pEnvoltoria{
    double x;
    double y;
    int nivelEnvoltoria;
}pontoEnvoltoria;

listaEnvoltoria criaPontoEnvoltoria(double x, double y){
    pontoEnvoltoria* p = (pontoEnvoltoria*)malloc(sizeof(pontoEnvoltoria));

    p->x = x;
    p->y = y;

    return p;
}

double distanciaPontosEnvoltoria(double ax, double bx, double ay, double by){
    double x = ax - bx;
    double y = ay - by;
    x = x * x;
    y = y * y;

    return x + y;
}

int orientacaoPontosEnvoltoria(Node *a, Node *b, Node *c){
     Node *p0 = (Node*)a;
     Node *p1 = (Node*)b;
     Node *p2 = (Node*)c;

    if(a == NULL || b == NULL || c == NULL){
        return 2;
    }
    double res;
    res = (getNoPy(p1) - getNoPy(p0)) * (getNoPx(p2) - getNoPx(p1)) - (getNoPx(p1) - getNoPx(p0)) * (getNoPy(p2) - getNoPy(p1));

    if(res == 0){ /*colinear*/
        return 0;
    }
    else if( res > 0){
        return 1; /*horario*/
    }

    return 2; /*antihorario*/

}

int comparaPontosEnvoltoria(Node *a, Node *b, Node *c){
    Node *p0 = (Node*)a;
    Node *p1 = (Node*)b;
    Node *p2 = (Node*)c;

    int o = orientacaoPontosEnvoltoria(a, b, c);

    int dist;

    if(o == 0){
        if(distanciaPontosEnvoltoria(getNoPx(p0), getNoPx(p2), getNoPy(p0), getNoPy(p2)) >= distanciaPontosEnvoltoria(getNoPx(p0), getNoPx(p1), getNoPy(p0), getNoPy(p1))){
            dist = 1;
        }
        if(dist == 1){
            return -1;
        }
        else{
            return 1;
        }
    }
    else if(o = 2){
        return -1;
    }
    else{
        return 1;
    }

}

double getXEnvoltoria(listaEnvoltoria lista){
    pontoEnvoltoria *p = (pontoEnvoltoria*)lista;
    return p->x;
}

double getYEnvoltoria(listaEnvoltoria lista){
    pontoEnvoltoria *p = (pontoEnvoltoria*)lista;
    return p->y;
}

int getNivelEnvoltoria(listaEnvoltoria lista){
    pontoEnvoltoria *p = (pontoEnvoltoria*)lista;
    return p->nivelEnvoltoria;
}

void calculaEnvoltoria(listaEnvoltoria listaE){
    listaStruct listaPontos = getListaTempPontos(listaE);
    listaStruct listaEnvoltoria = getListaTempEnvoltoria(listaE);
    Node noListaP = getFirst(listaPontos);
    Node noListaE = getFirst(listaEnvoltoria);
    Node a, b, c, maiorY = getFirst(listaPontos);
    tipo elemento1, elemento2;
    int nPontos = 0, nivel = 0; 

    while(noListaP != NULL){
        nPontos = nPontos + 1;
        noListaP = getNext(listaPontos);
    }

    if(nPontos < 3 ){
        return NULL;
    }

    noListaP = getFirst(listaPontos);
    elemento1 = getElemento(noListaP);

    while(noListaP != NULL){
        if(getYEnvoltoria(noListaP) == getYEnvoltoria(maiorY)){
            if(getXEnvoltoria(noListaP) > getXEnvoltoria(maiorY)){
                maiorY = noListaP;
            }
        }
        else if(getYEnvoltoria(noListaP) > getYEnvoltoria(maiorY)){
            maiorY = noListaP;
        }
        noListaP = getNext(noListaP);
    }

    swap(getFirst(listaPontos), maiorY);


}