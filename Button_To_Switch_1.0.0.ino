// Created By: Jmere36
// Purpose: To turn a button into a switch and turn on a light (light can be removed for other output)
// Instead of turning on when button is realeased it turns on when button is pressed
// Removes the flicker of holding the button as well
// This can add many functionalities to your build like, pressing the button to turn on a speaker system, then pressing again to turn it off
// You can also monitor what state the button is in on your pc, through the serial monitor
// If there's any issues or questions please contact my email at: jmere36@icloud.com


// Light is connected to pin 9
// Button or sensor is connected to pin 8

// Change Log:
// Created 1.0.0 with improved serial monitor and removed flickering of light

const int button = 8;
  // Adds the button or sensor for changing the state of the light
const int light = 9;
  //Adds the light or led to turn on or off
int in = 0;
  // The input int used by the button
int prev = "OFF";
  // Used to set the next state of the light
int prevprev = 0;
  // Used so that the 'if' loops do not conflict each other
int milli = 0;
  // Used to see how long it has been since last button press
int prevmilli = 0;
  // Used to set the milli int to the time of last button press
void setup() {
Serial.begin(9600);
  // Turns on serial communication
pinMode(button, INPUT);
pinMode(light, OUTPUT);
  // Sets the pins to the correct modes
}

void loop() {
in = digitalRead(button);

 // Reads the value of the button
if (in == HIGH) {
    // If the button is pressed
    milli = milli - prevmilli;
      // Set milli to the last time the button has been pressed
   prevmilli = millis();
      // Set prevmilli to the current millis time

if (milli > 1) {
    // If the last time button has been pressed is greater than 1 proceed
   // Can be changed to ignore a sensor for a period of time
  // E.g set a shock sensor to 100-200 because it can send a signal multiple times 
  if (prev == "ON") {
     // If prev is set to on continue
     prev = 0;
      // Set prev to 0 so it does not conflict with later 'if' statements   
     prevprev = 1;
       // Set prevprev to 1 for later use
     digitalWrite(light, LOW);
       // Set the light to high/on
    }
  if (prev == "OFF") {
     // If prev is set to off continue
     prev = "ON";
      // Set prev to on
     digitalWrite(light, HIGH);
       // Set the light to low/off
    }
  }
}
milli = millis();
  // Set milli to millis to count how long the last press has been
if (prevprev == 1) {
  // If prevprev is equal to 1 continue
  // This is used to change the state of prev without messing up the 'if' statements
  prevprev = 0;
    // Set prevprev to 0
  prev = "OFF";
    // Set prev to off
}
if (prev == "OFF") {
  // If prev is set to off continue
  digitalWrite(light, LOW);
    // Set light to low/off
    Serial.println("STATE: OFF");
      // Print to serial communicaion saying the led is in the off state
}
if (prev == "ON") {
  digitalWrite(light, HIGH);
    // Set light to high/on
    Serial.println("STATE: ON");
    // Print to serial communicaion saying the led is in the on state
}
}
