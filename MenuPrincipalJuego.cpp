/*
Nombre:
Autor:
Fecha:
Descripción:
*/


#include <iostream>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "MenuPrincipalJuego.h"
#include "OpcionesMenu.h"
#include "funciones.h"
#include "funcionesJuego.h"


using namespace std;

void menu_principal(){


    int xi=10, yi=10, z=0, player=1, m=1, n=0;
    int t1=6, t2=6, t3=6,t4=6,t5=6,t6=6,t7=6;
    bool repite = true;//Con ésta variable se va a controlar el ciclo. El bucle que se implementa más adelante.
    int opcion = 0, y = 11;


    do{
        estableceColor(16,6);
        system("cls");
        ifstream titulo; //Título del menú:
        string texto;
        titulo.open("tituloJuego.txt", ios::in);//Para abrir el archivo en modo lectura:
        if(titulo.fail()){
            cout << "No se pudo abrir el archivo.";
            exit(1);
        }
        while(!titulo.eof()){
            getline(titulo,texto);
            cout << "\t" << texto << endl;
        }
        titulo.close();
        //Las opciones del menú:#define KEY_UP 72

        cout << "\n\t\t       JUGAR\n"<<endl;
        cout << "\n\t\t   INSTRUCCIONES\n"<<endl;
        cout << "\n\t\t      CREDITOS\n"<<endl;
        cout << "\n\t\t       SALIR\n"<<endl;

        dibujacuadro(18,y);

        //Alternativas en donde se implementa el switch:
        switch(int z=getch()){

        case KEY_UP:
            opcion--; // resta uno a la variable(1-4)
            y -= 3;       //cambia la coordenada para el dibujo
            if(opcion > 3) opcion = 0; // segura que solo estén las opciones del 1 al 4
            if(opcion < 0) opcion = 3;
            if (y < 11) y = 20; //asegura que las coordenadas estén dentro el alcanze del dibujo
            break;

        case KEY_DOWN:
            opcion++; // suma uno a la variable(1-4)
            y += 3;       //cambia la coordenada para el dibujo
            if(opcion > 3) opcion = 0; // segura que solo esten las opciones del 1 al 4
            if(opcion < 0) opcion = 3;
            if (y > 20) y = 11;//asegura que las coordenadas estén dentro el alcanze del dibujo
            break;
        case ENTER: // al presionar el enter revisa la variable opción y selecciona lo siguiente
            switch (opcion){
                case 0://entrada a juego
                    system ("cls");
                    cargando();
                    intento(n, t1, t2, t3, t4, t5, t6, t7,xi, yi, player);
                    break;
                case 1: //entra a instrucciones
                    escribirInstrucciones();
                    system("pause>nul");
                    break;
                case 2: //entra a créditos
                    escribirCreditos();
                    system("pause>nul");
                    break;
                case 3:     // cierra el juego
                    exit(0);
            }

        }

    }while(repite);
}
//**************************************************************************************************
