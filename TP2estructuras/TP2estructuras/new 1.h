Iguales(g1,g2){
	bool iguales = true;
	Relacion<tipoVertice,tipoVertice> relacion;
	if(g1.numVertices() != g2.numVertices()){
		iguales = false;
	}else{
		tipoVertice v1 = g1.primerVertice();
		while(v1 != verticeNulo && iguales){
			tipoVertice v2 = g2.recuperarVertice(g1.etiqueta(v1));
			if(v2 != verticeNulo){
				if(g1.numVerticesAdyacentes(v1) == g2.numVerticesAdyacentes(v2)){
					relacion.agregarRelacion(v1,v2);
					v1 = g1.siguienteVertice(v1);
				}else{
					iguales = false;
				}
			}else{
				iguales = false;
			}
		}
	}
	
	if(iguales){
		tipoVertice v1 = g1.primerVertice();
		while(v1 != verticeNulo && iguales){
			tipoVertice va1 = g1.primerVerticeAdyacente(v1);
			while(va1 != verticeNulo && iguales){
				if(g2.adyacentes(relacion.imagen(v1),relacion.imagen(va1))){
					if(g1.peso(v1,va1) != g2.peso(relacion.imagen(v1),relacion.imagen(va1))){
						iguale = false;
					}else{
						va1 = g1.siguienteVerticeAdyacente(v1,va1);
					}
				}else{
					iguales = false;
				}
			}
			v1 = g1.siguienteVertice(v1);
		}
	}
	return iguales;
}



Iguales(Grafo g1, Grafo g2){
	bool iguales = true;
	if(g1.numVertices() != g2.numVertices()){
		iguales = false;
	}else{
		Relacion<tipoVertice,tipoVertice> relacion;
		tipoVertice v1 = g1.primerVertice();
		while(v1 != verticeNulo && iguales){
			tipoVertice v2 = g2.recuperarVertice(g1.etiqueta(v1));
			if(v2 != verticeNulo){
				if(g1.numVerticesAdyacentes() == g2.numVerticesAdyacentes()){
					relacion.agregarRelacion(v1,v2);
				}else{
					iguales = false;
				}
			}else{
				iguales = false;
			}
		}
		if(iguales){
			v1 = g1.primerVertice();
			while(v1 != verticeNulo && iguales){
				tipoVertice va1 = g1.primerVerticeAdyacente(v1);
				while(va1 != verticeNulo && iguales){
					if(g2.adyacentes(relacion.imagen(v1),relacion.imagen(va1))){
						if(g1.peso(v1,va1) != g2.peso(relacion.imagen(v1),relacion.imagen(va1))){
							iguales = false;
						}else{
							g1.siguienteVerticeAdyacente(v1,va1);
						}
					}else{
						iguales = false;
					}
				}
				v1 = siguienteVertice(v1);
			}
		}
	}
	return iguales;
}	