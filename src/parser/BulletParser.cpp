/*
 * BulletParser.cpp
 *
 *  Created on: 05/08/2014
 *      Author: vitor
 */

#include "BulletParser.h"

BulletParser::BulletParser(std::string file_name) {
	document.LoadFile(file_name.c_str());
}

ActionPtr BulletParser::parse_wait(tinyxml2::XMLElement* element_root) {
	auto expression = std::string(element_root->GetText());
	return ActionPtr(new ActionWait(Expression(expression)));
}

ActionPtr BulletParser::parse_vanish(tinyxml2::XMLElement* element_root) {
	return ActionPtr(new ActionVanish());
}

ActionPtr BulletParser::parse_repeat(tinyxml2::XMLElement* element_root) {
	int times;

	element_root->FirstChildElement("times")->QueryIntText(&times);
	auto actions = parse_actions(element_root->FirstChildElement("actions"));

	return ActionPtr(new ActionRepeat(actions, times));
}

ActionPtr BulletParser::parse_change_direction(
		tinyxml2::XMLElement* element_root) {
	auto direction = std::string(
			element_root->FirstChildElement("direction")->GetText());
	auto direction_type = std::string(element_root->FirstAttribute()->Value());

	Direction::DirectionType direction_type_enum;
	if (direction_type == "absolute") {
		direction_type_enum = Direction::ABSOLUTE;
	} else if (direction_type == "relative") {
		direction_type_enum = Direction::RELATIVE;
	} else if (direction_type == "aim") {
		direction_type_enum = Direction::AIM;
	} else {
		fprintf(stderr, "Unrecognized direction type %s\n",
				direction_type.c_str());
		exit(1);
	}

	auto time = std::string(element_root->FirstChildElement("time")->GetText());
	return ActionPtr(
			new ActionChangeDirection(Direction(Expression(direction), direction_type_enum), Expression(time)));
}

ActionPtr BulletParser::parse_change_speed(tinyxml2::XMLElement* element_root) {
	auto type = std::string(element_root->FirstAttribute()->Value());
	ActionChangeSpeed::ChangeSpeedType change_type;

	if (type == "absolute") {
		change_type = ActionChangeSpeed::ABSOLUTE;
	} else if (type == "relative") {
		change_type = ActionChangeSpeed::RELATIVE;
	} else {
		fprintf(stderr, "Unrecognized changeSpeed type %s\n", type.c_str());
		exit(1);
	}

	auto speed = std::string(
			element_root->FirstChildElement("speed")->GetText());
	auto time = std::string(element_root->FirstChildElement("time")->GetText());

	return ActionPtr(
			new ActionChangeSpeed(Expression(speed), Expression(time),
					change_type));
}

ActionPtr BulletParser::parse_fire(tinyxml2::XMLElement* root) {
	auto direction_element = root->FirstChildElement("direction");
	auto direction_expression = std::string(direction_element->GetText());
	auto direction_type = std::string(
			direction_element->FirstAttribute()->Value());

	auto speed_expression = std::string(
			root->FirstChildElement("speed")->GetText());

	Direction::DirectionType direction_type_enum;
	if (direction_type == "absolute") {
		direction_type_enum = Direction::ABSOLUTE;
	} else if (direction_type == "relative") {
		direction_type_enum = Direction::RELATIVE;
	} else if (direction_type == "aim") {
		direction_type_enum = Direction::AIM;
	} else {
		fprintf(stderr, "Unrecognized direction type %s\n",
				direction_type.c_str());
		exit(1);
	}

	BulletDefinition bullet_description;
	tinyxml2::XMLElement* bullet_element;
	if ((bullet_element = root->FirstChildElement("bulletRef")) != nullptr) {
		auto file_name = std::string(bullet_element->GetText());
		BulletParser parser(file_name);
		bullet_description = parser.parse();
	} else if ((bullet_element = root->FirstChildElement("bullet"))
			!= nullptr) {
		bullet_description = parse_bullet(bullet_element);
	} else {
		fprintf(stderr, "Bullet descriptor not found in fire action\n");
		exit(1);
	}

	return ActionPtr(
			new ActionFire(Direction(Expression(direction_expression),
					direction_type_enum), Expression(speed_expression),
					bullet_description));
}

std::vector<ActionPtr> BulletParser::parse_actions(tinyxml2::XMLElement* root) {
	std::vector<ActionPtr> actions;
	for (auto child = root->FirstChildElement(); child != nullptr;
			child = child->NextSiblingElement()) {
		if (wait_name == child->Name()) {
			actions.push_back(parse_wait(child));
		} else if (vanish_name == child->Name()) {
			actions.push_back(parse_vanish(child));
		} else if (fire_name == child->Name()) {
			actions.push_back(parse_fire(child));
		} else if (change_speed_name == child->Name()) {
			actions.push_back(parse_change_speed(child));
		} else if (change_direction_name == child->Name()) {
			actions.push_back(parse_change_direction(child));
		} else if (repeat_name == child->Name()) {
			actions.push_back(parse_repeat(child));
		} else {
			fprintf(stderr, "Unrecognized XML element with name %s\n",
					child->Name());
			exit(1);
		}
	}
	return actions;
}

BulletDefinition BulletParser::parse_bullet(tinyxml2::XMLElement* root) {
	BulletDefinition return_value;

	auto sprite = root->FirstChildElement("sprite");
	return_value.sprite_file_name = std::string(sprite->GetText());
	return_value.actions = parse_actions(root->FirstChildElement("actions"));

	return return_value;
}

BulletDefinition BulletParser::parse() {
	return parse_bullet(document.FirstChildElement());
}
