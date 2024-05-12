
using namespace std;

#include "TablaSimbolos.h"

TablaSimbolos::TablaSimbolos(TablaSimbolos *padre)
{
      if(padre == nullptr) nivel = 0;
      else nivel = padre->nivel + 1;
      this->padre = padre;
}

Simbolo *TablaSimbolos::buscarAmbito(string nombre)
{
     for (unsigned i=0;i<simbolos.size();i++)
       if (simbolos[i].nombre == nombre)
          return &(simbolos[i]);
     return NULL;
}

bool TablaSimbolos::nuevoSimbolo(Simbolo s)
{
     if (buscarAmbito(s.nombre)!=NULL)  // repetido en el ámbito
       return false;
     simbolos.push_back(s);
     return true;
}

Simbolo* TablaSimbolos::buscar(string nombre)
{
     for (unsigned i=0;i<simbolos.size();i++)
       if (simbolos[i].nombre == nombre) return &(simbolos[i]);
       
     if (padre != NULL)
       return padre->buscar(nombre);
     else
       return NULL;
}

string TablaSimbolos::crearVariable(string id, bool ambito)
{
    if (padre == NULL) {
        return id;
    } else {
        if (!ambito) {
            if (buscarAmbito(id) != nullptr) {
                ambito = true;
            }
        }
        if (ambito) {
            if (nivel != 1) {
                id = "_" + id;
            }
        }
        return padre->crearVariable(id,ambito);
    }
}
