// Code written by Nikhil. Language- C++
// Science Project
// Topic- Home Automation
// GitHub Repository- 

#include <IRremote.h>

#define code1 0x1FE50AF // Code for 1st Button
#define code2 0x1FED827 // Code for 2nd Button
#define code3 0x1FEF807 // Code for 3rd Button
#define code4 0x1FE30CF // Code for 4th Button
#define code5 0x1FE30CF // Code for 4th Button

int LED1 = 4;    // Pin for 1st Relay/Appliance
int LED2 = 5;   // Pin for 2nd Relay/Appliance
int LED3 = 6;   // Pin for 3rd Relay/Appliance
int LED4 = 7;   // Pin for 4th Relay/Appliance

IRrecv irrecv(11);  // IR Sensor connected to pin 11
decode_results results;

void setup() {
  Serial.begin(9600); // Serial Baud Rate 9600

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(LED1, 1); // Initially turns off all Relay
  digitalWrite(LED2, 1);
  digitalWrite(LED3, 1);
  digitalWrite(LED4, 1);

  irrecv.enableIRIn(); // Enable the IR Reciever
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // Prints the recieved IR HEX Code

    if (results.value == code1) {  // Button for LED1
      digitalWrite(LED1, !digitalRead(LED1));  // Toggle LED1
    }
    else if (results.value == code2) {  // Button for LED2
      digitalWrite(LED2, !digitalRead(LED2));  // Toggle LED2
    }
    else if (results.value == code3) {  // Button for LED3
      digitalWrite(LED3, !digitalRead(LED3));  // Toggle LED3
    }
    else if(results.value == code4) {  // Button for LED4
      digitalWrite(LED4, !digitalRead(LED4));  // Toggle LED4
    }

    else if(results.value == code5) { // Turns off All Relays
      digitalWrite(LED1, 0);
      digitalWrite(LED2, 0);
      digitalWrite(LED3, 0);
      digitalWrite(LED4, 0);
    }

    irrecv.resume();  // receive the next value
  }
}
