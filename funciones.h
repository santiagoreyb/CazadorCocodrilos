#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "librerias.h"

void bienvenida (void);
int numeros_al_azar (void);
void cocodrilos_cuartos (int matriz[QCUARTOS][QCUARTOS]);
int numero_balas (void);
void restar_cocodrilos_inicial (int filaindicada, int columnaindicada, int matriz[QCUARTOS][QCUARTOS]);
void cuarto_inicial(int matriz[QCUARTOS][QCUARTOS], int *fila, int *columna);
void imprimir_estado_matriz(int matriz[QCUARTOS][QCUARTOS]);
void imprimir_estado_cazador(int balas, char matrizr[QCUARTOS][QCUARTOS], int matriz[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS],
                             bool hay_ganador);
int balas_restantes(int balas, int matriz[QCUARTOS][QCUARTOS], int posicionfila, int posicioncolumna);
void restar_cocodrilos (int fila, int columna, int matriz[QCUARTOS][QCUARTOS], int balas);
void recorrido_cazador(int balas, int matriz[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS], char matrizr[QCUARTOS][QCUARTOS]);
void configuracion_inicial_laberinto(int matriz[QCUARTOS][QCUARTOS]);
void nueva_posicion_cazador(int matriz[QCUARTOS][QCUARTOS], int *fila, int *columna);
void copiar_matriz(int matriz[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS]);
void fin_del_juego(int fila, int columna, int matriz[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS], char matrizr[QCUARTOS][QCUARTOS],
                   int *balas, int *balasfaltantes, int *auxbalas, bool hay_ganador);
void inicio(void);
void llamado_de_funciones(int *fila, int *columna, int matriz[QCUARTOS][QCUARTOS], int matrizf[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS], char matrizr[QCUARTOS][QCUARTOS],
    int *balas, int *balasfaltantes, int *auxbalas, bool hay_ganador);
int balasf(int matrizf[QCUARTOS][QCUARTOS], int posicionfila, int posicioncolumna);
void balas_faltantes(int matrizf[QCUARTOS][QCUARTOS], int filaf, int columnaf, int *balasfaltantes);
#endif // FUNCIONES_H_INCLUDED
