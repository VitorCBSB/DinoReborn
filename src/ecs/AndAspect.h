/*
 * AndAspect.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef ANDASPECT_H_
#define ANDASPECT_H_

#include "Aspect.h"

class AndAspect: public Aspect {
public:
	template <typename... Asp>
	AndAspect(Asp... aspects) : Aspect( { aspects... } ) {}
	virtual ~AndAspect();

	bool validate(const Entity& e) {
		for (auto& aspect : aspects) {
			if (!aspect->validate(e)) {
				return false;
			}
		}
		return true;
	}
};

#endif /* ANDASPECT_H_ */
