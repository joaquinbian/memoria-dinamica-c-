#include <iostream>

using namespace std;

/*
Escribe un programa que solicite al usuario ingresar una lista de 10 números enteros. 
Luego, el programa debe mostrar los números pares distintos que se ingresaron. 
Para resolver este ejercicio, deberás implementar una función que reciba un vector de enteros y su tamaño, 
y que devuelva un puntero a un vector dinámico que contenga solo los números pares distintos del vector recibido.



 */

void cargarNumeros(int v[], int tam);
void mostrarNumeros(int v[], int tam);
int *cargarNumerosPares(int v[], int tam);
bool checkNumIsInList(int n, int v[], int tam);


int main(){
    const int CANTIDAD = 10;
    int *vectorPares = nullptr, vector[CANTIDAD];

    cargarNumeros(vector, CANTIDAD);

    vectorPares = cargarNumerosPares(vector, CANTIDAD);


    mostrarNumeros(vectorPares, CANTIDAD);




    return 0;
}



void cargarNumeros(int v[], int tam){
    int n;
    cout << "Ingrese " << tam << " numeros" << endl;


    for(int i = 0; i < tam; i++){
        cout << "Ingrese el numero " << i + 1 << " ";
        cin >> n;
        v[i] = n;  
    }
}

int *cargarNumerosPares(int v[], int tam){
    int index = 0, *vPares = nullptr;

    vPares = new int[tam];

    if(vPares == nullptr){
        cout << "No se pudo recuperar memoria";
        exit(-1);
    }

    for(int i = 0; i < tam; i++){
        //cout << v[i] << " is in list " << checkNumIsInList(v[i], v, tam) << endl;
        if(v[i] % 2 == 0 && !(checkNumIsInList(v[i], vPares, tam))){
            vPares[index] = v[i];
            index++;
        }
    }

    return vPares;
}


bool checkNumIsInList(int n, int v[], int tam){
    
    for(int i = 0; i < tam; i++){
        if(v[i] == n) {
            return true;
        }
    }

    return false;
}

void mostrarNumeros(int v[], int tam){
    for(int i = 0; i < tam; i++){
        if(v[i] > 0){
            cout << "Numero " << i + 1 << " -> " << v[i] << endl;
        }
    }
}