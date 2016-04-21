const int panStepperNXT = 4; //Changes on this input move the motor current one step up or down in the translator table (even when the motor is disabled).
const int panStepperDIR = 5; //Input that determines the direction of rotation. The direction can also be controlled through the SPI interface.
const int panStepperCS = 6;
const int panStepperERR = 7; //Error output. This pin drives low to indicate that an error condition has occurred. The specific error can be determined by using the SPI interface to check the error flags

const int moveStepperNXT = 8;//Changes on this input move the motor current one step up or down in the translator table (even when the motor is disabled).
const int moveStepperDIR = 9;//Input that determines the direction of rotation. The direction can also be controlled through the SPI interface.
const int moveStepperCS = 10;
const int moveStepperERR = 11;//Error output. This pin drives low to indicate that an error condition has occurred. The specific error can be determined by using the SPI interface to check the error flags


const int moveEncoderA = 2; // interrupt 0
const int moveEncoderB = 3; // interrupt 1

const int panEncoderA = 19; //interrupt 5
const int panEncoderB = 18; //interrupt 4

const int speedEncoderA = 16; // normal digital pin
const int speedEncoderB = 17; // normal digital pin

const int leftButtonPin = 13;
const int rightButtonPin = 12;
const int setButtonPin = 14;


//2, 3, 18, 19, 20, 21
