/*
 * JosePadialBot.cpp
 *
 *  Created on: 15 mayo 2018
 *      Author: Jose Antonio Padial Molina
 */

#include "JosePadialBot.h"

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

JosePadialBot::JosePadialBot() {
	// Inicializar las variables necesarias para ejecutar la partida

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

Move JosePadialBot::nextMove(const vector<Move> &adversary, const GameState &state) {

	Player miTurno = this->getPlayer();
	long timeout = this->getTimeOut();

	Move movimiento= M_NONE;

	for (int i = 1; i < 7; i++) {
		if (state.getSeedsAt(miTurno, (Position)i) == i) {
			movimiento = (Move)i;
			break;
		}
	}



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
