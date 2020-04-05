/*
 * JosePadialBot.h
 *
 *  Created on: 15 mayo 2018
 *      Author: Jose Antonio Padial Molina
 */

#include "Bot.h"

#ifndef MANUPCBOT_H_
#define MANUPCBOT_H_

class JosePadialBot:Bot {
public:
	JosePadialBot();
	~JosePadialBot();


	void initialize();
	string getName();
	Move nextMove(const vector<Move> &adversary, const GameState &state);
};

#endif /* MANUPCBOT_H_ */
