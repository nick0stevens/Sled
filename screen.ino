void drawToScreen() {

  display.clearDisplay();

  if (leftKeySet) {
    display.setCursor(0, 0);
    display.println("I");
  }
  else {
    display.setCursor(0, 0);
    display.println("<");
  }

  if (rightKeySet) {
    display.setCursor(118, 0);
    display.println("I");
  }

  else {
    display.setCursor(118, 0);
    display.println(">");
  }

  if (setKeySet) {
    display.setCursor(59, 0);
    display.println("I");
  }
  else {
    display.setCursor(59, 0);
    display.println("=");
  }

  
//write pos
    display.setCursor(15, 10);
    display.println(leftKeyPos);

    display.setCursor(50, 10);
    display.println(currentPos);
  
    display.setCursor(90, 10);
    display.println(rightKeyPos);

  // write dist

    display.setCursor(0, 20);
    display.print("dist:");
    display.print(calcDist());
    display.print("cm");

  // write speed

    display.print(" spd:");
    display.print(velocity);
    display.println("cm.s");

    // write time
      display.setCursor(0, 30);
    display.print("time: ");
    display.print(recordingDuration);
    display.print(" sec");
    

// going forward or back
//    display.setCursor(70, 30);
//    display.print("forward: ");
//    display.print(forward);

    
    // write state
      display.setCursor(0, 40);
    display.print("ready: ");
    display.print(readyState);

        // write  rec state
    display.setCursor(0, 50);
    display.print("rec: ");
    display.println(recording);
    
display.display();

}
