#ifndef LISTACIDADESQT_H_
#define LISTACIDADESQT_H_

#include "quadtree.h"
#include "envoltoria.h"
#include "lista.h"
#include "listaPontos.h"

typedef void *listaCidadeQT;

listaCidadeQT iniciaListaQTCidade();

listaCidadeQT getQuadtreeFormas(listaCidadeQT lista);

listaCidadeQT getQuadtreeObjetos(listaCidadeQT qt);

listaCidadeQT getQuadtreePostos(listaCidadeQT qt);

listaCidadeQT getQuadtreeRegioes(listaCidadeQT qt);

listaCidadeQT getQuadtreeCasosCovid(listaCidadeQT qt);

listaCidadeQT getQuadtreeQuadras(listaCidadeQT qt);

#endif
