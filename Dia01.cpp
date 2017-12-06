#include <program1.h>                                           // Archivo de traducción de seudocódigo a C++
/**
*    Enunciado: The captcha requires you to review a sequence of digits (your puzzle input) and find the sum of all digits that match the next digit in
                the list. The list is circular, so the digit after the last digit is the first digit in the list.

For example:
  
1122 produces a sum of 3 (1 + 2) because the first digit (1) matches the second digit and the third digit (2) matches the fourth digit.
1111 produces 4 because each digit (all 1) matches the next.
1234 produces 0 because no digit matches the next.
91212129 produces 9 because the only digit that matches the next one is the last digit, 9.
*/
principal                                                       // Unidad de programa principal
cadena captcha,cad;
limpiar;                                                        // Limpia la pantalla.
leer(captcha);
captcha += captcha[0];
entero i,t = captcha.size();
largo suma=0;
variarMas1(i,1,t-1)
    si(captcha[i] ES captcha[i-1]) entonces
        cad = captcha[i];
        mostrar << cad;
        suma += aEntero(cad);
        finSi
    finVariar
mostrar << salto << "El resultado es: " << suma << salto;
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal

