# Caso-2-Analisis-de-algoritmos
Caso 2 Melany Salas Fernández

Nota* En el excel se encuentran tablas con los datos de unos pruebas, tambien
estan los graficos de cada una de las funciones de acuerdo a los datos obtenidos
en cada prueba.

---------------------------------Analisis-----------------------------------
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
casos, esto se da porque cuando escogemos el pivote se escoge al numero mayor
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

-----------------------------------------------------------------------------------
4- INSERTION SORT LINEAL

    Cuando nos encontramos con el mejor de los casos en el insertion sort
no tenemos que hacer cambios, debido a que el algoritmo ya esta previamente
ordenado, si vemos las iteraciones estan directamente relacionadas con la
cantidad de elementos del array, si tengo un array de 200 elementos y estan
ordenados se haran 199 itenaciones y 0 cambios, si tenemos uno de 300 se 
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
prueba por cada 2000 elementos hay un aumento de 2000 en los cambios,
usando la formula de razon de cambio en funciones obtenemos que:
        Formula= (f(x1)-f(x2))/ x1-x2
                = (4000-2000)/ (3999-1999)
                = 1
Lo que nos indica que por cada elemento en el array vamos a tener un crecimciento 
de 1 en iteraciones, como es este caso:
                    ->Prueba con array de 20000 lineal
                        Tiempo de ejecución: 0
                        ENTRADAS AL CICLO FOR: 19999
                        CAMBIOS: 0
                        ITERACIONES DEL CICLO WHILE:  0


                    ->Prueba2 con array de 20001 lineal
                        Tiempo de ejecución: 0
                        ENTRADAS AL CICLO FOR: 20000
                        CAMBIOS: 0
                        ITERACIONES DEL CICLO WHILE:  0

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

------------------------------------------------------------------------------------
7- LOGRAR UN FREETEXT LOGARITMICO O LINEAL.

En este caso use el algoritmo de rabin karp, cuyo tiempo de en O(patternLength + 
textLength), resultando como un algoritmo lineal, ya que nuestro O(n) aumentara 
en 1 por cada elemento o caracter que le agreguemos al patron que estamos buscando.

____________________________________________________________________________
---------------------------------Pruebas------------------------------------
QUICKSORT_____________________________________________________________________

---------------------PRUEBA CON PIVOTE EN ULTIMO ELEMENTO---------------------
->Prueba con: 10 5 8 9 2 18 20 -1 2 -1000 200 201 2999 67 17 -2000 
		LLAMADAS A LA FUNCION QUICK: 21
		ENTRADAS AL CICLO FOR: 54
		CAMBIOS: 27
		Tiempo de ejecucion en microsegundos: 0
Array ordenado: -2000 -1000 -1 2 2 5 8 9 10 17 18 20 67 200 201 2999 

---------------------------PRUEBA CON PIVOTE RANDOM---------------------------
Array sin ordenar: 10 5 8 9 2 18 20 -1 2 -1000 200 201 2999 67 17 -2000 
		LLAMADAS A LA FUNCION QUICK: 21
		ENTRADAS AL CICLO FOR: 54
		CAMBIOS: 36
		Tiempo de ejecucion en microsegundos: 0
Array ordenado: -2000 -1000 -1 2 2 5 8 9 10 17 18 20 67 200 201 2999 


 ->Prueba con array de 2000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 3999
		ENTRADAS AL CICLO FOR: 1999000
		CAMBIOS: 2000999
		Tiempo de ejecucion en microsegundos: 19002
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 2001
		ENTRADAS AL CICLO FOR: 25300
		CAMBIOS: 13297
		Tiempo de ejecucion en microsegundos: 0

 ->Prueba con array de 4000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 7999
		ENTRADAS AL CICLO FOR: 7998000
		CAMBIOS: 8001999
		Tiempo de ejecucion en microsegundos: 78006
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 4001
		ENTRADAS AL CICLO FOR: 54576
		CAMBIOS: 29052
		Tiempo de ejecucion en microsegundos: 1000

 ->Prueba con array de 6000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 11999
		ENTRADAS AL CICLO FOR: 17997000
		CAMBIOS: 18002999
		Tiempo de ejecucion en microsegundos: 182013
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 6001
		ENTRADAS AL CICLO FOR: 87459
		CAMBIOS: 48705
		Tiempo de ejecucion en microsegundos: 1002

 ->Prueba con array de 8000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 15999
		ENTRADAS AL CICLO FOR: 31996000
		CAMBIOS: 32003999
		Tiempo de ejecucion en microsegundos: 342024
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 9881
		ENTRADAS AL CICLO FOR: 123596
		CAMBIOS: 60429
		Tiempo de ejecucion en microsegundos: 1001

 ->Prueba con array de 10000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 19999
		ENTRADAS AL CICLO FOR: 49995000
		CAMBIOS: 50004999
		Tiempo de ejecucion en microsegundos: 512038
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 12391
		ENTRADAS AL CICLO FOR: 148025
		CAMBIOS: 83036
		Tiempo de ejecucion en microsegundos: 1000

 ->Prueba con array de 12000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 23999
		ENTRADAS AL CICLO FOR: 71994000
		CAMBIOS: 72005999
		Tiempo de ejecucion en microsegundos: 724058
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 12001
		ENTRADAS AL CICLO FOR: 189162
		CAMBIOS: 101737
		Tiempo de ejecucion en microsegundos: 3994

 ->Prueba con array de 14000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 27999
		ENTRADAS AL CICLO FOR: 97993000
		CAMBIOS: 98006999
		Tiempo de ejecucion en microsegundos: 920604
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 18093
		ENTRADAS AL CICLO FOR: 218472
		CAMBIOS: 119731
		Tiempo de ejecucion en microsegundos: 2002

 ->Prueba con array de 16000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 31999
		ENTRADAS AL CICLO FOR: 127992000
		CAMBIOS: 128007999
		Tiempo de ejecucion en microsegundos: 1.2511e+006
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 23119
		ENTRADAS AL CICLO FOR: 299593
		CAMBIOS: 133241
		Tiempo de ejecucion en microsegundos: 3001


 ->Prueba con array de 18000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 35999
		ENTRADAS AL CICLO FOR: 161991000
		CAMBIOS: 162008999
		Tiempo de ejecucion en microsegundos: 1.62803e+006
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 26063
		ENTRADAS AL CICLO FOR: 491679
		CAMBIOS: 154900
		Tiempo de ejecucion en microsegundos: 2999


 ->Prueba con array de 20000 en el peor de los casos
	PIVOTE FIJO:
		LLAMADAS A LA FUNCION QUICK: 39999
		ENTRADAS AL CICLO FOR: 199990000
		CAMBIOS: 200009999
		Tiempo de ejecucion en microsegundos: 2.29407e+006
	PIVOTE RANDOM:
		LLAMADAS A LA FUNCION QUICK: 20001
		ENTRADAS AL CICLO FOR: 514116
		CAMBIOS: 171958
		Tiempo de ejecucion en microsegundos: 3001

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

 ->Prueba con array de 1000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 1297
		ENTRADAS AL CICLO FOR: 11096
		CAMBIOS: 5511
		Tiempo de ejecucion en microsegundos: 0


 ->Prueba con array de 2000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 2601
		ENTRADAS AL CICLO FOR: 29840
		CAMBIOS: 12026
		Tiempo de ejecucion en microsegundos: 1054


 ->Prueba con array de 3000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 3901
		ENTRADAS AL CICLO FOR: 50116
		CAMBIOS: 18678
		Tiempo de ejecucion en microsegundos: 1004


 ->Prueba con array de 4000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 5209
		ENTRADAS AL CICLO FOR: 70910
		CAMBIOS: 25400
		Tiempo de ejecucion en microsegundos: 1998


 ->Prueba con array de 5000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 6507
		ENTRADAS AL CICLO FOR: 93265
		CAMBIOS: 31695
		Tiempo de ejecucion en microsegundos: 1000


 ->Prueba con array de 6000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 7815
		ENTRADAS AL CICLO FOR: 115559
		CAMBIOS: 38307
		Tiempo de ejecucion en microsegundos: 2001


 ->Prueba con array de 7000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 9117
		ENTRADAS AL CICLO FOR: 139336
		CAMBIOS: 44905
		Tiempo de ejecucion en microsegundos: 2002


 ->Prueba con array de 8000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 10419
		ENTRADAS AL CICLO FOR: 163897
		CAMBIOS: 51458
		Tiempo de ejecucion en microsegundos: 2999


 ->Prueba con array de 9000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 11721
		ENTRADAS AL CICLO FOR: 189612
		CAMBIOS: 58141
		Tiempo de ejecucion en microsegundos: 4001


 ->Prueba con array de 10000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 13025
		ENTRADAS AL CICLO FOR: 209420
		CAMBIOS: 63584
		Tiempo de ejecucion en microsegundos: 4001


 ->Prueba con array de 11000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 14323
		ENTRADAS AL CICLO FOR: 236227
		CAMBIOS: 69913
		Tiempo de ejecucion en microsegundos: 4001


 ->Prueba con array de 12000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 15633
		ENTRADAS AL CICLO FOR: 263380
		CAMBIOS: 76670
		Tiempo de ejecucion en microsegundos: 4999


 ->Prueba con array de 13000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 16935
		ENTRADAS AL CICLO FOR: 292869
		CAMBIOS: 83706
		Tiempo de ejecucion en microsegundos: 5004


 ->Prueba con array de 14000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 18229
		ENTRADAS AL CICLO FOR: 323036
		CAMBIOS: 89684
		Tiempo de ejecucion en microsegundos: 3996


 ->Prueba con array de 15000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 19541
		ENTRADAS AL CICLO FOR: 353648
		CAMBIOS: 96617
		Tiempo de ejecucion en microsegundos: 4000


 ->Prueba con array de 16000 en el caso promedio
		LLAMADAS A LA FUNCION QUICK: 20841
		ENTRADAS AL CICLO FOR: 385170
		CAMBIOS: 103182
		Tiempo de ejecucion en microsegundos: 4000


INSERTION SORT_____________________________________________________________________
Array sin ordenar: 
10 5 8 9 2 18 20 -1 2 -1000 200 201 2999 67 17 -2000 
TIEMPO DE EJECUCION: 0
ENTRADAS AL CICLO FOR: 15
CAMBIOS: 53
Array ordenado: 
-2000 -1000 -1 2 2 5 8 9 10 17 18 20 67 200 201 2999 


 ->Prueba con array de 2000 lineal
		TIEMPO DE EJECUCION: 0
		ENTRADAS AL CICLO FOR: 1999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 4000 lineal
		TIEMPO DE EJECUCION: 0
		ENTRADAS AL CICLO FOR: 3999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 6000 lineal
		TIEMPO DE EJECUCION: 0
		ENTRADAS AL CICLO FOR: 5999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 8000 lineal
		TIEMPO DE EJECUCION: 0
		ENTRADAS AL CICLO FOR: 7999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 10000 lineal
		TIEMPO DE EJECUCION: 0
		ENTRADAS AL CICLO FOR: 9999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 12000 lineal
		TIEMPO DE EJECUCION: 0
		ENTRADAS AL CICLO FOR: 11999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 14000 lineal
		TIEMPO DE EJECUCION: 0
		ENTRADAS AL CICLO FOR: 13999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 16000 lineal
		TIEMPO DE EJECUCION: 1000
		ENTRADAS AL CICLO FOR: 15999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 18000 lineal
		TIEMPO DE EJECUCION: 0
		ENTRADAS AL CICLO FOR: 17999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 20000 lineal
		TIEMPO DE EJECUCION: 1001
		ENTRADAS AL CICLO FOR: 19999
		CAMBIOS: 0
		ITERACIONES DEL CICLO WHILE:  0


 ->Prueba con array de 2000 cuadratico
		TIEMPO DE EJECUCION: 7997
		ENTRADAS AL CICLO FOR: 1999
		CAMBIOS: 1999000
		ITERACIONES DEL CICLO WHILE:  1999000


 ->Prueba con array de 4000 cuadratico
		TIEMPO DE EJECUCION: 33003
		ENTRADAS AL CICLO FOR: 3999
		CAMBIOS: 7998000
		ITERACIONES DEL CICLO WHILE:  7998000


 ->Prueba con array de 6000 cuadratico
		TIEMPO DE EJECUCION: 78007
		ENTRADAS AL CICLO FOR: 5999
		CAMBIOS: 17997000
		ITERACIONES DEL CICLO WHILE:  17997000


 ->Prueba con array de 8000 cuadratico
		TIEMPO DE EJECUCION: 167013
		ENTRADAS AL CICLO FOR: 7999
		CAMBIOS: 31996000
		ITERACIONES DEL CICLO WHILE:  31996000


 ->Prueba con array de 10000 cuadratico
		TIEMPO DE EJECUCION: 226015
		ENTRADAS AL CICLO FOR: 9999
		CAMBIOS: 49995000
		ITERACIONES DEL CICLO WHILE:  49995000


 ->Prueba con array de 12000 cuadratico
		TIEMPO DE EJECUCION: 344027
		ENTRADAS AL CICLO FOR: 11999
		CAMBIOS: 71994000
		ITERACIONES DEL CICLO WHILE:  71994000


 ->Prueba con array de 14000 cuadratico
		TIEMPO DE EJECUCION: 361029
		ENTRADAS AL CICLO FOR: 13999
		CAMBIOS: 97993000
		ITERACIONES DEL CICLO WHILE:  97993000


 ->Prueba con array de 16000 cuadratico
		TIEMPO DE EJECUCION: 508036
		ENTRADAS AL CICLO FOR: 15999
		CAMBIOS: 127992000
		ITERACIONES DEL CICLO WHILE:  127992000


 ->Prueba con array de 18000 cuadratico
		TIEMPO DE EJECUCION: 691054
		ENTRADAS AL CICLO FOR: 17999
		CAMBIOS: 161991000
		ITERACIONES DEL CICLO WHILE:  161991000


 ->Prueba con array de 20000 cuadratico
		TIEMPO DE EJECUCION: 1.09908e+006
		ENTRADAS AL CICLO FOR: 19999
		CAMBIOS: 199990000
		ITERACIONES DEL CICLO WHILE:  199990000

_________________________________FREETEXT____________________________________
-----------------------------------------------------------------------------
Cargando texto...
El texto ha sido cargado con exito
Tiempo de cargado: 2.085
Presione una tecla para continuar . . .

-----------------------------------------------------------------------------
Patron a buscar : the city was still quiet and still cool
-----------------------------------------------------------------------------
Presione una tecla para continuar . . .
Encontrado en: 1109249
Encontrado en: 2815023
-----------------------------------------------------------------------------
Apariciones de the city was still quiet and still cool: 2
Tiempo de busqueda: 0.34
-----------------------------------------------------------------------------
Patron a buscar : The next day
-----------------------------------------------------------------------------
Presione una tecla para continuar . . .
Encontrado en: 9418
Encontrado en: 73579
Encontrado en: 254087
Encontrado en: 355885
Encontrado en: 434888
Encontrado en: 640491
Encontrado en: 745859
Encontrado en: 754926
Encontrado en: 770844
Encontrado en: 772450
Encontrado en: 817067
Encontrado en: 855033
Encontrado en: 878500
Encontrado en: 928206
Encontrado en: 932143
Encontrado en: 953052
Encontrado en: 973876
Encontrado en: 1011862
Encontrado en: 1055687
Encontrado en: 1200670
Encontrado en: 1201965
Encontrado en: 1300808
Encontrado en: 1428346
Encontrado en: 1479741
Encontrado en: 1520260
Encontrado en: 1621287
Encontrado en: 1625508
Encontrado en: 1673535
Encontrado en: 1715192
Encontrado en: 1779353
Encontrado en: 1959861
Encontrado en: 2061659
Encontrado en: 2140662
Encontrado en: 2346265
Encontrado en: 2451633
Encontrado en: 2460700
Encontrado en: 2476618
Encontrado en: 2478224
Encontrado en: 2522841
Encontrado en: 2560807
Encontrado en: 2584274
Encontrado en: 2633980
Encontrado en: 2637917
Encontrado en: 2658826
Encontrado en: 2679650
Encontrado en: 2717636
Encontrado en: 2761461
Encontrado en: 2906444
Encontrado en: 2907739
Encontrado en: 3006582
Encontrado en: 3134120
Encontrado en: 3185515
Encontrado en: 3226034
Encontrado en: 3327061
Encontrado en: 3331282
Encontrado en: 3379309
-----------------------------------------------------------------------------
Apariciones de The next day: 58
Tiempo de busqueda: 0.275

