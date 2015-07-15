/*
 * UIComponent.h
 *
 *  Created on: 23/12/2014
 *      Author: vitor
 */

#ifndef UICOMPONENT_H_
#define UICOMPONENT_H_

#include "../../ecs/VECS.h"

// Marker component for UI stuff
// Mostly to differentiate between things
// That should be rendered without offset
// And those that should not.
class UIComponent: public Component<UIComponent> {
};

#endif /* UICOMPONENT_H_ */
