#include <iostream>

using namespace std;

/*
Escribe un programa que solicite al usuario el tamaño de un array de enteros, lo cree dinámicamente utilizando new, 
el usuario debe poder cargar el array y mostrarlo, y luego libere la memoria con delete

 */



void cargarArray(int arr[], int size);
void mostrarArray(int arr[], int size);
int main(){
    int sizeArray, *arr;
    cout << "Ingrese cuantos elementos quiere tener en la lista: ";
    cin >> sizeArray;

    arr = new int[sizeArray];

    if(arr == nullptr){
        cout << "No se pudo asignar memoria";
        exit(1);
    }


    cargarArray(arr, sizeArray);
    mostrarArray(arr, sizeArray);



    delete []arr;
    return 0;
}
void cargarArray(int arr[], int sizeArray){
    int n;
    for(int i = 0; i < sizeArray; i++){
        cout << "Ingrese el numero de la posicion " << i+1 << "de la lista: ";
        cin >> n;
        arr[i] = n;
    }
}

void mostrarArray(int arr[], int sizeArray){
    for(int i = 0; i < sizeArray; i++){
        cout << "El numero de la posicion " << i+1 << " de la lista es " << arr[i] << endl;
    }
}