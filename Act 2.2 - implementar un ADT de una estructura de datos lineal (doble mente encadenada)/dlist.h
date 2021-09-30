#ifndef DLIST_H_
#define DLIST_H_

#include <iostream>
#include <sstream>

using namespace std;
  
template <class T> class DList;
template <class T> class DListIterator;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
	friend class DListIterator<T>;
};

template <class T>
class DList {
public:
	DList();
	DList(const DList<T>&) throw (OutOfMemory);
	~DList();
	std::string toStringForward() const;
  std::string toStringBackward() const;
	void operator= (const DList&) throw (OutOfMemory);
  std::string insertion(int);
  std::string update(int, int);
  std::string deleteAt(int);
  std::string search(int);

private:
	DLink<T> *head;
	DLink<T> *tail;
  int dato, pos;
	int size;

	friend class DListIterator<T>;
};

template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	DLink<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const {
	std::stringstream aux;
	DLink<T> *p;
	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string DList<T>::insertion(int dato){

}

template <class T>
std::string DList<T>::update(int pos, int dato){

}

template <class T>
std::string DList<T>::deleteAt(int pos){
  
}
