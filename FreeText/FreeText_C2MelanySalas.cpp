
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <fstream>

using namespace std; 
const int t = 256;
const int w = 1283;
int contApariciones = 0;


void Rabin_Karp_Algorithm(string text,string pattern){
    
    //Length of text string.
    int tlen = text.length();
    
    //Length of pattern string.
    int plen = pattern.length();
    
    int flag;
    int c=1,i=0;
    
    //Calculate hash_p(hash value of pattern) and hash_0
    int hash_p=0,hash=0;
    while(i<plen){
        hash_p=(hash_p*t + pattern[i])%w;
        hash=(hash*t + text[i])%w;
        i++;
    }
    //plen-> largo de la palabra
     //Calculate (t^(plen-1))%w
    for(int i=1;i<=plen-1;i++)
        c=(c*t)%w;
    
    i=0;
    while(i<=tlen-plen){
       if(hash_p==hash){
            flag=1;
            for(int j=0;j<plen;j++){
                if(pattern[j]==text[i+j]){
                    continue;
                }
                else{
                    flag = 0;
                    break;
                }
           }
            if(flag==1){
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

          
 
int main() 
{ 
    string text;
    string texto;
    ifstream fe("prueba.txt");
    while (!fe.eof()) {
        fe >> texto;
        text.append(texto);
        text.append(" ");
    }
    fe.close();
    string pattern="una";
    Rabin_Karp_Algorithm(text,pattern);
    cout << "Apariciones de " << pattern << ": "<< contApariciones;
    return 0; 
}
/*
----------------------------------RESPUESTAS-----------------------------------
7- Lograr un freetext search en tiempo logarítmico o lineal. Se recomienda usar un texto de mínimo 10MB.
En este caso use el algoritmo de rabin karp, cuyo tiempo de 
en O(patternLength+ textLength), resultando como un algorit-
mo lineal, ya que nuestro O(n) aumentara en 1 por cada elemen-
to o caracter que le agreguemos al patron que estamos buscando.

*/