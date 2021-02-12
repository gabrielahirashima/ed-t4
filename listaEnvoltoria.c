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
}pontoEnvoltoria;

listaEnvoltoria criaPontoEnvoltoria(double x, double y){
    pontoEnvoltoria* p = (pontoEnvoltoria*)malloc(sizeof(pontoEnvoltoria));

    p->x = x;
    p->y = y;

    return p;
}

void swapPontoEnvoltoria(pontoEnvoltoria* a, pontoEnvoltoria* b){
    pontoEnvoltoria temp;

    temp.x = a->x;
    temp.y = a->y;
    a->x = b->x;
    a->y = b->y;
    b->x = temp.x;
    b->y = temp.y;

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