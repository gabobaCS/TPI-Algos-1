#include <algorithm>
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
    // Implementacion
    return resp;
}

// EJERCICIO 5
void evolucionToroide(toroide &t){
    // Implementacions
    return;
}

// EJERCICIO 6
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out;
    // Implementacion
    return out;
}

// EJERCICIO 7
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    // Implementacion
    return resp;
}

// EJERCICIO 8
bool primosLejanos(toroide const &t, toroide const &u) {
	bool resp = false; 
    // Implementacion
    return resp;
}

// EJERCICIO 9
int seleccionNatural(vector <toroide> ts) {
    int resp = -1; // este valor puede ser cambiado de acuerdo a la propia implementacion    
	// Implementacion
    return resp;
}

// EJERCICIO 10
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    // Implementacion
    return out;
}

// EJERCICIO 11
bool vistaTrasladada(toroide const &t, toroide const &u){
	bool resp = false;
    // Implementacion
    return resp;
}

// EJERCICIO 12
int menorSuperficieViva(toroide const &t){
	int resp = -1;
	// Implementacion
	return resp;
}
