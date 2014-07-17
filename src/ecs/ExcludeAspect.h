/*
 * ExcludeAspect.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef EXCLUDEASPECT_H_
#define EXCLUDEASPECT_H_

#include "Aspect.h"
#include <string>

template<typename ... Comp>
class ExcludeAspect: public Aspect {
public:
	ExcludeAspect() :
			Aspect { Comp::id()... } {
	}

	bool validate(const Entity& e) const {
		for (auto& component_id : components) {
			if (e.has_component(component_id)) {
				return false;
			}
		}
		return true;
	}
};

#endif /* EXCLUDEASPECT_H_ */
