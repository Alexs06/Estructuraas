#ifndef Diccionario_LSE
#define Diccionario_LSE
#include <iostream>
#include <cstring>
using namespace std;
template<class T>

class Diccionario{
	class Nodo;
	
	private:
		Nodo * primero;
		Nodo * ultimo;
		int size;
	
		class Nodo{
			public:
				T vertice;
				Nodo * siguiente;
				
				Nodo(T vertice){
					this->vertice = vertice;
					this->siguiente = 0;
				}
				~Nodo(){
					if(this->siguiente){
						delete this->siguiente;
					}
				}

				
			
		};
	
	public:
		Diccionario(){
			primero = 0;
			ultimo = 0;
			size = 0;
		}
		
		~Diccionario(){
			if(primero){
				delete primero;
			}
		}
		
		void vaciar(){
			if(primero){
				delete primero;
				size = 0;
				ultimo = 0;
				primero = 0;
			}
		}
		
		bool vacio(){
			if(size == 0){
				return false;
			}else{
				return true;
			}
		}
		
		void agregar(T vertice){
			Nodo * nuevoNodo = new Nodo(vertice);
			if(this->ultimo){
				ultimo->siguiente = nuevoNodo;
				ultimo = nuevoNodo;
			}else{
				primero = ultimo = nuevoNodo;	
			}
		size++;
		}
		
		
		void eliminar(T vertice){
			Nodo * nodo = primero;
			Nodo * aux = 0;
			bool listo = false;
			while(!listo && nodo->siguiente != 0){
				if(nodo == primero  && nodo->vertice == vertice){//Si elimino el primer elemento
					primero = nodo->siguiente;
					nodo->siguiente = 0;
					delete nodo;
					if(primero == 0){//Si solo habia 1 elemento
						ultimo = 0;
					}
					listo = true;
				}
				else if(nodo->siguiente->vertice == vertice){
					if(nodo->siguiente == ultimo){
						delete nodo->siguiente;
						nodo->siguiente = 0;
						ultimo = nodo;
					}
					else{
						aux = nodo->siguiente->siguiente;
						nodo->siguiente->siguiente = 0;
						delete nodo->siguiente;
						nodo->siguiente = aux;
						
					}
					listo = true;
				}
				else{
					nodo = nodo->siguiente;
				}
			}
		size--;
		}
		
		
		bool pertenece(T vertice){
			Nodo * temporal = primero;
			while(temporal != 0){
				if(temporal->vertice == vertice){
					return true;
				}
			temporal = temporal->siguiente;
			}
		return false;
		}
		
		int numElem(){
			return size;
		}
		
		void imprimir(){
			Nodo * temporal = primero;
			while(temporal != 0){
				cout << temporal->vertice << endl;
				temporal = temporal->siguiente;
			}
		}
	};
#endif

