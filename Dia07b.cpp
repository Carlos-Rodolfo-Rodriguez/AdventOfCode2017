#include <program1.h>                                           // Archivo de traducciÃ³n de seudocÃ³digo a C++
/**
*    Enunciado: The programs explain the situation: they can't get down. Rather, they could get down, if they weren't expending all of their energy 
                trying to keep the tower balanced. Apparently, one program has the wrong weight, and until it's fixed, they're stuck here.
                For any program holding a disc, each program standing on that disc forms a sub-tower. Each of those sub-towers are supposed to be the 
                same weight, or the disc itself isn't balanced. The weight of a tower is the sum of the weights of the programs in that tower.
                In the example above, this means that for ugml's disc to be balanced, gyxo, ebii, and jptl must all have the same weight, and they 
                do: 61. However, for tknk to be balanced, each of the programs standing on its disc and all programs above it must each match. This 
                means that the following sums must all be the same:
ugml + (gyxo + ebii + jptl) = 68 + (61 + 61 + 61) = 251
padx + (pbga + havc + qoyq) = 45 + (66 + 66 + 66) = 243
fwft + (ktlj + cntj + xhth) = 72 + (57 + 57 + 57) = 243
                As you can see, tknk's disc is unbalanced: ugml's stack is heavier than the other two. Even though the nodes above ugml are balanced, 
                ugml itself is too heavy: it needs to be 8 units lighter for its stack to weigh 243 and keep the towers balanced. If this change were 
                made, its weight would be 60.
                Given that exactly one program is the wrong weight, what would its weight need to be to balance the entire tower?
*/
estructura Elem {
privado:
    campo cadena nombre;
    campo entero peso;
    campo vectorDin(cadena) enlaces;
publico:
    Elem(vectorDin(cadena));
    procedimiento muestra(entero);
    procedimiento fijaPeso(entero nuevoPeso) {peso = nuevoPeso;};
    funcion vectorDin(cadena) extraeEnlaces() {regresa(enlaces);};
    funcion cadena extraeNombre() {regresa(nombre);};
    funcion entera extraePeso() {regresa(peso);};
    funcion logico operador ES(Elem otroElem) {regresa((nombre ES otroElem.nombre) Y 
                                        (peso ES otroElem.peso) Y
                                        (enlaces ES otroElem.enlaces));};
    };

procedimiento Elem::muestra(entero nivel) {
cadena prefijo = "";
entero i;
variarMas1(i,0,nivel)
    prefijo += " -> ";
    finVariar
mostrar << prefijo << "Nombre: " << nombre 
                   << ", Peso: " << peso 
                   << ", Enlaces: ";
paraCada(unEnlace,enlaces)
    mostrar << unEnlace << " ";
    finParaCada
mostrar << salto;
}

Elem::Elem(vectorDin(cadena) vCad) {
nombre = vCad[0];
borra1EleVDin(vCad,0);
peso = aEntero(vCad[0]);
borra1EleVDin(vCad,0);
enlaces = vCad;
//muestra(1);
}

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

procedimiento muestraV(vectorDin(cadena) v) {
paraCada(cad,v)
    mostrar << cad << "  ";
    finParaCada
mostrar << salto;
}

funcion entera pesoSubArbol(vectorDin(Elem) dat, cadena esteNodo) {
entero t = tamanio(dat)
      ,ind = (t-1)
      ,resul;
mientras(ind >= 0 Y dat[ind].extraeNombre() NOES esteNodo)
    ind--;
    finMientras
si(ind >= 0) entonces
    resul = dat[ind].extraePeso();
    vectorDin(cadena) losEnlaces = dat[ind].extraeEnlaces();
    paraCada(esteEnlace,losEnlaces)
        resul += pesoSubArbol(dat,esteEnlace);
        finParaCada
    finSi
regresa(resul);
}

procedimiento balancea(vectorDin(Elem) dat,entero nivel) {
paraCadaValor(rama,dat)
    vectorDin(cadena) losEnlaces = rama.extraeEnlaces();
    entero t = tamanio(losEnlaces);
    si(t >= 2) entonces
        entero primerPeso = pesoSubArbol(dat,losEnlaces[0])
              ,ind =1
              ,otroPeso;
        iterar
            otroPeso = pesoSubArbol(dat,losEnlaces[ind]);
            salirSi(ind ES (t-1) O otroPeso NOES primerPeso);
            ind++;
            finIterar
        si(otroPeso NOES primerPeso) entonces
            mostrar << "Desbalanceo detectado en: ";
            rama.muestra(nivel);
            mostrar << "Pesos:\n";
            entero pe,pMin,pMax;
            pMin = pMax = (-1);
            paraCada(enlace,losEnlaces)
                pe = pesoSubArbol(dat,enlace);
                si(pMax < pe O pMax ES (-1)) pMax = pe;
                si(pMin > pe O pMin ES (-1)) pMin = pe;
                mostrar << enlace << ": " << pe << salto;
                finParaCada
            si(nivel ES 0) entonces
                entero difer = pMax - pMin;
                mostrar << "Probando...\n";
                paraCada(enlace,losEnlaces)
                    vectorDin(Elem) pruebas = dat;
                    mostrar << enlace << "..." << salto;
                    paraCada(prueba,pruebas)
                        si(prueba.extraeNombre() ES enlace) entonces
                            prueba.fijaPeso(prueba.extraePeso()-difer);
                            prueba.muestra(nivel);
                            balancea(pruebas,nivel+1);
                            mostrar << "¿Balanceado?\n";
                            prueba.fijaPeso(prueba.extraePeso()+ 2 * difer);
                            prueba.muestra(nivel);
                            balancea(pruebas,nivel+1);
                            mostrar << "¿Balanceado?\n";
                            finSi
                        finParaCada
                    mostrar << enlace << " (fin)" << salto;
                    finParaCada
        //                    paraCada(enlace,prueba.extraeEnlaces())
        //                        si(pesoSubArbol(pruebas,enlace) ES pMax) entonces
        //                            sinoSi(prueba.extraePeso() ES pMin) entonces
        //                            sino
        //                            finSi
        //                        finParaCada
                finSi
            finSi
        finSi
    finParaCada
}

procedimiento muestraV(vectorDin(Elem) v) {
paraCada(ele,v)
    ele.muestra(0);
    finParaCada
mostrar << salto;
}

principal                                                       // Unidad de programa principal
cadena renglon;
vectorDin(cadena) vPal;
vectorDin(Elem) datos;
limpiar;                                                        // Limpia la pantalla.
iterar
    leeRenglon(cin,renglon);
    salirSi(renglon ES "");
    vPal = palabrea(renglon);
//    muestraV(vPal);
    Elem ele = Elem(vPal);
//    ele.muestra(1);
    agregaEleVDin(datos,ele);
    finIterar
muestraV(datos);
balancea(datos,0);
//muestraV(datos);
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal

