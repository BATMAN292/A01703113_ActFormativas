//A01703113 - Sarah Guadalupe Martínez Navarro

#include <iostream>
using namespace std;

class Funciones{
  private:
    int x;

  public:
    int sumaIterativa(int);
    int sumaRecursiva(int);
    int sumaDirecta(int);
};

int Funciones::sumaIterativa(int x){
  int suma = 0;
  if (x==0){
    return 0;
  };
  for (int i=1; i<=x; i++)
    suma = suma + i;
  return suma;
};

int Funciones::sumaRecursiva(int x){
  if (x<=0){
    return 0;
  }
  else{
    return x+sumaRecursiva(x-1);
  };
};

int Funciones::sumaDirecta(int x){
  if(x==0){
    return 0;
  }
  else{
    return (x*(x+1))/2;
  };
};
