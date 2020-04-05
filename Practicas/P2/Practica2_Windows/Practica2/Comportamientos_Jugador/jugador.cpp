#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"


#include <iostream>
#include <cmath>

void ComportamientoJugador::PintaPlan(list<Action> plan) {
	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			cout << "A ";
		}
		else if (*it == actTURN_R){
			cout << "D ";
		}
		else if (*it == actTURN_L){
			cout << "I ";
		}
		else {
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}

void ComportamientoJugador::comprobarPosiblesAcciones(Nodo &pasado){
    if(bien_situado == false){
        int min = 1;
        int max = 8;
        switch(pasado.estado.orientacion){
            case 0:
                if((miniMapa[pasado.estado.fila][pasado.estado.columna-1] == 'S' || miniMapa[pasado.estado.fila][pasado.estado.columna-1] == 'T') ||
                   (miniMapa[pasado.estado.fila][pasado.estado.columna-1] == 'K' || miniMapa[pasado.estado.fila][pasado.estado.columna-1] == '?')
                   && pasado.estado.columna-1 >= min)
                    pasado.accionesPosibles.push_back(actTURN_L);
                if((miniMapa[pasado.estado.fila-1][pasado.estado.columna] == 'S' || miniMapa[pasado.estado.fila-1][pasado.estado.columna] == 'T') ||
                   (miniMapa[pasado.estado.fila-1][pasado.estado.columna] == 'K' || miniMapa[pasado.estado.fila-1][pasado.estado.columna] == '?')
                   && pasado.estado.fila-1 >= min){
                       if(aldeano_tonto == false)
                            pasado.accionesPosibles.push_back(actFORWARD);
                        else
                            aldeano_tonto = false;
                   }
                if((miniMapa[pasado.estado.fila][pasado.estado.columna+1] == 'S' || miniMapa[pasado.estado.fila][pasado.estado.columna+1] == 'T') ||
                   (miniMapa[pasado.estado.fila][pasado.estado.columna+1] == 'K' || miniMapa[pasado.estado.fila][pasado.estado.columna+1] == '?')
                   &&pasado.estado.columna+1 <= max)
                    pasado.accionesPosibles.push_back(actTURN_R);
            break;
            case 1:
                if((miniMapa[pasado.estado.fila-1][pasado.estado.columna] == 'S' || miniMapa[pasado.estado.fila-1][pasado.estado.columna] == 'T') ||
                   (miniMapa[pasado.estado.fila-1][pasado.estado.columna] == 'K' || miniMapa[pasado.estado.fila-1][pasado.estado.columna] == '?')
                   && pasado.estado.fila-1 >= min)
                    pasado.accionesPosibles.push_back(actTURN_L);
                if((miniMapa[pasado.estado.fila][pasado.estado.columna+1] == 'S' || miniMapa[pasado.estado.fila][pasado.estado.columna+1] == 'T') ||
                   (miniMapa[pasado.estado.fila][pasado.estado.columna+1] == 'K' || miniMapa[pasado.estado.fila][pasado.estado.columna+1] == '?')
                   && pasado.estado.columna+1 <= max){
                       if(aldeano_tonto == false)
                            pasado.accionesPosibles.push_back(actFORWARD);
                        else
                            aldeano_tonto = false;
                   }
                if((miniMapa[pasado.estado.fila+1][pasado.estado.columna] == 'S' || miniMapa[pasado.estado.fila+1][pasado.estado.columna] == 'T') ||
                   (miniMapa[pasado.estado.fila+1][pasado.estado.columna] == 'K' || miniMapa[pasado.estado.fila+1][pasado.estado.columna] == '?')
                   && pasado.estado.fila+1 <= max)
                    pasado.accionesPosibles.push_back(actTURN_R);
            break;
            case 2:
                if((miniMapa[pasado.estado.fila][pasado.estado.columna+1] == 'S' || miniMapa[pasado.estado.fila][pasado.estado.columna+1] == 'T') ||
                   (miniMapa[pasado.estado.fila][pasado.estado.columna+1] == 'K' || miniMapa[pasado.estado.fila][pasado.estado.columna+1] == '?')
                   && pasado.estado.columna+1 <= max)
                    pasado.accionesPosibles.push_back(actTURN_L);
                if((miniMapa[pasado.estado.fila+1][pasado.estado.columna] == 'S' || miniMapa[pasado.estado.fila+1][pasado.estado.columna] == 'T') ||
                   (miniMapa[pasado.estado.fila+1][pasado.estado.columna] == 'K' || miniMapa[pasado.estado.fila+1][pasado.estado.columna] == '?')
                   && pasado.estado.fila+1 <= max){
                       if(aldeano_tonto == false)
                            pasado.accionesPosibles.push_back(actFORWARD);
                        else
                            aldeano_tonto = false;
                   }
                if((miniMapa[pasado.estado.fila][pasado.estado.columna-1] == 'S' || miniMapa[pasado.estado.fila][pasado.estado.columna-1] == 'T') ||
                   (miniMapa[pasado.estado.fila][pasado.estado.columna-1] == 'K' || miniMapa[pasado.estado.fila][pasado.estado.columna-1] == '?')
                   && pasado.estado.columna-1 >= min)
                    pasado.accionesPosibles.push_back(actTURN_R);
            break;
            case 3:
                if((miniMapa[pasado.estado.fila+1][pasado.estado.columna] == 'S' || miniMapa[pasado.estado.fila+1][pasado.estado.columna] == 'T') ||
                   (miniMapa[pasado.estado.fila+1][pasado.estado.columna] == 'K' || miniMapa[pasado.estado.fila+1][pasado.estado.columna] == '?')
                   && pasado.estado.fila+1 <= max)
                    pasado.accionesPosibles.push_back(actTURN_L);
                if((miniMapa[pasado.estado.fila][pasado.estado.columna-1] == 'S' || miniMapa[pasado.estado.fila][pasado.estado.columna-1] == 'T') ||
                   (mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'K' || miniMapa[pasado.estado.fila][pasado.estado.columna-1] == '?')
                   && pasado.estado.columna-1 >= min){
                       if(aldeano_tonto == false)
                            pasado.accionesPosibles.push_back(actFORWARD);
                        else
                            aldeano_tonto = false;
                   }
                if((miniMapa[pasado.estado.fila-1][pasado.estado.columna] == 'S' || miniMapa[pasado.estado.fila-1][pasado.estado.columna] == 'T') ||
                   (miniMapa[pasado.estado.fila-1][pasado.estado.columna] == 'K' || miniMapa[pasado.estado.fila-1][pasado.estado.columna] == '?')
                   && pasado.estado.fila-1 >= min)
                    pasado.accionesPosibles.push_back(actTURN_R);
            break;
        }
    }
    else{
        int min = 3;
        int max = mapaResultado.size()-4;
        switch(pasado.estado.orientacion){
            case 0:
                if((mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'S' || mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'T') ||
                   (mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'K' || mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == '?')
                   && pasado.estado.columna-1 >= min)
                    pasado.accionesPosibles.push_back(actTURN_L);
                if((mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == 'S' || mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == 'T') ||
                   (mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == 'K' || mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == '?')
                   && pasado.estado.fila-1 >= min){
                       if(aldeano_tonto == false)
                            pasado.accionesPosibles.push_back(actFORWARD);
                        else
                            aldeano_tonto = false;
                   }
                if((mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == 'S' || mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == 'T') ||
                   (mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == 'K' || mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == '?')
                   &&pasado.estado.columna+1 <= max)
                    pasado.accionesPosibles.push_back(actTURN_R);
            break;
            case 1:
                if((mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == 'S' || mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == 'T') ||
                   (mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == 'K' || mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == '?')
                   && pasado.estado.fila-1 >= min)
                    pasado.accionesPosibles.push_back(actTURN_L);
                if((mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == 'S' || mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == 'T') ||
                   (mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == 'K' || mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == '?')
                   && pasado.estado.columna+1 <= max){
                       if(aldeano_tonto == false)
                            pasado.accionesPosibles.push_back(actFORWARD);
                        else
                            aldeano_tonto = false;
                   }
                if((mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == 'S' || mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == 'T') ||
                   (mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == 'K' || mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == '?')
                   && pasado.estado.fila+1 <= max)
                    pasado.accionesPosibles.push_back(actTURN_R);
            break;
            case 2:
                if((mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == 'S' || mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == 'T') ||
                   (mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == 'K' || mapaResultado[pasado.estado.fila][pasado.estado.columna+1] == '?')
                   && pasado.estado.columna+1 <= max)
                    pasado.accionesPosibles.push_back(actTURN_L);
                if((mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == 'S' || mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == 'T') ||
                   (mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == 'K' || mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == '?')
                   && pasado.estado.fila+1 <= max){
                       if(aldeano_tonto == false)
                            pasado.accionesPosibles.push_back(actFORWARD);
                        else
                            aldeano_tonto = false;
                   }
                if((mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'S' || mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'T') ||
                   (mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'K' || mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == '?')
                   && pasado.estado.columna-1 >= min)
                    pasado.accionesPosibles.push_back(actTURN_R);
            break;
            case 3:
                if((mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == 'S' || mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == 'T') ||
                   (mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == 'K' || mapaResultado[pasado.estado.fila+1][pasado.estado.columna] == '?')
                   && pasado.estado.fila+1 <= max)
                    pasado.accionesPosibles.push_back(actTURN_L);
                if((mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'S' || mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'T') ||
                   (mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == 'K' || mapaResultado[pasado.estado.fila][pasado.estado.columna-1] == '?')
                   && pasado.estado.columna-1 >= min){
                       if(aldeano_tonto == false)
                            pasado.accionesPosibles.push_back(actFORWARD);
                        else
                            aldeano_tonto = false;
                   }
                if((mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == 'S' || mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == 'T') ||
                   (mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == 'K' || mapaResultado[pasado.estado.fila-1][pasado.estado.columna] == '?')
                   && pasado.estado.fila-1 >= min)
                    pasado.accionesPosibles.push_back(actTURN_R);
            break;
        }
    }
}

Estado ComportamientoJugador::hacerNuevoEstado(const Estado &pasado, const Action &accion){
    Estado estado_final;
    estado_final = pasado;

    if(accion == actFORWARD){
        switch(pasado.orientacion){
            case 0:
                estado_final.fila--;
            break;
            case 1:
                estado_final.columna++;
            break;
            case 2:
                estado_final.fila++;
            break;
            case 3:
                estado_final.columna--;
            break;
        }
    }
    else if(accion == actTURN_L){
       switch(pasado.orientacion){
            case 0:
                estado_final.orientacion = 3;
            break;
            case 1:
                estado_final.orientacion = 0;
            break;
            case 2:
                estado_final.orientacion = 1;
            break;
            case 3:
                estado_final.orientacion = 2;
            break;
        }
    }
    else if(accion == actTURN_R){
        switch(pasado.orientacion){
            case 0:
                estado_final.orientacion = 1;
            break;
            case 1:
                estado_final.orientacion = 2;
            break;
            case 2:
                estado_final.orientacion = 3;
            break;
            case 3:
                estado_final.orientacion = 0;
            break;
        }
    }

    return estado_final;
}

bool ComportamientoJugador::pathFinding(const Estado &origen, const Estado &destino, list<Action> &plan) {
	//Borro la lista
	plan.clear();
	list<Nodo>Abiertos;
	set<Nodo>Cerrados;

	Nodo inicio;

	inicio.estado = origen;
	inicio.accion=actIDLE;
	Abiertos.push_back(inicio);


	while(inicio.estado != destino){
        bool esta_en_lista = false;
        auto it = Cerrados.find(inicio);

        if(it == Cerrados.end()){
            comprobarPosiblesAcciones(inicio);
            Cerrados.insert(inicio);
            for(auto it = inicio.accionesPosibles.begin(); it != inicio.accionesPosibles.end(); it++){
                Nodo hijo;

                hijo.estado = hacerNuevoEstado(inicio.estado, *it);
                hijo.accion = *it;
                comprobarPosiblesAcciones(hijo);
                hijo.accionesLlegada = inicio.accionesLlegada;
                hijo.accionesLlegada.push_back(inicio.accion);

                esta_en_lista = false;
                for(auto it2 = Abiertos.begin(); it2 != Abiertos.end(); it2++){
                    if(hijo.estado == it2->estado && hijo.estado.orientacion == it2->estado.orientacion){
                        esta_en_lista = true;
                        break;
                    }
                }
                if(esta_en_lista == false){
                    Abiertos.push_back(hijo);
                }
            }
        }
        Abiertos.erase(Abiertos.begin());
        if(Abiertos.empty()){
            cout << "No tengo nodos" << endl;
            return false;
        }
        else
            inicio = *Abiertos.begin();

	}

	Cerrados.insert(inicio);
	Abiertos.pop_front();
	inicio.accionesLlegada.push_back(inicio.accion);
	Abiertos.clear();

	plan = inicio.accionesLlegada;
	Cerrados.clear();
	PintaPlan(plan);

	/*vector<Nodo> nodo;
	for(auto it=Abiertos.begin(); it!=Abiertos.end();it++){
        nodo.push_back(*it);
	}
	int repe = 0;
	for(int i=0; i<nodo.size()-1;i++)
        for(int j=i+1; j<nodo.size();j++)
            if(nodo[i].estado == nodo[j].estado && nodo[i].estado.orientacion == nodo[j].estado.orientacion)
                repe++;
    cout << repe << endl;*/

	// Descomentar para ver el plan en el mapa
	VisualizaPlan(origen, plan);

	return true;
}

void ComportamientoJugador::InicializarMatrizPulgarcito(){
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
            pulgarcito[i][j] = 0;
}

void ComportamientoJugador::HayGPSCercano(const Sensores& sensores){
    filk = 4;
    colk = 4;
    switch(brujula){
        case 0:
            if(sensores.terreno[1] == 'K'){
                filk--; colk--;
            }
            else if(sensores.terreno[2] == 'K'){
                filk--;
            }
            else if(sensores.terreno[3] == 'K'){
                filk--; colk++;
            }
            else if(sensores.terreno[4] == 'K'){
                filk-=2; colk-=2;
            }
            else if(sensores.terreno[5] == 'K'){
                filk-=2; colk--;
            }
            else if(sensores.terreno[6] == 'K'){
                filk-=2;
            }
            else if(sensores.terreno[7] == 'K'){
                filk-=2; colk++;
            }
            else if(sensores.terreno[8] == 'K'){
                filk-=2; colk+=2;
            }
            else if(sensores.terreno[9] == 'K'){
                filk-=3; colk-=3;
            }
            else if(sensores.terreno[10] == 'K'){
                filk-=3; colk-=2;
            }
            else if(sensores.terreno[11] == 'K'){
                filk-=3; colk--;
            }
            else if(sensores.terreno[12] == 'K'){
                filk-=3;
            }
            else if(sensores.terreno[13] == 'K'){
                filk-=3; colk++;
            }
            else if(sensores.terreno[14] == 'K'){
                filk-=3; colk+=2;
            }
            else if(sensores.terreno[15] == 'K'){
                filk-=3; colk+=3;
            }
        break;
        case 1:
            if(sensores.terreno[1] == 'K'){
                filk--; colk++;
            }
            else if(sensores.terreno[2] == 'K'){
                colk++;
            }
            else if(sensores.terreno[3] == 'K'){
                filk++; colk++;
            }
            else if(sensores.terreno[4] == 'K'){
                filk-=2; colk+=2;
            }
            else if(sensores.terreno[5] == 'K'){
                filk--; colk+=2;
            }
            else if(sensores.terreno[6] == 'K'){
                colk+=2;
            }
            else if(sensores.terreno[7] == 'K'){
                filk++; colk+=2;
            }
            else if(sensores.terreno[8] == 'K'){
                filk+=2; colk+=2;
            }
            else if(sensores.terreno[9] == 'K'){
                filk-=3; colk+=3;
            }
            else if(sensores.terreno[10] == 'K'){
                filk-=2; colk+=3;
            }
            else if(sensores.terreno[11] == 'K'){
                filk--; colk+=3;
            }
            else if(sensores.terreno[12] == 'K'){
                colk+=3;
            }
            else if(sensores.terreno[13] == 'K'){
                filk++; colk+=3;
            }
            else if(sensores.terreno[14] == 'K'){
                filk+=2; colk+=3;
            }
            else if(sensores.terreno[15] == 'K'){
                filk+=3; colk+=3;
            }
        break;
        case 2:
            if(sensores.terreno[1] == 'K'){
                filk++; colk++;
            }
            else if(sensores.terreno[2] == 'K'){
                filk++;
            }
            else if(sensores.terreno[3] == 'K'){
                filk++; colk--;
            }
            else if(sensores.terreno[4] == 'K'){
                filk+=2; colk+=2;
            }
            else if(sensores.terreno[5] == 'K'){
                filk+=2; colk++;
            }
            else if(sensores.terreno[6] == 'K'){
                filk+=2;
            }
            else if(sensores.terreno[7] == 'K'){
                filk+=2; colk--;
            }
            else if(sensores.terreno[8] == 'K'){
                filk+=2; colk-=2;
            }
            else if(sensores.terreno[9] == 'K'){
                filk+=3; colk+=3;
            }
            else if(sensores.terreno[10] == 'K'){
                filk+=3; colk+=2;
            }
            else if(sensores.terreno[11] == 'K'){
                filk+=3; colk++;
            }
            else if(sensores.terreno[12] == 'K'){
                filk+=3;
            }
            else if(sensores.terreno[13] == 'K'){
                filk+=3; colk--;
            }
            else if(sensores.terreno[14] == 'K'){
                filk+=3; colk-=2;
            }
            else if(sensores.terreno[15] == 'K'){
                filk+=3; colk-=3;
            }
        break;
        case 3:
            if(sensores.terreno[1] == 'K'){
                filk++; colk--;
            }
            else if(sensores.terreno[2] == 'K'){
                colk--;
            }
            else if(sensores.terreno[3] == 'K'){
                filk--; colk--;
            }
            else if(sensores.terreno[4] == 'K'){
                filk+=2; colk-=2;
            }
            else if(sensores.terreno[5] == 'K'){
                filk++; colk-=2;
            }
            else if(sensores.terreno[6] == 'K'){
                colk-=2;
            }
            else if(sensores.terreno[7] == 'K'){
                filk--; colk-=2;
            }
            else if(sensores.terreno[8] == 'K'){
                filk-=2; colk-=2;
            }
            else if(sensores.terreno[9] == 'K'){
                filk+=3; colk-=3;
            }
            else if(sensores.terreno[10] == 'K'){
                filk+=2; colk-=3;
            }
            else if(sensores.terreno[11] == 'K'){
                filk++; colk-=3;
            }
            else if(sensores.terreno[12] == 'K'){
                colk+=3;
            }
            else if(sensores.terreno[13] == 'K'){
                filk--; colk-=3;
            }
            else if(sensores.terreno[14] == 'K'){
                filk-=2; colk-=3;
            }
            else if(sensores.terreno[15] == 'K'){
                filk-=3; colk-=3;
            }
        break;
    }
}

void ComportamientoJugador::descargarMapa(const Sensores& sensores){
    miniMapa[filk][colk] = sensores.terreno[0];
    switch(brujula){
        case 0:
            miniMapa[filk-1][colk-1] = sensores.terreno[1];
            miniMapa[filk-1][colk] = sensores.terreno[2];
            miniMapa[filk-1][colk+1] = sensores.terreno[3];
            miniMapa[filk-2][colk-2] = sensores.terreno[4];
            miniMapa[filk-2][colk-1] = sensores.terreno[5];
            miniMapa[filk-2][colk] = sensores.terreno[6];
            miniMapa[filk-2][colk+1] = sensores.terreno[7];
            miniMapa[filk-2][colk+2] = sensores.terreno[8];
            miniMapa[filk-3][colk-3] = sensores.terreno[9];
            miniMapa[filk-3][colk-2] = sensores.terreno[10];
            miniMapa[filk-3][colk-1] = sensores.terreno[11];
            miniMapa[filk-3][colk] = sensores.terreno[12];
            miniMapa[filk-3][colk+1] = sensores.terreno[13];
            miniMapa[filk-3][colk+2] = sensores.terreno[14];
            miniMapa[filk-3][colk+3] = sensores.terreno[15];
        break;
        case 1:
            miniMapa[filk-1][colk+1] = sensores.terreno[1];
            miniMapa[filk][colk+1] = sensores.terreno[2];
            miniMapa[filk+1][colk+1] = sensores.terreno[3];
            miniMapa[filk-2][colk+2] = sensores.terreno[4];
            miniMapa[filk-1][colk+2] = sensores.terreno[5];
            miniMapa[filk][colk+2] = sensores.terreno[6];
            miniMapa[filk+1][colk+2] = sensores.terreno[7];
            miniMapa[filk+2][colk+2] = sensores.terreno[8];
            miniMapa[filk-3][colk+3] = sensores.terreno[9];
            miniMapa[filk-2][colk+3] = sensores.terreno[10];
            miniMapa[filk-1][colk+3] = sensores.terreno[11];
            miniMapa[filk][colk+3] = sensores.terreno[12];
            miniMapa[filk+1][colk+3] = sensores.terreno[13];
            miniMapa[filk+2][colk+3] = sensores.terreno[14];
            miniMapa[filk+3][colk+3] = sensores.terreno[15];
        break;
        case 2:
            miniMapa[filk+1][colk+1] = sensores.terreno[1];
            miniMapa[filk+1][colk] = sensores.terreno[2];
            miniMapa[filk+1][colk-1] = sensores.terreno[3];
            miniMapa[filk+2][colk+2] = sensores.terreno[4];
            miniMapa[filk+2][colk+1] = sensores.terreno[5];
            miniMapa[filk+2][colk] = sensores.terreno[6];
            miniMapa[filk+2][colk-1] = sensores.terreno[7];
            miniMapa[filk+2][colk-2] = sensores.terreno[8];
            miniMapa[filk+3][colk+3] = sensores.terreno[9];
            miniMapa[filk+3][colk+2] = sensores.terreno[10];
            miniMapa[filk+3][colk+1] = sensores.terreno[11];
            miniMapa[filk+3][colk] = sensores.terreno[12];
            miniMapa[filk+3][colk-1] = sensores.terreno[13];
            miniMapa[filk+3][colk-2] = sensores.terreno[14];
            miniMapa[filk+3][colk-3] = sensores.terreno[15];
        break;
        case 3:
            miniMapa[filk+1][colk-1] = sensores.terreno[1];
            miniMapa[filk][colk-1] = sensores.terreno[2];
            miniMapa[filk-1][colk-1] = sensores.terreno[3];
            miniMapa[filk+2][colk-2] = sensores.terreno[4];
            miniMapa[filk+1][colk-2] = sensores.terreno[5];
            miniMapa[filk][colk-2] = sensores.terreno[6];
            miniMapa[filk-1][colk-2] = sensores.terreno[7];
            miniMapa[filk-2][colk-2] = sensores.terreno[8];
            miniMapa[filk+3][colk-3] = sensores.terreno[9];
            miniMapa[filk+2][colk-3] = sensores.terreno[10];
            miniMapa[filk+1][colk-3] = sensores.terreno[11];
            miniMapa[filk][colk-3] = sensores.terreno[12];
            miniMapa[filk-1][colk-3] = sensores.terreno[13];
            miniMapa[filk-2][colk-3] = sensores.terreno[14];
            miniMapa[filk-3][colk-3] = sensores.terreno[15];
        break;
    }
}

void ComportamientoJugador::DescubrirMapa(const Sensores& sensores){
    if(bien_situado){
        mapaResultado[fil][col] = sensores.terreno[0];
       if(brujula == 0){
            mapaResultado[fil-1][col-1] = sensores.terreno[1];
            mapaResultado[fil-1][col] = sensores.terreno[2];
            mapaResultado[fil-1][col+1] = sensores.terreno[3];
            mapaResultado[fil-2][col-2] = sensores.terreno[4];
            mapaResultado[fil-2][col-1] = sensores.terreno[5];
            mapaResultado[fil-2][col] = sensores.terreno[6];
            mapaResultado[fil-2][col+1] = sensores.terreno[7];
            mapaResultado[fil-2][col+2] = sensores.terreno[8];
            mapaResultado[fil-3][col-3] = sensores.terreno[9];
            mapaResultado[fil-3][col-2] = sensores.terreno[10];
            mapaResultado[fil-3][col-1] = sensores.terreno[11];
            mapaResultado[fil-3][col] = sensores.terreno[12];
            mapaResultado[fil-3][col+1] = sensores.terreno[13];
            mapaResultado[fil-3][col+2] = sensores.terreno[14];
            mapaResultado[fil-3][col+3] = sensores.terreno[15];
        }
        else if(brujula == 1){
            mapaResultado[fil-1][col+1] = sensores.terreno[1];
            mapaResultado[fil][col+1] = sensores.terreno[2];
            mapaResultado[fil+1][col+1] = sensores.terreno[3];
            mapaResultado[fil-2][col+2] = sensores.terreno[4];
            mapaResultado[fil-1][col+2] = sensores.terreno[5];
            mapaResultado[fil][col+2] = sensores.terreno[6];
            mapaResultado[fil+1][col+2] = sensores.terreno[7];
            mapaResultado[fil+2][col+2] = sensores.terreno[8];
            mapaResultado[fil-3][col+3] = sensores.terreno[9];
            mapaResultado[fil-2][col+3] = sensores.terreno[10];
            mapaResultado[fil-1][col+3] = sensores.terreno[11];
            mapaResultado[fil][col+3] = sensores.terreno[12];
            mapaResultado[fil+1][col+3] = sensores.terreno[13];
            mapaResultado[fil+2][col+3] = sensores.terreno[14];
            mapaResultado[fil+3][col+3] = sensores.terreno[15];
        }
        else if(brujula == 2){
            mapaResultado[fil+1][col+1] = sensores.terreno[1];
            mapaResultado[fil+1][col] = sensores.terreno[2];
            mapaResultado[fil+1][col-1] = sensores.terreno[3];
            mapaResultado[fil+2][col+2] = sensores.terreno[4];
            mapaResultado[fil+2][col+1] = sensores.terreno[5];
            mapaResultado[fil+2][col] = sensores.terreno[6];
            mapaResultado[fil+2][col-1] = sensores.terreno[7];
            mapaResultado[fil+2][col-2] = sensores.terreno[8];
            mapaResultado[fil+3][col+3] = sensores.terreno[9];
            mapaResultado[fil+3][col+2] = sensores.terreno[10];
            mapaResultado[fil+3][col+1] = sensores.terreno[11];
            mapaResultado[fil+3][col] = sensores.terreno[12];
            mapaResultado[fil+3][col-1] = sensores.terreno[13];
            mapaResultado[fil+3][col-2] = sensores.terreno[14];
            mapaResultado[fil+3][col-3] = sensores.terreno[15];
        }
        else if(brujula == 3){
            mapaResultado[fil+1][col-1] = sensores.terreno[1];
            mapaResultado[fil][col-1] = sensores.terreno[2];
            mapaResultado[fil-1][col-1] = sensores.terreno[3];
            mapaResultado[fil+2][col-2] = sensores.terreno[4];
            mapaResultado[fil+1][col-2] = sensores.terreno[5];
            mapaResultado[fil][col-2] = sensores.terreno[6];
            mapaResultado[fil-1][col-2] = sensores.terreno[7];
            mapaResultado[fil-2][col-2] = sensores.terreno[8];
            mapaResultado[fil+3][col-3] = sensores.terreno[9];
            mapaResultado[fil+2][col-3] = sensores.terreno[10];
            mapaResultado[fil+1][col-3] = sensores.terreno[11];
            mapaResultado[fil][col-3] = sensores.terreno[12];
            mapaResultado[fil-1][col-3] = sensores.terreno[13];
            mapaResultado[fil-2][col-3] = sensores.terreno[14];
            mapaResultado[fil-3][col-3] = sensores.terreno[15];
        }
    }
}

Action ComportamientoJugador::AndarPulgarcito(const Sensores& sensores){
    Action accion;
    Coordenadas izd, dlt, dcha;
    Coordenadas dltdcha, dltizd;

    dlt.dltdcha = &dltdcha;
    dlt.dltizd = &dltizd;
    switch(brujula){
        case 0:
            dltdcha.x = filp-1;
            dltdcha.y = colp+1;
            dltdcha.dato = pulgarcito[dlt.dltdcha->x][dlt.dltdcha->y];

            dlt.dltizd->x = filp-1;
            dlt.dltizd->y = colp-1;
            dlt.dltizd->dato = pulgarcito[dlt.dltizd->x][dlt.dltizd->y];

            izd.x = filp;
            izd.y = colp-1;
            izd.dato = pulgarcito[izd.x][izd.y];

            dlt.x = filp-1;
            dlt.y = colp;
            dlt.dato = pulgarcito[dlt.x][dlt.y];

            dcha.x = filp;
            dcha.y = colp+1;
            dcha.dato = pulgarcito[dcha.x][dcha.y];
            break;
        case 1:
            dltdcha.x = filp+1;
            dltdcha.y = colp+1;
            dltdcha.dato = pulgarcito[dlt.dltdcha->x][dlt.dltdcha->y];

            dltizd.x = filp-1;
            dltizd.y = colp+1;
            dltizd.dato = pulgarcito[dlt.dltizd->x][dlt.dltizd->y];

            izd.x = filp-1;
            izd.y = colp;
            izd.dato = pulgarcito[izd.x][izd.y];

            dlt.x = filp;
            dlt.y = colp+1;
            dlt.dato = pulgarcito[dlt.x][dlt.y];

            dcha.x = filp+1;
            dcha.y = colp;
            dcha.dato = pulgarcito[dcha.x][dcha.y];
            break;
        case 2:
            dltdcha.x = filp+1;
            dltdcha.y = colp-1;
            dltdcha.dato = pulgarcito[dlt.dltdcha->x][dlt.dltdcha->y];

            dltizd.x = filp+1;
            dltizd.y = colp+1;
            dltizd.dato = pulgarcito[dlt.dltizd->x][dlt.dltizd->y];

            izd.x = filp;
            izd.y = colp+1;
            izd.dato = pulgarcito[izd.x][izd.y];

            dlt.x = filp+1;
            dlt.y = colp;
            dlt.dato = pulgarcito[dlt.x][dlt.y];

            dcha.x = filp;
            dcha.y = colp-1;
            dcha.dato = pulgarcito[dcha.x][dcha.y];
            break;
        case 3:
            dltdcha.x = filp-1;
            dltdcha.y = colp-1;
            dltdcha.dato = pulgarcito[dlt.dltdcha->x][dlt.dltdcha->y];

            dltizd.x = filp+1;
            dltizd.y = colp-1;
            dltizd.dato = pulgarcito[dlt.dltizd->x][dlt.dltizd->y];

            izd.x = filp+1;
            izd.y = colp;
            izd.dato = pulgarcito[izd.x][izd.y];

            dlt.x = filp;
            dlt.y = colp-1;
            dlt.dato = pulgarcito[dlt.x][dlt.y];

            dcha.x = filp-1;
            dcha.y = colp;
            dcha.dato = pulgarcito[dcha.x][dcha.y];
            break;
    }
    return DeterminarMovimiento(dlt, izd, dcha, sensores);
}

Action ComportamientoJugador::DeterminarMovimiento(const Coordenadas& dlt, const Coordenadas& izd,
                                                   const Coordenadas& dcha, const Sensores& sensores){
    Action accion = actIDLE;
    unsigned int max = 0xFFFFFFFF;

    if((sensores.terreno[2] != 'S' && sensores.terreno[2] != 'T') && sensores.terreno[2] != 'K'){
        pulgarcito[dlt.x][dlt.y] = max;
        ActualizarDato(dlt, max);
    }
    if((sensores.terreno[1] != 'S' && sensores.terreno[1] != 'T') && sensores.terreno[1] != 'K'){
        pulgarcito[dlt.dltizd->x][dlt.dltizd->y] = max;
        ActualizarDatoPuntero(dlt.dltizd, max);
    }
    if((sensores.terreno[3] != 'S' && sensores.terreno[3] != 'T') && sensores.terreno[3] != 'K'){
        pulgarcito[dlt.dltdcha->x][dlt.dltdcha->y] = max;
        ActualizarDatoPuntero(dlt.dltdcha, max);
    }

    accion = BuscarMenor(dlt, izd, dcha, sensores);

    return accion;
}

void ComportamientoJugador::ActualizarDato(Coordenadas coor,unsigned int valor){
    coor.dato = valor;
}
void ComportamientoJugador::ActualizarDatoPuntero(Coordenadas *coor,unsigned int valor){
    coor->dato = valor;
}

Action ComportamientoJugador::BuscarMenor(const Coordenadas& dlt, const Coordenadas& izd, const Coordenadas& dcha
                                          , const Sensores& sensores){
    Action accion = actIDLE;
    bool vengo = false;
    unsigned int max = 0xFFFFFFFF;

    if(pulgarcito[dlt.x][dlt.y] != max && ((dlt.dato == izd.dato && dlt.dato == dcha.dato) ||
                                           (izd.dato <= dcha.dato && dlt.dato <= izd.dato) ||
                                           (dcha.dato <= izd.dato && dlt.dato <= dcha.dato))){
        accion = actFORWARD;
    }
    else if(pulgarcito[dlt.x][dlt.y] != max && ((izd.dato <= dlt.dato && dcha.dato <= izd.dato) ||
                                                (dlt.dato <= izd.dato && dcha.dato <= dlt.dato))){
        accion = actTURN_R;
    }
    else if(pulgarcito[dlt.x][dlt.y] != max && ((dcha.dato <= dlt.dato && izd.dato <= dcha.dato) ||
                                                (dlt.dato <= dcha.dato && izd.dato <= dlt.dato))){
        accion = actTURN_L;
    }
    else if(pulgarcito[dlt.x][dlt.y] == max && (izd.dato == dcha.dato)){
        if (!girar_derecha){
            accion = actTURN_L;
            if(rand()%2 == 0) girar_derecha = true;
            else girar_derecha = false;
        }
        else{
            accion = actTURN_R;
            if(rand()%2 == 0) girar_derecha = true;
            else girar_derecha = false;
        }
    }
    else if(pulgarcito[dlt.x][dlt.y] == max && (dcha.dato < izd.dato)){
        accion = actTURN_R;
    }
    else if(pulgarcito[dlt.x][dlt.y] == max && (izd.dato < dcha.dato)){
        accion = actTURN_L;
    }


    return accion;
}

Action ComportamientoJugador::think(Sensores sensores) {
  if (sensores.mensajeF != -1 && !bien_situado){
		fil = sensores.mensajeF;
		col = sensores.mensajeC;
		bien_situado = true;
		hayK = false;
		primera_vez = true;
	}

	// Actualizar el efecto de la ultima accion
	if(!primera_vez){
        switch (ultimaAccion){
            case actTURN_R: brujula = (brujula+1)%4; break;
            case actTURN_L: brujula = (brujula+3)%4; break;
            case actFORWARD:
                if(!sensores.colision){
                    switch (brujula){
                        case 0: fil--; filp--; break;
                        case 1: col++; colp++; break;
                        case 2: fil++; filp++; break;
                        case 3: col--; colp--; break;
                    }
                    pulgarcito[filp][colp] = marca;
                    marca++;
                }
                //cout << "fil: " << fil << "  col: " << col << " Or: " << brujula << endl;
        }
	}
	else primera_vez = false;

	if(gps_cerca == false && bien_situado == false){
        for(int i=0; i<16 && gps_cerca == false; i++){
            if(sensores.terreno[i] == 'K'){
                    cout << "esta es la i" << i << endl;
                gps_cerca = true;
                descargarMapa(sensores);
                HayGPSCercano(sensores);
                destinoK.columna = colk;
                destinoK.fila = filk;
                destinoK.orientacion = brujula;cout << "esta es la dK" << filk << " " << colk << endl;
                origenK.fila = 4;
                origenK.columna = 4;
                origenK.orientacion = brujula;
                hayK = pathFinding(origenK, destinoK, plan);
            }
        }
	}

    DescubrirMapa(sensores);

	// Determinar si ha cambiado el destino desde la ultima planificacion
	if (hayPlan and (sensores.destinoF != destino.fila or sensores.destinoC != destino.columna)){
		cout << "El destino ha cambiado\n";
		hayPlan = false;
	}

	// Determinar si tengo que construir un plan
	if (!hayPlan && bien_situado == true){
		Estado origen;
		origen.fila = fil;
		origen.columna = col;
		origen.orientacion = brujula;

		destino.fila = sensores.destinoF;
		destino.columna = sensores.destinoC;

    		hayPlan = pathFinding(origen,destino,plan);
	}


	// Ejecutar el plan
	Action sigAccion;

	if(bien_situado == true){
       if (hayPlan and plan.size()>0){
            if(sensores.superficie[2] == 'a' && plan.front() == actFORWARD){
                contador ++;
                sigAccion = actIDLE;
                if(contador == 3){
                    contador = 0;
                    aldeano_tonto = true;
                    hayPlan = false;
                }
            }
            else{
               sigAccion = plan.front();
                plan.erase(plan.begin());
            }
            if(((sensores.terreno[2] != 'T' && sensores.terreno[2] != '?') && (sensores.terreno[2] != 'S' && sensores.terreno[2] != 'K')) && sigAccion == actFORWARD){
                hayPlan = false;
                sigAccion = actIDLE;
            }
        }
        else {
            sigAccion = actTURN_L;
        }
	}
	else{
        if(hayK and plan.size()>0){
            if(sensores.superficie[2] == 'a'){
                sigAccion = actIDLE;
            }
            else{
               sigAccion = plan.front();
                plan.erase(plan.begin());
            }
            if(((sensores.terreno[2] != 'T' && sensores.terreno[2] != '?') && (sensores.terreno[2] != 'S' && sensores.terreno[2] != 'K')) && sigAccion == actFORWARD){
                hayK = false;
                gps_cerca = false;
                sigAccion = actIDLE;
            }
        }
        else{
            if(marca % mapaResultado.size() != 0)
                sigAccion = AndarPulgarcito(sensores);
            else{
                int tand = rand()%2;
                marca ++;
                if(tand == 0)
                    sigAccion = actTURN_R;
                else
                    sigAccion = actTURN_L;
            }
        }
	}


	ultimaAccion = sigAccion;
	return sigAccion;
}


void AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
}

void ComportamientoJugador::VisualizaPlan(const Estado &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
	Estado cst = st;

	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			switch (cst.orientacion) {
				case 0: cst.fila--; break;
				case 1: cst.columna++; break;
				case 2: cst.fila++; break;
				case 3: cst.columna--; break;
			}
			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R){
			cst.orientacion = (cst.orientacion+1)%4;
		}
		else if (*it == actTURN_L){
			cst.orientacion = (cst.orientacion+3)%4;
		}
		it++;
	}
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
