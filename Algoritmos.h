#ifndef Alg_2017
#define Alg_2017
#include <vector>
#include <cstdlib>
#include <iostream>
#include <map>
#include "GrafoND.h"
#include "GrafoMatriz.h"
#include <utility>
#include <climits>

/*#include "GrafoListaDeListas.h"
#define verticeNulo 0
typedef Grafo Grafo;
typedef Vertice* tipoVertice;*/


#include "GrafoMatriz.h"
#define verticeNulo -1
typedef GrafoMatriz Grafo;
typedef int tipoVertice;


#include "ColaP.h"
#include "ConjuntoDeConjuntos.h"
#include "Diccionario.h"

class Algoritmos {
	private:
		
		class Tripleta{
			public:
				int distancia;
				tipoVertice verticeMasCercano;
				bool usado;
				
				Tripleta();
				Tripleta(int,tipoVertice,bool);
				bool operator<=(Tripleta);
				bool operator==(Tripleta);
				bool operator=(Tripleta);
				friend std::ostream& operator<<(std::ostream& salida, Tripleta t){
					std::cout<<t.distancia<<std::endl;
					return salida;
				}
		};
		class Terna{
			public:
			
				int peso;
				tipoVertice v1;
				tipoVertice v2;
				
				Terna();
				Terna(tipoVertice,tipoVertice,int);//v1,v2,peso
				bool operator==(Terna&);
				void operator= (Terna&);
			
		};
	
	public:
		int encontrarMinimo(int tam, vector<bool>& v, vector<int> d);
		void dijkstra(Grafo&);
		int pesoMinimo(int[],bool[],int);
		void floyd(Grafo&); //yo
		void prim(Grafo&);
		void problemaVendedor(Grafo&); //listo :)
		void asignarArista(tipoVertice); 
		void copiarGrafo(Grafo&,Grafo&);
		bool estaEnLista(Terna*, list<Terna>);
		void recorridoEnProfundidad(Grafo&);
		void recorridoEnProfundidadR(tipoVertice,Grafo&);
		void eliminarVerticeNoAislado(Grafo&,tipoVertice);
		bool iguales(Grafo, Grafo);


};
#endif