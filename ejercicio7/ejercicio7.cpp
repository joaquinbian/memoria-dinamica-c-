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
int mostrarMenu();

string *cargarLibros(int tam);
string *cargarVectorStr(int tam);
string pedirLibro();

void cargarTiempoLectura(string libro, string libros[], int tiemposLectura[], int tam);
void ordernarLibros(string libros[], int tiempoLectura[], int tam);
void mostrarLibros(string v[], int tam);
void mostrarLibrosYTiempoLectura(string libros[], int tiempoLectura[], int tam);
void copyArrayInt(int v1[], int v2[], int tam);
void copyArrayStr(string v1[], string v2[], int tam);

int main(){
    int opcion, cantidadLibros, *tiempoLectura = nullptr;
    string libro;
    
    cantidadLibros = getCantidadCargaLibros();    
    string *libros = cargarLibros(cantidadLibros);

    opcion = mostrarMenu();
    do{
        if(opcion == 1){
            mostrarLibros(libros, cantidadLibros);
        } else if(opcion == 2) {
                //punto b
            if(tiempoLectura == nullptr){
                tiempoLectura = cargarVectorInt(cantidadLibros);
            } 
            libro = pedirLibro();
            cargarTiempoLectura(libro, libros, tiempoLectura, cantidadLibros);
        } else if(opcion == 3) {
            
            //punto 3
            ordernarLibros(libros, tiempoLectura, cantidadLibros);
        } else if(opcion == 4){
            cout << "gracias por haber usado la BIBLIOTECA" << endl;
            return 1;
        } else {
            cout << "Elige una opcion valida (1-4)" << endl;
        }

        opcion = mostrarMenu();    
    }while(opcion != 4);
  


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
        cout << "Ingrese el nombre del libro " << i + 1 << ": ";
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
        cout << "Libro " << i + 1 << " -> " << libros[i] << endl;
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



string *cargarVectorStr(int tam){
    string *v = nullptr;
    v = new string[tam];
    if(v == nullptr){
        cout << "No se pudo asignar memoria";
        exit(-1);
    }

    return v;
}


int getCantidadHorasLibro(string libro){
    int n;

    do{
        cout << "Ingrese los minutos de lectura para el libro " << libro << " ";
        cin  >> n;
    } while(n < 0);

    return n;
}

void ordernarLibros(string libros[], int tiempoLectura[], int tam){
    int *copyTiempoLectura = nullptr;
    string *copyLibros = nullptr;
    
    copyTiempoLectura = cargarVectorInt(tam);
    copyLibros = cargarVectorStr(tam);

    copyArrayInt(tiempoLectura, copyTiempoLectura, tam);
    copyArrayStr(libros, copyLibros, tam);

    for(int i = 0; i < tam; i++){
        for(int j = i + 1; j < tam; j++){
            int auxInt;
            string auxStr;
            if(copyTiempoLectura[i] < copyTiempoLectura[j]){
                auxInt = copyTiempoLectura[i];
                auxStr = copyLibros[i];
                copyTiempoLectura[i] = copyTiempoLectura[j];
                copyLibros[i] = copyLibros[j];
                copyTiempoLectura[j] = auxInt;
                copyLibros[j] = auxStr;
            }
        }
    }

    mostrarLibrosYTiempoLectura(copyLibros, copyTiempoLectura, tam);


    delete [] copyTiempoLectura;
    delete [] copyLibros;
}


void copyArrayInt(int v1[], int v2[], int tam){
    for(int i = 0; i < tam; i++){
        v2[i] = v1[i];
    }
}

void copyArrayStr(string v1[], string v2[], int tam){
    for(int i = 0; i < tam; i++){
        v2[i] = v1[i];
    }
}

void mostrarLibrosYTiempoLectura(string libros[], int tiempoLectura[], int tam){
    for(int i = 0; i < tam; i++){
        cout << "Libro N" << i+1 << " " << libros[i] << " ";
        cout << "Tiempo: " << tiempoLectura[i] << " minutos";
        cout << endl;
    }
}

int mostrarMenu(){
    int n;
    cout << endl;
    cout << "~~~~~~~~~~ Biblioteca ~~~~~~~~~~" << endl;
    cout << "Ingrese el numero del menu para indicar que accion quieres realizar" << endl;

    do {    
        //1
        cout << "1- Listado: Debe listar los libros en el orden en que fueron cargados." << endl;
        //2
        cout << "2- Tiempo de lectura: Se solicita el nombre del libro. Si no existe debe mostrar un mensaje aclaratorio. ";
        cout << "Si el libro existe, ingresar la cantidad de minutos que le llevó su lectura" << endl;
        //3
        cout << "3- Ranking: Mostrar los libros ordenados por tiempo de lectura de Mayor a Menor." << endl;
        //4        
        cout << "4- Salir: el programa debe salir del programa" << endl;

        cin >> n;
    }while(n < 0 && n > 4);

    return n;
}