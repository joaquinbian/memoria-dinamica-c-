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
int getCantidadHorasLibro(string libro);
int *cargarVectorInt(int tam);
string *cargarLibros(int tam);
string pedirLibro();
void cargarTiempoLectura(string libro, string libros[], int tiemposLectura[], int tam);
void ordernarLibros(string libros[], int tiempoLectura[]);
void mostrarLibros(string v[], int tam);

int main(){
    int opcion, cantidadLibros, *tiempoLectura = nullptr;
    string libro;
    
    cantidadLibros = getCantidadCargaLibros();    
    string *libros = cargarLibros(cantidadLibros);
    //punto a 
    mostrarLibros(libros, cantidadLibros);
    //punto b
    if(tiempoLectura == nullptr){
        cout << "no hay vector";
        tiempoLectura = cargarVectorInt(cantidadLibros);
    } 
    libro = pedirLibro();
    cargarTiempoLectura(libro, libros, tiempoLectura, cantidadLibros);
    
    //punto 3
    ordernarLibros(libros, tiempoLectura);
    


    delete [] libros;
    delete [] tiempoLectura;
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

void cargarTiempoLectura(string libro, string libros[], int tiemposLectura[], int tam){
    
    for(int i = 0; i < tam; i++){
        if(libro == libros[i]){
            tiemposLectura[i] = getCantidadHorasLibro(libro);
            return;
        }
    }

    cout << "No se ha encontrado el libro " << endl;;
}

string pedirLibro(){
    string n;
    cout << "Ingresa el nombre de tu libro que quieres registrar tiempo: ";
    cin >> n;


    return n;
}

void mostrarLibros(string libros[], int tam){
    for(int i = 0; i < tam; i++){
        cout << "Libro " << i + 1 << " -> " << libros[i];
    }
}

int *cargarVectorInt(int tam){
    int *v;
    v = new int[tam];
    if(v == nullptr){
        cout << "NO se pudo asignar memoria";
        exit(-1);
    }
    return v;
}


int getCantidadHorasLibro(string libro){
    int n;

    do{
        cout << "Ingrese las horas de lectura para el libro " << libro;
        cin  >> n;
    } while(n > 0);

    return n;
}

void ordernarLibros(string libros[], int tiempoLectura[]){}
