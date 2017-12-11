#include <program1.h>                                           // Archivo de traducción de seudocódigo a C++
/**
*    Enunciado: One program at the bottom supports the entire tower. It's holding a large disc, and on the disc are balanced several more sub-towers.
                At the bottom of these sub-towers, standing on the bottom disc, are other programs, each holding their own disc, and so on. 
                At the very tops of these sub-sub-sub-...-towers, many programs stand simply keeping the disc below them balanced but with no disc of 
                their own.
                You offer to help, but first you need to understand the structure of these towers. You ask each program to yell out their name, 
                their weight, and (if they're holding a disc) the names of the programs immediately above them balancing on that disc. 
                You write this information down (your puzzle input). Unfortunately, in their panic, they don't do this in an orderly fashion; by the 
                time you're done, you're not sure which program gave which information.
                For example, if your list is the following:
pbga (66)
xhth (57)
ebii (61)
havc (66)
ktlj (57)
fwft (72) -> ktlj, cntj, xhth
qoyq (66)
padx (45) -> pbga, havc, qoyq
tknk (41) -> ugml, padx, fwft
jptl (61)
ugml (68) -> gyxo, ebii, jptl
gyxo (61)
cntj (57)
                ...then you would be able to recreate the structure of the towers that looks like this:
                gyxo
              /     
         ugml - ebii
       /      \     
      |         jptl
      |        
      |         pbga
     /        /
tknk --- padx - havc
     \        \
      |         qoyq
      |             
      |         ktlj
       \      /     
         fwft - cntj
              \     
                xhth
                In this example, tknk is at the bottom of the tower (the bottom program), and is holding up ugml, padx, and fwft. Those programs are, 
                in turn, holding up other programs; in this example, none of those programs are holding up any other programs, and are all the tops 
                of their own towers. (The actual tower balancing in front of you is much larger.)
                Before you're ready to help them, you need to make sure your information is correct. What is the name of the bottom program?
*/
estructura Elem {
privado:
    campo cadena nombre;
    campo entero peso;
    campo vectorDin(cadena) enlaces;
publico:
    Elem(vectorDin(cadena));
    procedimiento muestra(entero);
    funcion vectorDin(cadena) extraeEnlaces() {regresa(enlaces);};
    funcion cadena extraeNombre() {regresa(nombre);};
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
/*
estructura Elem2 derivadaDe Elem {
privado:
    campo logico esRaiz;
publico:
    Elem2(logico )
    }
*/
procedimiento muestraV(vectorDin(Elem) v) {
paraCada(ele,v)
    ele.muestra(0);
    finParaCada
mostrar << salto;
}

procedimiento borraEnlaces(vectorDin(Elem) porRef arbol, Elem rama) {

}
 
procedimiento desvincula(vectorDin(Elem) vDatos) {
vectorDin(Elem) arbol = vDatos;
vectorDin(cadena) enlacesABorrar,estosEnlaces;
paraCada(rama,arbol)
    estosEnlaces = rama.extraeEnlaces();
    si(tamanio(estosEnlaces) > 0) entonces
        paraCada(esteEnlace,estosEnlaces)
            agregaEleVDin(enlacesABorrar,esteEnlace);
            finParaCada
        finSi
    finParaCada
mientras(tamanio(enlacesABorrar) > 0)
    entero ind = tamanio(arbol)-1;
    mientras(ind >= 0 Y arbol[ind].extraeNombre() NOES enlacesABorrar[0]) 
        ind--;
        finMientras
    si(ind >= 0) entonces
        borra1EleVDin(arbol,ind);
        finSi
    borra1EleVDin(enlacesABorrar,0);
    finMientras
mostrar << "Ra�z: ";
muestraV(arbol);
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
desvincula(datos);
//muestraV(datos);
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal

