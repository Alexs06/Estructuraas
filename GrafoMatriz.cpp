#include "GrafoMatriz.h"
#include <string>
using namespace std;

GrafoMatriz::GrafoMatriz(int size){
	ultimo = -1;
	cantidadVertices = 0;
	cantidadAristas = 0;
	matriz = new Arista*[size];
	for(int i = 0 ; i < size; ++i)
		matriz[i] = new Arista[size];
	vectorEtiquetas = new string[size];
	vectorAdy = new int[size];
	M = size;
	vrt = 0;
}

GrafoMatriz::GrafoMatriz(){
	ultimo = -1;
	cantidadVertices = 0;
	cantidadAristas = 0;
	matriz = new Arista*[100];
	for(int i = 0 ; i < 100; ++i)
		matriz[i] = new Arista[100];
	vectorEtiquetas = new string[100];
	vectorAdy = new int[100];
	M = 100;
	vrt = 0;
}

GrafoMatriz::~GrafoMatriz(){
	delete vectorEtiquetas;
	for(int i = 0 ; i < M ; ++i)
		delete [] matriz[i];
	delete[] matriz;
}

void GrafoMatriz::vaciar(){
	ultimo = -1;
	cantidadVertices = 0;
	cantidadAristas = 0;
}

bool GrafoMatriz::vacio(){
	if(ultimo == -1){
		return true;
	}else{
		return false;
	}
}

int GrafoMatriz::agregarVertice(string etiqueta){
	ultimo++;
	cantidadVertices++;
	vectorEtiquetas[ultimo] = etiqueta;
	for(int i = 0; i <= ultimo ; ++i){
		Arista arista;
		arista.peso = 0;
		arista.existe = false;
		matriz[ultimo][i] = arista;
	}
	
	for(int j = 0; j <= ultimo ; ++j){
		Arista arista1;
		arista1.peso = 0;
		arista1.existe = false;
		matriz[j][ultimo] = arista1;
	}
	
	return ultimo;

}


int GrafoMatriz::recuperarVertice(string etiqueta){
	for(int i = 0; i <= ultimo; ++i){
		if(vectorEtiquetas[i] == etiqueta){
			return i;
		}
	}
	return -1;
}

void GrafoMatriz::eliminarVertice(int vertice){
	if(vertice == ultimo){
		ultimo--;
	}else{
		for(int i = vertice; i < ultimo ; ++i){
			vectorEtiquetas[i+1] = vectorEtiquetas[i]; 
		}
	
		for(int j = vertice; j < ultimo ; ++j){
			for(int x = vertice ; x < ultimo ; ++x){
				matriz[j][x] = matriz[j][x+1];
			}
		}
		
		for(int o = vertice ; o <= ultimo ; ++o){
			for(int p = vertice ; p < ultimo ; ++p){
				matriz[p][o] = matriz[p+1][o]; 
			}
		}
	ultimo--;	
	}
	
}

string GrafoMatriz::etiqueta(int vertice){
	return vectorEtiquetas[vertice];
}

int GrafoMatriz::primerVerticeAdyacente(int vertice){
	vectorAdy[vertice] = 0;
	for(int i = 0 ; i <= ultimo; ++i){
		if(matriz[vertice][i].existe){
			return i;
		}
	}
	return -1;
}

int GrafoMatriz::siguienteVerticeAdyacente(int vertice, int noUso){
	vectorAdy[vertice] += 1;
	int encontrado = 0;
	for(int i = 0 ; i <= ultimo ; ++i){
		if(matriz[vertice][i].existe){
			encontrado++;
		}
		if(encontrado == vectorAdy[vertice]){
			++i;
			if(matriz[vertice][i].existe){
				return i;
			}
		}
	}
	return -1;
}

void GrafoMatriz::agregarArista(int fila, int columna, int peso){
	Arista arista;
	arista.peso = peso;
	arista.existe = true;
	matriz[fila][columna] = arista;
	cantidadAristas++;
}

void GrafoMatriz::eliminarArista(int fila, int columna){
	matriz[fila][columna].existe = false;
	matriz[fila][columna].peso = 0;
}

int GrafoMatriz::peso(int fila, int columna){
	return matriz[fila][columna].peso;
}

void GrafoMatriz::modificarPeso(int fila, int columna, int peso){
	matriz[fila][columna].peso = peso;
	
}

void GrafoMatriz::modificarEtiqueta(int vertice, string etiqueta){
	vectorEtiquetas[vertice] = etiqueta;
	
}


int GrafoMatriz::numVertices(){
	return cantidadVertices;
}

int GrafoMatriz::numAristas(){
	return cantidadAristas;
}

int GrafoMatriz::numVerticesAdyacentes(int vertice){
	int resultado = 0;
	for(int i = 0; i <= ultimo ; ++i){
		if(matriz[vertice][i].existe){
			resultado++;
		}
	}
	return resultado;
}

bool GrafoMatriz::adyacentes(int fila, int columna){
	if(matriz[fila][columna].existe){
		return true;
	}else{
		return false;
	}	
}

int GrafoMatriz::primerVertice(){
	vrt = 0;
	return 0;
}

int GrafoMatriz::siguienteVertice(int noUso){
	vrt++;
	if(vrt > ultimo){
		return -1;
	}else{
	return vrt;
	}
}






