#include "program1.h"
/**
*    Enunciado: Now, the jumps are even stranger: after each jump, if the offset was three or more, instead decrease it by 1. Otherwise, increase it by 1 as before.
                Using this rule with the above example, the process now takes 10 steps, and the offset values after finding the exit are left as 2 3 2 3 -1.
                How many steps does it now take to reach the exit?
*/
principal                                                       // Unidad de programa principal
vectorDin(entero) v;
entero codSalto
      ,ind = 0
      ,pasos = 0;
cadena renglon;
limpiar;                                                        // Limpia la pantalla.
iterar
    leeRenglon(std::cin,renglon);
    salirSi(renglon ES "");
    codSalto = aEntero(renglon);
    agregaEleVDin(v,codSalto);
    finIterar
mientras(0 <= ind Y ind < tamanio(v))
    codSalto = v[ind];
    si(codSalto >= 3) entonces
        v[ind]--;
        sino
        v[ind]++;
        finSi
    ind += codSalto;
    pasos++;
    finMientras
paraCada(ele,v)
    mostrar << ele << tabulado;
    finParaCada
mostrar << "\nPasos:" << pasos << salto;
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal                                                    // Fin de unidad de programa principal.


