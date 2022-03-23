#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <ctime> 

using namespace std;

//CONTADORES
int cambiosP=0;
int comparacionesFor = 0;
int llamadasQuick = 0;
int cicloWhile = 0;
unsigned tInicial, tFinal;

//-----------------------------------------------------------------QUICKSORT----------------------------------------------------------------------
//FUNCION QUE REALIZA LOS CAMBIOS DE POCISIONES EN EL ARRAY
void cambio(int* a, int* b){
    cambiosP++;
    int t = *a;
    *a = *b;
    *b = t;
}
 
//QUICKSORT CON PIVOTE FIJO (PRIMER ELEMENT0)------------------------------------------------------------------------------------------------------
//Recibe el array que se esta ordenando, incion que es el indice inicial y que es el indice final + 1
//Ordena los numeros mayores que el pivote a la izquierda y los otros a la derecha
int partition (int arr[], int inicio, int final){
    int r = rand() % final;
    int pivot = arr[final]; // Toma el elemento final como pivote
    
    int i = (inicio - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = inicio; j < final; j++){
        comparacionesFor++;
        // El elemento actual es mas pequeño que el pivote
        if (arr[j] < pivot){
            i++; // increment index of smaller element
            cambio(&arr[i], &arr[j]);
        }
    }
    cambio(&arr[i + 1], &arr[final]);
    return (i + 1);
}
 
//Funcion recusiva quickSort
void quickSort(int arr[], int inicio, int final){
    llamadasQuick++;
    if (inicio < final){
        //Divide el array
        int pi = partition(arr, inicio, final);
        // Separately sort elements before partition and after partition
        quickSort(arr, inicio, pi - 1);
        quickSort(arr, pi + 1, final);
    }
}

//QUICK SORT COON PIVOTE ALEATORIO-----------------------------------------------------------------------------------------------------------------
//Recibe el array que se esta ordenando, incion que es el indice inicial y que es el indice final + 1
//Ordena los numeros mayores que el pivote a la izquierda y los otros a la derecha
int partitionRan (int arr[], int inicio, int final)
{
    comparacionesFor++;
    srand (time(NULL));
    int random = inicio + rand() % (final - inicio);
    // Swap A[random] with A[high]
    cambio(&arr[random], &arr[final]);
 
    return partition(arr, inicio, final);
}
 
/* The main function that implements QuickSort*/
void quickSortRan (int arr[], int inicio, int final){
    llamadasQuick++; //Contador de llamadas al quicksort
    if (inicio < final){
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partitionRan(arr, inicio, final);
 
        // Separately sort elements before partition and after partition
        quickSortRan(arr, inicio, pi - 1);
        quickSortRan(arr, pi + 1, final);
    }
}


//------------------------------------------------------------------------------------------------------------
//Funcion para imprimir un array
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Funcion para inicializar contadores 
void inicializaCont(){
    cambiosP=0;
    comparacionesFor=0;
    llamadasQuick=0;
}

//Funcion para imprimir las estadisticas del algoritmo
void printEstadisticasQS(int contadorLlamadas, int contadorFOR, long double time, int cambios){
    cout << "\t\tLLAMADAS A LA FUNCION QUICK: " << contadorLlamadas << endl;
    cout << "\t\tENTRADAS AL CICLO FOR: " << contadorFOR << endl;
    cout << "\t\tCAMBIOS: " << cambios << endl;
    cout << "\t\tTiempo de ejecucion: " << time << endl;
    inicializaCont();
}

//Funcion para hacer las pruebas del algoritmo cuando es cuadratico
void pruebasQScuadratico( int pruebaQS[], int size){
    double time;

    for (int i = 0; i < size; i++){
        pruebaQS[i] = i;
    }
    
    tInicial= clock();
    quickSort(pruebaQS, 0, size - 1);
    tFinal = clock();

    //PRINTS CONTADORES
    cout<< "\tPIVOTE FIJO:" << endl;
    time = (double(tFinal-tInicial)/CLOCKS_PER_SEC);
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);

    //PIVOTE RANDOM
    tInicial= clock();
    quickSortRan(pruebaQS, 0, size - 1);
    tFinal = clock();

    cout<< "\tPIVOTE RANDOM:" << endl;
    time = (double(tFinal-tInicial)/CLOCKS_PER_SEC);
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);

}

//Funcion para hacer las pruebas del algoritmo para cuando es logaritmico
void pruebaQSlog(int pruebaQS[], int size){
    double time;

    for (int i = 0; i < size; i++){
        pruebaQS[i] = rand()%10000;
    }
    tInicial= clock();
    quickSort(pruebaQS, 0, size - 1);
    tFinal = clock();

    //PRINTS CONTADORES
    cout<< "\tPIVOTE FIJO:" << endl;
    time = (double(tFinal-tInicial)/CLOCKS_PER_SEC);
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);

    //PIVOTE RANDOM
    tInicial= clock();
    quickSortRan(pruebaQS, 0, size - 1);
    tFinal = clock();

    cout<< "\tPIVOTE RANDOM:" << endl;
    time = (double(tFinal-tInicial)/CLOCKS_PER_SEC);
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);
}

 //------------------------------------------------MAIN------------------------------------------
int main()
{
    inicializaCont();
    double time;

    //Prueba para demostrar que el algoritmo funciona
    cout << "QUICKSORT_____________________________________________________________________" << endl;
    cout <<"\n---------------------PRUEBA CON PIVOTE EN ULTIMO ELEMENTO---------------------" << endl;
    int arr[] = {10, 5, 8, 9, 2, 18, 20, -1, 2, -1000, 200, 201, 2999, 67, 17, -2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "->Prueba con: ";
    printArray(arr, n);

    tInicial= clock();
    quickSort(arr, 0, n - 1);
    tFinal = clock();

    //PRINTS CONTADORES
    time = (double(tFinal-tInicial)/CLOCKS_PER_SEC);
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);
    cout << "Array ordenado: "; printArray(arr, n);

    cout <<"\n---------------------------PRUEBA CON PIVOTE RANDOM---------------------------" << endl;
    int prueba2[] = {10, 5, 8, 9, 2, 18, 20, -1, 2, -1000, 200, 201, 2999, 67, 17, -2000};
    int sizePrueba2 = sizeof(prueba2) / sizeof(prueba2[0]);
    cout << "Array sin ordenar: ";
    printArray(prueba2, sizePrueba2);
    tInicial= clock();
    quickSortRan(prueba2, 0, sizePrueba2 - 1);
    tFinal = clock();

    //PRINTS CONTADORES
    time = (double(tFinal-tInicial)/CLOCKS_PER_SEC);
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);
    cout << "Array ordenado: ";printArray(prueba2, sizePrueba2);

    //Pruebas para observar el comportamiento del algoritmo condorfe los elementos aumentan
    //->ALGORITMO O(n^2)
    //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 2000 en el peor de los casos"<<endl;
    int pruebaQS2[2000];
    pruebasQScuadratico(pruebaQS2, 2000);
 
//-----------------------------------------------------------------------------------
    cout << "\n ->Prueba con array de 4000 en el peor de los casos"<<endl;
    int pruebaQS3[4000];
    pruebasQScuadratico(pruebaQS3, 4000);

    //-----------------------------------------------------------------------------------
    cout << "\n ->Prueba con array de 6000 en el peor de los casos"<<endl;
    int pruebaQS4[6000];
    pruebasQScuadratico(pruebaQS4, 6000);

   //-------------------------------------------------------------------------
    cout << "\n ->Prueba con array de 8000 en el peor de los casos"<<endl;
    int pruebaQS5[8000];
    pruebasQScuadratico(pruebaQS5, 8000);

    //-----------------------------------------------------------------------------------
    cout << "\n ->Prueba con array de 10000 en el peor de los casos"<<endl;
    int pruebaQS6[10000];
    pruebasQScuadratico(pruebaQS6, 10000);

    //-----------------------------------------------------------------------------------
    cout << "\n ->Prueba con array de 12000 en el peor de los casos"<<endl;
    int pruebaQS7[12000];
    pruebasQScuadratico(pruebaQS7, 12000);

    //-----------------------------------------------------------------------------------
    cout << "\n ->Prueba con array de 14000 en el peor de los casos"<<endl;
    int pruebaQS8[14000];
    pruebasQScuadratico(pruebaQS8, 14000);

    //-----------------------------------------------------------------------------------
    cout << "\n ->Prueba con array de 16000 en el peor de los casos"<<endl;
    int pruebaQS9[16000];
    pruebasQScuadratico(pruebaQS9, 16000);

    //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 18000 en el peor de los casos"<<endl;
    int pruebaQS0[18000];
    pruebasQScuadratico(pruebaQS0, 18000);

    //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 20000 en el peor de los casos"<<endl;
    int pruebaQS1[20000];
    pruebasQScuadratico(pruebaQS1, 20000);

    //->ALGORITMO O(logn)
   /*  //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 2000 en el caso promedio"<<endl;
    // PRUEBAQS2
    

    //-----------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 4000 en el caso promedio"<<endl;
    // PRUEBAQS3
    

    //-----------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 6000 en el caso promedio"<<endl;
    // PRUEBAQS4
   

   //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 8000 en el caso promedio"<<endl;
    // PRUEBAQS5
    

    //-----------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 10000 en el caso promedio"<<endl;
    // PRUEBAQS6
   

    //-----------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 12000 en el caso promedio"<<endl;
    // PRUEBAQS7
    

    //-----------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 14000 en el caso promedio"<<endl;
    // PRUEBAQS8
   

    //-----------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 16000 en el caso promedio"<<endl;
    // PRUEBAQS9
    

    //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 18000 en el caso promedio"<<endl;
    // PRUEBAQS8
    
    
    //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 20000 en el caso promedio"<<endl;
    // PRUEBAQS8

     */

    return 0;
}
/*
----------------------------------RESPUESTAS-----------------------------------
1-QUICKSORT LOGARITMICO

-------------------------------------------------------------------------------
2- QUICKSORT CUADRATICO
    El quicksort cuadrático lo obtenemos cuando se trabaja con el peor de los
casos, esto se da porque cuando se escoge el pivote se escoge al numero mayor
o menor del array, entonces al dividir, nos queda un  arbol desvalanceado
hacia un lado.
    Para demostrar esto, use un algoritmo que colocara el pivote en el ultimos
elemento y se le enviaron arrays ordenados de manera ascendente, haciendo
que cada vez que dividiera se escogiera como pivote al numero mayor del array
El comportamiento cuadratico se ve relejado en el creciemiento de la cantidad 
de cambios realizados en el algoritmo, tal y como vemos a continuacion:
                ->Elementos         ->Cambios
                    2000              2000999
                    4000              8001999
                    6000             18002999
                    8000             32003999
                   10 000            50004999
                   12 000            72005999
                   14 000            98006999
                   16 000           128007999
                   18 000           162008999
                   20 000           200009999
    Aqui se observa como entre los cambios del array de 2000 y el de 4000 hay una 
diferencia de 6001000 aprox, luego entre los de 4000 y 6000 hay una de 10001000 
aprox, entre el de 6000 y el de 8000 hay una de 14001000 aproximandamente y asi 
sigue aumentando entre cada array de manera considerable y, mas importante, no 
crece uniformemente. Este comportamiento tambien se observa si hacemos una
grafica con los valores de cambio en cada array, pues tiene la forma de las
funciones cuadraticas, aumenta creando una forma similar a la de una U, o en
este caso, media U.

----------------------------------------------------------------------------------

3-INFLUENCIA DEL PIVOTE FIJO Y ALEATORIO.
    Comparando la cantidad de cambios que hizo el algoritmo en el peor de los
casos con los que hizo el algoritmo escogiendo un pivote random es mejor usar 
este, ya que si en una iterancion escogi de pivote uno de los elementos de los 
extremos puede que en la siguente iteracion no, esto porque no tengo un indicio
de como se va a comportar el algoritmo.
    Cuando estoy en caso promedio no importa tanto porque es cuestion de suerte
la influencia tendra el pivote sobre mi algpritmo, puede que tenga suerte con
el random o puede que no, pero en este caso hay que tener en cuenta que el random
aunemtara un poco la carga del algoritmo.

*/

