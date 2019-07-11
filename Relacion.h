#ifndef RELACION_1_1
#define RELACION_1_1
#include <iostream>
#include <vector>
using namespace std;
template<class V>
class Relacion{
	private:
		vector<V> arreglo;
		
	
	public:
		Relacion(){
			arreglo = new vector<V>();
		}
		
		~Relacion(){
			delete arreglo;
		}
		
		void vaciar(){
			arreglo.clear();
		}
		
		bool vacio(){
			bool vacio = false;
			if (arreglo.empty()) {
				vacio = true;
				return vacio;
			}
			return vacio;
			
		}
		
		void agregarRelacion(int ind, V v){
			arreglo[ind] = v;
		}
		
		void eliminarRelacion(int ind, V v){
			arreglo.erase(ind);
		}
		
		
		bool existeRelacion(int ind,V v){
			if (arreglo[ind] != v) {
				return false;
			}
			return true;
			
		}
		
		int preimagen(V imagen){
			for (int i = 0; i <= arreglo.size();i++) {
				if (arreglo[i] == imagen) {
					return i;
				}
			}
			return -1;
		}
		
		V imagen(int preimagen){
			return arreglo[preimagen];
		}
		
	
};
#endif
