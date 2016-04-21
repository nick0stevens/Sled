void checkState() {


  if (leftKeySet && rightKeySet && startState) {
    readyState = true;
    startState = false;
    Serial.println("ready record, hit set to proceed");
    distCount = abs(leftKeyPos - rightKeyPos);
    Serial.print("dist =");
    Serial.println(distCount);
  }
  if (!leftKeySet || !rightKeySet) {
    readyState = false;
  }

  if ( leftKeySet) {
    if (!readyState) {
      distCount = abs(currentPos - leftKeyPos);
    }
  }

  if ( rightKeySet) {
    if (!readyState) {
      distCount = abs(currentPos - rightKeyPos);
    }
  }




  if (readyState) {
    if (setKeySet) {
      setState = true;
      Serial.println("set is set");
      readyState = false;
      setKeySet = false;
    }
  }
  if (setState) {
    if (!placedCamera) {
      panStepper.enableDriver();
      moveStepper.enableDriver();
      placeCamera();

    }
    if (setKeySet) {
      Serial.println("recording is set");
      recording = true;
      setKeySet = false;
      setState = false;
      readyState = false;
    }
  }





  if (recording) {
    choseDirection();
    moveCamera();
    Serial.println(currentPos);
    if (setKeySet) {
      reset();
    }

  }




}
