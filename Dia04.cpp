#include "program1.h"
/**
*    Enunciado: 
*/
funcion vectorDin(cadena) palabrea(cadena fr) {
vectorDin(cadena) resul;
cadena pal;
caracter cAnt = ' ';
fr += ".";
paraCada(c,fr)
//    mostrar << c;
    si(esComPal(cAnt,c)) entonces
        pal = c;
        sinoSi(NO esSigno(c)) entonces
        pal += c;
        sinoSi(esFinPal(cAnt,c)) entonces
        agregaEleVDin(resul,pal);
//        mostrar << salto << pal << salto;
        finSi
    cAnt = c;
    finParaCada
//mostrar << "<---" << salto;
regresa(resul);
}

funcion entera veces(cadena estaPal, vectorDin(cadena) pals) {
entero resul = 0; 
//mostrar << "--->|" << estaPal;
paraCada(pal,pals)
    si(pal ES estaPal) entonces
        resul++;
//        mostrar << pal << "==" << estaPal << salto;
        sino
//        mostrar << pal << "<>" << estaPal << salto;
        finSi
    finParaCada
//mostrar << "|<--- " << resul << " veces.\n";
regresa(resul);
}

funcion entera ocurrencias(vectorDin(cadena) pals) {
entero ve
      ,resul = 0;
paraCada(pal,pals)
    ve = veces(pal,pals);
    si(ve > resul) entonces
        resul = ve;
        finSi
    finParaCada
regresa(resul);
}

funcion logica esValida(cadena fr) {
vectorDin(cadena) palabras = palabrea(fr);
logico resul = ocurrencias(palabras) ES 1;
regresa(resul);
}

principal                                                       // Unidad de programa principal
cadena frase = "";
entero cant = 0;
limpiar;                                                        // Limpia la pantalla.
iterar
    leeRenglon(cin,frase);
    salirSi(frase ES "");
//    mostrar << frase;
    si(esValida(frase)) entonces 
        cant++;
//        mostrar << salto;
//        mostrar << " <-- SI:" << cant << salto;
        sino
//        mostrar << " <-- NO" << salto;
        finSi
    finIterar
mostrar << "Válidas:" << cant << salto;
//pausa;                                                          // Pausa antes de finalizar. 
finPrincipal                                                    // Fin de unidad de programa principal.


