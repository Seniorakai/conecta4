/*
Nombre:
Autor:
Fecha:
Descripción:
*/


#include <iostream>
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

enum {ESPACIO=32,BLOQUE = 219,PIXABAJO,PIXARRIBA=223};

using namespace std;

//**************************************************************************************************
void gotoxy(int x,int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x-1,y-1};
    SetConsoleCursorPosition(handle,coord);
}
//**************************************************************************************************

//**************************************************************************************************
void dibujacuadro (int x,int y){
    gotoxy(x,y);
    //dibuja marco arriba
    cout<< (char)BLOQUE;
    for (int i = 0 ; i < 15 ; i++) cout << (char)PIXARRIBA;
    cout << (char)BLOQUE;

    //dibuja marco medio
    gotoxy(x,y+1); //salto de linea sin sobrescribir
    cout << (char)BLOQUE;
    gotoxy(x+16,y+1);   //salto de linea sin sobrescribir
    cout << (char)BLOQUE;

    //dibuja marco bajo
    gotoxy(x,y+2);  //salto de linea sin sobrescribir
    cout<< (char)BLOQUE;
    for (int i = 0 ; i < 15 ; i++) cout << (char)PIXABAJO;
    cout << (char)BLOQUE;
}
//**************************************************************************************************

//**************************************************************************************************
void REINICIAR(char A[TAM_FIL][TAM_COL], int &t1, int &t2, int &t3, int &t4, int &t5, int &t6, int &t7, int &xi, int &yi, int& n){
    crearArreglo(A);
    n = 1;
    system("cls");
    t1 = t2 = t3 = t4 = t5 = t6 = t7 = 6;
    xi = 10;
    yi = 10;
    imprime_tablero(xi,yi);
}
//**************************************************************************************************

//**************************************************************************************************
void check_columna (int& q, int p, int& xi,int& yi){

    if (q==1) xi=12;
    if (q==2) xi=23;
    if (q==3) xi=34;
    if (q==4) xi=45;
    if (q==5) xi=56;
    if (q==6) xi=67;
    if (q==7) xi=78;

    //if (m==0) yi=41;
    if (p==6) yi=36;
    if (p==5) yi=31;
    if (p==4) yi=26;
    if (p==3) yi=21;
    if (p==2) yi=16;
    if (p==1) yi=11;
}
//**************************************************************************************************

//**************************************************************************************************
void estableceColor( int  colorFondo, int colorTexto) // 7 es gris ,0 negro, 4 rojo, 16 blanco
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo*16 + colorTexto);
}
/*      0 = Negro       8 = Gris
        1 = Azul        9 = Azul claro
        2 = Verde       A = Verde claro
        3 = Aguamarina  B = Aguamarina claro
        4 = Rojo        C = Rojo claro
        5 = Púrpura     D = Púrpura claro
        6 = Amarillo    E = Amarillo claro
        7 = Blanco      F = Blanco brillante*/


        ///Movimiento de cursor
//**************************************************************************************************

//**************************************************************************************************
void imprime_tablero(int& xi,int& yi){


    teclas_juego();

    int borde=219,sombra1=176,sombra2=177;
    gotoxy(10,10);
    //////////   Interno
    estableceColor(0,3);
    for (int i =0 ; i!=6 ; i++){                                                         // lineas horizontales
        for (int i=0; i!=79; i++) cout<< (char)borde;                                   /// primera horizontal arriba
            gotoxy(xi,yi+=1);
        for (int i=0; i!= 4; i++){                                                     /// entremedio
            for (int i=0 ; i !=8; i++) cout<<(char)borde<<(char)borde<<"         ";   /// 8 lineas verticales
            gotoxy(xi,yi+=1);                                                       ///salto de linea repecto a X
        }
    }
    for (int i=0; i!=79; i++) cout<< (char)borde;                                       /// ultima horizontal pared arriba

    //// Externo
    yi=10-1;
    gotoxy(10,10-1);
    estableceColor(3,0);
    cout<< (char)BLOQUE;    //top
    for (int i=0; i< 77 ; i++) cout<<(char)PIXARRIBA;
    cout << (char)BLOQUE;   //top

    for (int i=0; i< 31;i++){
      gotoxy(10,yi+=1);
      cout<< (char)BLOQUE;
      gotoxy(10+78,yi);
      cout<< (char)BLOQUE;

    }


    gotoxy(10,10+31);
    estableceColor(3,0);
    cout<< (char)BLOQUE;    //top
    for (int i=0; i< 77 ; i++) cout<<(char)PIXABAJO;
    cout << (char)BLOQUE;   //top



    /*estableceColor(0,15);
    gotoxy(10+80,10+10);
    cout<< "Recuerda!"<< endl;
    gotoxy(10+80,10+11);
    cout<< "Las teclas para jugar"<< endl;
    gotoxy(10+80,10+12);
    cout<< "<==   y   ==>";
    gotoxy(10+80,10+13);
    cout<< "mueve hacia los lados";
    gotoxy(10+80,10+14);
      cout<< (char)186;
    gotoxy(10+80,10+15);
    cout<< "V   baja la ficha";*/
}
//**************************************************************************************************

//**************************************************************************************************
void imprime_ficha(int xi,int yi, int p){

    gotoxy(xi,yi);
    if (p==1) {
         estableceColor(12,0);

         cout<< (char)201;    //top
         for (int i=0; i< 7 ; i++) cout<<(char)205;
         cout << (char)187;   //top
         estableceColor(0,12);

         for(int i=0; i<2; i++){ //center
            gotoxy(xi,yi+=1);
            estableceColor(12,0);
            cout << (char)186;
            estableceColor(0,12);
            for(int i =0 ; i<7 ; i++){
                cout<<(char)219;}
            estableceColor(12,0);
            cout << (char)186;
        }
         gotoxy(xi,yi+=1);
         cout<< (char)200;    //bottom
         for (int i=0; i< 7 ; i++) cout<<(char)205;
         cout << (char)188;   //bottom

         estableceColor(0,12);
    }
    if (p==2) {
        estableceColor(14,0);

         cout<< (char)201;    //top
         for (int i=0; i< 7 ; i++) cout<<(char)205;
         cout << (char)187;   //top
         estableceColor(0,14);


         for(int i=0; i<2; i++){ //center
            gotoxy(xi,yi+=1);
            estableceColor(14,0);
            cout << (char)186;
            estableceColor(0,14);
            for(int i =0 ; i<7 ; i++){
                cout<<(char)219;}
            estableceColor(14,0);
            cout << (char)186;
        }
         gotoxy(xi,yi+=1);
         cout<< (char)200;    //bottom
         for (int i=0; i< 7 ; i++) cout<<(char)205;
         cout << (char)188;   //bottom
         estableceColor(0,14);
    }
    //////////////////////////////// DIBUJA EL BOTON PLAYER
     xi=90;
     yi=10;

     gotoxy(xi,yi);
     cout<<(char)201<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)187;
     gotoxy(xi,yi+1);
     cout<< " PLAYER "<<p;
     gotoxy(xi,yi+2);
     cout<<(char)200<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)188;
}
//**************************************************************************************************

//**************************************************************************************************
void borra_ficha (int xx,int yy){
    //Pinta de negro un bloque de 5x9
    estableceColor(0,0);
    gotoxy(xx, yy);
    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 9 ; j++) cout << (char)186;
        gotoxy(xx, yy++);
    }
}
//**************************************************************************************************

//**************************************************************************************************
void animation (int xi,int yi, int player){

    int xx = xi, yy;
    for (yy = 11 ; yy < yi ; yy +=5) { //yi es el limite donde se presentara la ultima ficha, yy es variable modificable
        imprime_ficha(xx, yy, player);
        Sleep(100);
        borra_ficha(xx, yy);
    }
}
//**************************************************************************************************

//**************************************************************************************************
void cases(char A[TAM_FIL][TAM_COL], int n, int &tx, int player, int &xi, int &yi ){
    A[n][tx] = player; //
    check_columna(n, tx,xi,yi);
    tx--;  //Remueve un espacio de la columna 3
    animation(xi, yi, player); //corre animación de caída de ficha
    imprime_ficha(xi, yi, player);
}
//**************************************************************************************************
void teclas_juego()
{
    gotoxy(20,1);
    cout<< "<== Izquierda    "<< (char)186 << "  Bajar ficha  ==> Derecha";
    gotoxy(20,2);
    cout<< "ESC Menu         V";
}


