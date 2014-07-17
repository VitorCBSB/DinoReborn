/*
 * AllOfAspect.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef ALLOFASPECT_H_
#define ALLOFASPECT_H_

#include "Aspect.h"
#include "Entity.h"

template<typename ... Comp>
class AllOfAspect: public Aspect {
public:
	AllOfAspect() :
			Aspect { Comp::id()... } {
	}

	bool validate(const Entity& e) const {
		for (auto& component_id : components) {
			if (!e.has_component(component_id)) {
				return false;
			}
		}
		return true;
	}
};

#endif /* ALLOFASPECT_H_ */
