/*
 * Component.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "BaseIdGenerator.h"
#include <memory>

class ComponentBase {
};

template<typename T>
class Component: public ComponentBase {
public:
	static int id() {
		return BaseIdGenerator<ComponentBase>::id<T>();
	}
};

typedef std::unique_ptr<ComponentBase> ComponentPtr;

#endif /* COMPONENT_H_ */
