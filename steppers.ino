   void turnMoveStepper(long _delay)
{
  if(micros()>stepperFinishTime + _delay){
  // The NXT/STEP minimum high pulse width is 2 microseconds.
  digitalWrite(moveStepperNXT, HIGH);
  delayMicroseconds(3);
  digitalWrite(moveStepperNXT, LOW);
  delayMicroseconds(3);

  // The delay here controls the stepper motor's speed.  You can
  // increase the delay to make the stepper motor go slower.  If
  // you decrease the delay, the stepper motor will go fast, but
  // there is a limit to how fast it can go before it starts
  // missing steps.
 stepperFinishTime= micros();
  }
}


void turnPanStepper(long _panDelay)
{
    if(micros()>panFinishTime + _panDelay){
  // The NXT/STEP minimum high pulse width is 2 microseconds.
  digitalWrite(panStepperNXT, HIGH);
  delayMicroseconds(3);
  digitalWrite(panStepperNXT, LOW);
  delayMicroseconds(3);

  // The delay here controls the stepper motor's speed.  You can
  // increase the delay to make the stepper motor go slower.  If
  // you decrease the delay, the stepper motor will go fast, but
  // there is a limit to how fast it can go before it starts
  // missing steps.
 panFinishTime= micros();
    }
}

//void setDirection(bool dir)
//{
//  // The NXT/STEP pin must not change for at least 0.5
//  // microseconds before and after changing the DIR pin.
//  delayMicroseconds(1);
//  digitalWrite(amisDirPin, dir);
//  delayMicroseconds(1);
//}
