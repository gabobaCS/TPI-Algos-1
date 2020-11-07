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

// esRectangulo
bool esRectangulo(toroide t);

// esToroide
bool esToroide(toroide t);

int modulo(int n, int m);

// vecinosVivos
int vecinosVivos(toroide t, int f, int c);

bool esToroideMuerto(toroide t);