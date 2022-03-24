//Instituto Tecnologico de Costa Rica
//Caso 2- Análisis de algoritmos
//Melany Salas Fernandez_2021121147
//GitHub: https://github.com/MelSaFer/Caso-2-Analisis-de-algoritmos.git

//LIBRERIAS____________________________________________________________________________________________
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <fstream>
#include <time.h> 
#include <ctime> 
#include <chrono>


using namespace std; 

//VARIABLES GLOBALES______________________________________________________________________________________

const int t = 256;
const int w = 1283;
int contApariciones = 0;
int contComparaciones = 0;

//----------------------------------------------------------------------------------------------------------
//Funcion RabinKarp-> Freetext para busqueda de substrings
//Entradas: El texto en el que voy a buscar y el patron a buscar
//Salidas: None, hace un print de los indices en los que encuentra el patron en el texto
//----------------------------------------------------------------------------------------------------------
void Rabin_Karp_Algorithm(string text,string pattern){
    int tlen = text.length();    //Largo del texto
    int plen = pattern.length(); //Largo del patron
    int flag;  //Flag para saber si he encotrado el patron el el texto
    int c=1,i=0;
    
    //Cálculos del hash
    int hash_p=0,hash=0;
    while(i < plen){                        //i debe ser menor que el largo de la palabra
        hash_p=(hash_p*t + pattern[i])%w;   //Calculo del hash del patron
        hash=(hash*t + text[i])%w;          //Calculo del hash del texto
        i++;                                //Se incrementa el indice
    }
    //plen-> largo de la palabra
     //Calculate (t^(plen-1))%w  ->w= variable global con el valor 1283
    for(int i = 1; i <= plen - 1; i++)
        c=(c*t)%w;
    
    i=0;
    while(i <= tlen-plen){     //i debe ser menor o igual que el largo del texto menos el largo de la palabra
       if(hash_p == hash){     //Si el hash del patron es igual al hast del texto hay posibilidad de haya coincidencia
            flag=1;            //Si la flag se mantiene en 1 sigifica que el patron coicide
            for(int j = 0; j < plen; j++){   //Ciclo para comparar el patron con el substring en el texto
                if(pattern[j] == text[i+j]){
                    continue;    
                }
                else{
                    flag = 0;   //Cuando la flag cambia a 0 es porque el patron encontro una parte que no coincidia
                    break;
                }
           }
            if(flag==1){    //Si flag es significa que ha encontrado la palabra del patron en el texto
                cout <<"Encontrado en: " << i << endl;
                contApariciones++;
            }
       }
       //Calculate hash value of next window
       //hash_i+1 = t * {hash_i - text[i] * t^(plen-1)} + text[i+plen]
       if(i<tlen-plen){
           hash=((t*(hash-text[i]*c))+text[i+plen])%w;
            if(hash<0){
                hash = hash + w;
            }
       }
       i++;
    }
}

          
//MAIN___________________________________________________________________________________________________
int main() 
{ 
    //Variables para el cargado del texto
    string text;  //Se usa para almacenar el texto total
    string texto; //Va guardando palabra por palabra, conforme voy leyendo
    //Variables para tomar tiempo
    auto tInicial = chrono::steady_clock::now();
    auto tFinal = chrono::steady_clock::now();

    //---------------------------------------------------------------------------------------------------
    //----------------------------------------Cargado de texto-------------------------------------------

    cout <<"\n-----------------------------------------------------------------------------"<< endl;
    cout<< "Cargando texto..."<<endl;

    tInicial = chrono::steady_clock::now();
    ifstream fe("prueba.txt");
    while (!fe.eof()) {
        fe >> texto;
        text.append(texto);
        text.append(" ");
    }
    fe.close();

    tFinal = chrono::steady_clock::now();
    cout << "El texto ha sido cargado con exito"<<endl;

    cout << "Tiempo de cargado en microsegundos: " << chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count() <<endl;
    system("pause");

    //---------------------------------------------------------------------------------------------------
    //--------------------------------------------Prueba 1-----------------------------------------------
    string pattern="the city was still quiet and still cool";

    cout <<"\n-----------------------------------------------------------------------------"<< endl;
    cout << "Patron a buscar : " << pattern << endl;
    cout <<"-----------------------------------------------------------------------------"<< endl;
    system("pause");

    tInicial = chrono::steady_clock::now();
    Rabin_Karp_Algorithm(text,pattern);
    tFinal = chrono::steady_clock::now();

    cout <<"-----------------------------------------------------------------------------"<< endl;
    cout << "Apariciones de " << pattern << ": "<< contApariciones << endl;
    cout << "Tiempo de busqueda en microsegundos: " << chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count() <<endl;

    //---------------------------------------------------------------------------------------------------
    //--------------------------------------------Prueba 2-----------------------------------------------
    pattern="The next day";

    cout <<"\n-----------------------------------------------------------------------------"<< endl;
    cout << "Patron a buscar : " << pattern << endl;
    cout <<"-----------------------------------------------------------------------------"<< endl;
    system("pause");

    tInicial = chrono::steady_clock::now();
    Rabin_Karp_Algorithm(text,pattern);
    tFinal = chrono::steady_clock::now();

    cout <<"-----------------------------------------------------------------------------"<< endl;
    cout << "Apariciones de " << pattern << ": "<< contApariciones << endl;
    cout << "Tiempo de busqueda en microsegundos: " << chrono::duration_cast<chrono::microseconds>(tFinal - tInicial).count() <<endl;

    return 0; 
}
/*
--------------------------------------------RESPUESTAS------------------------------------------------
7- Lograr un freetext search en tiempo logarítmico o lineal. Se recomienda usar un texto de mínimo 10MB.
    En este caso use el algoritmo de rabin karp, cuyo tiempo es O(patternLength + textLength), 
resultando como un algoritmo lineal, ya que nuestro O(n) aumentara en 1 por cada elemento o caracter
que le agreguemos al patron que estamos buscando o al texto en el que buscaremos.
    ____________________________________________________________________________________
            Tamaño de patron        Tamaño del texto           O(np+nt)
    ------------------------------------------------------------------------------------
                    2                       10                     12
                    3                       10                     13
                    4                       10                     14
                    5                       10                     15
                    6                       10                     16
   --------------------------------------------------------------------------------------
                    2                       100                    102
                    3                       100                    103
                    4                       100                    104
                    5                       100                    105
                    6                       100                    106


*/