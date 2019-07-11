#include "Algoritmos.h"
#include "Relacion.h" 
#include "Diccionario.h"
#include "GrafoND.h"
#include "GrafoMatriz.h"
#include <list>
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
	/*Relacion<tipoVertice,Tripleta> relacion;
	
	Tripleta tripleta;
	
	tipoVertice v = g.primerVertice();
	for(int i = 0; i < g.numVertices(); ++i){
		relacion.agregarRelacion(v,Tripleta());
		v = g.siguienteVertice(v);
	}
	
	
	tipoVertice v1 = g.primerVertice();
	Tripleta trip4 = relacion.imagen(v1);
	trip4.distancia = 0;
	trip4.usado = false;
	relacion.modificarImagen(v1,relacion.imagen(v1),trip4);
	
	tipoVertice vertice;
	Tripleta trip;
	for(int contador = 0; contador < g.numVertices(); ++contador){
		vertice = relacion.minimoEnCodominio();
		cout << "El vertice minimo es " << vertice<<endl;
		trip = relacion.imagen(vertice);
		trip.usado = true;
		relacion.modificarImagen(vertice,relacion.imagen(vertice),trip);
		tipoVertice vortex = g.primerVertice();
		for(int x = 0 ; x < g.numVertices(); ++x){
			Tripleta trip3 = relacion.imagen(vortex);
			if(trip3.usado == false && g.adyacentes(vertice,vortex) && trip.distancia != INT_MAX &&
			    trip.distancia + g.peso(vertice,vortex) < trip3.distancia){
					Tripleta trip2 = relacion.imagen(vortex);
					trip2.distancia = trip.distancia + g.peso(vertice,vortex);
					relacion.modificarImagen(vortex,relacion.imagen(vortex),trip2);
				}
			vortex = g.siguienteVertice(vortex);	
		}
	}
	relacion.imprimir();*/
	
	
	int arbol[g.numVertices()];
	int llave[g.numVertices()];
	bool verticesIncluidos[g.numVertices()];
	tipoVertice vectorVertices[g.numVertices()];
	
	tipoVertice v = g.primerVertice();
	for(int i = 0; i < g.numVertices(); ++i){           //Llenar un vector con los vertices del grafo
		vectorVertices[i] = v;
		v = g.siguienteVertice(v);
	}
	
	for(int j = 0; j < g.numVertices(); ++j){
		llave[j] = INT_MAX;  //Infinito
		verticesIncluidos[j] = false;
	}
	
	llave[0] = 0; //El primer vertice siempre se incluye
	arbol[0] = -1; //Primer nodo es raiz del arbol
	
	for (int count = 0; count < g.numVertices()-1; count++){
		int u = pesoMinimo(llave,verticesIncluidos, g.numVertices());
		verticesIncluidos[u] = true;
		for(int x = 0 ; x < g.numVertices() ; ++x){
       
         if (!verticesIncluidos[x] && g.adyacentes(vectorVertices[u],vectorVertices[x]) && llave[u] != INT_MAX 
                                       && llave[u]+ g.peso(vectorVertices[u],vectorVertices[x]) < llave[x]){
            llave[x] = llave[u] + g.peso(vectorVertices[u],vectorVertices[x]);
		 }	
         }
	}
	
	cout<<"Vertice   Distancia"<<endl;
   for (int c = 0; c < g.numVertices(); ++c){
	  tipoVertice t = vectorVertices[c];
      cout<< g.etiqueta(t) <<"              "<<llave[c]<<endl;
   }
	
	

}	

int Algoritmos::pesoMinimo(int dist[], bool sptSet[], int iterar){
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < iterar; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

void Algoritmos::floyd(Grafo& g){
	//Paso 1 Crear matriz de Costos, matriz de Vertices y relacion 1 a 1 entre indices y etiquetas
	int totalVertices = g.numVertices();
	
	string ** matrizVertices = new string *[totalVertices]; //Contiene el vertice intermedio
	int ** matrizCostos = new int *[totalVertices]; 		//Costo minimo entre cada par de vertices
	string * relacion1a1 = new string[totalVertices];		//Asocia indices de un arreglo con etiquetas de vertices
	
	tipoVertice v = g.primerVertice();
	for(int i = 0; i < totalVertices; ++i){
		matrizVertices[i] = new string[totalVertices];
		matrizCostos[i] = new int[totalVertices];
		relacion1a1[i] = g.etiqueta(v);
		v = g.siguienteVertice(v);
	}
	
	//Paso 2 Llenar las matrices con los valores iniciales
	for(int i = 0; i < totalVertices; ++i){
		for(int j = 0; j < totalVertices; ++j){
			if(i==j){//Se aisla el caso donde pregunta por loops
				matrizCostos[i][j] = 0;
				matrizVertices[i][j] = "-";
			}
			else{//Si el vertice en [i] es adyacente con el vertice en [j] 
				if(g.adyacentes(g.recuperarVertice(relacion1a1[i]),g.recuperarVertice(relacion1a1[j]))){
					matrizCostos[i][j] = g.peso(g.recuperarVertice(relacion1a1[i]),g.recuperarVertice(relacion1a1[j]));
					matrizVertices[i][j] = relacion1a1[j];
				}
				else{//Si no hay arista
					matrizCostos[i][j] = INT_MAX;
					matrizVertices[i][j] = "-";
				}
			}
		}
	}
	
	//Paso 3 Encontrar los caminos más cortos
	for(int k = 0; k < totalVertices; ++k){
		for(int i = 0; i < totalVertices; ++i){
			for(int j = 0; j < totalVertices; ++j){
				if(matrizCostos[i][j] > matrizCostos[i][k] + matrizCostos[k][j]){
					matrizCostos[i][j] = matrizCostos[i][k] + matrizCostos[k][j];
					matrizVertices[i][j] = relacion1a1[k];
				}
			}
		}
	}
	cout << "La matriz está indexada de la siguiente forma: \n";
	for(int i = 0; i < totalVertices; ++i){
		cout << i+1 << " = " << relacion1a1[i] << endl;
	}
	cout << endl;
	//imprimir matrizCostos
	cout << "\nMatriz de Costos\n";
	for(int i = 0; i < totalVertices; ++i){
		for(int j = 0; j < totalVertices; ++j){
			if(matrizCostos[i][j] == INT_MAX){
				cout << "-" << " ";
			}
			else{
				cout << matrizCostos[i][j] << " ";
			}
			
		}
		cout << endl;
	}
	
	//imprimir matrizVertices
	cout << "\nMatriz de Vertices intermedios\n";
	for(int i = 0; i < totalVertices; ++i){
		for(int j = 0; j < totalVertices; ++j){
			cout << matrizVertices[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl;

}

void Algoritmos::prim(Grafo& grafo){
	string arregloEtiquetas[grafo.numVertices()];
    bool modificado[grafo.numVertices()];
    Grafo minCosto;
    vector<int> distancias;
    vector<bool> visitado;
    int n = grafo.numVertices();
    int costoTotal = 0;
    distancias.resize(n);
    visitado.resize(n);
    int pivote;
    map <int, tipoVertice> R11MinCosto;
    map <int, tipoVertice> R11;
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
        modificado[i] == false;
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
	tipoVertice v = g.primerVertice();
    map <tipoVertice, tipoVertice> m;
    tipoVertice vn;
    pair <tipoVertice, tipoVertice> p;
    while(v != 0){
        vn = g2.agregarVertice(g.etiqueta(v));
        p = std::make_pair(v, vn);
        m.insert(p);
        v = g.siguienteVertice(v);
    }
     v = g.primerVertice();
    tipoVertice va;
    tipoVertice vna;
    while(v != 0){
        if(g.numVerticesAdyacentes(v) != 0){
        va = g.primerVerticeAdyacente(v);
        while(va != 0){
            vn = m.at(v);
            vna = m.at(va);
           g2.agregarArista(vn, vna, g.peso(v, va));;
           va = g.siguienteVerticeAdyacente(v, va);
        }
        }
        v = g.siguienteVertice(v);
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
bool igualdad=true;
tipoVertice v1;
tipoVertice v2;
tipoVertice vAdy1;
tipoVertice vAdy2;

//primero pregunto por el tama;o de ambos grafos, ya que si el tama;o es diferentes jamas seran iguales
if(g1.numVertices()!=g2.numVertices()){
	igualdad=false;
}
//en caso de que si sean del mismo tama;o, tengo que empezar a fijarme, en que tengan los mismos vertices, que tengan la misma
//cantidad de vertices adyacentes y en que el peso de las aristas sea el mismo
else{
v1=g1.primerVertice();

while(v1!=verticeNulo && igualdad){
	v2=g2.recuperarVertice(g1.etiqueta(v1));
	
	//en caso de no encontrar el mismo vertice del grafo 1 en el grafo 2, entonces los grafos son diferentes
	if(v2==verticeNulo){
		igualdad=false;
	}
	//en caso de que si encuentra el vertice del grafo 1 en el grafo 2
	else{
		//pregunto por la cantidad de vertices adyacentes de v1 y v2, que son los mismos vertices en diferentes grafos
		if(g1.numVerticesAdyacentes(v1)==g2.numVerticesAdyacentes(v2)){
			vAdy1=g1.primerVerticeAdyacente(v1);
			vAdy2=g2.primerVerticeAdyacente(v2);
			
			//me voy moviendo por todos los vertices adyacentes al vertice del grafo 1 mientras no llegue a nulo y mientras ambos grafos sigan siendo iguales
			while(vAdy1!=verticeNulo && igualdad){
				//me voy moviendo por los vertices adyacentes del vertice del grafo 2 a ver si encuentro uno que sea igual a vAdy1
			 while(vAdy2!=verticeNulo || g2.etiqueta(vAdy2)!=g1.etiqueta(vAdy1)){
				 vAdy2=g2.siguienteVerticeAdyacente(v2,vAdy2);
				 
			 }
			 
			 //cuando se sale del while puede ser porque no encontro un vertice con la misma etiqueta o porque lo encontro
			 if(vAdy2==verticeNulo){
				 
				 igualdad=false;
			 }else{
				 //aqui significa que si encontro vertices adyacentes iguales del vertices con la misma etiqueta en ambos grafos,
				 //entonces tengo que fijarme si los pesos de las aristas son iguales
				 if(g1.peso(v1,vAdy1)!=g2.peso(v2,vAdy2)){
					 
					 igualdad=false;
				 }
				 
			 }
			 vAdy1=g1.siguienteVerticeAdyacente(v1,vAdy1);
			}
		}
	}
v1=g1.siguienteVertice(v1);	
}	
	
}

return igualdad;
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



