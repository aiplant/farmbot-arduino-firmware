/*
 * G01Handler.cpp
 *
 *  Created on: 15 maj 2014
 *      Author: MattLech
 */

#include "G01Handler.h"

static G01Handler *instance;

G01Handler *G01Handler::getInstance()
{
	if (!instance) {
		instance = new G01Handler();
	};
	return instance;
}
;

G01Handler::G01Handler() {
}

int G01Handler::execute(Command *command) {

	/*Serial.print("G00 was here\r\n");

	Serial.print("R99");
	Serial.print(" X ");
	Serial.print(command->getX());
	Serial.print(" Y ");
	Serial.print(command->getY());
	Serial.print(" Z ");
	Serial.print(command->getZ());
	Serial.print(" A ");
	Serial.print(command->getA());
	Serial.print(" B ");
	Serial.print(command->getB());
	Serial.print(" C ");
	Serial.print(command->getC());
	Serial.print("\r\n");*/


	stepsPerMm[0] = ParameterList::getInstance()->getValue(MOVEMENT_STEP_PER_MM_X);
	stepsPerMm[1] = ParameterList::getInstance()->getValue(MOVEMENT_STEP_PER_MM_Y);
	stepsPerMm[2] = ParameterList::getInstance()->getValue(MOVEMENT_STEP_PER_MM_Z);


	Movement::getInstance()->moveToCoords(
			CurrentState::getInstance()->getX()/stepsPerMm[0] + command->getX(),
			CurrentState::getInstance()->getY()/stepsPerMm[1] + command->getY(),
			CurrentState::getInstance()->getZ()/stepsPerMm[2] + command->getZ(),
			command->getA(), command->getB(), command->getC(), false, false,
			false);

	if (LOGGING) {
		CurrentState::getInstance()->print();
	}
	return 0;
}
