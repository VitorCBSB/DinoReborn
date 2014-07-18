/*
 * Entity.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <memory>
#include <stdint.h>
#include <unordered_map>
#include "Component.h"

class Entity {
private:
	uint64_t id;
	std::unordered_map<int, ComponentPtr> components;

public:
	Entity(uint64_t id) :
			id(id) {
	}
	virtual ~Entity() {
	}

	uint64_t get_id() const {
		return id;
	}

	template<typename T, typename ... Args>
	void add_component(Args ... args) {
		auto component = std::unique_ptr<T>(new T(args...));
		components[T::id()] = std::move(component);
	}

	template<typename T>
	void add_component(T* component) {
		auto component_id = T::id();
		components[component_id] = std::unique_ptr<T>(component);
	}

	template<typename T>
	T* get_component() {
		auto it = components.find(T::id());
		if (it == components.end()) {
			return nullptr;
		}
		return static_cast<T*>(it->second.get());
	}

	template<typename T>
	void remove_component() {
		components.erase(components.find(T::id()));
	}

	template<typename T>
	bool has_component() const {
		return components.find(T::id()) != components.end();
	}

	bool has_component(const int& component_id) const {
		return components.find(component_id) != components.end();
	}
};

typedef std::unique_ptr<Entity> EntityPtr;

#endif /* ENTITY_H_ */
