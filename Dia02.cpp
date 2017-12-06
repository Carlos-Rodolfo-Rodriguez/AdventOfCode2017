// Archivo de traducción de seudocódigo a C++
#include "program1.h"
/**
*    Enunciado: The spreadsheet consists of rows of apparently-random numbers. To make sure the recovery process is on the right track, they need you to
                calculate the spreadsheet's checksum. For each row, determine the difference between the largest value and the smallest value; the 
                checksum is the sum of all of these differences.

For example, given the following spreadsheet:

5 1 9 5
7 5 3
2 4 6 8
The first row's largest and smallest values are 9 and 1, and their difference is 8.
The second row's largest and smallest values are 7 and 3, and their difference is 4.
The third row's difference is 6.
In this example, the spreadsheet's checksum would be 8 + 4 + 6 = 18.


*/
constante entero T = 16;

principal                                                       // Unidad de programa principal
entero m[T][T],f,c,mini,maxi;
cadena renglon;
largo suma = 0;
limpiar;                                                        // Limpia la pantalla.
variarMas1(f,0,T-1);
    leer(m[f][0]);
    mostrar << m[f][0] << " - ";
    mini = maxi = m[f][0];
    variarMas1(c,1,T-1)
        leer(m[f][c]);
        si(m[f][c] < mini) entonces
            mini = m[f][c];
            sinoSi(m[f][c] > maxi) entonces
            maxi = m[f][c];
            finSi
        mostrar << m[f][c] << fSi(c < (T-1)," - ","\n");
        finVariar
    mostrar << mini << " <-> " << maxi << salto;
    suma += maxi - mini;
    finVariar
mostrar << "Suma: "<< suma << salto;
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal                                                    // Fin de unidad de programa principal.


