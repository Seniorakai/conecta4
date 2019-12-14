#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include "MenuPrincipalJuego.h"
#include "OpcionesMenu.h"

void TamVentana(int Ancho, int Alto);
using namespace std;

int main()
{   system("mode 650");
    cout << endl << endl << endl;
    lectura();
    //Sleep(300); //se puede quitar
    cargando();
    system ("cls");

    menu_principal();

    system("pause");
    return 0;
}

