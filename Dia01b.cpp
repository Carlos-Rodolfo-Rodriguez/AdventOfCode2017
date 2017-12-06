#include <program1.h>                                           // Archivo de traducción de seudocódigo a C++
/**
*    Enunciado: The instructions change:Now, instead of considering the next digit, it wants you to consider the digit halfway around the circular list.
                That is, if your list contains 10 items, only include a digit in your sum if the digit 10/2 = 5 steps forward matches it. 
                Fortunately, your list has an even number of elements.

For example:

1212 produces 6: the list contains 4 items, and all four digits match the digit 2 items ahead.
1221 produces 0, because every comparison is between a 1 and a 2.
123425 produces 4, because both 2s match each other, but no other digit has a match.
123123 produces 12.
12131415 produces 4..
*/
principal                                                       // Unidad de programa principal
cadena captcha,cad;
limpiar;                                                        // Limpia la pantalla.
leer(captcha);
entero i,i2,t = captcha.size();
largo suma=0;
variarMas1(i,1,t-1)
    i2 = i + t/2;
    si(i2 >= t) i2 -= t; 
    si(captcha[i] ES captcha[i2]) entonces
        cad = captcha[i];
        mostrar << cad;
        suma += aEntero(cad);
        finSi
    finVariar
mostrar << salto << "El resultado es: " << suma << salto;
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal

