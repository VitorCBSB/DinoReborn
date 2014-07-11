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
	Aspect(Components... components) :
			components { std::string(typeid(components).name())... } {
	}
	virtual ~Aspect();

	virtual bool validate(const Entity& e) const = 0;
};

typedef std::unique_ptr<Aspect> AspectPtr;

#endif /* ASPECT_H_ */
