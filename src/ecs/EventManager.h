/*
 * EventManager.h
 *
 *  Created on: 16/07/2014
 *      Author: vitor
 */

#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include "Event.h"
#include <functional>
#include <string>
#include <map>
#include <vector>

class EventCallbackBase {
public:
	void execute(const EventBase& event);
};

template <typename T>
class EventCallback : public EventCallbackBase {
private:
	std::function<void(const T&)> callback;

public:
	EventCallback(std::function<void(const T&)> callback) : callback(callback) {}
	void execute(const EventBase& event) {
		T& real_event = static_cast<T>(event);
		callback(real_event);
	}
};

class EventManager {
private:
	std::map<std::string, std::vector<EventCallbackBase>> callbacks;

public:
	template <typename E, typename Handler>
	void subscribe(Handler& handler) {
		void (Handler::*handle)(const E&) = &Handler::handle;
		auto callback = EventCallback<E>(std::bind(handle, &handler, std::placeholders::_1));
		callbacks[E::name()].push_back(callback);
	}

	template <typename E, typename ... Args>
	void broadcast(Args&... args) {
		E event(args...);
		for (auto& callback : callbacks[E::name()]) {
			callback.execute(event);
		}
	}
};

#endif /* EVENTMANAGER_H_ */
