/*
 * G01HANDLER.h
 *
 *  Created on: 15 maj 2014
 *      Author: MattLech
 */

#ifndef G01HANDLER_H_
#define G01HANDLER_H_
#include "GCodeHandler.h"
#include "Config.h"
#include "CurrentState.h"
#include "pins.h"
#include "Config.h"
#include "Movement.h"

class G01Handler : public GCodeHandler
{
public:
  static G01Handler *getInstance();
  int execute(Command *);

private:
  G01Handler();
  G01Handler(G01Handler const &);
  void operator=(G01Handler const &);
  long adjustStepAmount(long);
  long getNumberOfSteps(double, double);

  long stepsPerMm[3] = { 1.0, 1.0, 1.0 };
};

#endif /* G01HANDLER_H_ */
