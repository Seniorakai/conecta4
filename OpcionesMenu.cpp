/*
Nombre:
Autor:
Fecha:
Descripción:
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <limits>
#include "MenuPrincipalJuego.h"
#include "OpcionesMenu.h"
#include "funciones.h"
#include "funcionesJuego.h"
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define TAM_COL 10
#define TAM_FIL 10
#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

using namespace std;


//**************************************************************************************************
void escribirInstrucciones(){

    system("cls");
    ifstream instrucciones;
    string texto;

    instrucciones.open("instrucciones.txt", ios::in); //para abrir el archivo en modo lectura

    if (instrucciones.fail()){
        cout << "No se pudo abrir el archivo.";
        exit(1);
    }
    while (!instrucciones.eof()){
        getline(instrucciones,texto);
        cout << "\t" << texto << endl;
    }

    instrucciones.close();

}
//**************************************************************************************************

//**************************************************************************************************
void escribirCreditos()
{
    system("cls");

    ifstream creditos;
    string texto;

    creditos.open("creditos.txt", ios::in); //Se está abriendo el archivo.

    if(creditos.fail()){
        cout << "No se pudo abrir el archivo.";
        exit(1);
    }

    while(!creditos.eof()){
        getline(creditos,texto);
        cout << "\t\t" << texto << endl;
    }

    creditos.close();
}
//**************************************************************************************************

//**************************************************************************************************
void lectura(){   // es solo un titulo
    estableceColor(16,6);
    ifstream archivo;
    string texto;

    archivo.open("programacion.txt", ios::in); //para abrir el archivo en modo lectura
    if (archivo.fail()){
        cout << "No se pudo abrir el archivo.";
        exit(1);
    }
    while (!archivo.eof()){
        getline(archivo,texto);
        cout << texto<< endl;
    }
    archivo.close();
}
//**************************************************************************************************

//**************************************************************************************************
void cargando()
{

    cout << endl<< endl;
    //system ("color 2f");
   // system ("color 0e");
    estableceColor(16,6);
    char barrita = 219;
    cout << endl << endl<< endl<< "\t\t\t\t   Cargando, por favor espere... ";
    cout << "\n\n\n";
    cout << "\t\t\t\t\t";

    for (int i = 0 ; i <= 22 ; i++){
        cout << barrita;
        Sleep(75);
    }
    system ("cls");
}
//**************************************************************************************************
