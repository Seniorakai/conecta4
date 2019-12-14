#ifndef FUNCIONESJUEGO_H_INCLUDED
#define FUNCIONESJUEGO_H_INCLUDED



#define TAM_COL 10
#define TAM_FIL 10


void crearArreglo(char A[TAM_FIL][TAM_COL]);
int ImprimirGanador (int& player);
void GANADOR (char A[TAM_FIL][TAM_COL], int player, int &t1, int &t2, int &t3, int &t4, int &t5, int &t6, int &t7, int& n, int& xi, int& yi);
int ImprimirGanador (int& player);
void intento(int &n, int &t1, int &t2, int &t3, int &t4, int &t5, int &t6, int &t7,int &xi, int &yi, int& player);
void keyright(int &n, int &m,int &xi,int& yi,int& player);
void keyleft(int &n, int &m,int& xi,int& yi,int& player);
void keydwon (char A[TAM_FIL][TAM_COL], int player, int &t1, int &t2, int &t3, int &t4, int &t5, int &t6, int &t7, int &n, int &xi, int &yi);
void backmenu();

#endif // FUNCIONESJUEGO_H_INCLUDED
