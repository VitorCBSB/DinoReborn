/*
 * BaseIdGenerator.h
 *
 *  Created on: 17/07/2014
 *      Author: vitor
 */

#ifndef BASEIDGENERATOR_H_
#define BASEIDGENERATOR_H_

template<typename Base>
class BaseIdGenerator {
private:
	static int next_id;
public:
	template<typename T>
	int id() {
		static int id = next_id++;
		return id;
	}
};

template<typename Base>
int BaseIdGenerator<Base>::next_id = 0;

#endif /* BASEIDGENERATOR_H_ */
