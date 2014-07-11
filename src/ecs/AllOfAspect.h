/*
 * AllOfAspect.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef ALLOFASPECT_H_
#define ALLOFASPECT_H_

class AllOfAspect : public Aspect {
public:
	template <typename... Components>
	AllOfAspect(Components... components) : Aspect(components...) {}
	virtual ~AllOfAspect() {}

	bool validate(const Entity& e) const {
		for (auto& component_name : components) {
			if (!e.has_component(component_name)) {
				return false;
			}
		}
		return true;
	}
};

#endif /* ALLOFASPECT_H_ */
