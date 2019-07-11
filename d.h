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
   
   
   
   
   Par * par = pertenece(preimagen(menor),menor);
			par->usado = true;