#include <program1.h>                                           // Archivo de traducción de seudocódigo a C++
/**
*    Enunciado: This hash function simulates tying a knot in a circle of string with 256 marks on it. Based on the input to be hashed, the function repeatedly selects a span of 
                string, brings the ends together, and gives the span a half-twist to reverse the order of the marks within it. After doing this many times, the order of the marks 
                is used to build the resulting hash.
  4--5   pinch   4  5           4   1
 /    \  5,0,1  / \/ \  twist  / \ / \
3      0  -->  3      0  -->  3   X   0
 \    /         \ /\ /         \ / \ /
  2--1           2  1           2   5
                To achieve this, begin with a list of numbers from 0 to 255, a current position which begins at 0 (the first element in the list), a skip size (which starts at 0), 
                and a sequence of lengths (your puzzle input). Then, for each length:
                - Reverse the order of that length of elements in the list, starting with the element at the current position.
                - Move the current position forward by that length plus the skip size.
                - Increase the skip size by one.
                The list is circular; if the current position and the length try to reverse elements beyond the end of the list, the operation reverses using as many extra elements
                as it needs from the front of the list. If the current position moves past the end of the list, it wraps around to the front. Lengths larger than the size of the 
                list are invalid.
                Here's an example using a smaller list:
                Suppose we instead only had a circular list containing five elements, 0, 1, 2, 3, 4, and were given input lengths of 3, 4, 1, 5.
                - The list begins as [0] 1 2 3 4 (where square brackets indicate the current position).
                - The first length, 3, selects ([0] 1 2) 3 4 (where parentheses indicate the sublist to be reversed). After reversing that section (0 1 2 into 2 1 0), we 
                  get ([2] 1 0) 3 4.
                - Then, the current position moves forward by the length, 3, plus the skip size, 0: 2 1 0 [3] 4. Finally, the skip size increases to 1.
                - The second length, 4, selects a section which wraps: 2 1) 0 ([3] 4. The sublist 3 4 2 1 is reversed to form 1 2 4 3: 4 3) 0 ([1] 2.
                - The current position moves forward by the length plus the skip size, a total of 5, causing it not to move because it wraps around: 4 3 0 [1] 2. 
                - The skip size increases to 2.
                - The third length, 1, selects a sublist of a single element, and so reversing it has no effect.
                - The current position moves forward by the length (1) plus the skip size (2): 4 [3] 0 1 2. The skip size increases to 3.
                - The fourth length, 5, selects every element starting with the second: 4) ([3] 0 1 2. Reversing this sublist (3 0 1 2 4 into 4 2 1 0 3) produces: 3) ([4] 2 1 0.
                - Finally, the current position moves forward by 8: 3 4 2 1 [0]. The skip size increases to 4.
                In this example, the first two numbers in the list end up being 3 and 4; to check the process, you can multiply them together to produce 12.
                However, you should instead use the standard list size of 256 (with values 0 to 255) and the sequence of lengths in your puzzle input. Once this process is complete,
                what is the result of multiplying the first two numbers in the list?
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

plantilla(Tipo)
procedimiento muestraV(vectorDin(Tipo) v) {
paraCada(ele,v)
    mostrar << ele << "  ";
    finParaCada
mostrar << salto;
}

plantilla(Tipo)
procedimiento muestraV(entero t, Tipo v[]) {
entero ind;
variarMas1(ind,0,t-1)
    mostrar << v[ind] << "  ";
    finVariar
mostrar << salto;
}

procedimiento leeDatos(vectorDin(entero) porRef vDatos) {
cadena renglon;
vectorDin(cadena) vPal;
iterar
    leeRenglon(cin,renglon);
    salirSi(renglon ES "");
    vPal = palabrea(renglon);
    paraCada(pal,vPal)
        agregaEleVDin(vDatos,aEntero(pal));
        finParaCada
    finIterar
//muestraV(vDatos);
}

plantilla(Tipo)
procedimiento invierteV(vectorDin(Tipo) porRef v) {
entero izq = 0
      ,der = tamanio(v) - 1;
mientras(izq < der)
    swap(v[izq++],v[der--]);
    finMientras
}

procedimiento procesa(entero t, entero vCirc[], vectorDin(entero) v) {
entero pos = 0
      ,inc = 0
      ,desde;
paraCada(nSel,v)
    vectorDin(entero) copia(nSel);
    desde = pos;
    paraCada(ele,copia)
        ele = vCirc[desde++];
        si(desde ES t) desde = 0;
        finParaCada
//    muestraV(copia);
    invierteV(copia);
//    muestraV(copia);
    desde = pos;
    paraCada(ele,copia)
        vCirc[desde++] = ele;
        si(desde ES t) desde = 0;
        finParaCada
//    muestraV(t,vCirc);
    pos += nSel + inc++;
    si(pos >= t) pos -= t;
    finParaCada
}

constante entera T = 256;

principal                                                       // Unidad de programa principal
vectorDin(entero) vDat;
entero vect[T]
      ,pos = 0;
limpiar;                                                        // Limpia la pantalla.
paraCada(ele,vect)
    ele = pos++;
    finParaCada
muestraV(T,vect);
leeDatos(vDat);
muestraV(vDat);
procesa(T,vect,vDat);
muestraV(T,vect);
mostrar << "El resultado es: " << vect[0] * vect[1] << salto;
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal

