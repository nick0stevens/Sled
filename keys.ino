void checkKeys() {

  //check left key
  if (digitalRead(leftButtonPin) == HIGH && millis()> leftSetTime+250){
    leftSetTime= millis();
    if (leftKeySet) {
      //setState = false;
    }
    else {
      leftKeySet = true;
      leftKeyPos = moveMeasure.read();
      leftPanPos = panMeasure.read();
      Serial.print("left key Pos:");
      Serial.println(leftKeyPos);
      Serial.print("left Pan Pos:");
      Serial.println(leftPanPos);
    }
  }

  //check right key
  if (digitalRead(rightButtonPin) == HIGH  && millis()> rightSetTime+250){
    rightSetTime= millis();
    if (rightKeySet) {
   //   setState = false;
    }
    else {
      rightKeySet = true;
      rightKeyPos = moveMeasure.read();
      rightPanPos = panMeasure.read();
      Serial.print("right key Pos:");
      Serial.println(rightKeyPos);
      Serial.print("right Pan Pos:");
      Serial.println(rightPanPos);
    }
  }

  //check set key
  if (digitalRead(setButtonPin) == HIGH  && millis()> setSetTime+250){
    setSetTime= millis();
 
     setKeySet = true;
   
      
    
  }


}
