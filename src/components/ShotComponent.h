/*
 * ShotComponent.h
 *
 *  Created on: 17/12/2014
 *      Author: vitor
 */

#ifndef SHOTCOMPONENT_H_
#define SHOTCOMPONENT_H_

#include <string>
#include "../ecs/Component.h"
#include "../Timer.h"

#define SHOT_COOLDOWN_TIMER 100

class ShotComponent: public Component<ShotComponent> {
public:
	std::string shot_script;
	Timer shot_cooldown;
	bool shooting = false;

	ShotComponent() :
			shot_script("scripts/bullets/burst.xml") {
		shot_cooldown.start(SHOT_COOLDOWN_TIMER);
	}
};

#endif /* SHOTCOMPONENT_H_ */
