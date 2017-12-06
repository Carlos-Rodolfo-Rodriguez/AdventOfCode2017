// Archivo de traducción de seudocódigo a C++
#include "program1.h"
/**
*    Enunciado: "Based on what we're seeing, it looks like all the User wanted is some information about the evenly divisible values in the spreadsheet.
                Unfortunately, none of us are equipped for that kind of calculation - most of us specialize in bitwise operations."
                It sounds like the goal is to find the only two numbers in each row where one evenly divides the other - that is, where the result of 
                the division operation is a whole number. They would like you to find those numbers on each line, divide them, and add up each line's 
                result.

For example, given the following spreadsheet:

5 9 2 8
9 4 7 3
3 8 6 5
In the first row, the only two numbers that evenly divide are 8 and 2; the result of this division is 4.
In the second row, the two numbers are 9 and 3; the result is 3.
In the third row, the result is 2.
In this example, the sum of the results would be 4 + 3 + 2 = 9.
*/
constante entero T = 16;

principal                                                       // Unidad de programa principal
entero m[T][T],f,c,c2,v1,v2;
cadena renglon;
largo suma = 0;
limpiar;                                                        // Limpia la pantalla.
variarMas1(f,0,T-1);
    variarMas1(c,0,T-1)
        leer(m[f][c]);
        finVariar
    variarMas1(c,0,T-1)
        v1 = m[f][c];
        variarMas1(c2,0,T-1)
            v2 = m[f][c2];
            si(c NOES c2 Y v1 > v2 Y esMult(v1,v2)) entonces
                suma += v1 / v2;
                c2 = c = T;
                finSi
            finVariar
        finVariar
    finVariar
mostrar << "Suma: "<< suma << salto;
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal                                                    // Fin de unidad de programa principal.


