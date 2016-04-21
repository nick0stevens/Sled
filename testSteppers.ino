void testSteppers(){
  
    // Step in the default direction 1000 times.
  panStepper.setDirection(0);
   moveStepper.setDirection(0);
  for (unsigned int x = 0; x < 800; x++)
  {
    step();
  }

  // Wait for 300 ms.
currentPos= moveMeasure.read();
currentPan = panMeasure.read();
Serial.print("Stepper Count:");
Serial.println(currentPos);
Serial.print("Pan Count:");
Serial.println(currentPan);
  delay(3000);

  // Step in the other direction 1000 times.
  panStepper.setDirection(1);
   moveStepper.setDirection(1);
  for (unsigned int x = 0; x < 800; x++)
  {
    step();
  }

  // Wait for 300 ms.
  delay(3000);
 currentPos= moveMeasure.read();
currentPan = panMeasure.read();
Serial.print("Stepper Count:");
Serial.println(currentPos);
Serial.print("Pan Count:");
Serial.println(currentPan);
  
  
  
  
  }

  void step()
{
  // The NXT/STEP minimum high pulse width is 2 microseconds.
  digitalWrite(moveStepperNXT, HIGH);
  digitalWrite(panStepperNXT, HIGH);
  delayMicroseconds(3);
  digitalWrite(moveStepperNXT, LOW);
  digitalWrite(panStepperNXT, LOW);
  delayMicroseconds(3);

  // The delay here controls the stepper motor's speed.  You can
  // increase the delay to make the stepper motor go slower.  If
  // you decrease the delay, the stepper motor will go fast, but
  // there is a limit to how fast it can go before it starts
  // missing steps.
  delayMicroseconds(3000); //950 is lowest they can smooth go
}

// Writes a high or low value to the direction pin to specify
// what direction to turn the motor.

