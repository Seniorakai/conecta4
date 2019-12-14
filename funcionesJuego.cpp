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
#define KEY_LEFT 75 //Valor de la tecla izquierda
#define KEY_RIGHT 77 //Valor de la tecla derecha
#define TAM_COL 10  //Tamaño de la columna
#define TAM_FIL 10  //Tamaño de la fila
#define KEY_UP 72   //Valor de la tecla arriba
#define KEY_DOWN 80 //Valor de la tecla abajo
#define ESC 27      //Valor de la tecla ESC
#define ENTER 13    //Valor de la tecla ENTER

using namespace std;

//**************************************************************************************************
void crearArreglo(char A[TAM_FIL][TAM_COL])
{
    for (int x=1 ; x<=8; x++){
        for (int y=1 ; y<=7   ; y++){
            A[x][y]= '.';
        }
    }
}
//**************************************************************************************************

//**************************************************************************************************
void GANADOR (char A[TAM_FIL][TAM_COL], int player, int &t1, int &t2, int &t3, int &t4, int &t5, int &t6, int &t7, int& n, int& xi, int& yi){

    for(int X=1;X<=8;X++){
        for(int Y=1;Y<=6;Y++){
            if(A[X][Y]==player & A[X][Y+1]==player & A[X][Y+2]==player & A[X][Y+3]==player||A[X][Y]==player & A[X][Y-1]==player & A[X][Y-2]==player & A[X][Y-3]==player||A[X][Y]==player & A[X+1][Y]==player & A[X+2][Y]==player & A[X+3][Y]==player||A[X][Y]==player & A[X-1][Y]==player & A[X-2][Y]==player & A[X-3][Y]==player ||A[X][Y]==player & A[X+1][Y+1]==player & A[X+2][Y+2]==player & A[X+3][Y+3]==player||A[X][Y]==player & A[X+1][Y-1]==player & A[X+2][Y-2]==player & A[X+3][Y-3]==player){
                int K=ImprimirGanador(player);
                if (K==1){
                    REINICIAR(A, t1,t2,t3,t4,t5,t6,t7,xi,yi, n);
                }
            }
        }
    }
}
//**************************************************************************************************

//**************************************************************************************************
int ImprimirGanador (int& player){

    int y = 13,x = 20,loop = 1,z = 1/* variable de switch para detectar teclas*/,opcion = 1;

    //////////**************** FONDO NEGRO Y COLOR DEL JUGADOR ****************//////////

    if(player == 1)estableceColor(4,0); //establece color según el jugador ganador
    if(player == 2)estableceColor(6,0);//establece color según el jugador ganador
    for(int i = 0 ; i < 23 ; i++){
        gotoxy(x, y++);
        for(int j = 0 ; j < 53 ; j++)cout <<(char)219;
    }
    y = 13, x = 20;// restablece posición para el borde

    //////////**************** B O R D E ****************//////////

    gotoxy(x,y);
    //dibuja ╔═══════════════╗     top
    cout << (char)201;
    for (int i = 0 ; i < 51 ; i++) cout << (char)205;
    cout << (char)187;

    //dibuja ║              ║      mid
    for (int i = 0 ; i < 22 ; i++){
        gotoxy(x, y+1); //salto de linea sin sobrescribir
        cout << (char)186;
        gotoxy(x+52, y+1);   //salto de linea sin sobrescribir
        cout << (char)186;
        y++;
    }
    //dibuja ╚═══════════════╝      botom
    gotoxy(x,y++);  //salto de linea sin sobrescribir
    cout << (char)200;
    for (int i = 0 ; i < 51 ; i++) cout << (char)205;
    cout << (char)188;
    y= 14; //restablece la posición de y

    //////////****************IMPRESION GANADOR****************//////////

    if(player == 1){
        estableceColor(0,4); //color rojo
        string line; //variable para recibir las lineas de texto
        ifstream archivo ("G_Player1.txt"); //imprime jugador 1 ha ganado

        if (archivo.is_open()) {//asegura que el archivo este abierto
            while ( getline (archivo,line) ) { //recibe la siguente linea de texto del archivo
               gotoxy(x+3,y++); //imprime linea por linea en los renglones deseados
              cout << line << '\n';
            }
            archivo.close();//cierra el archivo
          }
    }
    if(player==2){
        estableceColor(0,6);//color amarillo
        string line;  //variable para recivir las lineas de texto
        ifstream archivo ("G_Player2.txt");//imprime jugador 2 ha ganado
        if (archivo.is_open()) {//asegura que el archivo este abierto
            while ( getline (archivo,line) ) {//recive la siguente linea de texto del archivo
               gotoxy(x+3,y++); //imprime linea por linea en los renglones deseados
              cout << line << '\n';
            }
            archivo.close(); //cierra el archivo
          }
    }
      gotoxy(26,33);
      cout<< "*Enter para seleccionar*";
      gotoxy(x+=6,y+2);
      cout<< "Jugar de nuevo"; //texto para las opciones
      gotoxy(x+=28,y+2);
      cout<< "Salir"; //texto para las opciones



      if(player==2)estableceColor(0,4);//color amarillo, inverso a jugador
      if(player==1)estableceColor(0,6);//color rojo, inverso a jugador
      gotoxy(26,31);//posición debajo jugar de nuevo
      for(int i=0; i<14; i++)cout<< (char)205; //imprime selección bajo jugar de nuevo

    while(loop==1){
      switch((z=getch())) {

      case KEY_LEFT:
          gotoxy(53,31);    //posición debajo salir
          for(int i=0; i<9; i++)cout<<" "; // borra lo que hay debajo de salir
          gotoxy(26,31);//posición debajo jugar de nuevo
          for(int i=0; i<14; i++)cout<< (char)205; //imprime selección bajo jugar de nuevo
          opcion--; //mantiene opción en 1
          if(opcion<1) opcion=1; //mantiene opción en 1

        break;

      case KEY_RIGHT:
          gotoxy(26,31); //posición debajo jugar de nuevo
          for(int i=0; i<14; i++)cout<<" ";//borra la selección debajo  "jugar de nuevo"
          gotoxy(53,31);//posición debajo salir
          for(int i=0; i<7; i++)cout<<(char)205;//imprime selección debajo "salir"
          opcion++; //mantiene opción en 2
          if(opcion>2) opcion=2; //mantiene opción en 2
        break;

      case ENTER:
        if(opcion==1) { //opcion 1 es jugar de nuevo
            return 1;
            loop=0;} //rompe ciclo }
        if(opcion==2) backmenu(); //opcion 2 es salir, cierra programa
        break;
      }
     }
}
//**************************************************************************************************

//***************************J U E GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG O ***********************************************************************
void intento(int &n, int &t1, int &t2, int &t3, int &t4, int &t5, int &t6, int &t7,int &xi, int &yi, int& player){
    int z=0, m=1;
    xi=10, yi=10, player=1, n=0;
    t1=6, t2=6, t3=6,t4=6,t5=6,t6=6,t7=6; //t es la "profundidad" de la columna, en este caso del arreglo
    char A[TAM_FIL][TAM_COL];
    crearArreglo(A);

    imprime_tablero(xi,yi);
    while (1){


        if (player>=3) {player=1;} /// cambio de jugador
        imprime_ficha(xi+1,5,player);

        switch((z = getch())) {


        case KEY_LEFT:              /// movimiento a la izquierda
            keyleft(n,m,xi,yi,player);
            break;
        case KEY_RIGHT:   /// movimiento a la derecha
            keyright(n,m,xi,yi,player);
            break;
         //////////////////////////////////////////////////////////////// DOWN
        case KEY_DOWN:
            keydwon(A, player, t1, t2, t3, t4, t5, t6, t7, n, xi, yi);
            GANADOR ( A, player, t1,t2, t3, t4, t5, t6, t7, n,xi, yi);
            player += 1;
        break;
        case ESC:   /// salida

            backmenu();
            break;

        }
    }
}
//**************************************************************************************************

//**************************************************************************************************
void keyright(int &n, int &m,int &xi,int& yi,int& player){
    n+=1;
    if(n > 7 || n < 1){ // Asegura que las columnas seleccionadas sean entre 1-7
        if (n > 7) n = 1;
        if (n < 1) n = 7;
    }
    if(m >6 || m < 0){
        if (m > 6) m = 0;
        if (m < 0) m = 6;
    }
    check_columna(n, m,xi,yi);
    gotoxy(xi, 4);   // borra la ficha superior
    estableceColor(0, 0);

    for (int i = 0 ; i < 5; i++ ){
    gotoxy(5, 4 +i);
    for(int i = 0 ; i < 99 ; i++){
    cout << (char)219;} }
    imprime_ficha(xi + 1, 5, player);

}
//**************************************************************************************************


//**************************************************************************************************
void keyleft(int &n, int &m,int& xi,int& yi,int& player){
    n-=1;
    if(n > 7 || n < 1){
        if (n > 7) n = 1;
        if (n < 1) n = 7;
    }
    if(m > 6 || m < 0){
        if (m > 6) m = 0;
        if (m < 0) m = 6;
    }
    check_columna(n,m,xi,yi);
    gotoxy(xi, 4);
    estableceColor(0, 0);

    for (int i = 0 ; i < 5; i++ ){
    gotoxy(5, 4+i);
    for(int i = 0 ; i < 99 ; i++){
        cout << (char)219;} }
    imprime_ficha(xi +1, 5, player);
}
//**************************************************************************************************

//**************************************************************************************************
void keydwon (char A[TAM_FIL][TAM_COL], int player, int &t1, int &t2, int &t3, int &t4, int &t5, int &t6, int &t7, int &n, int &xi, int &yi){

        switch (n){ // casos dependiendo en la columnaa

            case 1:
                if (t1 > 0){
                   cases(A, n, t1, player, xi, yi);
                }break;
            case 2:
                if (t2 > 0){
                    cases(A, n, t2, player, xi, yi);
                }break;
            case 3:
                if (t3 > 0){
                    cases(A, n, t3, player, xi, yi);
                }break;
            case 4:
                if (t4 > 0){
                    cases(A, n, t4, player, xi, yi);
                }break;

            case 5:
                if (t5 > 0){
                     cases(A, n, t5, player, xi, yi);
                }break;
            case 6:
                if (t6 > 0){
                     cases(A, n, t6, player, xi, yi);
                }break;
            case 7:
                if (t7 > 0){
                     cases(A, n, t7, player, xi, yi);
                }

                if (t7==0 && t6==0 && t5==0 && t4==0 && t3==0 && t2==0 && t1==0) // declaración de empate
                {estableceColor(0,6);//color amarillo
                string line;  //variable para recivir las lineas de texto
                ifstream archivo ("empate.txt");//imprime jugador 2 ha ganado
                if (archivo.is_open()) {//asegura que el archivo este abierto
                        int i=30,j=20;
                    while ( getline (archivo,line) ) {//recive la siguente linea de texto del archivo
                       gotoxy(i,j++); //imprime linea por linea en los renglones deseados
                      cout << line << '\n';
                    }
                    archivo.close(); //cierra el archivo
                  }
                  cargando();

                REINICIAR(A, t1,t2,t3,t4,t5,t6,t7,xi,yi, n);}

        }
}
//**************************************************************************************************
//**************************************************************************************************

void backmenu()
{
    estableceColor(0,6);//color amarillo
    string line;  //variable para recivir las lineas de texto
    ifstream archivo ("regresar.txt");//imprime jugador 2 ha ganado
    if (archivo.is_open()) {//asegura que el archivo este abierto
            int i=12,j=10;
        while ( getline (archivo,line) ) {//recive la siguente linea de texto del archivo
           gotoxy(i,j++); //imprime linea por linea en los renglones deseados
          cout << line << '\n';
        }
        archivo.close(); //cierra el archivo
      }
    //Sleep(3000);
    gotoxy(12,19);
    cargando();
    menu_principal();
}
//**************************************************************************************************
