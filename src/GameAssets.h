/*
 * GameAssets.h
 *
 *  Created on: 26/07/2014
 *      Author: vitor
 */

#ifndef GAMEASSETS_H_
#define GAMEASSETS_H_

#include "Sprite.h"
#include "parser/BulletDefinition.h"
#include <map>
#include <string>

class GameAssets {
public:
	static std::map<std::string, Sprite> sprites;
	static std::map<std::string, BulletDefinition> scripts;
};

#endif /* GAMEASSETS_H_ */
