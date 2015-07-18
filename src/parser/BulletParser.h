/*
 * BulletParser.h
 *
 *  Created on: 05/08/2014
 *      Author: vitor
 */

#ifndef BULLETPARSER_H_
#define BULLETPARSER_H_

#include "../Action.h"
#include "../ActionChangeSpeed.h"
#include "../ActionChangeDirection.h"
#include "../ActionWait.h"
#include "../ActionVanish.h"
#include "../ActionRepeat.h"
#include "../ActionFire.h"
#include "../Direction.h"
#include "tinyxml2.h"
#include "BulletDefinition.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

class BulletParser {
private:
	const std::string change_speed_name = "changeSpeed";
	const std::string change_direction_name = "changeDirection";
	const std::string wait_name = "wait";
	const std::string vanish_name = "vanish";
	const std::string repeat_name = "repeat";
	const std::string fire_name = "fire";
	tinyxml2::XMLDocument document;

	std::vector<ActionPtr> parse_actions(tinyxml2::XMLElement* root);
	ActionPtr parse_wait(tinyxml2::XMLElement* element_root);
	ActionPtr parse_change_speed(tinyxml2::XMLElement* element_root);
	ActionPtr parse_change_direction(tinyxml2::XMLElement* element_root);
	ActionPtr parse_vanish(tinyxml2::XMLElement* element_root);
	ActionPtr parse_repeat(tinyxml2::XMLElement* element_root);
	ActionPtr parse_fire(tinyxml2::XMLElement* element_root);
	BulletDefinition parse_bullet(tinyxml2::XMLElement* root);
	std::vector<ActionPtr> semantic_analysis(std::vector<ActionPtr>& actions);

public:
	BulletParser(std::string file_name);

	BulletDefinition parse();
};

#endif /* BULLETPARSER_H_ */
