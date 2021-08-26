//A01703113 - Sarah Guadalupe Martínez Navarro

#include <iostream>
using namespace std;

//crear la clase Funciones
class Funciones{
  private:
    int x; //variable que recibirán las funciones

  public:
  //declarar funciones
    int sumaIterativa(int);
    int sumaRecursiva(int);
    int sumaDirecta(int);
};

int Funciones::sumaIterativa(int x){
  int suma = 0; //inicio de la variable que juntará los valores que se suman
  if (x==0){
    return 0; //si el valor de x es igual a 0, no se realizarán sumas y sólo aparecerá el 0 que indicamos aquí
  };
  for (int i=1; i<=x; i++)
    suma = suma + i;
  return suma; //recibimos el valor de suma
};

int Funciones::sumaRecursiva(int x){
  if (x<=0){
    return 0;
  }
  else{
    return x+sumaRecursiva(x-1); // "la suma recursiva es como la escena de sueño en Inception" -el profe. Llamamos a la suma a repetirse consigo misma (pero con límite)
  };
};

int Funciones::sumaDirecta(int x){
  if(x==0){
    return 0;
  }
  else{
    return (x*(x+1))/2; //usamos sumas de Gauss para recibir nuestro resultado
  };
};
