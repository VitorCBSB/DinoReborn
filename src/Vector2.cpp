/*
 * Vector2.cpp
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#include "Vector2.h"

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2::~Vector2() {
}

Vector2 Vector2::operator +(Vector2 other) {
	return Vector2(this->x + other.x, this->y + other.y);
}

void Vector2::operator +=(Vector2 other) {
	this->x = this->x + other.x;
	this->y = this->y + other.y;
}

Vector2 Vector2::operator -(Vector2 other) {
	return Vector2(this->x - other.x, this->y - other.y);
}

void Vector2::operator -=(Vector2 other) {
	this->x = this->x - other.x;
	this->y = this->y - other.y;
}

Vector2 Vector2::operator *(float scalar) {
	return Vector2(this->x * scalar, this->y * scalar);
}

void Vector2::operator *=(float scalar) {
	this->x = this->x * scalar;
	this->y = this->y * scalar;
}

float Vector2::operator *(Vector2 other) {
	return this->x * other.x + this->y * other.y;
}

float Vector2::length() {
	return sqrt(this->x * this->x + this->y * this->y);
}

/*
 * Angle from -180 to 180, inclusive
 */
float Vector2::angle() {
	return ((180.0 / M_PI) * atan2(y, x));
}

float Vector2::angle(Vector2 other) {
	auto dot = *this * other;
	dot /= (this->length() * other.length());
	auto angle = (180.0 / M_PI) * acos(dot);
	return angle;
}

Vector2 Vector2::normalize() {
	float vecLength = length();
	if (vecLength == 0.0) {
		throw std::logic_error("Attempted to normalize zero vector.\n");
	}
	return Vector2(this->x / vecLength, this->y / vecLength);
}

Vector2 Vector2::rotate(float angleInDegrees) {
	float angleInRadians = angleInDegrees * M_PI / 180;

	return Vector2(
			this->x * cos(angleInRadians) - this->y * sin(angleInRadians),
			this->x * sin(angleInRadians) + this->y * cos(angleInRadians));
}

Vector2 Vector2::normal_vector() {
	return rotate(90);
}

float Vector2::distance(Vector2 other) {
	float diffx = this->x - other.x;
	float diffy = this->y - other.y;
	return sqrt((diffx * diffx) + (diffy * diffy));
}
