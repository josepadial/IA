/*
 * JosePadialBot.cpp
 *
 *  Created on: 15 mayo 2018
 *  Author: Jose Antonio Padial Molina
 */

#include "JosePadialBot.h"

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

JosePadialBot::JosePadialBot() {
	// Inicializar las variables necesarias para ejecutar la partida
	srand(time(0));

}

JosePadialBot::~JosePadialBot() {
	// Liberar los recursos reservados (memoria, ficheros, etc.)
}

void JosePadialBot::initialize() {
	// Inicializar el bot antes de jugar una partida
}

string JosePadialBot::getName() {
	return "JosePadialBot"; // Sustituir por el nombre del bot
}

int Heuristica(Player player, GameState st){
	Player oponente;
	int valor;
	int mis_puntos = 0;
	int sus_puntos = 0;

	if(st.getCurrentPlayer() == J1)
		oponente = J2;
	else
		oponente = J1;

	for(int i = 1; i<7; i++){
		mis_puntos += st.getSeedsAt(player, (Position)i);
		sus_puntos += st.getSeedsAt(oponente, (Position)i);
	}

	valor = (st.getScore(player) - st.getScore(oponente)) + (mis_puntos - sus_puntos);

	return valor;
}

int Poda(Player player, GameState st, Move &mv, int profundidad, int alfa, int beta){
	int mejor;

	if(st.isFinalState() || profundidad == 0){
		return Heuristica(player, st);
		//return st.getScore(player);
	}
	else{
		if(player == st.getCurrentPlayer()){
			for(int i=1; i<7; i++){
				if(st.getSeedsAt(player, (Position)i)){
					GameState gs = st.simulateMove((Move)i);
					Move  accionAnterior;
					mejor = Poda(player, gs, accionAnterior, profundidad-1, alfa, beta);
					if(gs.getCurrentPlayer() == player) mejor = 500;

					if(alfa < mejor){
						alfa = mejor;
						mv = (Move)i;
						
					}
					if(beta <= alfa){
						return alfa;
						
					}
				}
			}
			return alfa;
		}
		else{
			for(int i=1; i<7; i++){
				if(st.getSeedsAt(player, (Position)i)){
					GameState gs = st.simulateMove((Move)i);
					mejor = Poda(player, gs, mv, profundidad-1, alfa, beta);
					if(gs.getCurrentPlayer() == player) mejor = 500;

					if(beta > mejor){
						beta = mejor;
						//mv = (Move) i;
						
					}
					if(beta<=alfa){
						return beta;
					}
				}
			}
			return beta;
		}
	}
}

int MiniMax(Player player,GameState st, Move &mv, int profundidad){
	Move mierda;
	int mejor=INT32_MIN;
	int max = INT32_MIN;
	int min = INT32_MAX;
	if(st.isFinalState() || profundidad == 0)
		//return Heuristica(player, st);
		return st.getScore(player);
	else{
		for(int i=1; i<7; i++){
			if(st.getSeedsAt(player, (Position)i)){
				GameState gs = st.simulateMove((Move)i);
				int valor = MiniMax(player, gs, mierda, profundidad-1);

				if(st.getCurrentPlayer() == player){
					if(valor > max){
						max = valor;
						mejor = valor;
						mv = (Move)i;
					}
				}
				else{
					if(valor < min){
						min = valor;
						mejor = valor;
						mv = (Move)i;
					}
				}
			}
		}
		return mejor;
	}
}

Move JosePadialBot::nextMove(const vector<Move> &adversary, const GameState &state) {

	Player miTurno = this->getPlayer();
	Player oponente;

	if(state.getCurrentPlayer() == J1)
		oponente = J2;
	else
		oponente = J1;

	long timeout = this->getTimeOut();
	bool hay_vacio = false; 
	bool tengo_que_robar = false;

	Move movimiento= M_NONE;

	for (int i = 1; i < 7; i++) {
		if (state.getSeedsAt(miTurno, (Position)i) == i) {
			movimiento = (Move)i;
			break;
		}
	}

	if(movimiento == M_NONE){
		int cantidad;
		int cantidad_mia;
		int cantidad_ant = 0;
		int cantidad_ant_rob = 0;
		int numero;
		int numero_mio;
		for(int i=1; i<7; i++){
			cantidad = state.getSeedsAt(oponente, (Position)(7-i));
			cantidad_mia = state.getSeedsAt(miTurno, (Position)(i+cantidad));
			if(cantidad < (7-i)){
				if(state.getSeedsAt(oponente, (Position)(7-i-cantidad)) == 0 && cantidad_mia != 0){
					if(cantidad > cantidad_ant_rob){
						hay_vacio = true;
						numero = (i+cantidad);
						cantidad_ant_rob = cantidad;
					}
				}
			}
		}

		for(int i=1; i<7; i++){
			cantidad_mia = state.getSeedsAt(miTurno, (Position)i);
			cantidad = state.getSeedsAt(oponente, (Position)(7-(i+cantidad)));
			if(cantidad_mia < i && cantidad_mia > 0){
				if(state.getSeedsAt(miTurno,(Position)(i-cantidad_mia)) == 0 && cantidad_ant < cantidad){
					if(state.getSeedsAt(oponente, (Position)(7-(i+cantidad))) > 0){
						tengo_que_robar = true;
						numero_mio = i;
						cantidad_ant = cantidad;
					}
				}
			}
		}

		if(state.getSeedsAt(miTurno, (Position)1) > 1){
			movimiento = (Move)1;
		}
		else if(hay_vacio == true){
			movimiento = (Move)(numero);
		}
		else if(tengo_que_robar == true){
			movimiento = (Move)(numero_mio);
		}
		else{

			int profundidad = 10;
			//int no_sirve = MiniMax(miTurno, state, movimiento, profundidad);
			int no_sirve = Poda(miTurno, state, movimiento, profundidad, INT32_MIN, INT32_MAX);
		}
	}

	hay_vacio=false;
	tengo_que_robar = false;



	// Implementar aquí la selección de la acción a realizar

	// OJO: Recordatorio. NO USAR cin NI cout.
	// Para salidas por consola (debug) utilizar cerr. Ejemplo:
	// cerr<< "Lo que quiero mostrar"<<endl;


	// OJO: Recordatorio. El nombre del bot y de la clase deben coincidir.
	// En caso contrario, el bot no podrá participar en la competición.
	// Se deberá sustituir el nombre JosePadialBot como nombre de la clase por otro
	// seleccionado por el alumno. Se deberá actualizar también el nombre
	// devuelto por el método getName() acordemente.

	return movimiento;
}
