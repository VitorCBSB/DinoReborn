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

class System {
private:
	AspectPtr root_aspect;

public:
	System(Aspect* root_aspect) : root_aspect(AspectPtr(root_aspect)) {}
	virtual ~System();
};

#endif /* SYSTEM_H_ */
