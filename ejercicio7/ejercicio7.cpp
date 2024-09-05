#include <iostream>

using namespace std;


/*
Escribe un programa que simule la gestión de un club de lectura. 
El programa debe solicitar al usuario la cantidad de libros que desea cargar y posteriormente pedir los nombres de dichos libros. 
Una vez cargados los libros se debe mostrar un menú  con las siguientes opciones:

1- Listado: Debe listar los libros en el orden en que fueron cargados.
2- Tiempo de lectura: Se solicita el nombre del libro. Si no existe debe mostrar un mensaje aclaratorio. Si el libro existe, 
    ingresar la cantidad de minutos que le llevó su lectura.
3- Ranking: Mostrar los libros ordenados por tiempo de lectura de Mayor a Menor.
4- Salir: el programa debe salir del programa

 */

int getCantidadCargaLibros();
string *cargarLibros(int tam);
void cargarTiempoLectura(string libros[], int tiemposLectura[], int tam);

int main(){

    int cantidadLibros = getCantidadCargaLibros();
    
    string *libros = cargarLibros(cantidadLibros);
    int *tiempoLectura = cargarTiempoLectura(cantidadLibros);
    

    return 0;
}

int getCantidadCargaLibros(){
    int n;
    do {
        cout << "Cuantos libros deseas registrar? ";
        cin >> n;
    } while(n < 0);

    return n;
}

string *cargarLibros(int tam){
    string *v, libro;
    cout << "*********** Cargar libros ***********" << endl;
    v = new string[tam];
    if(v == nullptr){
        cout << "no se pudo asignar memoria";
        exit(-1);
    }

    for(int i = 0; i < tam; i++){
        cout << "Ingrese el nombre del libro " << i + 1 << ':';
        cin >> libro;
        v[i] = libro;
    }

    return v;
}

int *cargarTiempoLectura(int tam){

}