/*
 * Aspect.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef ASPECT_H_
#define ASPECT_H_

#include <vector>
#include <memory>
#include "Entity.h"

class Aspect {
protected:
	std::vector<std::string> components;

public:
	template<typename ... Components>
	Aspect(Components ... components) :
			components { std::string(typeid(Components).name())... } {
	}
	virtual ~Aspect();

	template<typename T>
	void add_component() {
		components.push_back(std::string(typeid(T).name()));
	}

	bool validate(const Entity& e) {
		for (auto& component : components) {
			if (!e.has_component(component)) {
				return false;
			}
		}
		return true;
	}
};

typedef std::unique_ptr<Aspect> AspectPtr;

#endif /* ASPECT_H_ */
