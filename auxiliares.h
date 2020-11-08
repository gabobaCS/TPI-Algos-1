//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);

#endif //REUNIONESREMOTAS_AUXILIARES_H

int columnas(toroide t);

bool esRectangulo(toroide t);

bool esToroide(toroide t);

int modulo(int n, int m);

vector<int> ticksHastaMorir(vector<toroide> ts);

int vecinosVivos(toroide t, int f, int c);

bool esToroideMuerto(toroide t);

bool esTraslacion(toroide const &t, toroide const &u, int x, int y);

toroide hacerTraslacion(toroide t, int y, int x);

int cantidadDeVivas(toroide t);

void imprimirToroide(toroide t);

toroide extraerRect(toroide t, int y1, int y2, int x1, int x2);

void imprimirTodosLosRect(toroide t);

toroide hacerSubrect(toroide t, int y1, int y2, int x1, int x2);

vector<toroide> todosLosSubrect(toroide t);

vector<toroide> subrectsConVivas(vector<toroide> ts, toroide t);

int minimaArea(vector<toroide> ts);

