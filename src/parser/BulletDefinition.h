/*
 * BulletDefinition.h
 *
 *  Created on: 05/08/2014
 *      Author: vitor
 */

#ifndef BULLETDEFINITION_H_
#define BULLETDEFINITION_H_

#include <string>
#include <memory>
#include "../Action.h"

class BulletDefinition {
public:
	std::string sprite_file_name;
	std::vector<ActionPtr> actions;

	BulletDefinition(std::string sprite_file_name,
			std::vector<ActionPtr> actions) :
			sprite_file_name(sprite_file_name), actions(actions) {
	}
};

#endif /* BULLETDEFINITION_H_ */
