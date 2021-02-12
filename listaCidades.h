#ifndef LISTACIDADES_H_
#define LISTACIDADES_H_

#include "lista.h"

/*define listaCidade como ponteiro void*/
typedef void *listaCidade;

/*inicia a lista de cidade temporaria*/
listaCidade iniciaListaCidadeTemp();

/*inicia a lista de cidade quadtree*/
listaCidade iniciaListaCidade();

/*inicia a lista de envoltoria*/
listaStruct criaListaEnvoltoria();

/*Retorna a quadtree de Formas*/
listaStruct getQuadtreeFormas(listaCidade lista);

/*Retorna a quadtree de Objetos*/
listaStruct getQuadtreeObjetos(listaCidade qt);

/*Retorna a quadtree de Postos de Saude*/
listaStruct getQuadtreePostos(listaCidade qt);

/*Retorna a quadtree de Radios*/
listaStruct getQuadtreeRadios(listaCidade qt);

/*Retorna a quadTree de Casos de Covid*/
listaStruct getQuadtreeCasosCovid(listaCidade qt);

/*Retorna a quadtree de Quadra*/
listaStruct getQuadtreeQuadras(listaCidade qt);

/*Retorna a quadtree de Regioes*/
listaStruct getQuadtreeRegioes(listaCidade qt);

/*Retorna a lista temporaria de envoltoria*/
listaStruct getListaTempEnvoltoria(listaCidade lista);

/*Retorna a lista temporaria de pontos*/
listaStruct getListaTempPontos(listaCidade lista);

/*Retorna a lista de Formas*/
listaStruct getListaTempFormas(listaCidade lista);

/*Retorna a lista de Objetos*/
listaStruct getListaTempObjetos(listaCidade qt);

/*Retorna a lista temporaria de Postos de Saude*/
listaStruct getListaTempPostos(listaCidade qt);

/*Retorna a lista de Radios*/
listaStruct getListaTempRadios(listaCidade qt);

/*Retorna a quadtree de Casos de Covid*/
listaStruct getListaTempCasosCovid(listaCidade qt);

/*Retorna a lista temporaria de Quadra*/
listaStruct getListaTempQuadras(listaCidade qt);

/*Retorna a lista temporaria de Regioes*/
listaStruct getListaTempRegioes(listaCidade qt);

/*Compara a id recebida com as ids dos objetos na lista, se encontra um correspondente, retorna este*/
Node comparaIdObjetos(listaCidade lista, char *id);

/*Compara o cep recebido com os ceps das quadras na lista, se encontra um correspondente, retorna este*/
Node comparaCepQuadra(listaCidade lista, char *id);

/*Compara a id recebida com as ids das formas na lista, se encontra um correspondente, retorna este*/
Node comparaIdFormas(listaCidade lista, int id);

/*Compara o endereço recebido com as ids dos objetos na lista, se encontra um correspondente, retorna este*/
Node comparaEnderecoCasosCovid(listaCidade lista, char *cep, char face, int num);

#endif