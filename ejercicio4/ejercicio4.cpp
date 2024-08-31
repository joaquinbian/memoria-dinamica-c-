#include <iostream>

using namespace std;


/*
Hacer una función que reciba un vector de enteros y su tamaño y devuelva la cantidad de números distintos que se repiten en el vector.
*/

int checkRepetidos(int arr[], int size);
bool checkNumIsInList(int n, int arr[], int size);

int main(){

    const int CANTIDAD = 10;
    int contador, arr[CANTIDAD] = {1,1,2,3,4,1,6,7,1,9};

    contador = checkRepetidos(arr, CANTIDAD);

    cout << "La cantidad de numeros repetidos es " << contador << endl; 

    return 0; 
}

int checkRepetidos(int arr[], int size){
    int contador, checks[size];

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] == arr[j] && !(checkNumIsInList(arr[j], checks, size))){
                checks[i] = arr[i];
                contador++;
            }
        }
    }

    return contador;
    
}

bool checkNumIsInList(int n, int arr[], int size){
    for(int i = 0; i < size; i++){
        if(n == arr[i]){
            return true;
        }
    }

    return false;
}


