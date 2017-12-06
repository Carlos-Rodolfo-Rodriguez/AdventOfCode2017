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
    si(esComPal(cAnt,c)) entonces
        pal = c;
        sinoSi(NO esSigno(c)) entonces
        pal += c;
        sinoSi(esFinPal(cAnt,c)) entonces
        agregaEleVDin(resul,pal);
        finSi
    cAnt = c;
    finParaCada
regresa(resul);
}

funcion logica esAnagrama(cadena c1, cadena c2) {
logico resul;
entero lC1 = longitud(c1)
      ,lC2 = longitud(c2)
      ,posi;
//mostrar << "|"+c1+"|"+c2+"|\n";
si(lC1 ES lC2 Y lC2 ES 0 O c1 ES c2) entonces
    resul = VERDADERO;
    sinoSi(lC1 ES lC2) entonces
    posi = posCarEnCad(c1[0],c2);
    si(posi >= 0) entonces
        resul = esAnagrama(sinPrimerCar(c1),sinCarPos(posi+1,c2));
        sino
        resul = FALSO;
        finSi
    sino 
    resul = FALSO;
    finSi
regresa(resul);
}

funcion entera anagramas(vectorDin(cadena) palabras) {
entero resul = 0
      ,t = tamanio(palabras)
      ,i1,i2;
variarMas1(i1,0,t-2)
    variarMas1(i2,i1+1,t-1)
        si(esAnagrama(palabras[i1],palabras[i2])) resul++;
        finVariar
    finVariar
regresa(resul);
}

funcion logica esValida(cadena fr) {
vectorDin(cadena) palabras = palabrea(fr);
logico resul = anagramas(palabras) ES 0;
regresa(resul);
}

principal                                                       // Unidad de programa principal
cadena frase = "";
entero cant = 0;
limpiar;                                                        // Limpia la pantalla.
iterar
    leeRenglon(cin,frase);
    salirSi(frase ES "");
    si(esValida(frase)) entonces 
        cant++;
        finSi
    finIterar
mostrar << "Válidas:" << cant << salto;
//pausa;                                                          // Pausa antes de finalizar. 
finPrincipal                                                    // Fin de unidad de programa principal.


