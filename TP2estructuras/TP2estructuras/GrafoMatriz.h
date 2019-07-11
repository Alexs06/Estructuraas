#ifndef GRAFO_MATRIZ
#define GRAFO_MATRIZ
#include <cstring>
#include <iostream>
using namespace std;
class GrafoMatriz{
	class Arista;
	
	private:
		string  * vectorEtiquetas;
		Arista ** matriz;
		int * vectorAdy;
		int ultimo;
		int cantidadVertices;
		int cantidadAristas;
		int M;
		int vrt;
		
		class Arista{
			public:
				bool existe;
				int peso; 
		};
		
		public:
			GrafoMatriz(int);
			GrafoMatriz();
			~GrafoMatriz();
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