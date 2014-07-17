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
#include <initializer_list>
#include "Entity.h"

class Aspect {
protected:
	std::vector<int> components;

public:
	Aspect(std::initializer_list<int> components) :
			components(components) {
	}
	virtual ~Aspect() {
	}

	virtual bool validate(const Entity& e) const = 0;
};

typedef std::unique_ptr<Aspect> AspectPtr;

#endif /* ASPECT_H_ */
