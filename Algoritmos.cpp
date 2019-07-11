#include "Algoritmos.h"
#include "Relacion.h" 
#include "Diccionario.h"
#include "GrafoND.h"
#include "GrafoMatriz.h"
#include <list>
#include <String>

using namespace std;
typedef int tipoVertice;
typedef GrafoMatriz Grafo;
//Variables globales
	Grafo* g;
	Diccionario<tipoVertice> d;

	string* solucionFinal;
	string* solucionActual;
	int costoFinal;
	int costoActual;
	int solucionesFactibles;
	int indice ;
	Diccionario<tipoVertice> dicc;
	
//constructor por defecto de una tripleta
Algoritmos::Tripleta::Tripleta(){
	distancia = INT_MAX;
	verticeMasCercano = verticeNulo;
	usado = false;
	
	
}

//constructor de una tripleta
Algoritmos::Tripleta::Tripleta(int distancia ,tipoVertice vertice, bool usado){
	this->distancia = distancia;
	verticeMasCercano = vertice;
	this->usado = usado;
}

//sobrecarga del operador <= para una tripleta
bool Algoritmos::Tripleta::operator <=(Tripleta t1){
	bool resultado = false;
	if(distancia <= t1.distancia){
		resultado = true;
	}
	return resultado;
}

//sobrecarga del operador == para una tripleta
bool Algoritmos::Tripleta::operator==(Tripleta t1){
	if(t1.usado == usado && t1.verticeMasCercano == verticeMasCercano && t1.distancia == distancia){
		return true;
	}else{
		return false;
	}
}

//sobrecarga del operador = para una tripleta
bool Algoritmos::Tripleta::operator=(Tripleta t1){
	usado = t1.usado;
	verticeMasCercano = t1.verticeMasCercano;
	distancia = t1.distancia;
	return true;
}

//constructor por defecto de una terna
Algoritmos::Terna::Terna(){
	
}

//constructor de una terna
Algoritmos::Terna::Terna(tipoVertice ver1, tipoVertice ver2, int pesoEntrada){
	v1 = ver1;
	v2 = ver2;
	peso = pesoEntrada;
}

//sobrecarga del operador = para una terna
void Algoritmos::Terna:: operator= (Terna& terna2){
	v1 = terna2.v1;
	v2 = terna2.v2;
	peso = terna2.peso;
}

//sobrecarga del operador == para una terna
bool Algoritmos::Terna:: operator==(Terna& terna2){
	bool iguales = false;
	if((v1 == terna2.v1 || v1 == terna2.v2) && (v2 == terna2.v1 || v2 == terna2.v2) && peso == terna2.peso){
		iguales = true;
	}
	return iguales;
}

void Algoritmos::dijkstra(Grafo& g){
	
	
}	

int Algoritmos::pesoMinimo(int dist[], bool sptSet[], int iterar){
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < iterar; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

void Algoritmos::prim(Grafo& grafo){
	int nVert = grafo.numVertices();
	string * arregloEtiquetas = new string[grafo.numVertices() ];
    bool * modificado = new bool[grafo.numVertices()];
    Grafo minCosto;
    vector<int> distancias;
    vector<bool> visitado;
    int n = grafo.numVertices();
    int costoTotal = 0;
    distancias.resize(n);
    visitado.resize(n);
    int pivote;
    Relacion<tipoVertice> R11MinCosto;
	Relacion<tipoVertice> R11;
    pair<int, tipoVertice> p;
    pair<int, tipoVertice> p2;
    tipoVertice v = grafo.primerVertice();
    tipoVertice vn;
    int contador = 0;
   while(v != 0){
        visitado[contador] = false;
        arregloEtiquetas[contador] = grafo.etiqueta(grafo.primerVertice());
        p = std::make_pair(contador,v);
        R11.insert(p);
        vn  = minCosto.agregarVertice(grafo.etiqueta(v));
        p2 = std::make_pair(contador, vn);
        R11MinCosto.insert(p2);
        contador++;
        v = grafo.siguienteVertice(v);;
    }
    for(int i = 1; i <= n -1; i++){
        if(grafo.adyacentes(R11.at(0), R11.at(i))){
            distancias[i] = grafo.peso((R11.at(0)), R11.at(i));
        }
        else{
            distancias[i] = INT_MAX;
        }
        modificado[i] = false;
    }
    for(int i = 1; i <= n -1; i++){
        pivote = encontrarMinimo(n, visitado, distancias);
        for(int j = 1; j <= n-1; j++){
            if(j != pivote){
            if(grafo.adyacentes(R11.at(pivote), R11.at(j))){
            if(grafo.peso(R11.at(pivote), R11.at(j)) < distancias[j] && !minCosto.adyacentes(R11MinCosto.at(pivote), R11MinCosto.at(j))){
                distancias[j] = grafo.peso(R11.at(pivote), R11.at(j));
                arregloEtiquetas[j] = grafo.etiqueta(R11.at(pivote));
                minCosto.agregarArista(R11MinCosto.at(pivote), R11MinCosto.at(j),grafo.peso(R11.at(pivote), R11.at(j)));
            }
            }
        }
        }  
    };
    std::cout<<"Arbol de minimo costo"<<std::endl;
    for(int i = 1; i <= n -1; i++){
        std::cout<<"arista "<<i<<std::endl;
        std::cout<<"Vertices: "<<grafo.etiqueta(R11.at(i))<<" y "<<arregloEtiquetas[i]<<std::endl;
        std::cout<<"Costo : "<<distancias[i]<<std::endl;
        costoTotal += distancias[i];
    }
    std::cout<<"Costo total : "<<costoTotal<<std::endl;
    minCosto.vaciar();
}

int Algoritmos::encontrarMinimo(int tam, vector<bool>& v, vector<int> d){ //metodo auxiliar para el algoritmo de Prim
    int posPivote = -1;
    int valorMinimo = INT_MAX;
    for(int i = 1; i <= tam -1; i++){
        if(v[i] == false){
        if(d[i] < valorMinimo){
            valorMinimo = d[i];
            posPivote = i;
        }
    }
    }
    v[posPivote] = true;
    return posPivote;
}

void Algoritmos::problemaVendedor(Grafo& graf){
	g = &graf;
	solucionFinal = new string[graf.numVertices()];
	solucionActual = new string[graf.numVertices()];
	costoFinal = -1;
	costoActual = 0;
	solucionesFactibles = 0;;
	indice = 0;
	dicc.agregar(graf.primerVertice());
	
	asignarArista(graf.primerVertice());
	
	if(costoFinal != -1){
		cout << "Total de soluciones: " << solucionesFactibles << endl;
		cout << "Solucion Optima: \n";
		cout << graf.etiqueta(graf.primerVertice());
		for(int i = 0; i < graf.numVertices(); ++i){
			cout << " - " << solucionFinal[i];
		}
		cout << graf.etiqueta(graf.primerVertice()) << " Se cierra el circuito" << endl <<"Costo total: " << costoFinal;
	}
	else{
		cout << "\n------------El grafo no tiene solucion al Problema del Vendedor";
	}
	cout << endl << endl;
	dicc.vaciar();
}


void Algoritmos::copiarGrafo(Grafo& g,Grafo& g2){
	g2.vaciar();
	Relacion<tipoVertice> r11;
	Relacion<tipoVertice> r12;
			if (!g.vacio()) {
				d.vaciar();

				tipoVertice vp1 = g.primerVertice();
				tipoVertice vp2 = g2.agregarVertice(g2.etiqueta(vp1));
				int ind = 0;
					r11.agregarRelacion(ind, vp1);
					r12.agregarRelacion(ind, vp2);
					ind++;
					tipoVertice v1 = g.siguienteVertice(vp1);
					while (v1 != 0) {
						tipoVertice v2 = g2.agregarVertice(g.etiqueta(v1));//Creo todos los vertices y la R11
						r11.agregarRelacion(ind, v1);
						r12.agregarRelacion(ind, v2);

					}
						//Luego debo crear cada arista
					
							while (vp1 != 0) {
								tipoVertice va = g.primerVerticeAdyacente(vp1);//Me muevo por sus adyacentes
									while (va != 0) {
										int peso = g.peso(vp1, va);
										g2.agregarArista(r11.imagen(vp1), r11.imagen(va), peso);
										va = g.siguienteVerticeAdyacente(vp1, va);
									}
									vp1 = g.siguienteVertice(vp1);
							}
			}
}



void Algoritmos::asignarArista(tipoVertice v){
	
	tipoVertice va = g->siguienteVertice(g->primerVertice());
	while(va != verticeNulo){
		if(g->adyacentes(v,va) && !dicc.pertenece(va)){
			dicc.agregar(va);
			solucionActual[indice] = g->etiqueta(va);
			costoActual += g->peso(v,va);
			++indice;
			if(dicc.numElem() == g->numVertices()){// Cerrar el ciclo
				if(g->adyacentes(va,g->primerVertice())){
						costoActual += g->peso(va,g->primerVertice());
						++solucionesFactibles;
					if(costoFinal == -1){//si es la primera solucion encontrada
						costoFinal = costoActual;
						for(int i = 0; i < g->numVertices(); ++i){
							solucionFinal[i] = solucionActual[i];
						}
					}
					else if (costoFinal > costoActual){//si se encontró una mejor solucion
						costoFinal = costoActual;
						for(int i = 0; i < g->numVertices(); ++i){
							solucionFinal[i] = solucionActual[i];
						}
					}
					//Arrepentimiento de cerrar el ciclo
					costoActual -= g->peso(va,g->primerVertice());
				}		
			}
			else{
				asignarArista(va);
			}
			//Arrepentimiento
			dicc.eliminar(va);
			--indice;
			costoActual -= g->peso(v,va);
		}
		va = g->siguienteVertice(va);
	}
	
	
	
	
}

/*Requiere: dos grafos inicializados
Efecto: dice si dos grafos son iguales, esto significa que tengan los mismos pesos en las aristas
correspondientes y los mismos vertices
Modifica: no modifica nada
*/
bool Algoritmos::iguales(Grafo g1, Grafo g2){
	bool sonIgual = false;
		if(g1.numVertices() != g2.numVertices()) {
			return sonIgual;
		}
		else {
			sonIgual = true;
			Relacion<tipoVertice> R11;
			tipoVertice v1 = g1.primerVertice();
				while (v1 != verticeNulo && sonIgual){
					tipoVertice v2 = BuscarEtiqueta(g1.etiqueta(v1), g2);
						if (v2 != verticeNulo){
						if( g1.numVerticesAdyacentes(v1) == g2.numVerticesAdyacentes(v2)) {
							R11.agregarRelacion(v1, v2);
							v1 = g1.siguienteVertice(v1);
						}
						else {
							sonIgual = false;
						}
						}
						else {
							sonIgual = false;
						}
				}
			if (sonIgual){
				v1 = g1.primerVertice();
			while (v1 != verticeNulo && sonIgual) {
				tipoVertice va1 = g1.primerVerticeAdyacente(v1);
			while (va1 != verticeNulo && sonIgual) {
				//if (g2.existeArista(R11.imagen(v1),R11.imagen(va1))) {
					if (g1.peso(v1,va1) != g2.peso(R11.imagen(v1),R11.imagen(va1))) {
						sonIgual = false;
					}
					else {
						va1 = g1.siguienteVerticeAdyacente(v1, va1);
					}
				}
				//else {
			
				 sonIgual = false;
				//}
			}
			v1 = g1.siguienteVertice(v1);
			//}
			}
				
		}
		return(sonIgual);
	}
	
tipoVertice Algoritmos::BuscarEtiqueta(string e,Grafo& g) {
	
	tipoVertice v = g.primerVertice();
		while (v != verticeNulo) {
			if (e == g.etiqueta(v)) {
				return v;
			}
			else {
				v = g.siguienteVertice(v);
			}
		}
		return verticeNulo;
}

/*Requiere: grafo inicializado y vertice que exista en el grafo
Efecto: elimina un vertice que esta unido a otros dos vertices mediante aristas
Modifica: grafo
*/
void Algoritmos::eliminarVerticeNoAislado(Grafo& grafo, tipoVertice vertice){
	//hay que ir moviendose por el grafo y preguntando al vertice en el que me encuentro si uno de sus vertices adyacentes
	//es el vertice que deseo eliminar
	tipoVertice pos=grafo.primerVertice();
	tipoVertice posAdy;
	
	//me voy moviendo por todo el grafo hasta llegar a un vertice vacio, que significaria que ya recorri todo el grafo
	while(pos!=verticeNulo){
		
		//me pongo en el primer vertice adyacente de la posicion del grafo en la que me encuentro, y mientras
		//ninguno de los vertices adyacentes sea el vertice que entra como parametro o ya no haya vertices adyacentes
		//entonces me muevo por los vertices adyacentes
		posAdy=grafo.primerVerticeAdyacente(pos);
		
		while(posAdy!=verticeNulo && posAdy!=vertice){
			posAdy=grafo.siguienteVerticeAdyacente(pos,1);
		}
		
		//al salirme del while puede ser porque ya no hayan vertices adyacentes, pero lo que me importaria es si
		//me salgo debido a que encontre como vertice adyacente al vertice que entra como parametro del metodo
		if(posAdy==vertice){
			//si son iguales entonces elimino esa arista
			grafo.eliminarArista(pos, posAdy);
		}
		
		//me muevo por el grafo
		pos=grafo.siguienteVertice(pos);
		
		
	}
	
	posAdy=grafo.primerVerticeAdyacente(vertice);
	tipoVertice posTemporal;
	while(posAdy!=verticeNulo){
		
		posTemporal=posAdy;
		grafo.eliminarArista(vertice, posAdy);
		posAdy=grafo.siguienteVerticeAdyacente(vertice, posTemporal);
	}
	
	//cuando salgo de este while significa que ya recorri todo el grafo, lo que significa que ahora tengo el vertice que
	//deseo eliminar como un vertice aislado, como ya existe un metodo para eliminar un vertice aislado, simplemente lo llamo
	
	//cuando salgo de este while significa que ya recorri todo el grafo, lo que significa que ahora tengo el vertice que
	//deseo eliminar como un vertice aislado, como ya existe un metodo para eliminar un vertice aislado, simplemente lo llamo
	grafo.eliminarVertice(vertice);
	
}

/*Requiere: grafo inicializado
Efecto: recorre el grafo e imprime etiquetas
Modifica: no modifica nada
En este algoritmo hay que ir marcando por cuales vertices ya se paso para evitar que se encicle
*/
void Algoritmos::recorridoEnProfundidad(Grafo& grafo){
	if(!grafo.vacio()){
		tipoVertice v = grafo.primerVertice();
		while(v != -1){
			if(!d.pertenece(v)){
				recorridoEnProfundidadR(v,grafo);
			}
			v = grafo.siguienteVertice(v);
		}
	}
	
	d.vaciar();
}

//metodo recursivo de recorrido en profundidad primero
void Algoritmos::recorridoEnProfundidadR(tipoVertice vertice,Grafo& grafo){
	//muestro la etiqueta del vertice que aun no pertenece al diccionario y luego lo agrego al diccionario
	cout<<grafo.etiqueta(vertice)<<endl;
	d.agregar(vertice);
	
	//me posiciono en el primer vertice adyacente del vertice anterior
	tipoVertice vertAdy=grafo.primerVerticeAdyacente(vertice);
	
	//mientras no haya recorrido todos los vertices adyacentes, si el vertice no pertenece al diccionario, llamo recursivamente
	//sino entonces me sigo moviendo por los vertices adyacentes
	while(vertAdy!=verticeNulo){
		if(!d.pertenece(vertAdy)){
			
			recorridoEnProfundidadR(vertAdy,grafo);
		}
		vertAdy=grafo.siguienteVerticeAdyacente(vertice, vertAdy);
		
	}
	
}

void Algoritmos::kruskal(Grafo g1, Grafo g2) {
	
}



