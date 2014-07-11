/*
 * System.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <memory>
#include <vector>
#include "Aspect.h"
#include "Entity.h"

class System {
protected:
	std::vector<AspectPtr> aspects;

public:
	System();
	virtual ~System();

	bool validate(const Entity& e) const {
		for (auto& aspect : aspects) {
			if (!aspect->validate(e)) {
				return false;
			}
		}
		return true;
	}

	virtual void logic() = 0;
};

#endif /* SYSTEM_H_ */
