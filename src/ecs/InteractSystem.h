/*
 * InteractSystem.h
 *
 *  Created on: 14/07/2015
 *      Author: vitor
 */

#ifndef ECS_INTERACTSYSTEM_H_
#define ECS_INTERACTSYSTEM_H_

#include <vector>
#include <map>
#include "System.h"
#include "Entity.h"
#include "Aspect.h"

class InteractSystem : public System {
protected:
	EntityMap valid_entities_A;
	EntityMap valid_entities_B;

	std::vector<AspectPtr> aspects_A;
	std::vector<AspectPtr> aspects_B;

	bool check_entity_validity(EntityPtr e, const std::vector<AspectPtr>& aspects) {
		for (auto& aspect : aspects) {
			if (!aspect->validate(*e)) {
				return false;
			}
		}
		return true;
	}

public:
	InteractSystem(WorldPtr world_ptr) : System(world_ptr) {
	}
	virtual ~InteractSystem() {
	}

	void add_aspect_A(Aspect* aspect) {
		aspects_A.push_back(AspectPtr(aspect));
	}

	void add_aspect_B(Aspect* aspect) {
		aspects_B.push_back(AspectPtr(aspect));
	}

	void remove_entity(uint64_t entity_id) {
		valid_entities_A.erase(entity_id);
		valid_entities_B.erase(entity_id);
	}

	void update_entity(EntityPtr e) {
		remove_entity(e->get_id());
		if (check_entity_validity(e, aspects_A)) {
			valid_entities_A[e->get_id()] = e;
		}
		if (check_entity_validity(e, aspects_B)) {
			valid_entities_B[e->get_id()] = e;
		}
	}

	void process(double dt) {
		for (auto entity_A : valid_entities_A) {
			for (auto entity_B : valid_entities_B) {
				process_pair(*entity_A.second, *entity_B.second, dt);
			}
		}
	}

	virtual void process_pair(Entity& entityA, Entity& entityB, double dt) = 0;
};

#endif /* ECS_INTERACTSYSTEM_H_ */
