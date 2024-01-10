#include "librerias.h"
#include "funciones.h"
// PROYECTO FINAL: SANTIAGO REY Y SANTIAGO RIVEROS
using namespace std;
int main()
{
    inicio();
    return 0;
}
int numeros_al_azar (void){
    return rand() % (15 - 1 + 1) + 1;
}
int numero_balas (void){
    int retorno;
    cout << "==============================================================================\n";
    cout << "==================================SALVAJES!!==================================\n";
    cout << "==============================================================================\n";
    cout << "Señores Salvajes!! Cuantas balas le otogaran al cazador para defenderse???? ";
    cin >> retorno;
    return retorno;
}
void cuarto_inicial(int matriz[QCUARTOS][QCUARTOS], int *fila, int *columna){
    cout << "==============================================================================\n";
    cout << "==================================CAZADOR!!===================================\n";
    cout << "==============================================================================\n";
    while(*fila < 1 || *fila > 7 || *columna < 1 || *columna > 7){
        cout << "Señor cazador indique la fila en la que desea empezar >> ";
        cin >> *fila;
        cout << "Señor cazador indique la columna en la que desea empezar >> ";
        cin >> *columna;
        if(*fila < 1 || *fila > 7 || *columna < 1 || *columna > 7)
            cout << "ERROR!!, vuelva a ingresar las posiciones "<<endl;
    }
}
void imprimir_estado_cazador(int balas, char matrizr[QCUARTOS][QCUARTOS], int matriz[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS],
                             bool hay_ganador){
    int i = 0, j = 0;
    recorrido_cazador(balas, matriz, matrizi, matrizr);
    if(hay_ganador)
        cout << "==============================RECORRIDO===FINAL===============================\n";
    else
        cout << "===============================ESTADO====CAZADOR==============================\n";
    while(i<QCUARTOS){
        while(j<QCUARTOS){
            cout << "["<<matrizr[i][j]<<"]"<<'\t';
            j++;
        }
        cout << endl;
        j=0;
        i++;
    }
    cout << "==============================================================================\n";
    if(!hay_ganador)
        cout << '\t' <<'\t' << "Usted cuenta aun con " << balas << " balas" << endl;


}
void restar_cocodrilos (int fila, int columna, int matriz[QCUARTOS][QCUARTOS], int balas){
    if(matriz[fila][columna] <= balas){
        matriz[fila][columna]=0;
    }else
        matriz[fila][columna] -= balas;
}
int balas_restantes(int balas, int matriz[QCUARTOS][QCUARTOS], int posicionfila, int posicioncolumna) {
    while(balas>0&&matriz[posicionfila][posicioncolumna]>0){
        matriz[posicionfila][posicioncolumna] -= 1;
        balas -=1;
    }
    return balas;
}
void configuracion_inicial_laberinto(int matriz[QCUARTOS][QCUARTOS]){
    int i = 0, j = 0;

    cout << "=============================CONFIGURACION==INICIAL==========================\n";
    while(i<QCUARTOS){
        while(j<QCUARTOS){
            cout << "["<<matriz[i][j]<<"]"<<'\t';
            j++;
        }
        cout << endl;
        j=0;
        i++;
    }
    cout << "==============================================================================\n";
}
void nueva_posicion_cazador(int matriz[QCUARTOS][QCUARTOS], int *fila, int *columna){
    int menor=1000;
    int filamenor = 0;
    int columnamenor = 0;

    if((matriz[*fila][*columna-1]<menor)&&(matriz[*fila][*columna-1]!=0)){
        menor = matriz[*fila][*columna-1];
        filamenor = *fila;
        columnamenor = *columna-1;
    }
    if((matriz[*fila-1][*columna]<menor)&&(matriz[*fila-1][*columna]!=0)){
        menor = matriz[*fila-1][*columna];
        filamenor = *fila-1;
        columnamenor = *columna;
    }
    if((matriz[*fila][*columna+1]<menor)&&(matriz[*fila][*columna+1]!=0)){
        menor = matriz[*fila][*columna+1];
        filamenor = *fila;
        columnamenor = *columna+1;
    }
    if((matriz[*fila+1][*columna]<menor)&&(matriz[*fila+1][*columna]!=0)){
        menor = matriz[*fila+1][*columna];
        filamenor = *fila+1;
        columnamenor = *columna;
    }
    *fila = filamenor;
    *columna = columnamenor;
}
void bienvenida (void){

    cout << "Hola! Usted está a punto de entrar en una travesía de vida o muerte!" << endl << endl
         << "Los salvajes le hemos preparado un muy difícil laberinto!" << endl << endl
         << "Estamos preparando el número de vidas... digo, de balas que podrá utilizar..." << endl
         << "Veamos qué tan resistente es >:) " << endl << endl << "¡A jugar!" << endl << endl;
}

void cocodrilos_cuartos (int matriz [QCUARTOS][QCUARTOS]){
    int i = 0, j = 0, autom = 0, coco = 0;

    cout << "¿Desea que los cocodrilos sean automáticamente ingresados?" << endl ;
    cout << "Pulse 0 para sí o cualquier otro número para no >> ";
    cin  >> autom ;

    if(autom == 0)
        for (i = 0; i < QCUARTOS; i++)
            for (j = 0; j < QCUARTOS; j++)
                matriz[i][j]= numeros_al_azar();
    else
        for (i = 0; i < QCUARTOS; i++)
            for (j = 0; j < QCUARTOS; j++){
                cout << "Indique el número de cocodrilos que desea ingresar en la fila " << i << " columna " << j << " : ";
                cin  >> coco ;
                cout << endl;
                if (coco <=15 && coco>=1)
                    matriz[i][j]= coco;
                else{
                    cout << endl << "Recuerde que deben haber entre 1 y 15 cocodrilos en cada cuarto!!" << endl << endl;
                    j--;
                }
            }
}

void restar_cocodrilos_inicial (int filaindicada, int columnaindicada, int matriz[QCUARTOS][QCUARTOS]){

    matriz[filaindicada][columnaindicada] = 0;

}

void imprimir_estado_matriz (int matriz[QCUARTOS][QCUARTOS]){
    int i = 0, j = 0;
    cout << "===============================ESTADO====MATRIZ==============================\n";
    while(i<QCUARTOS){
        while(j<QCUARTOS){
            cout << "["<<matriz[i][j]<<"]"<<'\t';
            j++;
        }
        cout << endl;
        j=0;
        i++;
    }
    cout << "==============================================================================\n";
}

void recorrido_cazador(int balas, int matriz[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS], char matrizr[QCUARTOS][QCUARTOS]) {
    int i = 0, j = 0;
    for (i = 0; i < QCUARTOS; i++)
        for (j = 0; j < QCUARTOS; j++)
            if (matriz[i][j] < matrizi[i][j])
                matrizr[i][j] = 'X';
}
void copiar_matriz(int matriz[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS]){
    int i = 0, j = 0;
        for (i = 0; i < QCUARTOS; i++)
            for (j = 0; j < QCUARTOS; j++)
                matrizi[i][j] = matriz[i][j];
}
void fin_del_juego(int fila, int columna, int matriz[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS], char matrizr[QCUARTOS][QCUARTOS],
                   int *balas, int *balasfaltantes, int *auxbalas, bool hay_ganador){
    if (fila==0 || columna ==0 || fila==8 || columna ==8 && matriz[fila][columna]==0){
        configuracion_inicial_laberinto(matrizi);
        imprimir_estado_cazador(*balas, matrizr, matriz, matrizi, hay_ganador);
        cout << '\t' << "Felicitaciones!! usted logro sobrevivir de los audaces salvajes!!" << endl;
        cout << '\t' <<'\t' << "usted quedo con "<< *balas << " balas sobrantes"<<endl;
        *balas = 0;
    }else if(*balas==0){
        configuracion_inicial_laberinto(matrizi);
        imprimir_estado_cazador(*balas, matrizr, matriz, matrizi, hay_ganador);
        cout << '\t' <<'\t' << "Lo siento, usted es un triste perdedor :(" << endl;
        cout << '\t' <<'\t' << "Usted quedo con "<< *balas << " balas antes de morir"<<endl;
        cout << "Usted necesecitaba como minimo "<< *balasfaltantes << " balas para poder ganar,";
        cout << " le hicieron falta "<< (*auxbalas-*balasfaltantes)*-1 << " :("<<endl;
        }
}
void inicio(void){
    int matriz[QCUARTOS][QCUARTOS]={0}, matrizi[QCUARTOS][QCUARTOS]={0};
    char matrizr[QCUARTOS][QCUARTOS]={0};
    int balas = 0, fila = -1, columna = -1, continuar = 0, balasfaltantes = 0, auxbalas = 0;
    bool hay_ganador = false;
    int matrizf[QCUARTOS][QCUARTOS]={0};
    llamado_de_funciones(&fila, &columna, matriz, matrizf, matrizi, matrizr, &balas, &balasfaltantes, &auxbalas, hay_ganador);
    while(balas>0){
        if(matriz[fila][columna]==0){
            restar_cocodrilos (fila, columna, matriz, balas);
            nueva_posicion_cazador(matriz, &fila, &columna);
            balas = balas_restantes(balas, matriz, fila, columna);
        }
        cout << "Digite cualquier numero para continuar >> ";
        cin >> continuar;
        imprimir_estado_matriz(matriz);
        imprimir_estado_cazador(balas, matrizr, matriz, matrizi, false);
        fin_del_juego(fila, columna, matriz, matrizi, matrizr, &balas, &balasfaltantes, &auxbalas, true);
    }
}
void llamado_de_funciones(int *fila, int *columna, int matriz[QCUARTOS][QCUARTOS], int matrizf[QCUARTOS][QCUARTOS], int matrizi[QCUARTOS][QCUARTOS], char matrizr[QCUARTOS][QCUARTOS],
    int *balas, int *balasfaltantes, int *auxbalas, bool hay_ganador){
    system("color 02");
    srand(time(NULL));
    bienvenida();
    *balas = numero_balas();
    *auxbalas = *balas;
    cocodrilos_cuartos(matriz);
    copiar_matriz(matriz, matrizi);
    copiar_matriz(matriz, matrizf);
    imprimir_estado_matriz(matriz);
    cuarto_inicial(matriz, &*fila, &*columna);
    balas_faltantes(matrizf, *fila, *columna, &*balasfaltantes);
    restar_cocodrilos_inicial(*fila, *columna, matriz);
    cout << "Los cuartos con los cocodrilos inician asi" << endl;
    imprimir_estado_matriz(matriz);
    imprimir_estado_cazador(*balas, matrizr, matriz, matrizi, false);
}
void balas_faltantes(int matrizf[QCUARTOS][QCUARTOS], int filaf, int columnaf, int *balasfaltantes){
    int balas = 0;
    restar_cocodrilos_inicial(filaf, columnaf, matrizf);
    while(filaf < 8 && columnaf < 8 && filaf > 0 && columnaf > 0)
        if(matrizf[filaf][columnaf]==0){
            restar_cocodrilos (filaf, columnaf, matrizf, 1000);
            nueva_posicion_cazador(matrizf, &filaf, &columnaf);
            *balasfaltantes += balasf(matrizf, filaf, columnaf);
        }
}
int balasf(int matrizf[QCUARTOS][QCUARTOS], int posicionfila, int posicioncolumna) {
    int retorno = 0;
    while(matrizf[posicionfila][posicioncolumna]>0){
        matrizf[posicionfila][posicioncolumna] -= 1;
        retorno ++;
    }
    return retorno;
}
