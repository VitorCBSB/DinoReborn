/*
 * Component.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>
#include <typeinfo>

class ComponentBase {
public:
	ComponentBase() {
	}
	virtual ~ComponentBase() {
	}
};

template<typename T>
class Component: public ComponentBase {
public:
	Component() {
	}
	virtual ~Component() {
	}

	static std::string name() {
		return std::string(typeid(T).name());
	}
};

#endif /* COMPONENT_H_ */
