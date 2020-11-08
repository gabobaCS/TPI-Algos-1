#include <algorithm>
#include <iostream>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
//    bool resp = false; // este valor puede ser cambiado de acuerdo a la propia implementacion
    return esToroide(t);
}

// EJERCICIO 2
vector<posicion> posicionesVivas(toroide const &t) {
	vector<posicion> vivos;
    for(int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            if (t[i][j])  vivos.push_back(make_pair(i,j));
        }
    }
    return vivos;
}

// EJERCICIO 3
float densidadPoblacion(toroide const &t) {
	float resp = posicionesVivas(t).size()/(t[0].size()*t.size());
    return resp;
}

// EJERCICIO 4
bool evolucionDePosicion(toroide const &t, posicion x) {
	bool resp = false;
	int cantVivos = vecinosVivos(t, x.first, x.second);
	if (t[x.first][x.second]){
	    if (2 <= cantVivos && cantVivos <= 3) resp = true;
	} else {
        if (cantVivos == 3) resp = true;
    }
    return resp;
}

// EJERCICIO 5
void evolucionToroide(toroide &t){
    toroide t0 = t;
    for (int i = 0; i < t0.size(); i++){
        for (int j = 0; j < columnas(t0); j++) {
            t[i][j] = evolucionDePosicion(t0, make_pair(i,j));
        }
    }
    return;
}

// EJERCICIO 6
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out = t;
    for (int ticks = 0; ticks < K; ticks++){
        evolucionToroide(out);
    }
    return out;
}

// EJERCICIO 7
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    toroide evolucion = t;
    evolucionToroide(evolucion);
    int ticks = 1; // el codigo de arriba ya es un tick
    while(evolucion != t && !esToroideMuerto(evolucion)){
        evolucionToroide(evolucion);
        ticks += 1;
    }
    if (t == evolucion){
        resp = true;
        p = ticks;
    }
    return resp;
}

// EJERCICIO 8
bool primosLejanos(toroide const &t, toroide const &u) {
	bool resp = false;
    int k = 1;
	bool ningunoEsPeriodico = evolucionMultiple(t, k) != t && evolucionMultiple(u, k) != u;
	bool ningunoMuere = !esToroideMuerto(evolucionMultiple(t, k)) && !esToroideMuerto(evolucionMultiple(u, k));
    while(ningunoEsPeriodico && ningunoMuere && !resp){
        if (evolucionMultiple(t, k) == t || evolucionMultiple(u, k) == u){
            resp = true;
        } else {
            k++;
        }
    }
    return resp;
}

// EJERCICIO 9
int seleccionNatural(vector <toroide> ts) {
//    int resp = -1; // este valor puede ser cambiado de acuerdo a la propia implementacion
//    vector<int> cantTicksHastaQueMuere = ticksHastaMorir(ts); // la pre dice que todos mueren


//    return resp;
}

// EJERCICIO 10
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    for (int i = 0; i < t.size(); i++){
        vector<bool> filaActual;
        for (int j = 0; j < t[0].size(); j++){
            filaActual.push_back(t[i][j] && u[i][j]);
        }
        out.push_back(filaActual);
    }
    return out;
}

// EJERCICIO 11
bool vistaTrasladada(toroide const &t, toroide const &u){
	bool resp = false;
    for (int i = 0; i <= t.size(); i++){
        for (int j = 0; j <= t[0].size(); j++){
            if (esTraslacion(t,u,i,j)) resp = true;
        }
    }
    return resp;
}

void imprimirVector(vector<int> vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

// EJERCICIO 12
int menorSuperficieViva(toroide const &t){
	int resp = (t.size() * t[0].size());
	for(int i = 0; i < t.size(); i++){
	    for(int j = 0; j < t[0].size(); j++){
	        toroide trasladado = hacerTraslacion(t, i, j);
	        vector<toroide> subrects = todosLosSubrect(trasladado);
	        vector<toroide> conTodasVivas = subrectsConVivas(subrects,t);
            if (minimaArea(conTodasVivas) < resp)
                resp = minimaArea(conTodasVivas);

	    }
	}

	return resp;
}
