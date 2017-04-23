#ifndef NODOARBIN_H_
#define NODOARBON_H_
#include <iostream>

using namespace std;

template <class T>
class nodoarbolbin
{
	private:
		nodoarbin<T>* hijoizq,hijoder;
		T e;
	public:
		nodoarbin<T>();
		T getelemento();
		nodoarbin<T>* gethijoizquierdo();
		nodoarbon<T>* gethijoderecho();
		void setelemento(T elem)
		void sethijoizquierdo(nodoarbin<T>* p);
		void sethijoderecho(nodoarbin<T>* p);
};

template <class T>
nodoarbin<T>::nodoarbin()
{
	hijoizquierdo=NULL;
	hijoderecho=NULL;
}

template <class T>
T nodoarbin<T>::getelemento()
{
	return e;
}

template <class T>
nodoarbin<T>* nodoarbin<T>::gethijoizquierdo()
{
	return hijoizquierdo;
}


template <class T>
nodoarbin<T>* nodoarbin<T>::gethijoderecho()
{
	return hijoderecho;
}

template <class T>
void nodoarbin<T>::setelemento(T elem)
{
	e=elem;
}

template <class T>
void nodoarbin<T>::sethijoizquierdo(nodoarbin<T>* p)
{
	hijoizq=p;
}


template <class T>
void nodoarbin<T>::sethijoderecho(nodoarbin<T>* p)
{
	hijoder=p;
}

#endif
