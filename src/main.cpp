/*
 * main.cpp
 *
 *  Created on: 13/07/2014
 *      Author: vitor
 */

#include "Game.h"
#include "parser/Expression.h"

//int main() {
//	Game game;
//	game.run();
//	return 0;
//}

int main() {
	Expression expression("1 + 2 / 3 + 0");
	printf("%f", expression.eval());
}
