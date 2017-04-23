#ifndef ARBOLN_H_
#define ARBOLN_H_
#include <iostream>
#include "nodoarbol.h"
#include "lista.h"
using std::cout;

template <class T>
class arboln
{
	private:
		nodoarbol<T> *nodoraiz;
		static void recorridopreorden(nodoarbol<T> *ptrRaiz);
		static void recorridoinorden(nodoarbol<T> *ptrRaiz);
	public:
		arboln<T>();
		arboln<T>(T e,lista<arboln<T> > lst);
		arboln<T>(T e);
		bool esNulo();
		T raiz();
		lista<arboln<T> > hijos();
		void insertarsubarbol(arboln<T> arbol);
		void eliminarsubarbol(int pos);
		//~arboln<T>(); 
		void destruir();
		nodoarbol<T> copiar();
		void preorden();
		void inorden();
		void setraiz(nodoarbol<T> N);
		
		
};

template <class T>
arboln<T>::arboln()
{
	nodoraiz=NULL;
}

template <class T>
arboln<T>::arboln(T e,lista<arboln<T> > lst)
{
	nodoarbol<T> *aux;
	int i,longit;
	nodoraiz= new nodoarbol<T>;
	nodoraiz->setelemento(e);
	nodoraiz->sethermanoderecho(NULL);
	longit=lst.longitud();
	if(longit==0)
		nodoraiz->sethijoizquierdo(NULL);
	else
	{
		nodoraiz->sethijoizquierdo(lst.consultar(1).nodoraiz);
		aux=nodoraiz->gethijoizquierdo();
		for(i=2;i<=longit;i++)
		{
			aux->sethermanoderecho(lst.consultar(i).nodoraiz);
			aux=aux->gethermanoderecho();
		}
		aux->sethermanoderecho(NULL);
	}
}

template <class T>
arboln<T>::arboln(T e)
{
	nodoraiz= new nodoarbol<T>;
	nodoraiz->setelemento(e);
	nodoraiz->sethermanoderecho(NULL);
	nodoraiz->sethijoizquierdo(NULL);
}

template <class T>
bool arboln<T>::esNulo()
{
	return (nodoraiz==NULL);
}

template <class T>
T arboln<T>::raiz()
{
	return (nodoraiz->getelemento());
}

template <class T>
lista<arboln<T> > arboln<T>::hijos()
{
	nodoarbol<T> *aux;
	arboln<T> arbolaux;
	lista<arboln<T> > lst;
	lst();
	aux=nodoraiz->gethijoizquierdo();
	while(aux!=NULL)
	{
		arbolaux.nodoraiz=aux;
		lst.insertar(arbolaux,lst,lst.longitud+1);
		aux=aux->gethermanoderecho();
	}
	return lst;
}

template <class T>
void arboln<T>::eliminarsubarbol(int pos)
{
	nodoarbol<T> *aux;
	arboln<T> subarbol;
	int i;
	if(pos==1)
	{
		subarbol.nodoraiz=nodoraiz->gethijoizquierdo();
		nodoraiz->sethijoizquierdo(nodoraiz->gethijoizquierdo()->gethermanoderecho());
	}
	else
	{
		aux=nodoraiz->gethijoizquierdo();
		for(i=2;i<=pos-1;i++)
		{
			aux=aux->gethermanoderecho();
		}
		subarbol.nodoraiz=aux->gethermanoderecho();
		aux->sethermanoderecho((aux->gethermanoderecho())->gethermanoderecho());
	}
	subarbol.nodoraiz.sethermanoderecho(NULL);
	~subarbol();
}

template <class T>
void arboln<T>::insertarsubarbol(arboln<T> arbol)
{
	nodoarbol<T>* aux;
	if(nodoraiz->gethijoizquierdo()==NULL)
		nodoraiz->sethijoizquierdo(arbol.nodoraiz);
	else
	{
		aux=nodoraiz->gethijoizquierdo();
		while(aux.gethermanoderecho()!=NULL)
		{
			aux=aux->gethermanoderecho();
		}
		aux->sethermanoderecho(arbol.nodoraiz);
	}
}

template <class T>
void arboln<T>::preorden()
{
	recorridopreorden(nodoraiz);
}

template <class T>
void arboln<T>::recorridopreorden(nodoarbol<T> *ptrRaiz)
{
	nodoarbol<T> *aux;
	if(ptrRaiz!=NULL)
	{
		cout << "" << ptrRaiz->getelemento();
		aux=ptrRaiz->gethijoizquierdo();
		while(aux!=NULL)
		{
			recorridopreorden(aux);
			aux=aux->gethermanoderecho();
		}
	}
}



template <class T>
void arboln<T>::destruir()
{
	arboln aux;
	if(nodoraiz->gethermanoderecho()!=NULL)
	{
		aux.nodoraiz=nodoraiz->gethermanoderecho();
		aux.destruir();
	}
	if(nodoraiz->gethijoizquierdo()!=NULL)
	{
		aux.nodoraiz=nodoraiz->gethijoizquierdo();
		aux.destruir();
	}
	delete [] nodoraiz;
	nodoraiz=NULL;
}
/*template <class T>
arboln<T>::~arboln()
{
	destruir();
}*/

template <class T>
void arboln<T>::setraiz(nodoarbol<T> N)
{
	nodoraiz= new nodoarbol<T>(N.getelemento(),N.gethijoizquierdo(),N.gethermanoderecho());
}

template <class T>
void arboln<T>::inorden()
{
	recorridoinorden(nodoraiz);
}

template <class T>
void arboln<T>::recorridoinorden(nodoarbol<T> *ptrRaiz)
{
	nodoarbol<T> *aux;
	if(ptrRaiz!=NULL)
	{
		recorridoinorden(ptrRaiz->gethijoizquierdo());
		cout << "" << nodoraiz->getelemento();
		aux=ptrRaiz->gethijoizquierdo();
		while(aux!=NULL)
		{
			recorridoinorden(aux);
			aux=aux->gethermanoderecho();
		}
	}
}

#endif
