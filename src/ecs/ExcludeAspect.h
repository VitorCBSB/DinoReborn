/*
 * ExcludeAspect.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef EXCLUDEASPECT_H_
#define EXCLUDEASPECT_H_

#include "Aspect.h"

class ExcludeAspect: public Aspect {
public:
	template <typename... Components>
	ExcludeAspect(Components... components) : Aspect(components...) {}
	virtual ~ExcludeAspect() {}

	bool validate(const Entity& e) const {
		for (auto& component_name : components) {
			if (e.has_component(component_name)) {
				return false;
			}
		}
		return true;
	}
};

#endif /* EXCLUDEASPECT_H_ */
