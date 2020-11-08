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
    vector<int> seqTicks;
    int cantTicks = 0;
    int p; // sin esto no puedo usar la funcion esPeriodico
    for (int i = 0; i < ts.size(); i++){
        if (esPeriodico(ts[i], p)) {
            seqTicks.push_back(-1);
        } else {
            while (!esToroideMuerto(ts[i])){
                evolucionToroide(ts[i]);
                cantTicks++;
            }
            seqTicks.push_back(cantTicks);
            cantTicks = 0;
        }
    }
    return seqTicks;
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
    cout << endl;
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

toroide hacerSubrect(toroide t, int y1, int y2, int x1, int x2){
    toroide subrect;
    for (int i = y1; i <= y2; i++){
        vector<bool> fila;
        for(int j = x1; j <= x2; j++){
            fila.push_back(t[i][j]);
        }
        subrect.push_back(fila);
    }
    return subrect;
}

vector<toroide> todosLosSubrect(toroide t){
    vector<toroide> subrects;
       for(int y1 = 0; y1 < t.size(); y1++){
           for(int y2 = 0; y2 < t.size(); y2++){
               for(int x1 = 0; x1 < t[0].size(); x1++){
                   for(int x2 = 0; x2 < t[0].size(); x2++){
                       if (x1 <= x2 && y1 <= y2 )
                           subrects.push_back(hacerSubrect(t, y1, y2, x1, x2));
                   }
               }
           }
       }
    return subrects;
}

vector<toroide> subrectsConVivas(vector<toroide> ts, toroide t){
    //Genera una secuencia que posee unicamente aquellos subrectangulos que poseen todas las celdas vivas del toroide.
    vector<toroide> nuevaLista;
    for (int i = 0; i < ts.size(); i++){
        int vivas = posicionesVivas(ts[i]).size();
        if (vivas == posicionesVivas(t).size())
            nuevaLista.push_back(ts[i]);
    }
    return nuevaLista;
}

int areaToroide(toroide t){
    return t.size()*t[0].size();
}

int minimaArea(vector<toroide> ts){
    int min = areaToroide(ts[0]);
    for (int i = 0; i < ts.size(); i++){
        if (areaToroide(ts[i]) < min)
            min = areaToroide(ts[i]);
    }
    return min;
}





