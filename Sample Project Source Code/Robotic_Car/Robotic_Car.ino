/* ONLINE ARDUINO WORKSHOP SAMPLE PROJECTS
 * This is a sample code for "Robotic Car"
 * Written by: Prawira (praw0001@e.ntu.edu.sg) Contact me if you find any errors
 * Supported by: Garage@EEE (School of Electrical and Electronics Engineering, Nanyang Technological University)
 */

#include <NewPing.h> //include the library called NewPing

//LED pin
#define red_led 8
#define green_led 9

//Ultrasonic pins
#define TRIGGER_PIN  10
#define ECHO_PIN     11
#define MAX_DISTANCE 50
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//Motor pins
#define E1 12  // Enable Pin for motor 1 (LEFT)
#define E2 13  // Enable Pin for motor 2 (RIGHT)

#define I1 3  // Control pin 1 for motor 1 (LEFT)
#define I2 4  // Control pin 2 for motor 1 (LEFT)
#define I3 6  // Control pin 1 for motor 2 (RIGHT)
#define I4 7  // Control pin 2 for motor 2 (RIGHT)

void setup() {
  // put your setup code here, to run once:
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);

  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  const int type=1;

  //type 0: troubleshooting for the car
  if(type==0){
    check_distance();
    digitalWrite(red_led,HIGH);
    move_forward(300);
    delay(100);
  }
  
  //type 1: move when distance less than 10 cm
  if (type==1){
    digitalWrite(red_led,HIGH);
    int distance = check_distance();
    if (distance<=20&&distance>=1){
      digitalWrite(red_led,LOW);
      digitalWrite(green_led, HIGH);
      immediate_move_forward();
    }
    else {
      digitalWrite(red_led,HIGH);
      digitalWrite(green_led, LOW);
      move_stop();
    }
  }
  delay(1);
  
}

int check_distance() {
  Serial.print("Distance: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
  return sonar.ping_cm();
}
void immediate_move_forward () {
  digitalWrite(E1, HIGH);
  digitalWrite(E2, HIGH);

  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);

  delay(20);
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}

void move_backwards (int delayval) {
  digitalWrite(E1, HIGH);
  digitalWrite(E2, HIGH);

  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
  delay(delayval);
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}

void move_forward (int delayval) {
  digitalWrite(E1, HIGH);
  digitalWrite(E2, HIGH);

  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);

  delay(delayval);
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}

void move_stop () {
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}

void move_turnleft (int delayval) {
  digitalWrite(E1, HIGH);
  digitalWrite(E2, HIGH);

  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);

  delay(delayval);
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}

void move_turnright (int delayval) {
  digitalWrite(E1, HIGH);
  digitalWrite(E2, HIGH);

  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);

  delay(delayval);

  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}
