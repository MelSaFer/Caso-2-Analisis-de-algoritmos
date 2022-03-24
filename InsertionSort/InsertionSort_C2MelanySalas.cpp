//Instituto Tecnologico de Costa Rica
//Caso 2- Análisis de algoritmos
//Melany Salas Fernandez_2021121147
//GitHub: https://github.com/MelSaFer/Caso-2-Analisis-de-algoritmos.git


//LIBRERIAS____________________________________________________________________________________________
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <ctime> 
#include <chrono>

using namespace std;

//VARIABLES GLOBALES______________________________________________________________________________________
//CONTADORES
int cambiosP=0;
int comparacionesFor = 0;
int cicloWhile = 0;


//-------------------------------------------------INSERTIONSORT-------------------------------------------
void insertionSort(int *array, int size) {
   int key, j;  //Se definen variables
   for(int i = 1; i < size; i++) {      //Ciclo for que recorre el array
        comparacionesFor++;             //Contador de iteraciones for
        key = array[i];                 //Key toma el valor del array[i]
        j = i;                          //J copia el valor de i
        while(j > 0 && array[j-1] > key) {  //Se ordena el sub array, sale del ciclo cuando esta ordenado de 0 a j-1
            cicloWhile++;               //Contador del ciclo while
            array[j] = array[j-1];
            cambiosP++;                 //Aumenta el contador de cambios
            j--;  
        }
        array[j] = key;                 //Se inserta el elemnto en la posicion respectiva
   }
}

//----------------------------------------------------------------------------------------------------------
//Funcion para imprimir arrays
//Entradas: Un array de tamaño n y el tamaño de array (n)
//Salidas: None, hace prints de los elementos
//----------------------------------------------------------------------------------------------------------
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//----------------------------------------------------------------------------------------------------------
//Funcion para imprimir estadisticas del algoritmo
//Entradas: enteros, uno para el tiempo de ejecucion en seguntos, un contador de ciclos for, un contador de 
//          cambios y un contador de iteraciones en ciclo while
//Salidas: None, hace prints de las estadisticas.
//----------------------------------------------------------------------------------------------------------
void printEstadisticasIS(long double time, int contadorFOR,  int cambios, int cicloW){
    cout << "\t\tTIEMPO DE EJECUCION: " << time << endl;
    cout << "\t\tENTRADAS AL CICLO FOR: " << comparacionesFor << endl;
    cout << "\t\tCAMBIOS: " << cambios << endl; 
    cout << "\t\tITERACIONES DEL CICLO WHILE:  " << cicloW << endl; 
}

//----------------------------------------------------------------------------------------------------------
//Funcion para hacer pruebas del algoritmo cuando este es lineal (Esta ordenado)
//Entradas: Un array de tamaño n y un entero con el tamaño del array
//Salidas: None
//----------------------------------------------------------------------------------------------------------
void pruebaISlineal(int pruebaIS[], int size){
    double time;
    auto tInicial = chrono::steady_clock::now();
    auto tFinal = chrono::steady_clock::now();
    for (int i = 0; i < size; i++){
        pruebaIS[i] = i;
    }
    tInicial = chrono::steady_clock::now();
    insertionSort(pruebaIS, size);
    tFinal = chrono::steady_clock::now();
    
    //PRINTS CONTADORES
    time = chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count();
    printEstadisticasIS(time, comparacionesFor, cambiosP, cicloWhile);

}

//----------------------------------------------------------------------------------------------------------
//Funcion para hacer pruebas del algoritmo cuando este es cuadratico
//Entradas:Un array de tamaño n y un entero con el tamaño del array
//Salidas: None
//----------------------------------------------------------------------------------------------------------
void pruebaISCuadratico(int pruebaIS[], int size){
    double time;
    auto tInicial = chrono::steady_clock::now();
    auto tFinal = chrono::steady_clock::now();
    for (int i = size; i > 0 ; i--){
        pruebaIS[size-i] = i;
    }
    tInicial = chrono::steady_clock::now();
    insertionSort(pruebaIS, size);
    
    tFinal = chrono::steady_clock::now();
    
    //PRINTS CONTADORES
    time = chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count();
    printEstadisticasIS(time, comparacionesFor, cambiosP, cicloWhile);

}

//---------------------------------------------------------------MAIN----------------------------------------------------
int main(){
    double time;
    auto tInicial = chrono::steady_clock::now();
    auto tFinal = chrono::steady_clock::now();
    cout << "\n\nINSERTION SORT_____________________________________________________________________" << endl;

    cambiosP=0; comparacionesFor=0; cicloWhile=0;

    int prueba[] = {10, 5, 8, 9, 2, 18, 20, -1, 2, -1000, 200, 201, 2999, 67, 17, -2000};
    
    int sizePrueba = sizeof(prueba) / sizeof(prueba[0]);
    cout << "Array sin ordenar: \n";
    tInicial = chrono::steady_clock::now();
    printArray(prueba, sizePrueba);

    insertionSort(prueba, sizePrueba);

    
    tFinal = chrono::steady_clock::now();
    time = chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count();
    cout << "TIEMPO DE EJECUCION: " << time << endl;
    cout << "ENTRADAS AL CICLO FOR: " << comparacionesFor << endl;
    cout << "CAMBIOS: " << cambiosP << endl; 

    cout << "Array ordenado: \n";
    printArray(prueba, sizePrueba);

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 2000 lineal"<<endl;
    cambiosP=0; comparacionesFor=0; cicloWhile=0;

    int pruebaIS[2000];
    pruebaISlineal(pruebaIS, 2000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;
    
    //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 4000 lineal"<<endl;
    int pruebaIS2[4000];
    pruebaISlineal(pruebaIS2, 4000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 6000 lineal"<<endl;
    int pruebaIS3[6000];
    pruebaISlineal(pruebaIS3, 6000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 8000 lineal"<<endl;
    int pruebaIS4[8000];
    pruebaISlineal(pruebaIS4, 8000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 10000 lineal"<<endl;
    int pruebaIS5[10000];
    pruebaISlineal(pruebaIS5, 10000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 12000 lineal"<<endl;
    int pruebaIS6[12000];
    pruebaISlineal(pruebaIS6, 12000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;
    
    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 14000 lineal"<<endl;
    int pruebaIS7[14000];
    pruebaISlineal(pruebaIS7, 14000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 16000 lineal"<<endl;
    int pruebaIS8[16000];
    pruebaISlineal(pruebaIS8, 16000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 18000 lineal"<<endl;
    int pruebaIS9[18000];
    pruebaISlineal(pruebaIS9, 18000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;
    
    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 20000 lineal"<<endl;
    int pruebaIS10[20000];
    pruebaISlineal(pruebaIS10, 20000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //-------------------------------------------CUADRATICO--------------------------------------------
    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 2000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS, 2000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;
    
    //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 4000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS2, 4000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 6000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS3, 6000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 8000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS4, 8000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 10000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS5, 10000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 12000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS6, 12000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;
    
    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 14000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS7, 14000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 16000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS8, 16000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;;

    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 18000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS9, 18000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;
    
    //-------------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 20000 cuadratico"<<endl;
    pruebaISCuadratico(pruebaIS10, 20000);
    time=0; comparacionesFor=0; cambiosP=0;cicloWhile=0;
    return 0;
}

/*
----------------------------------RESPUESTAS-----------------------------------
4- INSERTION SORT LINEAL
   Cuando nos encontramos con el mejor de los casos en el insertion sort
no tenemos que hacer cambios, debido a que el algoritmo ya esta previamente
ordenado, si vemos, las iteraciones estan directamente relacionadas con la
cantidad de elementos del array, si tengo un array de 200 elementos y están
ordenados se harán 199 itenaciones y 0 cambios, si tenemos uno de 300 se 
realizarian 299 iteraciones y 0 cambios, asi sucesivamente con cada array
de distintos tamaños como se observa a continuacion:
            ->Elementos         ->Cambios       ->Iteraciones
                2000                0                1999
                4000                0                3999
                6000                0                7999
                8000                0                8999
               10 000               0                9999
               12 000               0               11999
               14 000               0               13999
               16 000               0               15999
               18 000               0               17999
               20 000               0               19999
    En estas pruebas se ve reflejado que las iteraciones son el tamaño
n - 1, obteniendo como conclusion que entre más grande sea la entrada, 
mayor sera nuestro problema, ya que se relaciona con la cantidad de ele-
mentos en la lista, ademas, vemos como crece de manera uniforme, en esta
prueba por cada 2000 elementos hay un aumento de 2000 en las iteraciones,
usando la formula de razon de cambio en funciones obtenemos que:
        Formula= (f(x1)-f(x2))/ (x1-x2)
                = (4000-2000)/ (3999-1999)
                = 1
	Lo que nos indica que por cada elemento en el array vamos a tener un 
crecimciento de 1 en iteraciones por cada elemento nuevo a en el array, 
como es este caso:
                    ->Prueba con array de 20000 lineal
                        Tiempo de ejecución: 0
                        ENTRADAS AL CICLO FOR: 19999
                        CAMBIOS: 0
                        ITERACIONES DEL CICLO WHILE:  0

                    ->Prueba 2 con array de 20001 lineal
                        Tiempo de ejecución: 0
                        ENTRADAS AL CICLO FOR: 20000
                        CAMBIOS: 0
                        ITERACIONES DEL CICLO WHILE:  0
	Cuando tenemos 20000 elemenos, hacemos 19999 entradas en el for, pero
cuando le agregamos un elemento al array hace 20000 entradas al for.

------------------------------------------------------------------------------------
5- INSERTION SORT CUADRATICO.

   En el caso de Insertion Sort Cuadrático, tenemos que realizar todos los 
cambios, es decir, tenemos un array totalmente desordenado entonces, debemos
hacer los cambios cada vez que hacemos un sub array, si tenemos un array de 
5 elementos que esta desordenado hariamos algo asi:

                       	array = 5, 4, 3, 2, 1
   Si analizamos  {5, 4} debemos cambiar 4 y obtenemos {4, 5}
Luego analizamos {4, 5, 3} y debemos cambiar el 3 dos veces obteniendo
primero {4, 3, 7} y luego {3, 4, 5}.Posteriormente analizamos con el 
siguiente elemento {3, 4, 5, 2}, el 2 debemos moverlo tres veces, al final
obtenemos {2, 3, 4, 5}. Con el ultimo elemento que es 1, deberiamos hacer cuatro 
cambios. Obtenemos el array ordenado {1, 2, 3, 4, 5} y un total de cambios de 10,
si tuvieramos un 6 elemento entonces serian 15 cambios totales y asi sucesivamente.
    
    Con las pruebas realizadas obtuvimos:
            ->Elementos         ->Cambios       ->Iteraciones
                2000             1999000             1999
                4000             7998000             3999
                6000             17997000            7999
                8000             31996000            8999
               10 000            49995000            9999
               12 000            71994000           11999
               14 000            97993000           13999
               16 000           127992000           15999
               18 000           161991000           17999
               20 000           199990000           19999

   En este caso, el comportamiento que vemos es el considerable aumento
de cambios cada vez que hay un aumento en la cantidad de elementos, si vemos
la diferecia entre los cambios del array de 2000 y el de 4000, es de 5999000,
luego vemos la del de 4000 y la de 6000 y es de 9999000, la del de 6000 y el
de 8000 es de 13999000 y asi sigue creciendo considerablemente y de manera
desigulal, esto porque entre mas grande en el problema, la cantidad de cam-
bios crece de forma exponecial.
*/