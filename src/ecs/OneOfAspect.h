/*
 * OneOfAspect.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef ONEOFASPECT_H_
#define ONEOFASPECT_H_

#include "Aspect.h"
#include <string>
#include <initializer_list>

class OneOfAspect: public Aspect {
public:
	OneOfAspect(std::initializer_list<std::string> components) :
			Aspect(components) {
	}
	virtual ~OneOfAspect() {
	}

	bool validate(const Entity& e) const {
		for (auto& component_name : components) {
			if (e.has_component(component_name)) {
				return true;
			}
		}
		return false;
	}
};

#endif /* ONEOFASPECT_H_ */
