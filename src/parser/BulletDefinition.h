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

	BulletDefinition() {
	}
	BulletDefinition(std::string sprite_file_name,
			std::vector<ActionPtr>& actions) :
			sprite_file_name(sprite_file_name) {
		for (auto& action : actions) {
			this->actions.push_back(std::move(action));
		}
		actions.clear();
	}
	BulletDefinition(const BulletDefinition& other) :
			sprite_file_name(other.sprite_file_name) {
		for (auto& action : other.actions) {
			actions.push_back(action->clone());
		}
	}
	BulletDefinition& operator=(const BulletDefinition& other) {
		sprite_file_name = other.sprite_file_name;
		actions.clear();
		for (auto& action : other.actions) {
			actions.push_back(action->clone());
		}
		return *this;
	}
};

#endif /* BULLETDEFINITION_H_ */
