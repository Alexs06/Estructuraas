/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <List>
#include <Vector>
#include <iostream>
//#include "ConjuntoDeConjuntos.h"
using namespace std;
ConjuntoDeConjuntos::ConjuntoDeConjuntos(){
    
}
bool ConjuntoDeConjuntos::vacio(){
    if(!listaConjuntos.size() == 0){
        return false;
    }
    return true;
}
void ConjuntoDeConjuntos::vaciar(){
    listaConjuntos.clear();
}
ConjuntoDeConjuntos::~ConjuntoDeConjuntos(){
    
}
string ConjuntoDeConjuntos::conjuntoAlQuePertenece(string elem){
    list<Conjunto>::iterator it;
    it = listaConjuntos.begin();
    Conjunto c;
    list<string>::iterator it2;
    string elementoActual;
    while(it != listaConjuntos.end()){
        c = *it;
        it2 = c.listaElementos.begin();
        while(it2 != c.listaElementos.end()){
            elementoActual = *it2;
            if(elementoActual == elem){
                return it->id;
            }
            it2++;
        }
        it++;
    }
    return "no encontrado";
}
void ConjuntoDeConjuntos::agregarConjunto(Conjunto c){
    listaConjuntos.push_back(c);
}
void ConjuntoDeConjuntos::agregarConjunto(string elemento){
    Conjunto c = Conjunto(elemento);
    c.agregarElemento(elemento);
    listaConjuntos.push_back(c);
}
void ConjuntoDeConjuntos::unirConjuntos(string id1, string id2){
    Conjunto conjuntoNuevo; 
    list<Conjunto>:: iterator it;
    list<Conjunto>:: iterator it2;
    it = listaConjuntos.begin();
    while(it->id != id1){
        it++;
    }
    it2 = listaConjuntos.begin();
    while(it2->id != id2){
        it2++;
    }
    it->listaElementos.merge(it2->listaElementos);
    listaConjuntos.erase(it2);
    it->id = id1 + " U " + id2;
}
ConjuntoDeConjuntos::numConjuntos(){
    return listaConjuntos.size();
}
/* //Código de ejemplo
 * Conjunto c1 = Conjunto("A");
    Conjunto c2 = Conjunto("B");
    c1.agregarElemento("1");
    c2.agregarElemento("2");
    ConjuntoDeConjuntos CC;
    CC.agregarConjunto(c1);
    CC.agregarConjunto(c2);
    std::cout<<CC.vacio() <<std::endl;
      std::cout<<CC.conjuntoAlQuePertenece("1")<<std::endl;
    std::cout<<CC.conjuntoAlQuePertenece("2")<<std::endl;
    CC.unirConjuntos("A", "B");
    std::cout<<CC.conjuntoAlQuePertenece("1")<<std::endl;
    std::cout<<CC.numConjuntos()<<std::endl;
 */