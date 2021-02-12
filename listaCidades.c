#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "tree.h"
#include "listaCidades.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "listaFormas.h"
#include "listaPostos.h"
#include "listaRegioes.h"
#include "listaCasosCovid.h"

typedef struct cidadetemp{
    listaStruct listaFormas;
    listaStruct listaObjUrbanos;
    listaStruct listaQuadras;
    listaStruct listaRadios;
    listaStruct listaPostos;
    listaStruct listaCasosCovid;
    listaStruct listaRegioes;
}CidadeTemp;

typedef struct cidadeenvoltoria{
    listaStruct listaEnvoltoria;
    listaStruct listaPontos;
}CidadeEnvoltoria;

typedef struct cidade{
    QuadTreeQT quadTreeFormas;
    QuadTreeQT quadTreeObjUrbanos;
    QuadTreeQT quadTreeQuadras;
    QuadTreeQT quadTreeRadios;
    QuadTreeQT quadTreePostos;
    QuadTreeQT quadTreeCasosCovid;
    QuadTreeQT quadTreeRegioes;
}Cidade;

listaCidade iniciaListaCidadeTemp(){
    CidadeTemp *cid;
    cid = (CidadeTemp*)malloc(sizeof(CidadeTemp));

    cid->listaFormas = criaQuadTree();
    cid->listaObjUrbanos = criaQuadTree();
    cid->listaQuadras = criaQuadTree();
    cid->listaRadios = criaQuadTree();
    cid->listaPostos = criaQuadTree();
    cid->listaCasosCovid = criaQuadTree();
    cid->listaRegioes = criaQuadTree();

    return cid; 
}

listaCidade iniciaListaCidade(){
    Cidade *cid;
    cid = (Cidade*)malloc(sizeof(Cidade));

    cid->quadTreeFormas = criaQuadTree();
    cid->quadTreeObjUrbanos = criaQuadTree();
    cid->quadTreeQuadras = criaQuadTree();
    cid->quadTreeRadios = criaQuadTree();
    cid->quadTreePostos = criaQuadTree();
    cid->quadTreeCasosCovid = criaQuadTree();
    cid->quadTreeRegioes = criaQuadTree();

    return cid; 
}

listaStruct criaListaEnvoltoria(){
    CidadeEnvoltoria *cid;
    cid = (CidadeEnvoltoria*)malloc(sizeof(CidadeEnvoltoria));

    cid->listaEnvoltoria = criaLista();
    cid->listaPontos = criaLista();
}

listaStruct getQuadtreeFormas(listaCidade lista){
    Cidade* list = (Cidade*)lista;
    return list->quadTreeFormas;
}

listaStruct getQuadtreeObjetos(listaCidade qt){
    Cidade* list = (Cidade*)qt;
    return list->quadTreeObjUrbanos;
}

listaStruct getQuadtreePostos(listaCidade qt){
    Cidade* list = (Cidade*)qt;
    return list->quadTreePostos;
}

listaStruct getQuadtreeRadios(listaCidade qt){
    Cidade* list = (Cidade*)qt;
    return list->quadTreeRadios;
}

listaStruct getQuadtreeCasosCovid(listaCidade qt){
    Cidade* list = (Cidade*)qt;
    return list->quadTreeCasosCovid;
}

listaStruct getQuadtreeQuadras(listaCidade qt){
    Cidade* list = (Cidade*)qt;
    return list->quadTreeQuadras;
}

listaStruct getQuadtreeRegioes(listaCidade qt){
    Cidade* list = (Cidade*)qt;
    return list->quadTreeRegioes;
}

listaStruct getListaTempEnvoltoria(listaCidade lista){
    CidadeEnvoltoria* list = (CidadeEnvoltoria*)lista;
    return list->listaEnvoltoria;
}

listaStruct getListaTempPontos(listaCidade lista){
    CidadeEnvoltoria* list = (CidadeEnvoltoria*)lista;
    return list->listaPontos;
}

listaStruct getListaTempFormas(listaCidade lista){
    CidadeTemp* list = (CidadeTemp*)lista;
    return list->listaFormas;
}

listaStruct getListaTempObjetos(listaCidade qt){
    CidadeTemp* list = (CidadeTemp*)qt;
    return list->listaObjUrbanos;
}

listaStruct getListaTempPostos(listaCidade qt){
    CidadeTemp* list = (CidadeTemp*)qt;
    return list->listaPostos;
}

listaStruct getListaTempRadios(listaCidade qt){
    CidadeTemp* list = (CidadeTemp*)qt;
    return list->listaRadios;
}

listaStruct getListaTempCasosCovid(listaCidade qt){
    CidadeTemp* list = (CidadeTemp*)qt;
    return list->listaCasosCovid;
}

listaStruct getListaTempQuadras(listaCidade qt){
    CidadeTemp* list = (CidadeTemp*)qt;
    return list->listaQuadras;
}

listaStruct getListaTempRegioes(listaCidade qt){
    CidadeTemp* list = (CidadeTemp*)qt;
    return list->listaRegioes;
}

Node comparaIdObjetos(listaCidade lista, char *id){
    listaStruct list = getListaObjetos(lista);
    Node no = getFirst(list);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getIdObjetos(elemento), id) == 0){
                    return elemento;
            }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}

Node comparaCepQuadra(listaCidade lista, char *id){
    listaStruct list = getListaQuadras(lista);
    Node no = getFirst(list);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getCepQuadra(elemento), id) == 0){
                    return elemento;
            }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}

Node comparaIdFormas(listaCidade lista, int id){
    listaStruct list = getListaFormas(lista);
    Node no = getFirst(list);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(getIdFormas(elemento)== id){
                    return elemento;
            }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}

Node comparaEnderecoCasosCovid(listaCidade lista, char *cep, char face, int num){
     listaStruct list = getListaCasosCovid(lista);

    Node no = getFirst(list);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getCepCasosCovid(elemento), cep) == 0){
                    if(getFaceCasosCovid(elemento) == face ){
                        if(getNumCasosCovid(elemento) == num){
                            return elemento;
                        }
                    }
                }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}