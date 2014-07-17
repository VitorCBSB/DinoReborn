/*
 * OneOfAspect.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef ONEOFASPECT_H_
#define ONEOFASPECT_H_

#include "Aspect.h"
#include "Entity.h"

template<typename ... Comp>
class OneOfAspect: public Aspect {
public:
	OneOfAspect() :
			Aspect { Comp::id()... } {
	}

	bool validate(const Entity& e) const {
		for (auto& component_id : components) {
			if (e.has_component(component_id)) {
				return true;
			}
		}
		return false;
	}
};

#endif /* ONEOFASPECT_H_ */
