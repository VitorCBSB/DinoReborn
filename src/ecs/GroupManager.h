/*
 * GroupManager.h
 *
 *  Created on: 21/07/2014
 *      Author: vitor
 */

#ifndef GROUPMANAGER_H_
#define GROUPMANAGER_H_

#include "Entity.h"
#include <string>
#include <map>
#include <stdint.h>

class GroupManager {
private:
	std::map<std::string, std::map<uint64_t, EntityPtr>> groups;

public:
	void assign_entity_to_group(std::string group_name, EntityPtr entity) {
		groups[group_name][entity->get_id()] = entity;
	}

	std::map<uint64_t, EntityPtr>& get_entities_from_group(std::string group_name) {
		return groups[group_name];
	}

	void remove_entity(uint64_t entity_id) {
		for (auto& group : groups) {
			group.second.erase(entity_id);
		}
	}

};

#endif /* GROUPMANAGER_H_ */
