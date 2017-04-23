#include <iostream>
#include "nodo.h"
#include "pila.h"
#include "cola.h"

using namespace std;

int verificar(int uno, int dos)
{
	if(uno>dos)
		return 0;
	if(uno<dos)
		return 1;
	if(uno==dos)
		return 2;
}

int main()
{
	pila<int> Puno,Pdos,aux,guerra;
	cola<int> Cuno,Cdos;
	int i,n,num,jugadas,a;
	cin >> n;
	while(n>0)
	{
		jugadas=0;
		for(i=1;i<=26;i++)
		{
			cin >> num;
			aux.apilar(num);
		}
		for(i=1;i<=26;i++)
		{
			Cuno.encolar(aux.topee());
			aux.desapilar();
		}
		for(i=1;i<=26;i++)
		{
			cin >> num;
			aux.apilar(num);
		}
		for(i=1;i<=26;i++)
		{
			Cdos.encolar(aux.topee());
			aux.desapilar();
		}
		while((!Cuno.esVacia())&&(!Cdos.esVacia()))
		{
			a=1;
			while((a>=0)&&(a<=2))
			{
				jugadas++;
				Puno.apilar(Cuno.obtenerFrente());
				Cuno.desencolar();
				Pdos.apilar(Cdos.obtenerFrente());
				Cdos.desencolar();
		
				a=verificar((Puno.topee()),Pdos.topee());
				if(a==0)
				{
					while(!guerra.esVacia())
					{
						Cuno.encolar(guerra.topee());
						guerra.desapilar();
					}
					Cuno.encolar(Puno.topee());
					Puno.desapilar();
					Cuno.encolar(Pdos.topee());
					Pdos.desapilar();
					a=5;
				}
				if(a==1)
				{
					while(!guerra.esVacia())
					{
						Cdos.encolar(guerra.topee());
						guerra.desapilar();
					}
					Cdos.encolar(Puno.topee());
					Puno.desapilar();
					Cdos.encolar(Pdos.topee());
					Pdos.desapilar();
					a=5;
				}
				if(a==2)
				{
					guerra.apilar(Puno.topee());
					guerra.apilar(Pdos.topee());
					guerra.apilar(Cuno.obtenerFrente());
					Cuno.desencolar();
					guerra.apilar(Cdos.obtenerFrente());
					Cdos.desencolar();
					a=5;
				}
			}
		}
		if((Cuno.esVacia())&&(Cdos.esVacia()))
			cout<<"Empate";
		else
		{
			if(Cuno.esVacia()==1)
					cout<<"Jugador_2" <<endl;
				else
					cout<<"Jugador_1" <<endl;
		}
		cout<<" "<<jugadas;
		n--;
	}
return 0;
}
