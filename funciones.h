#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TAM_COL 10
#define TAM_FIL 10

void gotoxy(int x,int y);
void dibujacuadro (int x,int y);
void REINICIAR(char A[TAM_FIL][TAM_COL], int &t1, int &t2, int &t3, int &t4, int &t5, int &t6, int &t7, int &xi, int &yi, int& n);
void check_columna (int& q, int p, int& xi,int& yi);
void estableceColor( int  colorFondo, int colorTexto);
void imprime_tablero(int& xi,int& yi);
void imprime_ficha(int xi,int yi, int p);
void borra_ficha (int xx,int yy);
void animation (int xi,int yi, int player);
void cases(char A[TAM_FIL][TAM_COL], int n, int &tx, int player, int &xi, int &yi );
void teclas_juego();
#endif // FUNCIONES_H_INCLUDED
