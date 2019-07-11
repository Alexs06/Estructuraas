/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *

 */

#ifndef GRAFOLISTADELISTAS_H
#define GRAFOLISTADELISTAS_H
#include<List>
#include<Vector>
#include<iostream>
using namespace std;   
struct Vertice{
    Vertice(string eti){
    etiqueta = eti;
    siguiente = 0;
    };
    Vertice(Vertice* sig, string eti){
        siguiente = sig;
        etiqueta = eti;
    };
     ~Vertice(){};
    string etiqueta;
    Vertice* siguiente;
};
struct Par{
    Par(){
        pesoArista = 0;
        vertice = 0;
    };
    Par(Vertice* v){
       vertice = v; 
       pesoArista = 0;
    };
    Par(Vertice* v,int p){
        vertice = v;
        pesoArista = p;
    };
    Par(string eti, int p){
        Vertice* v;
        v = new Vertice(eti);
        vertice = v;
        pesoArista = p;
    };
    Vertice* vertice;
    int pesoArista;
};
class Grafo{
    public:
		Grafo();
		virtual ~Grafo();
		void vaciar();
		bool vacio();
		Vertice* agregarVertice(string eti);
		void eliminarVertice(Vertice* v);
		void modificarEtiqueta(Vertice* v, string nuevaEtiqueta);
		string etiqueta(Vertice* v);
		void agregarArista(Vertice* vertice1, Vertice* vertice2, int peso);
		void eliminarArista(Vertice* vertice1, Vertice* vertice2);
		void modificarPeso(Vertice* vertice1, Vertice* vertice2, int nuevoPeso);
		int peso(Vertice* vertice1, Vertice* vertice2);
		bool adyacentes(Vertice* vertice1, Vertice* vertice2);
		Vertice* primerVertice();
		Vertice* siguienteVertice(Vertice* v);
		Vertice* primerVerticeAdyacente(Vertice* v);
		Vertice* siguienteVerticeAdyacente(Vertice* v, Vertice* ady);
		int numVertices();
		int numVerticesAdyacentes(Vertice* v);
		list<Par> buscarListaPares(Vertice* v); //método auxiliar para encontrar la lista de pares asociada a un vertice
		list<Par> buscarListaPares(string eti);
		Vertice* recuperarVertice(string eti);
		
    private:
		list<list<Par> > listaVertices;

};
#endif /* GRAFOLISTADELISTAS_H */

