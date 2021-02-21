#ifndef LISTAPONTOS_H_
#define LISTAPONTOS_H_

#include "lista.h"

typedef void *listaPonto;

listaPonto criaPonto(double x, double y);

double getXPonto(Node no);

double getYPonto(Node no);

double distanciaPontos(double x1, double y1, double x2, double y2);

int orientacaoPolar(Node a, Node b, Node c);

int comparaPontos(Node a, Node b, Node c);

#endif