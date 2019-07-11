/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConjuntoDeConjuntos.h
 * Author: Pabos95
 *
 * Created on 17 de noviembre de 2017, 12:48 PM
 */


#ifndef CONJUNTODECONJUNTOS_H
#define CONJUNTODECONJUNTOS_H
#include <list>
//#include "GrafoListaDeListas.h"
using namespace std;
struct Conjunto{
    Conjunto(){
        
    };
    Conjunto(string nombre){
        id = nombre;
    };
    Conjunto(string nombre, list<string> l){
        listaElementos = l;
        id = nombre;
    };
    void agregarElemento(string elem){
        listaElementos.push_back(elem);
    };
    list<string> listaElementos;
    string id;
};
class ConjuntoDeConjuntos{
    public:
   
    ConjuntoDeConjuntos();
    ~ConjuntoDeConjuntos();
    void vaciar();
    bool vacio();
    string conjuntoAlQuePertenece(string elem);
    void agregarConjunto(Conjunto c);
    void agregarConjunto(string elem);
    void unirConjuntos(string id1, string id2);
     list<Conjunto > listaConjuntos;
     int numConjuntos();
};

#endif /* CONJUNTODECONJUNTOS_H */

