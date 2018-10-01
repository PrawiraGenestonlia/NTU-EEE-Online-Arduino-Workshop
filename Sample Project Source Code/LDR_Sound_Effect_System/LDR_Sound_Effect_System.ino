/* ONLINE ARDUINO WORKSHOP SAMPLE PROJECTS
   This is a sample code for "LDR Sound Effect System"
   Written by: Prawira (praw0001@e.ntu.edu.sg) Contact me if you find any errors
   Supported by: Garage@EEE (School of Electrical and Electronics Engineering, Nanyang Technological University)
*/

//define all of the hardware pins
#define LDR1 A0
#define LDR2 A1
#define LDR3 A2
#define LDR4 A3
#define LDR5 A4
#define LDR6 A5
#define speaker 9

//declare all the global variables used in the project
int threshold;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(speaker,OUTPUT);
  threshold = calibrate_LDR(); //call the function calibrate_LDR
}

void loop() {
  // put your main code here, to run repeatedly:
  //check if the respective ldr is being shot then play a sound accodingly
  if (check_state(LDR1) == 1) {
    tone(speaker, 400,150);
    
  }
  if (check_state(LDR2) == 1) {
    tone(speaker, 800, 150);
  }
  if (check_state(LDR3) == 1) {
    tone(speaker, 1200, 150);
  }
  if (check_state(LDR4) == 1) {
    tone(speaker, 1600, 150);
  }
  if (check_state(LDR5) == 1) {
    tone(speaker, 1800, 150);
  }
  if (check_state(LDR6) == 1) {
    tone(speaker, 2000, 150);
  }
  delay(10);
  digitalWrite(speaker,LOW);
}

void debug() {
  Serial.println(" ---- D E B U G ---- ");
  Serial.println(analogRead(LDR1));
  Serial.println(analogRead(LDR2));
  Serial.println(analogRead(LDR3));
  Serial.println(analogRead(LDR4));
  Serial.println(analogRead(LDR5));
  Serial.println(analogRead(LDR6));
  Serial.println("");

}

int calibrate_LDR () { //function to set a threshold value according to the environment lighting
  int LDR1 = analogRead(LDR1);
  int LDR2 = analogRead(LDR2);
  int LDR3 = analogRead(LDR3);
  int LDR4 = analogRead(LDR4);
  int LDR5 = analogRead(LDR5);
  int LDR6 = analogRead(LDR6);
  int average_reading = (LDR1 + LDR2 + LDR3 + LDR4 + LDR5 + LDR6) / 6;
  Serial.print("The average LDR reading is ");
  Serial.println(average_reading);
  int threshold = average_reading * 2 / 3;
  return threshold;
}

int check_state(int pin) { //check a specific led if being shot
  int state;
  int A_something = pin - 14;
  Serial.print("The A");
  Serial.print(A_something);
  Serial.print(" reading is ");
  Serial.print(analogRead(pin));
  if (analogRead(pin) <= threshold) {
    state = 1;
  }
  else {
    state = 0;
  }
  Serial.print(". It's state is ");
  Serial.println(state);
  return state;
}


