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
        if (t[0] != t[i]) res = false;
    }
    return (t.size() > 0 && columnas(t) && res);
}

bool esToroide(toroide t){
    return esRectangulo(t) && t.size()>=3 && columnas(t)>=3;
}