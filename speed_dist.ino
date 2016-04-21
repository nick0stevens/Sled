
long calcDelay (){
 // total recording time in microsecconds /the total amount of steps need to cover distance (distCount * 400/256) *the ratio od teeth
 //distCount = abs(leftKeyPos - rightKeyPos);
 long tempSteps = distCount/(4.0*moveEncRes)*moveEncTeeth/moveStepTeeth*(360L/(moveStepAngle*moveStep));
long temp = (recordingDuration*1000.0*1000.0)/tempSteps;

 stepage = tempSteps; 
// Serial.println("delay: ");
// Serial.println(temp);
tempDelay = temp;
if (temp<950){temp = 950L;}
 return temp;
  }

float calcDist(){
  
  // take the distCount from the encoder convert to total revolutions on moveStepper and multiple by wheel perimeter * the ratio of teeth
  return distCount/(4*moveEncRes)/moveStepTeeth*moveEncTeeth*wheelPerimeter;
  //return distCount/(360.0/(moveStepAngle*moveStep))*wheelPerimeter;
        }


long panDelay(){
  tempPanDist = abs(abs(leftPanPos)-abs(rightPanPos));
  long tempSteps = tempPanDist/(4.0*panEncRes)*panEncTeeth/panStepTeeth*(360L/(panStepAngle*panStep));
  tempStepage = tempSteps;
 //long tempSteps =(panEncTeeth/panStepTeeth*(360L/(moveStepAngle*moveStep))/panEncRes)*tempPanDist;
  long temp = (recordingDuration*1000*1000)/tempSteps;
  tempPanDelay = temp;
  if (temp<950){temp = 950L;}
   return temp;
  }

void checkSpeedAndTime(){
  //3617

 speedRate= speedMeasure.read();
//  qe1Move=qe.tick();

//  if (qe1Move=='>')
//    speedCount=speedCount+0.25;
//  else if (qe1Move=='<')
//  speedCount=speedCount-0.25;
  
  if(speedRate>oldSpeedRate){
    speedCount=speedCount+0.25;}
     else if(speedRate<oldSpeedRate){
    speedCount=speedCount-0.25;}
    oldSpeedRate=speedRate;
    
    speedCount= constrain(speedCount,0.25,5);

  velocity = speedCount;
recordingDuration = calcDist()/velocity;

  }
