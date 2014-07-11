/*
 * OneOfAspect.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef ONEOFASPECT_H_
#define ONEOFASPECT_H_

#include "Aspect.h"

class OneOfAspect: public Aspect {
public:
	template <typename... Components>
	OneOfAspect(Components... components) : Aspect(components...) {}
	virtual ~OneOfAspect() {}

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
