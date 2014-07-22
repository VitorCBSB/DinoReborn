/*
 * Vector2.h
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <math.h>

class Vector2 {
public:
	float x, y;
	Vector2(float x = 0, float y = 0);
	virtual ~Vector2();

	Vector2 operator+(Vector2 other);
	void operator+=(Vector2 other);
	Vector2 operator-(Vector2 other);
	void operator-=(Vector2 other);
	Vector2 operator*(float scalar);
	void operator*=(float scalar);
	float operator*(Vector2 other);
	float length();
	float distance(Vector2 other);
	Vector2 normalize();
	Vector2 rotate(float angleInDegrees);
	Vector2 normal_vector();
};

#endif /* VECTOR2_H_ */
