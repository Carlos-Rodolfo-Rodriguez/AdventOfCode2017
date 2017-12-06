// Versión 2017
//#define WINDOWS
#ifndef PROGRAM1_H
#define PROGRAM1_H
// Inclusiones (¿todo?)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <ctime>
#include <cstring>
#include <list>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <assert.h>
#include <stdio.h>

using namespace std;

// Sólo para Linux:
#ifndef WINDOWS
#ifndef TECLAS
#include <termios.h>
#include <unistd.h>
inline int leeTec(bool conEco = true) {
    struct termios oldattr, newattr;
    char ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
//    newattr.c_lflag &= ~( ICANON );
    newattr.c_lflag &= ~(conEco ? ICANON : ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
//    ch = (((int)(ch=getchar()) == (-61))?leeTecla(conEco):ch);
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
#define TECLAS
#define pausa                  {mostrar << "En pausa. <Escape> para continuar...";while (leeTec(false) != 27);}
#define leeTecSinEco(x)        x=leeTec(false)
#define leeTecConEco(x)        ((x=leeTec()) == (-61)?(x=leeTec(true)):x);
#define leeTecla(x)            x=leeTec(true)
#define limpiar                system("clear");
#endif
// Sólo para Windows
#else
#include <conio.h>
#define pausa                  {mostrar << "En pausa...";system("pause");}
#define leeTecla(x)            x=getche()
#define leeTecSinEco(x)        x=getch()
#define leeTecConEco(x)        x=getche()
#define limpiar                system("cls");
#endif

/*
   Tipos de datos
*/
#define largo                   long
#define larga                   largo
#define Largo			        largo
#define Larga			        largo
#define entero                  int
#define entera                  entero
#define Entero			        entero
#define Entera			        entero
#define real                    float
#define Real			        real
#define doble                   double
#define Doble			        doble
#define caracter                char
#define Caracter		        caracter
#define logico                  bool
#define logica                  logico
#define Logico			        logico
#define Logica			        logico
#define Cadena                  cadena
#define cadena                  std::string
#define clicks                  clock_t
#define Clicks                  clicks
#define tiempoEnCPP             std::chrono::high_resolution_clock
#define TiempoEnCPP             tiempoEnCPP
#define tiempoEnC               time_t
#define TiempoEnC               tiempoEnC
#define sinSigno                unsigned
//#define cadena               char *
//typedef char cadena[256];
//typedef char cadena20[20];
//typedef unsigned char byte;
#define FALSO                   false
#define PI                      3.1415927
#define VERDADERO               true

// Programación genérica (metaprogramación)
//#define plantilla(tipo)         template <class tipo>
#define plantilla(tipo)         template <typename tipo>
#define implementa              template

// Estructuras
#define estructura              struct
#define Estructura		        estructura
#define campo

// Objetos
#define clase                           class
#define publico                         public
#define derivadaDe                      publico
#define privado                         private
#define amigo                           friend
#define amiga                           amigo
#define estatica                        estatico
#define estatico                        static
#define protegido                       protected
#define noCambia                        const
#define nuevo                           new
#define borrar                          delete
#define esto                            this
#define CodConstructorAsumido(unaClase) unaClase::ConstructorAsumido(unaClase)
#define ConstructorAsumido(unaClase)    unaClase()
#define Destructor(unaClase)            ~unaClase()

/*
   Procedimientos
*/
#define mostrar                 std::cout
#define mostrarErr              cerr
#define mostrarConAncho(x)      cout.width(x)
#define mostrarConDecim(x)      cout.precision(x)
#define estableceAncho(x)       setw(x)
#define leer(x)                 cin >> x
#define leerM(x,y)              mostrar << y;cin >> x
#define operador                operator

/*
   Traducciones genéricas
*/
#define Principal              principal
#define principal              int main(int argc, char *argv[]) { //unitbuf(cout);
#define QtPrincipal            int main(int argc, char *argv[]) {QCoreApplication a(argc, argv);
#define finQtPrincipal         return a.exec(); }
#define finPrincipal           return EXIT_SUCCESS;}
#define programa               void main() { /##/                               // Borland
#define finPrograma            }
#define procedimiento          Procedimiento
#define Procedimiento          void
#define finProcedimiento       }
#define Funcion
#define funcion
#define finFuncion             }
#define regresa(x)             retorna(x)
#define retorna(x)             return(x)
#define noCompartido           static
#define global                 extern
#define Bloque                 {
#define finBloque              }
// Decisiones
#define si(x)                  if(x)
#define entonces               {
#define sino                   } else {
#define finSi                  }
#define sinoSi(x)              } else if(x)
#define segun(x)               segunCaso(x)
#define segunCaso(x)           switch (x) {
#define finSegun               }
#define sale                   break
#define caso                   case
#define otroCaso               break; case
#define casoAsumido            break; default

// Bucles
#define iterar                 do {
#define salirSi(x)             if(x) break
#define finIterar              } while (VERDADERO);
#define mientras(x)            while (x) {
#define finMientras            }
#define repetir                do {
#define hasta(x)               } while (NO (x));
#define variar(vc,vi,vf,inc)   si(1+((vf-vi)/(inc))>0) for(vc=vi;((inc>0)?(vc<=vf):(vc>=vf));vc+=inc) {
#define variarMas1(vc,vi,vf)   si(1+(vf-vi)>0) for(vc=vi;vc<=vf;vc++) {
#define variarMenos1(vc,vi,vf) si(1+(vf-vi)>0) for(vc=vi;vc<=vf;vc--) {
#define finVariar              }
#define paraCada(x,conj)       for(auto & x : conj) {
#define paraCadaValor(x,conj)  for(auto x : conj) {
#define finParaCada            }
#define finPara                finParaCada

// Memoria estática
#define arreglo(tipo,tam)                   array<tipo,tam>
#define arreglo2D(tipo,tam1,tam2)           array<array<tipo,tam2>,tam1>        
#define arreglo3D(tipo,tam1,tam2,tam3)      array<array<array<tipo,tam3>,tam2>,tam1>        

// Memoria dinámica
#define vectorDin(tipo)                     vector<tipo>
//#define vectorDin(tipo,tam)                 vector<tipo>(tam)
//#define vectorDin(tipo,tam,inic)            vector<tipo>(tam,inic)
#define matrizDin2D(tipo)                   vector<vector<tipo>>
#define matrizDin3D(tipo)                   vector<vector<vector<tipo>>>
#define insertaEleVDin(vec,valor)           {auto it = vec.begin(); vec.insert(it,(valor));}
#define intercalaEleVDin(vec,valor,pos)     vec.emplace(vec.begin()+(pos),(valor))
#define agregaEleVDin(vec,valor)            {auto it = vec.end(); vec.insert(it,(valor));}
#define borra1EleVDin(vec,pos)              if(tamanio(vec) > pos Y pos >= 0) vec.erase(vec.begin()+(pos));
#define tamanio(vec)                        vec.size()
#define listaDe(tipo)                       vectorDin<tipo> 
#define insertaLista(lis,valor)             {auto it = lis.begin(); lis.insert(it,(valor));}
#define intercalaEnLista(lis,valor,pos)     lis.emplace(lis.begin()+(pos),(valor))
#define agregaALista(lis,valor)             {auto it = lis.end(); lis.insert(it,(valor));}


// Equivalencias
#define salto                  endl
#define tabulado               (char) 9
#define ES                     ==
#define NO                     !
#define NOES                   !=
#define bitO                   |
#define O                      ||
#define bitY                   &
#define Y                      &&
#define bitOEX(x,y)            (x ^ y)
#define porVal
#define porRef                 &
#define deRef                  *
#define apuntadoPor            *
#define constante              const

// Pseudo funciones
#define equiv(x,y)             (((x) Y (y)) O ((NO (x)) Y (NO (y))))
#define noEquiv(x,y)           (NO equiv(x,y))
#define signo(x)               fSi(x>0,1,fSi(x<0,(-1),0))
#define raiz2(x)               sqrt(x)
#define fSi(x,y,z)             (x?y:z)
#define XalaY(x,y)             pow(x,y)
#define cuadrado(x)            ((x)*(x))
#define SIoNO(x)               ((x)?" Si ": " No ")
#define mayusculas(x)          toupper(x)
#define maximo(a,b)            (a>b?a:b)
#define minimo(a,b)            (a<b?a:b)
#define esMult(a,b)            ((a % b) ES 0)
#define esImpar(x)             (x % 2)
#define esPar(x)               (NO (esImpar(x)))
#define esDigito(x)            ((x >= '0') Y (x <= '9'))
#define esLetra(x)             (strchr("ABCDEFGHIJKLMNÑOPQRSTUVWXYZabcdefghijklmnñopqrstuvwxyzáéíóúüÁÉÍÓÚÜ",x))
#define esSigno(x)             NO (esLetra(x) O esDigito(x))
#define esVocal(x)             (strchr("AEIOUaeiouáéíóúüÁÉÍÓÚÜ",x))
#define sinPrimerCar(cad)      (cad.substr(1))
#define carEstaEnCad(car,cad)  (posCarEnCad(car,cad) >= 0)
#define posCarEnCad(car,cad)   (cad.find(car))
#define sinCarPos(x,cad)       (cad.substr(0,x-1)+cad.substr(x))
#define esConso(x)             (esLetra(x) Y NO esVocal(x))
#define plural(x)              fSi(x NOES 1,"s","")
#define esComPal(x,y)          (esSigno(x) Y NO esSigno(y))
#define esFinPal(x,y)          (NO esSigno(x) Y esSigno(y))
#define aCaracter(x)           "0123456789"[x]
#define arcoTangente(y,x)      atan2(y,x)
#define seno(x)                sin(x)
#define coseno(x)              cos(x)
#define tangente(x)            tan(x)
#define grados(x)              (180.0/PI*(x))
#define radianes(x)            (PI/180.0*(x))
#define grados360(x)           grados(fSi(x < 0,(x+2*PI),(x)))
#define distancia(x1,y1,x2,y2) raiz2(cuadrado(x2-x1)+ cuadrado(y2-y1))
#define angulo(x1,y1,x2,y2)    atan2((y2-y1),(x2-x1))
#define ahoraC()               clock()
//#define ahoraC()                     time(nullptr)
#define ahora()                     chrono::high_resolution_clock::now()

//Fechas y tiempo

//#define poneCadAhora(c)        {TiempoEnC seg = ahora(); struct tm * infoTiempo = localtime(& seg); c = asctime(infoTiempo);}
inline funcion struct tm * estrTiempoActual() {
struct tm * resul;
TiempoEnC seg = ahoraC();
resul = localtime(& seg);
regresa(resul);
}
inline funcion Cadena cadDiaSem(entero diaSem) {
assert(0 <= diaSem Y diaSem < 7);
cadena resul [] = {"Domingo","Lunes","Martes","MiÃ©rcoles","Jueves","Viernes","SÃ¡bado"};
regresa(resul[diaSem]);
}
inline funcion Cadena cadMes(entero mes) {
assert(0 <= mes Y mes < 12);
cadena resul [] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
regresa(resul[mes]);
}
// Hoy
#define cadHoyIngles()              (asctime(estrTiempoActual()))
#define numeroDiaHoy()              (estrTiempoActual()->tm_mday)
#define cadDiaHoy()                 (aCadena(numeroDiaHoy()))
#define numeroMesHoy()              (1+estrTiempoActual()->tm_mon)
#define cadMesHoy()                 cadMes(numeroMesHoy())
#define numeroAnioHoy()             (1900+estrTiempoActual()->tm_year)
#define cadAnioHoy()                (aCadena(numeroAnioHoy()))
#define numeroHoraHoy()             (estrTiempoActual()->tm_hour)
#define cadHoraHoy()                (aCadena(numeroHoraHoy()))
#define numeroMinHoy()              (estrTiempoActual()->tm_min)
#define cadMinHoy()                 (aCadena(numeroMinHoy()))
#define numeroSegHoy()              (estrTiempoActual()->tm_sec)
#define cadFechaHoy()               (aCadena(numeroDiaHoy(),"00")+"/"+aCadena(numeroMesHoy(),"00")+"/"+aCadena(numeroAnioHoy(),"00"))
#define cadDiaSemHoy()              (cadDiaSem(estrTiempoActual()->tm_wday))
#define cadCortaDiaSemHoy()         (cadDiaSem(estrTiempoActual()->tm_wday).substr(0,3))
#define cadHorMinSegHoy()           (aCadena(numeroHoraHoy(),"00")+":"+aCadena(numeroMinHoy(),"00")+":"+aCadena(numeroSegHoy(),"00"))
#define cadLargaTiempoHoy()         (cadDiaSemHoy()+" "+cadHorMinSegHoy())
#define cadFechaAhora()             (cad3DiaSemHoy()+", "+cadDiaHoy())
#define cadLargaAhora()             (cadFechaHoy()+" "+cadHorMinSegHoy())

// ConversiÃ³n a cadenas
inline funcion cadena aCadena(entero nro) {
cadena resul;
si(nro >= 10) entonces
    resul = aCadena(nro/10) + aCadena(nro % 10);
    sinoSi(nro < 0) entonces
    resul = "-" + aCadena(-nro);
    sino
    segun(nro)
        caso 0      : resul = "0";
        otroCaso 1  : resul = "1";
        otroCaso 2  : resul = "2";
        otroCaso 3  : resul = "3";
        otroCaso 4  : resul = "4";
        otroCaso 5  : resul = "5";
        otroCaso 6  : resul = "6";
        otroCaso 7  : resul = "7";
        otroCaso 8  : resul = "8";
        otroCaso 9  : resul = "9";
        casoAsumido : resul = "*";
        finSegun
    finSi
regresa (resul);
}
inline funcion cadena aCadena(real nro, entero dig) {
cadena resul = aCadena((entero)nro) + "." + aCadena((entero)((nro-(entero)nro)*XalaY(10,dig)));
regresa(resul);
}
inline funcion cadena aCadena(entero nro, cadena relleno) {
cadena resul = aCadena(nro);
entero difLongi = relleno.length() - resul.length();
si( difLongi > 0) entonces
    resul = relleno.substr(0,difLongi) + resul;
    finSi
regresa(resul);
}

inline funcion entero aEntero(cadena cad) {
entero resul
      ,longi = cad.length();
si(longi > 0) entonces
    si(cad.substr(0,1) ES "-") entonces
        resul = -aEntero(cad.substr(1));
        sinoSi(longi > 1) entonces
        resul = 10 * aEntero(cad.substr(0,longi-1)) + aEntero(cad.substr(longi-1,1));
        sino
        cadena cadDigitos = "0123456789"; 
        resul = cadDigitos.find(cad);
        finSi
    sino
    resul = 0;
    finSi
regresa(resul);
}

// Posiblemente innecesarias en G++
#define longitud(x)                 x.length()
#define cadIguales(x,y)             (strcmp(x,y) ES 0)
#define agregaYaX(x,y)              strcat(x,y)
#define borraCad(x)                 while(strlen(x)) x[longitud(x)-1]='\0'
#define asigna(carX,cadY)           borraCad(cadY);cadY[0]=carX
#define agrega(cadX,carY)           cadX[longitud(cadX)] = carY
#define inserta(carX,cadY)          {int largoCadY = longitud(cadY);for(int p=largoCadY;p>0;p--)cadY[p] = cadY[p-1];cadY[0] = carX;}
#define duplicaCadena(o,d)          strcpy(d,o)
#define carALargo(c)                strtol(c,NULL,10)

// Al azar
#define iniciAlAzar                 srand(time(NULL))
#define alAzar                      rand()
#define alAzarHasta(x)              (alAzarReal*(x))
#define alAzarEntre(x,y)            ((x)+alAzarHasta((y)-(x)))
#define alAzarReal                  (rand()/(real)RAND_MAX)
#define alAzarRealEntre(x,y)        (x+(y-x)*alAzarReal)
#define decimales(x,deci)           (entero)((x)*XalaY(10,deci))/XalaY(10,deci)
//#define alAzarDecHasta(x,y)    alAzarHasta(x * (entero)XalaY(10,x))/XalaY(10,x)

//Archivos
#define archivo                             fstream
#define flujoEntrada(ent,arch,modo)         std::ifstream ent(arch,modo)
//#define flujoEntrada(ent,arch)              std::ifstream ent(arch,std::ifstream::in)
#define flujoSalida(sal,arch,modo)          std::ofstream sal(arch,modo)
//#define flujoSalida(sal,arch)               std::ofstream sal(arch,std::ofstream::out)
#define abrir(arch,nombre, modo)            arch.open(nombre,modo)
//#define abrir(arch,nombre)                  arch.open(nombre)
#define cerrar(arch)                        arch.close()
#define estaAbierto(arch)                   arch.is_open()
#define esFinDarch(arch)                    arch.eof()
#define todoBien(arch)                      arch.good()
#define errorEn(arch)                       arch.fail()
#define estaMal(arch)                       arch.bad()
#define leeRenglon(arch,cad)                getline(arch,cad)
#define puntLectura(arch)                   arch.tellg()
#define puntEscritura(arch)                 arch.tellp()
#define posAbsLectura(arch)                 arch.seekg()
#define posAbsEscritura(arch)               arch.seekp()
#define posRelLectura(arch,cuanto,desde)    arch.seekg(cuanto,desde)
#define posRelEscritura(arch,cuanto,desde)  arch.seekp(cuanto,desde)
#define DESDEINICIO                         ios::beg
#define DESDEFIN                            ios::end
#define DESDEACA                            ios::cur
#define ALEER                               ios::in
#define AESCRIBIR                           ios::out
#define ALFINAL                             ios::ate
#define AGREGAR                             ios::app
#define ATRUNCAR                            ios::trunc
#define BINARIO                             ios::binary

// Gráficos OpenGL
#define grafico                             glutInit (&argc, argv)
#define Gr_iniModo(modo)                    glutInitDisplayMode(modo)
#define Gr_iniTamVent(tHor,tVert)           glutInitWindowSize(tHor,tVert)
#define Gr_iniPosVent(posX,posY)            glutInitWindowPosition(posX,posY)
#define Gr_creaVentana(titulo)              glutCreateWindow(titulo)
#define Gr_mostrar()                        glutMainLoop()
#define Gr_limpiarColor(rojo,verde,azul,op) glClearColor(rojo,verde,azul,op)
#define Gr_limpiar(buff)                    glClear(buff)
#define Gr_RVA(rojo,verde,azul)             glColor3f(rojo,verde,azul)
#define Gr_RVA4(rojo,verde,azul,op)         glColor4f(rojo,verde,azul,op)
#define Gr_colorFondo(rojo,verde,azul,op)   glClearColor(rojo,verde,azul,op)
#define Gr_empieza(algo)                    glBegin(algo)
#define Gr_empiezaPuntos()                  Gr_empieza(GL_POINTS)               // Puntos
#define Gr_tamPunto(tama)                   glPointSize(tama)
#define Gr_empiezaSegmentos()               Gr_empieza(GL_LINES)                // Pares de puntos definiendo segmentos no conectados
#define Gr_empiezaLineas()                  Gr_empieza(GL_LINE_STRIP)           // Vértices conectados por líneas
#define Gr_empiezaLineasCerradas()          Gr_empieza(GL_LINE_LOOP)            // Vértices conectados por líneas más la última con la primera
#define Gr_lineaDePuntos(bitX16)            glLineStipple(1,bitX16)             // Patrón de dibujo de la línea
#define Gr_anchoLinea(ancho)                glLineWidth(ancho)                  // Ancho de la linea
#define Gr_HabLineaDePuntos()               Gr_habilita(GL_LINE_STIPPLE)
#define Gr_empiezaTriangulos()              Gr_empieza(GL_TRIANGLES)            // Triplas de vértices definiendo triángulos
#define Gr_empiezaTriangulosConectados()    Gr_empieza(GL_TRIANGLE_STRIP)       // Triángulos conectados
#define Gr_empiezaVentilador()              Gr_empieza(GL_TRIANGLE_FAN)         // Triángulos conectados como aspas de un ventilador
#define Gr_empiezaCuadrilateros()           Gr_empieza(GL_QUADS)                // Cuatriplas definiendo cuadriláteros
#define Gr_empiezaCuadrilaterosConectados() Gr_empieza(GL_QUAD_STRIP)           // Cuadriláteros conectados
#define Gr_empiezaPoligonos()               Gr_empieza(GL_POLYGON)              // Polígono
#define Gr_termina                          glEnd
#define Gr_habilita(algo)                   glEnable(algo)
#define Gr_inhabilita(algo)                 glDisable(algo)
#define Gr_estaHabilitado(algo)             glIsEnabled(algo)
#define Gr_vertice(x,y,z)                   glVertex3f(x,y,z)
#define Gr_procesa()                        glFlush()
#define Gr_procMuestra(proc)                glutDisplayFunc(proc)
#define Gr_eventoRedim(proc)                glutReshapeFunc(proc)
#define Gr_eventoTecla(proc)                glutKeyboardFunc(proc)
#define Gr_eventoRaton(proc)                glutMouseFunc(proc)
#define Gr_eventoMueve(proc)                glutMotionFunc(proc)
#define Gr_eventoDescanso(proc)             glutIdleFunc(proc)
#define Gr_modeloDibujo(modelo)             glShadeModel(modelo)
#define Gr_ApilaMatriz()                    glPushMatrix()
#define Gr_DesapilaMatriz()                 glPopMatrix()
#define Gr_IntercambiaBuffers()             glutSwapBuffers()

// Otras
#define DEPURACION
#define GENERAZAR
//#define ORDENADO
#endif
