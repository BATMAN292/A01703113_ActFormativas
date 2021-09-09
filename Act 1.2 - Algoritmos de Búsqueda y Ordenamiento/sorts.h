// Sarah G. Martínez Navarro
// A01703113
// NOTA: No sé por qué no quiere funcionar :( Ya es la 1:30am y esto no quiere jalar y aún tengo que estudiar para 2 exámenes que tengo hoy. Lo intentaré corregir después.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

#ifndef SORTS_H_
#define SORTS_H_

template <class T>
class sorts{
  private:
    void swap(std::vector<T>&, int, int);
	  void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	  void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	  void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);

  public:
    std::vector<T> ordenaSeleccion(const std::vector<T>&);
    std::vector<T> ordenaBurbuja(const std::vector<T>&);
    std::vector<T> ordenaMerge(const std::vector<T>&);
    
    int busqSecuencial(std::vector<int>, int val);
    int busqBinaria(std::vector<int>, int val);

    std::list<T> mergeList(const std::list<T>&, const std::list<T>&);
};

//swap
template <class T>
void sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
};

//selectionSort
template <class T>
std::vector<T> sorts<T>::ordenaSeleccion(const std::vector<T> &source) {
	std::vector<T> v(source);
	int pos;
	for (int i = v.size() - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (v[j] > v[pos]) {
				pos = j;
			}
		}
		if (pos != i) {
			swap(v, i, pos);
		}
	}
	return v;
}

//bubbleSort
template <class T>
std::vector<T> sorts<T>::ordenaBurbuja(const std::vector<T> &source) {
std::vector<T> v(source);
	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

//copyArray
template <class T>
void sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

//mergeArray
template <class T>
void sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;
	i = low;
	j = mid + 1;
	k = low;
	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

//mergeSplit
template <class T>
void sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;
	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

//mergeSort
template <class T>
std::vector<T> sorts<T>::ordenaMerge(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size() - 1);
	return v;
}

template <class T>
int sorts<T>::busqSecuencial(std::vector<int> v, int val){
  for(int i=0; i<v.size()-1;i++){
    if(val==v[i]){
      return i;
    };
  };
  return -1;
};

template <class T>
int sorts<T>::busqBinaria(std::vector<int>v, int val){
  int x;
  int y=0;
  int z=v.size()-1;
  while(y<z){
    x = (y+z)/2;
    if(val == v[x]){
      return x;
    }
    else if(val<v[x]){
      z = x-1;
    }
    else if(val>v[x]){
      y = x+1;
    };
  };
  return -1;
};

#endif
