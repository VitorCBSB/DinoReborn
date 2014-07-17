/*
 * Event.h
 *
 *  Created on: 15/07/2014
 *      Author: vitor
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <string>
#include <typeinfo>

class EventBase {
};

template<typename T>
class Event: public EventBase {
public:
	static std::string name() {
		return std::string(typeid(T).name());
	}
};

#endif /* EVENT_H_ */
