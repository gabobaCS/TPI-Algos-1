#include <iostream>
#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

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
            if (!(i == 0 && j == 0) && t[modulo((f+i), t.size())][modulo((c+j), columnas(t))]){
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

bool esTraslacion(toroide const &t, toroide const &u, int y, int x){
    //Que dados dos toroides me diga si uno es la traslacion en x,y del otro.
    bool res = true;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            if(t[i][j] != u[(i+y) % t.size()][(j+x) % t[0].size()])
                res = false;
        }
    }
    return res;
}

void imprimirToroide(toroide t){
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            cout << t[i][j] << " ";
        }
        // Newline for new row
        cout << endl;
    }
}

int cantidadDeVivas(toroide t){
    int vivas = 0;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            if (t[i][j]) vivas++;
        }
    }
    return vivas;
}

toroide hacerTraslacion(toroide t, int y, int x){
    toroide trasladado = t;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            trasladado[(i+y)%t.size()][(j+x)%t[0].size()] = t[i][j];
        }
    }
    return trasladado;
}

toroide extraerRect(toroide t, int esq1, int esq2){
    toroide rect;
    for (int i = 0; i < esq1; i++){
        vector<bool> fila;
        for (int j = 0; j < esq2; j++){
            fila.push_back(t[i][j]);
        }
        rect.push_back(fila);
    }
    imprimirToroide(rect);
    return rect;
}

vector<toroide> SubrectsConVivas(toroide t){
    //Devuelve una secuencia de los rectangulos de t que contienen todas las vivas.
    vector<toroide> rectangulos;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            toroide rect = extraerRect(t,i,j);
            if (posicionesVivas(rect).size() ==  posicionesVivas(t).size())
                rectangulos.push_back(rect);
        }
    }
}

//vector<toroide>


vector<int> listaDeAreas(vector<toroide> toroides){
    vector<int> areas;
    for (int i = 0; i < toroides.size(); i++){
        areas.push_back(toroides[0].size() * toroides[0][0].size());
    }
    return areas;
}

