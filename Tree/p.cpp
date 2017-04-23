#include "lista.h"
#include <iostream>
#include "arboln.h"
int main()
{
	bool x=0;
	nodoarbol<int> A(1),B(2),C(3),D(4),E(5),F(6),G(7),H(8),e(x);
	arboln<int> arbol,arbol2;
	G.conectar(e,e);
	H.conectar(e,e);
	D.conectar(e,e);
	F.conectar(G,e);
	E.conectar(e,F);
	C.conectar(H,D);
	B.conectar(E,C);
	A.conectar(B,e);
	arbol.setraiz(A);
	arbol2=arbol;
	arbol2.inorden();
	return 0;
}
////////////////////ANEXO
////////////////////////////////NODO USADO PARA ARBOLES
/* EL METODO CONECTAR DEBE SER USADO A PARTIR DE LOS NODOS HOJAS YA QUE ESTE
METODO HACE USO DE MEMORIA DINAMICA Y PUEDE ALTERAR LAS CONEXIONES,ES DECIR 
QUE PARA UTILIZAR ESTE METODO SE DEBEN conectar PRIMERO LOS NODOS HOJAS PARA 
LUEGO IR DESCOMPONIENDO EL ARBOL PASO A PASO Y CONECTANDO UNO A UNO, ACTO 
CONTRARIO EL VACIAR DE ARBOL_N TENDRA ERRORES, IGUALMENTE SU DESTRUCTOR*/
	
	


