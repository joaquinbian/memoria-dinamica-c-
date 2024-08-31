#include <iostream>


using namespace std;

/*
Crear un programa que contenga un menú con las siguientes opciones:
1- Cargar Vector: El programa debe solicitar al usuario la cantidad de elementos que va a cargar, 
posteriormente se solicitara cuales son dichos números para almacenarlos en un vector utilizando asignación dinámica de memoria.
2- Mostrar Vector: En caso de tener cargado el vector, debe mostrarlo por pantalla.
3- Salir: Sale del programa (no olvidar liberar la memoria)
Pista: Recordar que se puede inicializar un puntero con el valor nullptr
 */


int mostrarMenu();
int pedirTamanioArr();
bool deseasContinuar();
void cargarVector(int arr[], int size);
void mostrarVector(int arr[], int size);

int main(){
    int opcion, size, *arr = nullptr;
    bool continuar;

    opcion = mostrarMenu();
    do {
        
        if(opcion == 1){
            if(arr != nullptr){
                delete []arr;
            }
            size = pedirTamanioArr();
            arr = new int[size];
            cargarVector(arr, size);
        } else if(opcion == 2){
            if(arr != nullptr){
                mostrarVector(arr, size);
            } else {
                cout << "El vector no ha sido cargado" << endl;
            }

        } else if(opcion == 3){
            continuar = false;
            break;
        }

        continuar = deseasContinuar();

        if(continuar) {
            opcion = mostrarMenu();
        }

    }while(continuar);
     
    cout << "has salido del programa" << endl;
    delete []arr;
    
    return 0;
}


int mostrarMenu(){
    int opcion;

    do{
        cout << "*****************************************************"<< endl;
        cout << "Bienvenido al programa donde podras cargar un vector :)"<< endl;
        cout << "*****************************************************"<< endl;

        cout << "Elige una opcion: " << endl;
        cout << "1- Cargar Vector " << endl;
        cout << "2- Mostrar Vector " << endl;
        cout << "3- Salir del programa " << endl;

        cin >> opcion;

    }while(opcion < 1 && opcion > 3);

    return opcion;
}


int pedirTamanioArr(){
    int size;

    do {
        cout << "Ingrese el tamanio de su lista de enteros: ";
        cin >> size;
    }while(size < 1);

    return size;
}

void cargarVector(int arr[], int sizeArray){
    int n;
    for(int i = 0; i < sizeArray; i++){
        cout << "Ingrese el numero de la posicion " << i+1 << " de la lista: ";
        cin >> n;
        arr[i] = n;
    }
}

void mostrarVector(int arr[], int sizeArray){
    for(int i = 0; i < sizeArray; i++){
        cout << "El numero de la posicion " << i+1 << " de la lista es " << arr[i] << endl;
    }
}


bool deseasContinuar(){
    string res;
    bool continuar;
    

    do {
        cout << "Deseas continuar con el programa? (S/N): ";
        cin >> res; 
    }while((res != "S" && res != "s" )&&(res != "N" && res != "n"));

    if((res == "S"  || res == "s" )){
        return true;
    } else {
        return false;
    }
    
}

