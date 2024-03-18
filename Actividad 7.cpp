/******************************************************************************
//actividad 7
Nombre: Kaleb Alejandro Falcon Marquez
Fecha: 08/03/2024
Programa: Operaciones de conjuntos
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion: Operaciones con conjuntos de Unión, Intersección, Diferencia y complemento.
*******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

std::set<std::string> conjunto1;
std::set<std::string> conjunto2;
int tamannoC1 = 0;
int tamannoC2 = 0;
int opcion;

void ingresar(){
    string elemento;
    cout << "Ingrese valores para el conjunto 1:" << endl;
    for (int i = 0; i < tamannoC1; ++i) {
        cout << "Elemento " << i+1 << " ";
        cin >> elemento;
        conjunto1.insert(elemento);
    }
    cout << endl;
    cout << "Ingrese valores para el conjunto 2:" << endl;
    for (int i = 0; i < tamannoC2; ++i) {
        cout << "Elemento " << i+1 << " ";
        cin >> elemento;
        conjunto2.insert(elemento);
    }
    cout << endl;
}

void mostrar(){
    cout << "Tus conjuntos son:" << endl;
    cout << "Conjunto 1: { ";
    for (const auto& elem : conjunto1) {
        cout << elem << " ";
    }
    cout << "}" << endl;

    cout << "Conjunto 2: { ";
    for (const auto& elem : conjunto2) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

void editar(){
    string elementoRemplazar;
    string elementoNuevo;

    cout << "\n\t\t¿Que conjunto desea editar?." << endl;
    cout << "\t1-Conjunto 1." << endl;
    cout << "\t2-Conjunto 2." << endl;

    cout << "\n\tIngrese la opcion del metodo que desea usar: ";
    cin >> opcion;

    switch (opcion){
        case 1:
        cout << endl;
        cout << "Conjunto 1: { ";
        for (const auto& elem : conjunto1) {
            cout << elem << " ";
        }
        cout << "}" << endl;

        cout << "Ingrese el elemento que desea editar en el conjunto 1: ";
        cin >> elementoRemplazar;
        cout << "Ingrese el nuevo valor del elemento: ";
        cin >> elementoNuevo;

        if (conjunto1.erase(elementoRemplazar)) {
            conjunto1.insert(elementoNuevo);
            cout << "Elemento editado correctamente en el conjunto 1." << endl;
        }
        else {
            cout << "El elemento \"" << elementoRemplazar << "\" no existe en el conjunto 1, intentelo nuevamente." << endl;
        }
        break;

        case 2:
        cout << endl;
        cout << "Conjunto 2: { ";
        for (const auto& elem : conjunto2) {
            cout << elem << " ";
        }
        cout << "}" << endl;

        cout << "Ingrese el elemento que desea editar en el conjunto 2: ";
        cin >> elementoRemplazar;
        cout << "Ingrese el nuevo valor del elemento: ";
        cin >> elementoNuevo;

        if (conjunto2.erase(elementoRemplazar)) {
            conjunto2.insert(elementoNuevo);
            cout << "Elemento editado correctamente en el conjunto 2." << endl;
        }
        else {
            cout << "El elemento \"" << elementoRemplazar << "\" no existe en el conjunto 2, intentelo nuevamente." << endl;
        }
        break;
    }
}

void borrar(){
    string elementoB;
    cout << "\n\t\t¿De qué conjunto desea borrar un elemento?" << endl;
    cout << "\t1-Conjunto 1." << endl;
    cout << "\t2-Conjunto 2." << endl;

    cout << "\n\tIngrese la opción del conjunto en el que desea borrar un elemento: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
        cout << endl;
        cout << "Conjunto 1: { ";
        for (const auto& elem : conjunto1) {
            cout << elem << " ";
        }
        cout << "}" << endl;

        cout << "Ingrese el elemento que desea borrar del conjunto 1: ";
        cin >> elementoB;
        if (conjunto1.erase(elementoB)) {
            cout << "Elemento \"" << elementoB << "\" borrado correctamente del conjunto 1." << endl;
        }
        else {
            cout << "El elemento \"" << elementoB << "\" no existe en el conjunto 1." << endl;
        }
        break;

        case 2:
        cout << endl;
        cout << "Conjunto 2: { ";
        for (const auto& elem : conjunto2) {
            cout << elem << " ";
        }
        cout << "}" << endl;

        cout << "Ingrese el elemento que desea borrar del conjunto 2: ";
        cin >> elementoB;
        if (conjunto2.erase(elementoB)) {
            cout << "Elemento \"" << elementoB << "\" borrado correctamente del conjunto 2." << endl;
        }
        else {
            cout << "El elemento \"" << elementoB << "\" no existe en el conjunto 2." << endl;
        }
        break;
    }
}

void vaciar(){
    conjunto1.clear();
    conjunto2.clear();
    cout << "Conjuntos vaciados correctamente." << endl;
}

void operaciones(){
    cout << "\n\t¿Que operacion de conjuntos utilizara?." << endl;
    cout << "\t1. Union." << endl;
    cout << "\t2. Intersección." << endl;
    cout << "\t3. Diferencia." << endl;
    cout << "\t4. Complemento." << endl;
    cout << "\t5. Volver al menu." << endl;

    cout << "\n\tIngrese la opcion del metodo que desea usar: ";
    cin >> opcion;

    switch (opcion){
        case 1:
        cout << "la union de sus conjuntos es:" << endl;
        for (const auto& elem : conjunto1) {
            cout << elem << " ";
        }
        for (const auto& elem : conjunto2) {
            if (conjunto1.find(elem) == conjunto1.end()) {
                cout << elem << " ";
            }
        }
        cout << endl; 
        operaciones();
        break;

        case 2:
        cout << "la intersección de sus conjuntos es:" << endl;
        for (const auto& elem : conjunto1) {
            if (conjunto2.find(elem) != conjunto2.end()) {
                cout << elem << " ";
            }
        }
        cout << endl;
        operaciones();
        break;

        case 3:
        cout << "la diferencia de sus conjuntos es:" << endl;
        for (const auto& elem : conjunto1) {
            if (conjunto2.find(elem) == conjunto2.end()) {
                cout << elem << " ";
            }
        }
        operaciones();
        break;

        case 4:
        cout << "El completo de sus conjuntos es:" << endl;
        for (const auto& elem : conjunto2) {
            if (conjunto1.find(elem) == conjunto1.end()) {
                cout << elem << " ";
            }
        }
        operaciones();
        break;
        
        case 5:
        cout << "Retorno al menu." << endl;
        break;
        
    }
}

void menu(){
    cout << "\n\t\tBienvenido." << endl;
    cout << "\t1. Ingresar valores a los conjuntos." << endl;
    cout << "\t2. Mostrar los valores de los conjuntos." << endl;
    cout << "\t3. Editar valores de los conjuntos." << endl;
    cout << "\t4. Borrar valores de los conjuntos." << endl;
    cout << "\t5. Vaciar por completo los conjutos." << endl;
    cout << "\t6. Operaciones con los conjutos." << endl;
    cout << "\t7. Salir." << endl;

    cout << "\n\tIngrese la opcion del metodo que desea usar: ";
    cin >> opcion;

    switch (opcion){
        case 1:
        ingresar();
        menu();
        break;

        case 2:
        mostrar();
        menu();
        break;

        case 3:
        editar();
        menu();
        break;

        case 4:
        borrar();
        menu();
        break;

        case 5:
        vaciar();
        menu();
        break;

        case 6:
        operaciones();
        menu();
        break;

        case 7:
        cout << "Programa finalizado.";
        break;
    }
}

int main(){
    do{
    cout << "ingrese el tamaño de su primer conjunto: " << endl;
    cin >> tamannoC1;
    }while(tamannoC1 < 5);

    do{
    cout << "ingrese el tamaño de su segundo conjunto: " << endl;
    cin >> tamannoC2;
    }while(tamannoC2 < 5);

    menu();

    return 0;
}