float wheelDiam = 1.20; // in centimeters
float wheelPerimeter = PI*wheelDiam; 
//encoders

// pan encoder measures camera rotate
Encoder panMeasure(panEncoderA, panEncoderB);
float panDegrees =0;
float panAngle =0;
int panEncRes = 256;
int panEncTeeth = 20; // number of teeth on gear wheel


// move encoder measures camera movement along path
Encoder moveMeasure(moveEncoderA, moveEncoderB);
float moveDegrees =0;
float moveAngle =0;
int moveEncRes = 256;
int moveEncTeeth = 28; // number of teeth on gear wheel


//QuadEncoder qe(speedEncoderA,speedEncoderB);
//int qe1Move=0;
Encoder speedMeasure(speedEncoderA,speedEncoderB);
//float moveDegrees =0;
//float moveAngle =0;

//speeed encoder measures the speed along path
//QuadEncoder speedEncoder(speedEncoderA,speedEncoderB);
int speedRate = 2;
int tempSpeed;

// steppers

// pan stepper rotates camera
AMIS30543 panStepper;
const uint8_t panPin = 4;
const uint8_t panSelect = 6;
boolean clockwise =true;
int panStepperCount = 1;
int panCurrentlimit = 300; // in milliamps
//int  panDelay = 200;
float panStep = 1; // number of microsteps per step
long panFinishTime;
int panStepTeeth = 16; // teeth on gear wheel
float panStepAngle = 1.8; // angle in degrees of single step

// move stepper moves camera forward or back 
AMIS30543 moveStepper;
const uint8_t movePin = 8;
const uint8_t moveSelect =10;
boolean left = false;
int moveStepperCount = 1;
int moveCurrentlimit = 300;// in milliamps
long  moveDelay = 800;
float moveStep= 1; // number of microsteps per step
long stepperFinishTime;
int moveStepTeeth = 16; // number of teeth on gear wheel
float moveStepAngle = 0.5; // angle in degrees of single step
long tempDelay;
long tempPanDelay;

// keys
boolean leftKeySet = false;
long leftSetTime;
boolean rightKeySet = false;
long rightSetTime;
boolean setKeySet = false;
long setSetTime;


//
long distance= 0;
boolean readyState = false;
boolean recording = false;
boolean forward= false;
boolean adjustingLeft= false;
boolean adjustingRight = false;
boolean placedCamera = false;
boolean placedPanCamera = false;
boolean placedSledCamera = false;
boolean setState= false;
boolean startState= true;
boolean moveDirection = forward;
float tempPanDist;
int leftKeyPos;
int leftPanPos;
int rightKeyPos;
int rightPanPos;
int currentPos;
int currentPan;
float distCount;
float velocity;
long recordingDuration;
float oldSpeedRate;
float speedCount;
long tempStepage;
long stepage;

// moving left is increases encoder count

