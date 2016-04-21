
#include <SPI.h>
// stepper driver library
#include <AMIS30543.h>
// motor encoder library
#include <Encoder.h>
// speed encoder library
#include <QuadEncoder.h>
// screen libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "shieldPins.h"
#include  "variables.h"


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif



void setup() {
  Serial.begin(9600);
 //initialize display

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

display.setTextSize(1);
display.setTextColor(WHITE);
//  display.display();
  delay(2000);

 // Clear the buffer.
  display.clearDisplay();

  // miniature bitmap display
  display.clearDisplay();
  display.drawBitmap(30, 16,  logo16_glcd_bmp, 16, 16, 1);
  display.display();
  delay(2000);
  display.clearDisplay();
  Serial.println("yup");
  SPI.begin();
  panStepper.init(panStepperCS);
  moveStepper.init(moveStepperCS);

  // Drive the NXT/STEP  pins low initially.
  digitalWrite(panStepperNXT, LOW);
  digitalWrite(moveStepperNXT, LOW);
  pinMode(panStepperNXT, OUTPUT);
  pinMode(moveStepperNXT, OUTPUT);

    // Drive the DIR pins low initially.
  digitalWrite(panStepperDIR, LOW);
  digitalWrite(moveStepperDIR, LOW);
  pinMode(panStepperDIR, OUTPUT);
  pinMode(moveStepperDIR, OUTPUT);

  // Give the driver some time to power up.
  delay(1);

  // Reset the driver to its default settings.
  panStepper.resetSettings();
  moveStepper.resetSettings();

  panStepper.setCurrentMilliamps(panCurrentlimit);
  moveStepper.setCurrentMilliamps(moveCurrentlimit);

  // Set the number of microsteps that correspond to one full step.
  panStepper.setStepMode(panStep);
  moveStepper.setStepMode(moveStep);
  
  // Enable the motor outputs.
 // panStepper.enableDriver();
 // moveStepper.enableDriver();

  

}

void loop() {
currentPos= moveMeasure.read();
currentPan = panMeasure.read();
checkKeys();
checkSpeedAndTime();
checkState();
drawToScreen();
   
 //testSteppers();
}



