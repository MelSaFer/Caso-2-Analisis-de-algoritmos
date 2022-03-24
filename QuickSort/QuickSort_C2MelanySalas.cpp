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
int llamadasQuick = 0;
int cicloWhile = 0;


//-----------------------------------------------QUICKSORT-------------------------------------------------

//----------------------------------------------------------------------------------------------------------
//Funcion para hacer cambios de posiciones, intercamcia el valor de a por el de b y viceversa
//Entradas: un entero a y un entero b
//Salidas: None
//----------------------------------------------------------------------------------------------------------
void cambio(int* a, int* b){
    cambiosP++;
    int t = *a;
    *a = *b;
    *b = t;
}
 
//QUICKSORT CON PIVOTE FIJO (PRIMER ELEMENT0)----------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------
//Funcion para hacer la divicion del array, escoge pivote y ordena los numeros mayores que el pivote a la 
//   izquierda y los otros a la derecha.
//Entradas:Recibe el array que se esta ordenando, inicio que es el indice inicial y que es el indice final + 1
//Salidas: None
//----------------------------------------------------------------------------------------------------------
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
 
//----------------------------------------------------------------------------------------------------------
//Funcion principal del QuickSort
//Entradas:Un array de tamaño n, un entero con el indice inicial y otro con el final
//Salidas: 
//----------------------------------------------------------------------------------------------------------
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

//QUICK SORT COON PIVOTE ALEATORIO--------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
//Funcion partition random hace la divicion del array, escoge pivote y ordena los numeros mayores que el 
//                          pivote a la izquierda y los otros a la derecha.
//Entradas:Recibe el array que se esta ordenando, inicio que es el indice inicial y que es el indice final + 1
//Salidas: None
//----------------------------------------------------------------------------------------------------------
int partitionRan (int arr[], int inicio, int final)
{
    comparacionesFor++;
    srand (time(NULL));
    int random = inicio + rand() % (final - inicio);
    // Swap A[random] with A[high]
    cambio(&arr[random], &arr[final]);
 
    return partition(arr, inicio, final);
}
 
//----------------------------------------------------------------------------------------------------------
//Funcion principal del QuickSort -> llama a partition en su version random
//Entradas:Un array de tamaño n, un entero con el indice inicial y otro con el final
//Salidas: 
//----------------------------------------------------------------------------------------------------------
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
//Funcion para inicializar contadores 
//Entradas: None
//Salidas: None
//---------------------------------------------------------------------------------------------------------- 
void inicializaCont(){
    cambiosP=0;
    comparacionesFor=0;
    llamadasQuick=0;
}

//----------------------------------------------------------------------------------------------------------
//Funcion para imprimir estadisticas del algoritmo
//Entradas: enteros, uno para el tiempo de ejecucion en seguntos, un contador de ciclos for, un contador de 
//          cambios y un contador de iteraciones en ciclo while
//Salidas: None, hace prints de las estadisticas.
//----------------------------------------------------------------------------------------------------------
void printEstadisticasQS(int contadorLlamadas, int contadorFOR, long double time, int cambios){
    cout << "\t\tLLAMADAS A LA FUNCION QUICK: " << contadorLlamadas << endl;
    cout << "\t\tENTRADAS AL CICLO FOR: " << contadorFOR << endl;
    cout << "\t\tCAMBIOS: " << cambios << endl;
    cout << "\t\tTiempo de ejecucion en microsegundos: " << time << endl;
    inicializaCont();
}

//----------------------------------------------------------------------------------------------------------
//Funcion para hacer las pruebas del algoritmo cuando es cuadratico
//Entradas: Un array de tamaño n y un entero con el tamaño del array
//Salidas: None
//----------------------------------------------------------------------------------------------------------
void pruebasQScuadratico( int pruebaQS[], int size){
    double time;
    auto tInicial = chrono::steady_clock::now();
    auto tFinal = chrono::steady_clock::now();

    for (int i = 0; i < size; i++){
        pruebaQS[i] = i;
    }
    
    tInicial = chrono::steady_clock::now();
    quickSort(pruebaQS, 0, size - 1);
    tFinal = chrono::steady_clock::now();

    //PRINTS CONTADORES
    cout<< "\tPIVOTE FIJO:" << endl;
    time = chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count();
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);

    //PIVOTE RANDOM
    tInicial = chrono::steady_clock::now();
    quickSortRan(pruebaQS, 0, size - 1);
    tFinal = chrono::steady_clock::now();

    cout<< "\tPIVOTE RANDOM:" << endl;
    time = chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count();
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);

}

//----------------------------------------------------------------------------------------------------------
//Funcion para hacer las pruebas del algoritmo para cuando es logaritmico
//Entradas: Un array de tamaño n y un entero con el tamaño del array
//Salidas: None
//----------------------------------------------------------------------------------------------------------
void pruebaQSlog(int pruebaQS[], int size){
    double time;
    auto tInicial = chrono::steady_clock::now();
    auto tFinal = chrono::steady_clock::now();

    for (int i = 0; i < size; i++){
        pruebaQS[i] = i;
    }
    //pruebaQS[size-1]= size/2;
    //tInicial = chrono::steady_clock::now();
    //quickSort(pruebaQS, 0, size - 1);
    //tFinal = chrono::steady_clock::now();

    //PRINTS CONTADORES
    //cout<< "\tPIVOTE FIJO:" << endl;
    //time = chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count();
    //printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);

    //PIVOTE RANDOM
    tInicial = chrono::steady_clock::now();
    quickSortRan(pruebaQS, 0, size - 1);
    tFinal = chrono::steady_clock::now();

    //cout<< "\tPIVOTE RANDOM:" << endl;
    time = chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count();
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);
}

 //------------------------------------------------MAIN------------------------------------------
int main()
{
    auto tInicial = chrono::steady_clock::now();
    auto tFinal = chrono::steady_clock::now();
    inicializaCont();
    long double time;

    //Prueba para demostrar que el algoritmo funciona
    cout << "QUICKSORT_____________________________________________________________________" << endl;
    cout <<"\n---------------------PRUEBA CON PIVOTE EN ULTIMO ELEMENTO---------------------" << endl;
    int arr[] = {10, 5, 8, 9, 2, 18, 20, -1, 2, -1000, 200, 201, 2999, 67, 17, -2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "->Prueba con: ";
    printArray(arr, n);

    tInicial = chrono::steady_clock::now();
    quickSort(arr, 0, n - 1);
    tFinal = chrono::steady_clock::now();

    //PRINTS CONTADORES
    time = chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count();
    printEstadisticasQS(llamadasQuick, comparacionesFor, time , cambiosP);
    cout << "Array ordenado: "; printArray(arr, n);

    cout <<"\n---------------------------PRUEBA CON PIVOTE RANDOM---------------------------" << endl;
    int prueba2[] = {10, 5, 8, 9, 2, 18, 20, -1, 2, -1000, 200, 201, 2999, 67, 17, -2000};
    int sizePrueba2 = sizeof(prueba2) / sizeof(prueba2[0]);
    cout << "Array sin ordenar: ";
    printArray(prueba2, sizePrueba2);
    tInicial = chrono::steady_clock::now();
    quickSortRan(prueba2, 0, sizePrueba2 - 1);
    tFinal = chrono::steady_clock::now();

    //PRINTS CONTADORES
    time = chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count();
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
    cout<<"\n\nCASO PROMEDIO-----------------------------------------------------------------"<<endl;
     //------------------------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 1000 en el caso promedio"<<endl;
    int pruebaQS1log[1000];
    pruebaQSlog(pruebaQS1log, 1000);   

    //-----------------------------------------------------------------------------------
   cout << "\n\n ->Prueba con array de 2000 en el caso promedio"<<endl;
    int pruebaQS2log[2000];
    pruebaQSlog(pruebaQS2log, 2000);  

   //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 3000 en el caso promedio"<<endl;
    int pruebaQS3log[3000];
    pruebaQSlog(pruebaQS3log, 3000);  

   //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 4000 en el caso promedio"<<endl;
    int pruebaQS4log[4000];
    pruebaQSlog(pruebaQS4log, 4000);  


    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 5000 en el caso promedio"<<endl;
    int pruebaQS5log[5000];
    pruebaQSlog(pruebaQS5log, 5000);

    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 6000 en el caso promedio"<<endl;
    int pruebaQS6log[6000];
    pruebaQSlog(pruebaQS6log, 6000);
    
    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 7000 en el caso promedio"<<endl;
    int pruebaQS7log[7000];
    pruebaQSlog(pruebaQS7log, 7000);
   
    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 8000 en el caso promedio"<<endl;
    int pruebaQS8log[8000];
    pruebaQSlog(pruebaQS8log, 8000);

    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 9000 en el caso promedio"<<endl;
    int pruebaQS9log[9000];
    pruebaQSlog(pruebaQS9log, 9000);
        
    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 10000 en el caso promedio"<<endl;
    int pruebaQS10log[10000];
    pruebaQSlog(pruebaQS10log, 10000);

    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 11000 en el caso promedio"<<endl;
    int pruebaQS11log[11000];
    pruebaQSlog(pruebaQS11log, 11000);

    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 12000 en el caso promedio"<<endl;
    int pruebaQS12log[12000];
    pruebaQSlog(pruebaQS12log, 12000);

    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 13000 en el caso promedio"<<endl;
    int pruebaQS13log[13000];
    pruebaQSlog(pruebaQS13log, 13000);

    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 14000 en el caso promedio"<<endl;
    int pruebaQS14log[14000];
    pruebaQSlog(pruebaQS14log, 14000);

    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 15000 en el caso promedio"<<endl;
    int pruebaQS15log[15000];
    pruebaQSlog(pruebaQS15log, 15000);

    //-------------------------------------------------------------------------
    cout << "\n\n ->Prueba con array de 16000 en el caso promedio"<<endl;
    int pruebaQS16log[16000];
    pruebaQSlog(pruebaQS16log, 16000);

    

    return 0;
}
/*
----------------------------------RESPUESTAS-----------------------------------
1-QUICKSORT LOGARITMICO
    En el caso del quicksort n(log(n)) se uso un pivote random en una lista
ordenada de manera ascendente, en las pruebas con este pivote no podemos
predecir como será el funcionamiento de este, pero tiende a ser mejor que 
usar un pivote fijo en con este tipo del listas.
    En la demostracion de este algoritmo se observa lo siguente:
                ->Elementos         ->Cambios
                    1000               5511
                    2000              12026
                    3000              18678
                    4000              25400
                    5000              31695
                    6000              38307
                    7000              44905
                    8000              51458
                    9000              58141
                    10000             63584
                    11000             69913
                    12000             76670
                    13000             83706
                    14000             89684
                    15000             96617
                    16000             103182
    En este caso se observa como el cambio entre el array de 1000 y de 2000 ele-
mentos hay un cambio de 6515, entre el de 2000 y el de 3000 uno de 6652, entre
el de 3000 y el de 6000 es de 6722 y asi sicesivamente, la diferencia varia entre
los 6000 y los 7000 cambios entre mayor es la entrada por cada 1000 elemento, 
pero no llega a ser uniforme ya que varia entre los elementos.
    Al graficar en relacion a los cambios vemos como se cumple el comportamiento
lineal del orden logaritmico O(n log n), ya que el cambio es similar cuando 
obtenemos entradas cada vez mas grandes

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
este, ya que si en una iterancion escogí de pivote uno de los elementos de los 
extremos puede que en la siguente iteracion no, esto porque no tengo un indicio
de como se va a comportar el algoritmo en cada iteracion, debido a la variacion 
en cada una de ellas.
    Cuando estoy en caso promedio no importa tanto porque es cuestion de suerte
la influencia que tendra el pivote sobre mi algpritmo, puede que tenga suerte con
el random o puede que no, pero en este caso hay que tener en cuenta que el random
aumentara un poco la carga del algoritmo. 
	En resumen, cuando tenemos una lista ordenada, el pivote random es la mejor
opcion, ya que nos ayuda a evitar el peor de los casos (cuando el pivote es uno
de los minimos o maximos del array), cuando tenemos una lista totalmente desorde-
nada no importa cual pivote utilicemos, ya que dependera de la posicion que se
escoja como pivote y no podemos saber cual sera un elemento intermedio, indepen-
dientemente de cual de las 2 formas usemos puede que se escoja un buen o un mal 
pivote.


*/

