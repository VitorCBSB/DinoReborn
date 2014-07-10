/*
 * System.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <memory>
#include "Aspect.h"
#include "Entity.h"

class System {
private:
	AspectPtr root_aspect;

public:
	System(Aspect* root_aspect) :
			root_aspect(AspectPtr(root_aspect)) {
	}
	virtual ~System();

	bool validate(const Entity& e) {
		return root_aspect->validate(e);
	}
};

#endif /* SYSTEM_H_ */
