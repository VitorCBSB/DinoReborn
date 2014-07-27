/*
 * GameAnimations.h
 *
 *  Created on: 26/07/2014
 *      Author: vitor
 */

#ifndef GAMEANIMATIONS_H_
#define GAMEANIMATIONS_H_

#include "Sprite.h"
#include <map>
#include <string>

class GameAnimations {
public:
	static std::map<std::string, Sprite> sprites;
};

#endif /* GAMEANIMATIONS_H_ */
