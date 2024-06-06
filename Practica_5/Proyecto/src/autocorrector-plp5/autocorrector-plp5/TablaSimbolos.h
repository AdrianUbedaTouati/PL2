#ifndef _TablaSimbolos_
#define _TablaSimbolos_

#include <string>
#include <vector>

using namespace std;

const int ENTERO=0;
const int REAL=1;

struct Simbolo {

    string nombre;
    int tipo;
    int dir;
    int tam;
};


class TablaSimbolos {

public:

    TablaSimbolos *padre;
    vector<Simbolo> simbolos;

    TablaSimbolos(TablaSimbolos *padre);
    TablaSimbolos *getAmbitoAnterior() { return padre; }

    Simbolo *buscarAmbito(string nombre); // ver si está en el ámbito actual
    bool nuevoSimbolo(Simbolo s);
    Simbolo* buscar(string nombre);
};


#endif