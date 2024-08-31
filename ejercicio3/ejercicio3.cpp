#include <iostream>

using namespace std;



/*
Hacer un programa que solicite al usuario 10 números y luego muestre primero los números positivos y luego los negativos.
El programa debe crear dos arrays dinámicos con la cantidad exacta en cada caso: uno para almacenar los números positivos y otro para los números negativos. 

*/
void cargarListaYContadores(int totalList[], int size, int *contadorPos, int *contadorNeg);
void cargarPositivos(int totalList[], int sizeTotal, int arrPos[], int totalPos);
void cargarNegativos(int totalList[], int sizeTotal, int arrNeg[], int totalNeg);
void mostrarArray(int arr[], int size);

int main(){
    int totalList[10], *arrPos=nullptr, *arrNeg=nullptr, contadorPos = 0, contadorNeg = 0;

    cargarListaYContadores(totalList, 10, &contadorPos, &contadorNeg);

   cout << endl << contadorPos << " " << contadorNeg;
    arrPos = new int[contadorPos];

    if(arrPos == nullptr){
        cout << "NO se pudo entregar la memoria";
        exit(1);
    }

    arrNeg = new int[contadorNeg];

    if(arrNeg == nullptr){
        cout << "NO se pudo entregar la memoria";
        exit(1);
    }

    cargarPositivos(totalList, 10, arrPos, contadorPos);
    cargarNegativos(totalList, 10, arrNeg, contadorNeg);

    cout << "********CONTADOR POSITIVOS********" << endl;
    mostrarArray(arrPos, contadorPos);
    cout << "********CONTADOR NEGATIVOS********" << endl;
    mostrarArray(arrNeg, contadorNeg);



    return 0;
}

void cargarListaYContadores(int totalList[], int size, int *contadorPos, int *contadorNeg){
    int n;

    cout << "Ingresa los numeros para completar la lista " << endl;
    for(int i = 0; i < size; i++){
        cout << "Ingresa el numero para la posicion " << i + 1 << " de la lista: ";
        cin >> n;
        if(n > 0){
            //esto va entre parenetesis porque sino *var++ es = a var++, e incrementa
            //la direccion de memoria con aritmetica de punteros, no el valor en si
            (*contadorPos)++;
        } else {

            (*contadorNeg)++;
        }


        totalList[i] = n;
    }
        cout << contadorPos << "     "  << contadorNeg << endl;
        cout << *contadorPos << "     "  << *contadorNeg << endl;
}

void cargarPositivos(int totalList[], int sizeTotal, int arrPos[], int totalPos){
    int currentIndex = 0;
    for(int i = 0; i < sizeTotal; i++){
        if(totalList[i] > 0){
            arrPos[currentIndex] = totalList[i];
            currentIndex++;
        }   
    }
}

void cargarNegativos(int totalList[], int sizeTotal, int arrNeg[], int totalNeg){
    int currentIndex = 0;
    for(int i = 0; i < sizeTotal; i++){
        if(totalList[i] < 0){
            arrNeg[currentIndex] = totalList[i];
            currentIndex++;
        }   
    }
}


void mostrarArray(int arr[], int sizeArray){
    for(int i = 0; i < sizeArray; i++){
        cout << "El numero de la posicion " << i+1 << " de la lista es " << arr[i] << endl;
    }
}