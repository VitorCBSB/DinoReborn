/*
 * World.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "Entity.h"
#include "System.h"
#include "Aspect.h"
#include <memory>
#include <stdint.h>
#include <map>
#include <string>

class World {
private:
	std::map<std::string, SystemPtr> systems;
	std::map<uint64_t, EntityPtr> entities;

	uint64_t new_entity_id = 0;

public:
	World();
	virtual ~World();

	Entity& create_entity();
	void remove_entity(uint64_t id);
	void process(double dt);

	template <typename T, typename ... Args>
	void add_system(Args... args) {
		systems[T::name()] = SystemPtr(new T(args...));
	}

	template <typename Subscribed, typename Subscriber, typename ... Subscribers>
	void subscribe_system() {
		systems[Subscribed::name()]->add_subscriber(systems[Subscriber::name()]);
		subscribe_system<Subscribed, Subscribers...>();
	}

	template <typename Subscribed, typename Subscriber>
	void subscribe_system() {
		systems[Subscribed::name()]->add_subscriber(systems[Subscriber::name()]);
	}
};

#endif /* WORLD_H_ */
