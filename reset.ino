void reset(){
  recording=false;
  placedCamera= false;
  placedPanCamera= false;
  placedSledCamera= false;
  readyState= false;
  setState= false;
  panStepper.disableDriver();
  moveStepper.disableDriver();
  Serial.println("reset");

  leftKeyPos =0;
leftPanPos =0;
rightKeyPos =0 ;
rightPanPos =0 ;
 currentPos =0;
currentPan =0;

leftKeySet = false;
rightKeySet = false;
setKeySet = false;
distance= 0;
startState= true;

  
  }
