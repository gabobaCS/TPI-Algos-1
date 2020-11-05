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

int vecinosVivos(toroide t, int f, int c){
    int cantidad = 0;
    for (int i = -1; i<=1; i++){
        for (int j = -1; j<=1; j++){
            int primer = (f+i) % t.size();
            int segundo = (c+j) % columnas(t);
            if ((i != 0 || j != 0) && t[abs(primer)][abs(segundo)] == true){
                cantidad++;
            }
        }
    }
    return cantidad;
}