#include <program1.h>                                           // Archivo de traducción de seudocódigo a C++
/**
*    Enunciado: To prove you've removed it, you need to count all of the characters within the garbage. The leading and trailing < and > don't count, nor do any canceled characters or the ! doing the canceling.

<>, 0 characters.
<random characters>, 17 characters.
<<<<>, 3 characters.
<{!>}>, 2 characters.
<!!>, 0 characters.
<!!!>>, 0 characters.
<{o"i!a,<{i<a>, 10 characters.
How many non-canceled characters are within the garbage in your puzzle input?
*/
funcion entera cuentaBasura(cadena conBasura) {
entero resul = 0;
//cadena cadLimpia = "";
caracter cAnt = ' ';
logico esBasura = FALSO;
paraCada(car,conBasura)
    si(cAnt NOES '!') entonces
        si(car ES '<' Y NO esBasura) entonces
            esBasura = VERDADERO;
            sinoSi(car ES '>' Y esBasura) entonces
            esBasura = FALSO;
            sinoSi(esBasura Y car NOES '!') entonces
            resul++;
//            sinoSi(NO esBasura Y (car ES '{' O car ES '}')) entonces
//            cadLimpia += car;
            finSi
        cAnt = car;
        sinoSi(car ES '!') entonces
        cAnt = ' ';
        sino
        cAnt = ' ';
        finSi
    finParaCada
regresa(resul);
}

principal                                                       // Unidad de programa principal
cadena renglon;
limpiar;                                                        // Limpia la pantalla.
iterar
    leeRenglon(cin,renglon);
    salirSi( renglon ES "");
//    mostrar << "Original:" << renglon << salto;
    mostrar << "Removidos:" << cuentaBasura(renglon) << salto;
    finIterar
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal

