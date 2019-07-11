#ifndef GRAFO_ND
#define GRAFO_ND
#include "GrafoMatriz.h"

class GrafoND{
	private:
		GrafoMatriz * grafo;
		
	public:
		GrafoND(int);
		~GrafoND();
		void vaciar();
		bool vacio();
		int agregarVertice(string);
		void eliminarVertice(int);
		int recuperarVertice(string);
		string etiqueta(int);
		int primerVerticeAdyacente(int);
		int primerVertice();
		int siguienteVertice(int);
		int siguienteVerticeAdyacente(int,int);
		void modificarEtiqueta(int,string);
		void agregarArista(int,int,int);
		void eliminarArista(int,int);
		int peso(int,int);
		void modificarPeso(int,int,int);
		int numVertices();
		int numAristas();
		int numVerticesAdyacentes(int);
		bool adyacentes(int,int);
		
		
};
#endif