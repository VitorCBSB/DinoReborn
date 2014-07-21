/*
 * TagManager.h
 *
 *  Created on: 21/07/2014
 *      Author: vitor
 */

#ifndef TAGMANAGER_H_
#define TAGMANAGER_H_

#include "Entity.h"
#include <map>
#include <string>

class TagManager {
private:
	std::map<std::string, EntityPtr> tagged_entities;

public:
	void set_tag(std::string tag, EntityPtr entity) {
		entity->set_tag(tag);
		tagged_entities[tag] = entity;
	}

	void remove(std::string tag) {
		tagged_entities.erase(tag);
	}

	EntityPtr get_entity(std::string tag) {
		if (!tagged_entities.count(tag)) {
			return nullptr;
		}
		return tagged_entities[tag];
	}

};

#endif /* TAGMANAGER_H_ */
