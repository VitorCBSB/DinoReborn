/*
 * GameAnimations.h
 *
 *  Created on: 26/07/2014
 *      Author: vitor
 */

#ifndef GAMEDATA_H_
#define GAMEDATA_H_

#include "Sprite.h"
#include "parser/BulletDefinition.h"
#include <map>
#include <string>

class GameData {
public:
	static std::map<std::string, Sprite> sprites;
	static std::map<std::string, BulletDefinition> scripts;
};

#endif /* GAMEDATA_H_ */
