#ifndef LISTAENVOLTORIA_H_
#define LISTAENVOLTORIA_H_
#include "listaEnvoltoria.h"

typedef void *listaEnvoltoria;

listaEnvoltoria criaPontoEnvoltoria(double x, double y);

void swapPontoEnvoltoria(pontoEnvoltoria* a, pontoEnvoltoria* b);

double distanciaPontosEnvoltoria(double ax, double bx, double ay, double by);

int orientacaoPontosEnvoltoria(Node *a, Node *b, Node *c);

int comparaPontosEnvoltoria(Node *a, Node *b, Node *c);

#endif