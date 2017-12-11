#include <program1.h>
/**
*    Enunciado: Each instruction consists of several parts: 
                    the register to modify, 
                    whether to increase or decrease that register's value, 
                    the amount by which to increase or decrease it, 
                    and a condition. If the condition fails, skip the instruction without modifying the register. 
                The registers all start at 0. The instructions look like this:
b inc 5 if a > 1
a inc 1 if b < 5
c dec -10 if a >= 1
c inc -20 if c == 10
                These instructions would be processed as follows:
                    Because a starts at 0, it is not greater than 1, and so b is not modified.
                    a is increased by 1 (to 1) because b is less than 5 (it is 0).
                    c is decreased by -10 (to 10) because a is now greater than or equal to 1 (it is 1).
                    c is increased by -20 (to -10) because c is equal to 10.
                After this process, the largest value in any register is 1.
                You might also encounter <= (less than or equal to) or != (not equal to). 
                However, the CPU doesn't have the bandwidth to tell you what all the registers are named, and leaves that to you to determine.
                What is the largest value in any register after completing the instructions in your puzzle input?


*/
estructura Registro {
    campo cadena nombre;
    campo entero valor;
    Registro(cadena nom) {nombre = nom; valor = 0;};
    procedimiento muestra() {mostrar << "Registro:" << nombre << ", valor:" << valor << salto;}
    };

estructura Condicion {
        campo cadena registro;
        campo cadena comparador;
        campo entero valor;
        procedimiento muestra() {mostrar << "Condición: "+registro+comparador << valor << salto;}
        };

estructura Instruccion {
    campo cadena registro;
    campo logico esSuma;
    campo entero operando;
    Condicion cond;
    Instruccion(vectorDin(cadena));
    procedimiento muestra() {mostrar << "Instrucción -> Registro:" << registro << "  " << fSi(esSuma,"+","-") << " " << operando << salto;};
    };

procedimiento muestraV(vectorDin(cadena) v) {
paraCada(cad,v)
    mostrar << cad << "  ";
    finParaCada
mostrar << salto;
}

Instruccion::Instruccion(vectorDin(cadena) vPal) {
//muestraV(vPal);
registro = vPal[0];
esSuma = (vPal[1] ES "inc");
operando = aEntero(vPal[2]);
cond.registro = vPal[4];
cond.comparador = vPal[5];
cond.valor = aEntero(vPal[6]);
}
#undef esLetra
#define esLetra(x)  (strchr("+-<=>!ABCDEFGHIJKLMNÑOPQRSTUVWXYZabcdefghijklmnñopqrstuvwxyzáéíóúüÁÉÍÓÚÜ",x))

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

funcion logico estaEn(vectorDin(Registro) vRegi, cadena nombreRegi) {
logico resul = FALSO;
entero i = tamanio(vRegi) - 1;
mientras(i >= 0 Y NO (resul = resul O (vRegi[i].nombre ES nombreRegi)))
    i--;
    finMientras
regresa(resul);
}

procedimiento generaRegistros(vectorDin(Instruccion) vInst, vectorDin(Registro) porRef vRegi) {
paraCada(instr,vInst)
    si(NO estaEn(vRegi,instr.registro)) entonces
        Registro nvoReg(instr.registro);
        agregaEleVDin(vRegi,nvoReg);
        nvoReg.muestra();
        finSi
    si(NO estaEn(vRegi,instr.cond.registro)) entonces
        Registro nvoReg(instr.cond.registro);
        agregaEleVDin(vRegi,nvoReg);
        nvoReg.muestra();
        finSi
    finParaCada
}

funcion entero indRegi(vectorDin(Registro) vRegi, cadena regABusc) {
entero resul = tamanio(vRegi) - 1;
mientras(resul >= 0 Y vRegi[resul].nombre NOES regABusc)
    resul--;
    finMientras
regresa(resul);
}

funcion logico cumpleCond(Condicion cond, vectorDin(Registro) vRegi) {
logico resul;
entero iR = indRegi(vRegi,cond.registro);
si(cond.comparador ES "<") entonces
    resul = vRegi[iR].valor < cond.valor;
    sinoSi(cond.comparador ES "<=") entonces
    resul = vRegi[iR].valor <= cond.valor;
    sinoSi(cond.comparador ES ">") entonces
    resul = vRegi[iR].valor > cond.valor;
    sinoSi(cond.comparador ES ">=") entonces
    resul = vRegi[iR].valor >= cond.valor;
    sinoSi(cond.comparador ES "==") entonces
    resul = vRegi[iR].valor == cond.valor;
    sinoSi(cond.comparador ES "!=") entonces
    resul = vRegi[iR].valor != cond.valor;
    finSi
regresa(resul);
}

procedimiento procesaInstrucc(vectorDin(Instruccion) vInst, vectorDin(Registro) porRef vRegi) {
paraCada(instr,vInst)
    instr.cond.muestra();
    si(cumpleCond(instr.cond,vRegi)) entonces
        mostrar << "Aceptada.\n";
        entero iR = indRegi(vRegi,instr.registro);
        instr.muestra();
        si(instr.esSuma) entonces
            vRegi[iR].valor += instr.operando;
            sino
            vRegi[iR].valor -= instr.operando;
            finSi
        vRegi[iR].muestra();
        sino
        mostrar << "Rechazada.\n";
        finSi
    finParaCada
}

principal                                                       // Unidad de programa principal
cadena renglon;
vectorDin(cadena) vPal;
vectorDin(Instruccion) vInstr;
vectorDin(Registro) vReg;
limpiar;                                                        // Limpia la pantalla.
iterar
    leeRenglon(cin,renglon);
    salirSi(renglon ES "");
//    mostrar << "Lee:"<< renglon << salto;
    vPal = palabrea(renglon);
//    muestraV(vPal);
    Instruccion instr(vPal);
    agregaEleVDin(vInstr,instr);
    finIterar
generaRegistros(vInstr,vReg);
procesaInstrucc(vInstr,vReg);
mostrar << "Estado final:\n";
entero valMax = vReg[0].valor;
paraCada(reg,vReg)
    reg.muestra();
    si(reg.valor > valMax) valMax = reg.valor;
    finParaCada
mostrar << "El máximo es " << valMax << salto;
pausa;                                                          // Pausa antes de finalizar. 
finPrincipal