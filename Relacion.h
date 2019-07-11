#ifndef RELACION_1_1
#define RELACION_1_1
#include <iostream>
using namespace std;
template<class T,class V>
class Relacion{
	private:
		class Par;
		Par * primera;
		Par * ultima;
		int size;
		
		class Par{
			public:
				T v1;
				V v2;
				bool usado;
				Par * siguiente;
				
				Par(T v1, V v2){
					siguiente = 0;
					usado = false;
					this->v1 = v1;
					this->v2 = v2;
				}
				
				~Par(){
					if(this->siguiente){
						delete this->siguiente;
					}
				}
		};
		
	public:
		Relacion(){
			primera = 0;
			ultima = 0;
			size = 0;
		}
		
		~Relacion(){
			if(primera){
				delete primera;
			}
		}
		
		void vaciar(){
			if(primera){
				delete primera;
				size = 0;
				ultima = 0;
				primera = 0;
			}
		}
		
		bool vacio(){
			if(size == 0){
				return false;
			}else{
				return true;
			}
		}
		
		void agregarRelacion(T v1, V v2){
			Par * nuevoPar = new Par(v1,v2);
			if(this->ultima){
				ultima->siguiente = nuevoPar;
				ultima = nuevoPar;
			}else{
				primera = ultima = nuevoPar;	
			}
			size++;
		}
		
		void eliminarRelacion(T v1, V v2){
			Par * par = pertenece(v1,v2);
			Par * nodo = primera;
			Par * aux = 0;
			bool listo = false;
			while(!listo && nodo->siguiente != 0){
				if(nodo == primera  && par->v1 == v1 && par->v2 == v2){//Si elimino el primer elemento
					primera = nodo->siguiente;
					nodo->siguiente = 0;
					delete nodo;
					if(primera == 0){//Si solo habia 1 elemento
						ultima = 0;
					}
					listo = true;
				}
				else if(nodo->siguiente->v1 == v1 && nodo->siguiente->v2 == v2){
					if(nodo->siguiente == ultima){
						delete nodo->siguiente;
						nodo->siguiente = 0;
						ultima = nodo;
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
		
		Par* pertenece(T v1,V v2){
			Par * temporal = primera;
			while(temporal != 0){
				if(temporal->v1 == v1 && temporal->v2 == v2){
					return temporal;
				}
			temporal = temporal->siguiente;
			}
		return temporal;
		}
		
		bool existeRelacion(T v1,V v2){
			Par * temporal = primera;
			while(temporal != 0){
				if(temporal->v1 == v1 && temporal->v2 == v2){
					return true;
				}
			temporal = temporal->siguiente;
			}
		return false;
		}
		
		T preimagen(V imagen){
			Par * temporal = primera;
			while(temporal != 0){
				if(temporal->v2 == imagen){
					return temporal->v1;
				}
			temporal = temporal->siguiente;
			}
		return 0;
		}
		
		V imagen(T preimagen){
			Par * temporal = primera;
			while(temporal != 0){
				if(temporal->v1 == preimagen){
					return temporal->v2;
				}
			temporal = temporal->siguiente;
			}
		return temporal->v2;
		}
		
		void modificarImagen(T v1, V v2, V v3){
			Par * par = pertenece(v1,v2);
			par->v2 = v3;
		}
		
		bool estaEnDominio(T v){
			Par * temporal = primera;
			bool esta = false;
			while(temporal && !esta){
				if(temporal->v1 == v){
					esta = true;
				}
				temporal = temporal->siguiente;
			}
			return esta;
		}
		
		bool estaEnCodominio(V v){
			Par * temporal = primera;
			bool esta = false;
			while(temporal && !esta){
				if(temporal->v2 == v){
					esta = true;
				}
				temporal = temporal->siguiente;
			}
			return esta;
		}
		
		int numRel(){
			return size;
		}
		
		void imprimir(){
			Par * primero = primera;
			while(primero != 0){
				cout<< primero->v1<<"     "<< primero->v2<<endl;
				primero = primero->siguiente;
			}
		}
		
		T minimoEnCodominio(){
			/*Par * par = primera;
			V menor;
			V temporal;
			while(par != 0){
				if(par->usado == true){
					par = par->siguiente;
					while(par->usado != true){
						par = par->siguiente;
					}
					menor = par->v2;
				}else{
					menor = par->v2;
				}
				if(par->v2 <= menor){
					menor = par->v2;
				}
				par = par->siguiente;
					
					
				
				
			}
			Par * p = pertenece(preimagen(menor),menor);
			p->usado = true;
			return preimagen(menor);*/
		}

		
};
#endif