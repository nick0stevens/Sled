void placeCamera() {
  // set the sled to go in correct direction to start
  // work out the mid point of the range
  int midDist = (abs(leftKeyPos) + abs(rightKeyPos)) / 2;
  int midPoint = leftKeyPos - midDist;

  Serial.print("mid point is ");
  Serial.println(midPoint);

  if (currentPos > leftKeyPos) {
    Serial.println("too far left, moving rightward to left key pos");
    moveStepper.setDirection(!left);
    adjustToStart(leftKeyPos);
    Serial.println(!left);
  }

  else if (currentPos < rightKeyPos) {
    Serial.println("too far right, moving leftward to right key pos");
    moveStepper.setDirection(left);
    adjustToStart(rightKeyPos);

  }

  else if (currentPos < midPoint) { // inside but closer to right side
    Serial.println("in between but too far left, moving rightward to right key pos");
    moveStepper.setDirection(!left);
    adjustToStart(rightKeyPos);
  }
  else {
    Serial.println("in between but too far right,moving leftward to left key pos");
    moveStepper.setDirection(left);
    adjustToStart(leftKeyPos);
  }


  // set the Pan to go in correct direction to start
  // work out the mid point of the range
  int midPanDist = (abs(leftPanPos) + abs(rightPanPos)) / 2;
  int midPanPoint = rightPanPos - midPanDist;

  Serial.print("mid Pan point is ");
  Serial.println(midPanPoint);

  if (currentPan > leftPanPos) {
    Serial.println("Pan too far left, moving rightward to left key pos");
    panStepper.setDirection(!left);
    adjustToPanStart(leftPanPos);
    Serial.println(!left);
  }

  else if (currentPan < rightPanPos) {
    Serial.println("Pan too far right, moving leftward to right key pos");
    panStepper.setDirection(left);
    adjustToPanStart(rightPanPos);

  }

  else if (currentPan < midPanPoint) { // inside but closer to right side
    Serial.println("Pan in between but too far left, moving rightward to right key pos");
    panStepper.setDirection(!left);
    adjustToPanStart(rightPanPos);
  }
  else {
    Serial.println("Pan in between but too far right,moving leftward to left key pos");
    panStepper.setDirection(left);
    adjustToPanStart(leftPanPos);
  }


}

void  adjustToStart(int _goal) {
  while (!placedSledCamera) {
    currentPos = moveMeasure.read();

    turnMoveStepper(1000);


    delayMicroseconds(10);

    if (abs(currentPos - _goal) < 2 ) {
      placedSledCamera = true;

      Serial.println(" placed Camera");
    }

  }
}

void  adjustToPanStart(int _goal) {
  while (!placedPanCamera) {
    currentPan = panMeasure.read();

    turnPanStepper(1000);


    delayMicroseconds(10);

    if (abs(currentPan - _goal) < 2 ) {
      placedPanCamera = true;

      Serial.println(" placed Pan Camera");
      Serial.print("dist ");
      Serial.print(calcDist());
      Serial.print(" ");
      Serial.print("calcDelay ");
      Serial.println(calcDelay());
      Serial.print("stepage ");
      Serial.print(stepage);
      Serial.print(" ");
      Serial.print("estDelay ");
      Serial.println(tempDelay);
      Serial.print("left ");
      Serial.print(leftPanPos);
      Serial.print(" ");
      Serial.print("right ");
      Serial.print(rightPanPos);
      Serial.print(" ");
      Serial.print("temp ");
      Serial.print(tempDelay);
      Serial.print(" ");
      Serial.print("pan ");
      Serial.print(panDelay());
      Serial.print(" tempPan ");
      Serial.print(tempPanDelay);
      Serial.print(" tempsteps ");
      Serial.println(tempStepage);
      
    }
    if (placedSledCamera && placedPanCamera) {
      placedCamera = true;
    }
  }
}



void  moveCamera() {
  while (recording) {
    currentPos = moveMeasure.read();
//    Serial.print("currentPos:");
//    Serial.print(currentPos);
    currentPan = panMeasure.read();
//    Serial.print("currentPan:");
//    Serial.println(currentPan);
   //   turnMoveStepper(15000);
    turnMoveStepper(calcDelay());
    turnPanStepper(panDelay());
    delayMicroseconds(10);

    if (moveDirection != forward) {
      if (currentPos > leftKeyPos ) {
        recording = false;
        Serial.println(" finnished on the left");
        reset();
      }
    }
    if (moveDirection == forward) {
      if (currentPos < rightKeyPos ) {
        recording = false;
        Serial.println(" finnished on the right");
        reset();
      }
    }
  }
}

void choseDirection() {
  if (abs(abs(currentPos) - abs(leftKeyPos)) < 30 ) {
    moveStepper.setDirection(!left);
    moveDirection = forward;
    Serial.println("starting on the left");
    //      setMoveDirection(forward);
    //      setPanDirection(forward);
  }
  else {
    moveDirection = !forward;
    moveStepper.setDirection(left);
    Serial.println("starting on the right");
    //           setMoveDirection(!forward);
    //           setPanDirection(!forward);
  }

}


//void setMoveDirection(bool dir)
//{
//  // The NXT/STEP pin must not change for at least 0.5
//  // microseconds before and after changing the DIR pin.
//  delayMicroseconds(1);
//  digitalWrite(moveStepperDIR, dir);
//  delayMicroseconds(1);
//}
//
//
//void setPanDirection(bool dir)
//{
//  // The NXT/STEP pin must not change for at least 0.5
//  // microseconds before and after changing the DIR pin.
//  delayMicroseconds(1);
//  digitalWrite(panStepperDIR, dir);
//  delayMicroseconds(1);
//}
