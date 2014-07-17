/*
 * Event.h
 *
 *  Created on: 15/07/2014
 *      Author: vitor
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "BaseIdGenerator.h"

class EventBase {
};

template<typename T>
class Event: public EventBase {
public:
	static int id() {
		return BaseIdGenerator<EventBase>::id<T>();
	}
};

#endif /* EVENT_H_ */
