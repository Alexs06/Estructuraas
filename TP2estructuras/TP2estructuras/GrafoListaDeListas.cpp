/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GrafoListaDeListas.h"
Grafo::Grafo(){
    
}
bool Grafo::vacio(){
    if(listaVertices.size() == 0){
        return true;
    }
    return false;
}
void Grafo::vaciar(){
    while(!listaVertices.empty()){
        Vertice* v = primerVertice();
        eliminarVertice(v);
    }
}
int Grafo::numVertices(){
    return listaVertices.size();
}
Vertice* Grafo::primerVertice(){
    return listaVertices.front().front().vertice;
}
Vertice* Grafo::primerVerticeAdyacente(Vertice* v){
    list<list<Par> >::iterator it;
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != v){
      it++;  
    }
    list<Par>::iterator it2;
    it2 = it->begin();
	++it2;
    if(it2 != it->end()){
		return it2->vertice;
    }
    return 0;
}
Vertice* Grafo::siguienteVerticeAdyacente(Vertice* v, Vertice* ady){
    list<list<Par> >::iterator it;
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != v){
      it++;  
    }
    list<Par>::iterator it2;
    it2 = it->begin();
    if(it->size() != 1){
		while(it2 != it->end() && it2->vertice != ady){
		   it2++;  
		}
		it2++;
		if(it2 == it->end()){
			return 0;
		}
		else{
			return it2->vertice;
		}
	}
    return 0;
}
int Grafo::numVerticesAdyacentes(Vertice* v){
     list<list<Par> >::iterator it;
     it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != v){
      it++;  
    }
     int total = it->size();
     return total - 1;
}
void Grafo::eliminarVertice(Vertice* v){
     list<list<Par> >::iterator it;
     it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != v){
      it++;  
    }
     delete it->front().vertice;
    listaVertices.erase(it); 
}
void Grafo::eliminarArista(Vertice* vertice1, Vertice* vertice2){
    list<list<Par> >::iterator it;
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != vertice1){
      it++;  
    }
    list<Par>::iterator it2;
    it2 = it->begin();
    while(it2 != it->end() && it2->vertice != vertice2){
        it2++;
    }
    it->erase(it2);
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != vertice2){
      it++;  
    }
    it2 = it->begin();
    while(it2 !=it->end() && it2->vertice != vertice1){
        it2++;
    }
    it->erase(it2);
}
Vertice* Grafo::agregarVertice(string eti){
    Vertice* v;
    if(listaVertices.empty()){
     v = new Vertice(eti);
    Par p = Par(v);
    list<Par> l;
    l.push_back(p);
    listaVertices.push_back(l);
    return v;
    }
    else{
     v = new Vertice(eti);
     Par ultimo = listaVertices.back().front();
     ultimo.vertice->siguiente = v;
    Par p = Par(v);
    list<Par> l;
    l.push_back(p);
    listaVertices.push_back(l);
    return v;
    }
}

string Grafo::etiqueta(Vertice* v){
    list<list<Par> >::iterator it;
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != v){
      it++;  
    }
    return it->front().vertice->etiqueta;
}
void Grafo::modificarEtiqueta(Vertice* v, string nuevaEtiqueta){
    list<list<Par> >::iterator it;
    it = listaVertices.begin();
   while(it != listaVertices.end() && it->front().vertice != v){
        it++;
    }
    it->front().vertice->etiqueta = nuevaEtiqueta;
}
void Grafo::agregarArista(Vertice* vertice1, Vertice* vertice2, int peso){
    list<list<Par> >::iterator it;
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != vertice1){
        it++;
    }
    Par p1 = Par(vertice2, peso);
    it->push_back(p1);
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != vertice2){
        it++;
    }
    Par p2 = Par(vertice1, peso);
    it->push_back(p2);
    modificarPeso(vertice1, vertice2, peso);
}
void Grafo::modificarPeso(Vertice* vertice1, Vertice* vertice2, int nuevoPeso){
    list<list<Par> >::iterator it;
    list<Par>::iterator it2;
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != vertice1){
        it++;
    }
    it2 = it->begin();
    while(it2 != it->end() &&  it2->vertice != vertice2){
        it2++;
    }
    it2->pesoArista = nuevoPeso;
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != vertice2){
        it++;
    }
    it2 = it->begin();
    while(it2 != it->end() &&  it2->vertice != vertice1){
        it2++;
    }
    it2->pesoArista = nuevoPeso;
}
int Grafo::peso(Vertice* vertice1, Vertice* vertice2){
     list<list<Par> >::iterator it;
    list<Par>::iterator it2;
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != vertice1){
        it++;
    }
    it2 = it->begin();
    while(it2->vertice->etiqueta != vertice2->etiqueta && it2 != it->end()){
        it2++;
    }
    return it2->pesoArista;
}
bool Grafo::adyacentes(Vertice* vertice1, Vertice* vertice2){
    list<list<Par> >::iterator it;
    list<Par>::iterator it2;
    it = listaVertices.begin();
    while(it != listaVertices.end() && it->front().vertice != vertice1){
        it++;
    }
    it2 = it->begin();
    while(it2 != it->end() &&  it2->vertice != vertice2){
        it2++;
    }
    if(it2->vertice == vertice2){
            return true;
        }
    else{
    return false;
    }
}
Vertice* Grafo::siguienteVertice(Vertice* v){
   list<list<Par> >::iterator it;
    it = listaVertices.begin();
    while(it->front().vertice != v && it != listaVertices.end()){
      it++;  
    }
    if(it->front().vertice == listaVertices.back().front().vertice){
        return 0;
    }
    return it->front().vertice->siguiente;
}
Vertice* Grafo::recuperarVertice(string eti){
    list<list<Par> >::iterator it;
    it = listaVertices.begin();
    while(it->front().vertice->etiqueta != eti && it != listaVertices.end()){
        it++;
    }
    return it->front().vertice;
}
Grafo::~Grafo(){
    vaciar();
}