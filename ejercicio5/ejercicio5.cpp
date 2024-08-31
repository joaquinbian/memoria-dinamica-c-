#include <iostream>

using namespace std;

/*
Hacer una función que reciba un vector de enteros y su tamaño y luego muestre el vector ordenado de forma ascendente
tener en cuenta que el vector enviado como argumento no debe ser modificado.
 */


void orderListAsc(int arr[], int size);
void copyArr(int arr[], int aux[], int size);
void mostrarVector(int arr[], int size);

int main(){
    const int CANTIDAD = 10;
    int arr[CANTIDAD] = {1,1,2,3,4,1,6,7,1,9};

    cout << "********************** ARRAY MODOFICADOO ************************" << endl;
    orderListAsc(arr, CANTIDAD);

    cout << endl << endl;
    cout << "********************** ARRAY SIN MODIFICAR ************************" << endl;
    mostrarVector(arr, CANTIDAD);

    return 0;
}

void orderListAsc(int arr[], int size){
    int aux, checks[size];
    
    copyArr(arr, checks, size);

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(checks[i] < checks[j]){
                aux = checks[i];
                checks[i] = checks[j];
                checks[j] = aux;
            }
        }
    }

    mostrarVector(checks, size);
}
void copyArr(int arr[], int aux[], int size){
    for(int i = 0; i < size; i++){
        aux[i] = arr[i];
    }
}

void mostrarVector(int arr[], int sizeArray){
    for(int i = 0; i < sizeArray; i++){
        cout << "El numero de la posicion " << i+1 << " de la lista es " << arr[i] << endl;
    }
}
