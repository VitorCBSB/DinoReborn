/*
 * BoundingCircleComponent.h
 *
 *  Created on: 22/07/2014
 *      Author: vitor
 */

#ifndef BOUNDINGCIRCLECOMPONENT_H_
#define BOUNDINGCIRCLECOMPONENT_H_

#include "../ecs/VECS.h"

class BoundingCircleComponent: public Component<BoundingCircleComponent> {
public:
	double radius;

	BoundingCircleComponent(double radius) :
			radius(radius) {
	}
};

#endif /* BOUNDINGCIRCLECOMPONENT_H_ */
