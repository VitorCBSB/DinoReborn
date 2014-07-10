/*
 * Entity.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <memory>
#include <typeinfo>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include "Component.h"

class Entity {
private:
	std::unordered_map<std::string, std::unique_ptr<Component>> components;

public:
	Entity();
	virtual ~Entity();

	template<typename T, typename ... Args>
	void add_component(Args&... args) {
		auto component = std::unique_ptr < T > (new T(args...));
		auto component_name = std::string(typeid(T).name());
		components[component_name] = component;
	}

	template<typename T>
	void add_component(T* component) {
		auto component_name = std::string(typeid(T).name());
		components[component_name] = std::unique_ptr < T > (component);
	}

	template<typename T>
	T& get_component() {
		auto it = components.find(std::string(typeid(T).name()));
		if (it == components.end()) {
			throw std::invalid_argument("Entry not found");
		}
		return static_cast<T>(*(it->second));
	}

	template<typename T>
	void remove_component() {
		components.erase(components.find(std::string(typeid(T).name())));
	}

	template<typename T>
	bool has_component() const {
		return components.find(std::string(typeid(T).name()))
				!= components.end();
	}

	bool has_component(const std::string& component_name) const {
		return components.find(component_name) != components.end();
	}
};

#endif /* ENTITY_H_ */
