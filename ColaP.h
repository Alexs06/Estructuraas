#ifndef Cola_Prioridades0
#define Cola_Prioridades0

#include <iostream>

using namespace std;

template <class T>
class ColaPrioridad {
	
	private:
	
		class Par{
			public:
			void crear(T e,int p){ //Elemento Prioridad
				this->elemento = e;
				this->prioridad = p;
			}
			int prioridad;
			T elemento;
		};
		int ultimo;
		Par * arreglo;
	
	public:

		void crear(){
			int maximo = 0;
			cout << "Ingrese el tamano maximo de la cola" << endl;
			cin >> maximo;
			arreglo = new ColaPrioridad::Par [maximo];
			ultimo = 0;	
		}
		void crear(int numero){
			arreglo = new ColaPrioridad::Par [numero];
			ultimo = 0;	
		}

		void destruir(){
			delete arreglo;
			ultimo = 0;
		}

		void vaciar(){
			ultimo = 0;
		}

		bool vacia(){
			bool vacio = false;
			if (ultimo == 0){
				vacio = true;
			}
			return vacio;
		}

		void agregar (T elemento,int prioridad){
			
			ColaPrioridad::Par nuevo;
			nuevo.crear(elemento,prioridad);	
			++ultimo;
			arreglo[ultimo] = nuevo; //Agregado en el espacio fisico disponible
			int posActual = ultimo;
			ColaPrioridad::Par aux;
			
			//Inicia retroceso
			while(posActual != 1 && arreglo[posActual].prioridad < arreglo[posActual/2].prioridad){
				aux.crear(arreglo[posActual].elemento,arreglo[posActual].prioridad); 
				arreglo[posActual] = arreglo[posActual/2];
				arreglo[posActual/2] = aux;
				posActual = posActual/2;	
			}
			
		}

		T eliminar(){
			T elemento =  arreglo[1].elemento;
			arreglo[1] = arreglo[ultimo]; //Le caigo encima al primer elemento
			--ultimo; //Quito el ultimo fisicamente
			
			bool acomodado = false;
			int posActual = 1;
			int minimo;
			int indice;
			ColaPrioridad::Par aux;
			
			//Inicia reacomodo
			while(!acomodado){
				if(posActual*2 <= ultimo){ //Si tiene un hijo 
					minimo = arreglo[posActual*2].prioridad;
					indice = posActual*2;
				
					if(posActual*2 +1 <= ultimo){//En caso de que tenga 2 hijos
						if(minimo > arreglo[posActual*2 +1].prioridad){//Si el hijo derecho es el menor de entre los 2
							minimo = arreglo[posActual*2 +1].prioridad;
							indice = posActual*2 +1;
						}
					}
					
					if(arreglo[posActual].prioridad > minimo){//Intercambio si se necesita
						aux.crear(arreglo[posActual].elemento, arreglo[posActual].prioridad);
						arreglo[posActual] = arreglo[indice];
						arreglo[indice] = aux;
						posActual = indice;	
					}
					else{
						acomodado = true;
					}
				}
				else{//Si ha llegado a una hoja
					acomodado = true;
				}
			}
			return elemento;
		}
		
		int numElem(){
			return ultimo;
		}
		
};
#endif