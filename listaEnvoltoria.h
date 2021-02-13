#ifndef LISTAENVOLTORIA_H_
#define LISTAENVOLTORIA_H_
#include "listaEnvoltoria.h"

typedef void *listaEnvoltoria;


listaEnvoltoria criaPontoEnvoltoria(double x, double y);

double distanciaPontosEnvoltoria(double ax, double bx, double ay, double by);

int orientacaoPontosEnvoltoria(Node *a, Node *b, Node *c);

int comparaPontosEnvoltoria(Node *a, Node *b, Node *c);

double getXEnvoltoria(listaEnvoltoria lista);

double getYEnvoltoria(listaEnvoltoria lista);

int getNivelEnvoltoria(listaEnvoltoria lista);

#endif