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
private:
	std::vector<std::unique_ptr<Aspect>> aspects;

public:
	template <typename... Asp>
	Aspect(Asp... aspects) : aspects{ aspects...} {}
	virtual ~Aspect();

	virtual bool validate(const Entity& e) = 0;
};

typedef std::unique_ptr<Aspect> AspectPtr;

#endif /* ASPECT_H_ */
