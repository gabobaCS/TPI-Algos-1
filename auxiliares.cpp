#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

// columnas
int columnas(toroide t){
    return (t.size() > 0? t[0].size() : 0);
}

bool esRectangulo(toroide t){
    bool res = true;
    for (int i = 0; i < t.size(); i++){
        if (t[0].size() != t[i].size()) res = false;
    }
    return (t.size() > 0 && columnas(t) > 0 && res);
}

bool esToroide(toroide t){
    return esRectangulo(t) && t.size()>=3 && columnas(t)>=3;
}

int modulo(int n, int m){
    if (n < 0){
        while (n < 0) n += m;
    } else {
        n = n % m;
    }
    return n;
}

int vecinosVivos(toroide t, int f, int c){
    int cantidad = 0;
    for (int i = -1; i<=1; i++){
        for (int j = -1; j<=1; j++){
            if (!(i == 0 && j == 0) && t[modulo((f+i), t.size())][modulo((c+j), columnas(t))] == true){
                cantidad++;
            }
        }
    }
    return cantidad;
}

bool esToroideMuerto(toroide t){
    toroide muerto = t; // con esto agarro las dimensiones de t
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < columnas(t); j++){
            muerto[i][j] = false;
        }
    }
    return (muerto == t);
}

vector<int> ticksHastaMorir(vector<toroide> ts){
    vector<int> seqTicks(ts.size());
    int cantTicks = 0;
    for (int i = 0; i < ts.size(); i++){

    }
}

