#include <iostream>
#ifndef LIST_H
#define LIST_H
using namespace std;

template<typename T>

class List {
	public:
		virtual void insert(int pos, T element); //inserta element en pos
		virtual void append(T element);//inserta element al principio de la lista
		virtual void prepend(T element);//inserta element al final de la lista
		virtual T remove(int pos); //elimina el elemento en pos y lo devuelve. Lanza out_of_range si pos no es valida.
		virtual T get(int pos);//devuelve el elemento en pos (OOR)
		virtual bool empty(); //¿lista vacia?
		virtual int size();//num. elementos de la lista
};

#endif