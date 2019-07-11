#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>
#include <String>

/*
#include "GrafoListaDeListas.h"
#define verticeNulo 0
typedef Vertice* tipoVertice;*/

/*
#include "GrafoMatriz.h"
#define verticeNulo -1
typedef int tipoVertice;
*/


#include "ConjuntoDeConjuntos.h"
#include "ColaP.h"
#include "Diccionario.h"
#include "Algoritmos.h"




using namespace std;

void desplegarMenu(){
	cout << "Seleccione alguna instruccion: \n" //Operadores basicos
			"\nOPERADORES BASICOS\n"
			"1-Vaciar\n"
			"2-Vacio?\n"
			"3-Agregar vertice\n"
			"4-Eliminar vertice aislado\n"
			"5-Modificar etiqueta\n"
			"6-Agregar arista\n"
			"7-Existe arista?\n"
			"8-Eliminar arista\n"
			"9-Peso de una arista\n"
			"10-Modificar peso\n"
			"11-Numero de Vertices\n"
			"12-Lista de vertices adyacentes\n"
			"13-Lista de todos los vertices del grafo\n"
			
			"\nALGORITMOS\n" //Algoritmos 
			"14_Dijkstra\n"
			"15_Floyd\n"
			"16_Prim\n"
			"17_Kruskal\n"
			"18_Copiar un grafo\n"
			"19_Grafos iguales?\n"
			"20_Problema del vendedor\n"
			"\n0-Salir del programa\n\n";	
}
	

int main() {
    
    Grafo g = Grafo();
	Grafo gCopia = Grafo();
	Grafo gPrueba = Grafo();
    Algoritmos algoritmo;
	
	/**Se llena el grafo prueba*/
	gPrueba.agregarVertice("v1");
	gPrueba.agregarVertice("v2");
	gPrueba.agregarVertice("v3");
	gPrueba.agregarVertice("v4");
	gPrueba.agregarArista(gPrueba.recuperarVertice("v1"),gPrueba.recuperarVertice("v2"),3);
	gPrueba.agregarArista(gPrueba.recuperarVertice("v1"),gPrueba.recuperarVertice("v3"),4);
	gPrueba.agregarArista(gPrueba.recuperarVertice("v1"),gPrueba.recuperarVertice("v4"),2);
	gPrueba.agregarArista(gPrueba.recuperarVertice("v2"),gPrueba.recuperarVertice("v3"),5);
	gPrueba.agregarArista(gPrueba.recuperarVertice("v2"),gPrueba.recuperarVertice("v4"),1);
	gPrueba.agregarArista(gPrueba.recuperarVertice("v3"),gPrueba.recuperarVertice("v4"),3);
	/**Grafo de prueba llenado*/
	
	cout << "\nBienvenido al programa de grafos\n"
			"Las etiquetas de los vertices del grafo son strings\n\n";
	int menu = -1;
	while(menu != 0){
		desplegarMenu();
		cin >> menu;
		switch(menu){
			case 1:{ //Vaciar el grafo
				g.vaciar();
				cout << "------------Grafo Vaciado\n\n";
			}
			break;
			
			case 2:{//Preguntar si está vacío
				bool answer = g.vacio();
				if(answer){
					cout << "------------El grafo esta vacio\n\n";
				}
				else{
					cout << "------------El grafo no esta vacio\n\n";
				}
			}
			break;
			
			case 3:{ //Agregar un vertice
				string hilera;
				cout << "Etiqueta del vertice?\n";
				cin >> hilera;
				g.agregarVertice(hilera);
				cout << "------------Vertice agregado\n\n";
			}
			break;
			
			case 4:{ //Eliminar un vertice
				string namae;
				cout << "Etiqueta del vertice?\n";
				cin >> namae;
				tipoVertice v = g.recuperarVertice(namae);
				g.eliminarVertice(v);
				cout << "------------Vertice eliminado\n\n";
			}
			break;
			case 5:{ //Modificar etiqueta de un vertice
				string anterior;
				string nuevo;
				cout << "Etiqueta del vertice?\n";
				cin >> anterior;
				tipoVertice v = g.recuperarVertice(anterior);
				cout << "Nueva etiqueta del vertice?\n";
				cin >> nuevo;
				g.modificarEtiqueta(v,nuevo);
				cout << "------------Etiqueta modificada\n\n";
			}
			break;
			
			case 6:{//Agregar arista entre 2 vertices
				string s1,s2;
				int peso;
				cout << "Etiqueta del vertice 1?\n";
				cin >> s1;
				cout << "Etiqueta del vertice 2?\n";
				cin >> s2;
				tipoVertice v1 = g.recuperarVertice(s1);
				tipoVertice v2 = g.recuperarVertice(s2);
				cout << "Peso de la arista?\n";
				cin >> peso;
				g.agregarArista(v1,v2,peso);
				cout << "------------Arista agregada\n\n";
			}
			break;
			
			case 7:{//Pregunta si existe algun arista entre vertices
				string s1,s2;
				cout << "Etiqueta del vertice 1?\n";
				cin >> s1;
				cout << "Etiqueta del vertice 2?\n";
				cin >> s2;
				tipoVertice v1 = g.recuperarVertice(s1);
				tipoVertice v2 = g.recuperarVertice(s2);
				bool existe = g.adyacentes(v1,v2);
				if(existe){
					cout << "------------Si hay arista\n\n";
				}
				else{
					cout << "------------No hay arista\n\n";
				}
			}
			break;
			
			case 8:{//Eliminar arista entre 2 vertices
				string s1,s2;
				cout << "Etiqueta del vertice 1?\n";
				cin >> s1;
				cout << "Etiqueta del vertice 2?\n";
				cin >> s2;
				tipoVertice v1 = g.recuperarVertice(s1);
				tipoVertice v2 = g.recuperarVertice(s2);
				g.eliminarArista(v1,v2);
				cout << "------------Arista eliminada\n\n";
			}
			break;
			case 9:{//Peso de una arista
				string s1,s2;
				cout << "Etiqueta del vertice 1?\n";
				cin >> s1;
				cout << "Etiqueta del vertice 2?\n";
				cin >> s2;
				tipoVertice v1 = g.recuperarVertice(s1);
				tipoVertice v2 = g.recuperarVertice(s2);
				if(g.adyacentes(v1,v2)){
					int peso = g.peso(v1,v2);
					cout << "------------El peso de la arista es: " << peso << "\n\n";
				}
				else{
					cout << "------------No existe arista entre los vertices\n\n";
				}
				
			}
			break;
			
			case 10:{//Modificar el peso de una arista
				string s1,s2;
				cout << "Etiqueta del vertice 1?\n";
				cin >> s1;
				cout << "Etiqueta del vertice 2?\n";
				cin >> s2;
				tipoVertice v1 = g.recuperarVertice(s1);
				tipoVertice v2 = g.recuperarVertice(s2);
				int peso;
				cout << "Nuevo peso?\n";
				cin >> peso;
				g.modificarPeso(v1,v2,peso);
				cout << "------------Peso modificado\n\n";
			}
			break;
			
			case 11:{//Numero de vertices del grafo
				cout << "------------El numero de vertices en el grafo es: " << g.numVertices() << "\n\n";
			}
			break;
			
			case 12:{//Lista de vertices adyacentes a un vertice
				tipoVertice v,va;
				string nombre; 
				cout << "Nombre del vertice?\n";
				cin >> nombre;
				v = g.recuperarVertice(nombre);
				va = g.primerVerticeAdyacente(v);
				if(va != verticeNulo){
					cout << "Lista de vertices adyacentes: \n";
					while(va != verticeNulo){
						cout << g.etiqueta(va) << " ";
						va = g.siguienteVerticeAdyacente(v,va);
					}
					cout << "\n\n";
				}
				else{
					cout << "------------El vertice esta aislado\n\n";
				}
				
			}
			break;
			
			case 13:{//Lista de todos los vertices del grafo
				if(!g.vacio()){
					tipoVertice v = g.primerVertice();
					cout << "Lista total de vertices: \n";
					while(v != verticeNulo){
						cout << g.etiqueta(v) << " ";
						v = g.siguienteVertice(v);
					}
					cout << endl << endl;
				}
				else{
					cout << "------------Grafo vacio\n\n";
				}
				
			}
			break;
			//------Tener un grafo predeterminado para probar los de abajo
			case 14:{//Dijkstra
				algoritmo.dijkstra(g);
			}
			break;
			case 15:{//Floyd
				
			}
			break;
			case 16:{//Prim
				algoritmo.prim(g);
				
			}
			break;
			case 17:{//Kruskal
				algoritmo.kruskal(g,gCopia);
				
			}
			break;
			case 18:{//Copiar un grafo a gCopia
				algoritmo.copiarGrafo(g,gCopia);
				cout << "------------Grafo principal copiado a grafoCopia\n\n";
			}
			break;
			case 19:{//Grafos iguales entre el original y gCopia
				bool iguales = algoritmo.iguales(g,gCopia);
				if(iguales){
					cout << "------------El grafo principal y la copia son igueles\n\n";
				}
				else{
					cout << "------------El grafo principal y la copia NO son iguales\n\n";
				}
			}
			break;
			case 20:{//Problema del vendedor
				algoritmo.problemaVendedor(g);
			}
			break;
			
			case 0:{
				cout << "---------------Ha salido correctamente del programa---------------\n";
			}
			break;
			
		}
	}
   
   
   
    
    return 0;
}

