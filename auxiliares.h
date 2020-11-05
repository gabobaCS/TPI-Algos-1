//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);

#endif //REUNIONESREMOTAS_AUXILIARES_H

// columnas
int columnas(toroide t);

// enRango
bool enRango();

// enRangoToroide
bool enRangoToroide(int c, int f, toroide t);

// esRectangulo
bool esRectangulo(toroide t);

// esToroide
bool esToroide(toroide t);