#include "GrafoND.h"
#include "GrafoMatriz.h"
#include <cstring>
using namespace std;

GrafoND::GrafoND(int size){
	grafo = new GrafoMatriz(size);
}		

GrafoND::~GrafoND(){
	delete grafo;
}

void GrafoND::vaciar(){
	grafo->vaciar();
}

bool GrafoND::vacio(){
	return grafo->vacio();
}

int GrafoND::agregarVertice(string e){
	grafo->agregarVertice(e);
	return 1;
}

void GrafoND::eliminarVertice(int v){
	grafo->eliminarVertice(v);
}

int GrafoND::recuperarVertice(string e){
	return grafo->recuperarVertice(e);
}

string GrafoND::etiqueta(int v){
	return grafo->etiqueta(v);
}

int GrafoND::primerVerticeAdyacente(int v){
	return grafo->primerVerticeAdyacente(v);
}

int GrafoND::primerVertice(){
	return grafo->primerVertice();
}

int GrafoND::siguienteVertice(int v){
	return grafo->siguienteVertice(v);
}

int GrafoND::siguienteVerticeAdyacente(int v, int n){
	grafo->siguienteVerticeAdyacente(v,n);
	return 2;
}

void GrafoND::modificarEtiqueta(int v, string e){
	grafo->modificarEtiqueta(v,e);
}

void GrafoND::agregarArista(int v, int v2, int p){
	grafo->agregarArista(v,v2,p);
	grafo->agregarArista(v2,v,p);
}

void GrafoND::eliminarArista(int v1,int v2){
	grafo->eliminarArista(v1,v2);
	grafo->eliminarArista(v2,v1);
}

int GrafoND::peso(int v1, int v2){
	return grafo->peso(v1,v2);
}

void GrafoND::modificarPeso(int v1, int v2, int p){
	grafo->modificarPeso(v1,v2,p);
	grafo->modificarPeso(v2,v1,p);
}

int GrafoND::numVertices(){
	return grafo->numVertices();
}

int GrafoND::numAristas(){
	return grafo->numAristas();
}

int GrafoND::numVerticesAdyacentes(int v){
	return grafo->numVerticesAdyacentes(v);
}

bool GrafoND::adyacentes(int v1, int v2){
	return grafo->adyacentes(v1,v2);
}





