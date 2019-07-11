#include "GrafoND.h"
#include "GrafoMatriz.h"
#include "Algoritmos.h"
#include <iostream>
#include "Diccionario.h"
using namespace std;

int main(){
	GrafoMatriz grafo(100);
	GrafoMatriz grafo2(100);
	
	grafo.agregarVertice("a");
	grafo.agregarVertice("b");
	grafo.agregarVertice("c");
	
	grafo.agregarArista(grafo.recuperarVertice("a"),grafo.recuperarVertice("b"),4);
	grafo.agregarArista(grafo.recuperarVertice("b"),grafo.recuperarVertice("c"),3);
	grafo.agregarArista(grafo.recuperarVertice("c"),grafo.recuperarVertice("a"),2);
	
	cout<<"Cree primer grafo"<<endl;
	
	grafo2.agregarVertice("a");
	grafo2.agregarVertice("b");
	grafo2.agregarVertice("c");
	
	grafo2.agregarArista(grafo2.recuperarVertice("a"), grafo2.recuperarVertice("b"),4);
	grafo2.agregarArista(grafo2.recuperarVertice("b"), grafo2.recuperarVertice("c"),3);
	grafo2.agregarArista(grafo2.recuperarVertice("c"), grafo.recuperarVertice("a"),2);
	
	
	
	Algoritmos a;
	//a.dijkstra(grafo);
	//a.prim(grafo);
	cout<< a.iguales(grafo, grafo2)<<endl;
	//a.recorridoEnProfundidad(grafo);
	//a.eliminarVerticeNoAislado(grafo,2);
	//a.recorridoEnProfundidad(grafo);
	

	
	
	
	return 0;
}