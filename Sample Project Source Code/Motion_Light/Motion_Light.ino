/* ONLINE ARDUINO WORKSHOP SAMPLE PROJECTS
   This is a sample code for "Motion Light"
   Written by: Prawira (praw0001@e.ntu.edu.sg) Contact me if you find any errors
   Supported by: Garage@EEE (School of Electrical and Electronics Engineering, Nanyang Technological University)
*/

#include <NewPing.h> //include library called NewPing

//define all of the hardware pins
#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7

#define tail 2
#define led_speed 6 //1-10
int led[]={0,led1, led2, led3, led4, led5, led6}; //declare led in an array

#define MAX_DISTANCE 40
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing ultrasonic1(8, 9, MAX_DISTANCE);
NewPing ultrasonic2(10, 11, MAX_DISTANCE);
NewPing ultrasonic3(12, 13, MAX_DISTANCE);


void setup() {
  // put your setup code here, to run once:
  for (int i=1;i<=6;i++){
    pinMode(led[i],OUTPUT);
  }  
  Serial.begin(9600);
  randomSeed(analogRead(0)); //compulsory step to use random function subsequently
}

void loop() {
  // put your main code here, to run repeatedly:
  if (check_state_ultrasonic_1()==1&&check_state_ultrasonic_2_far ()==0){
    for (int i = 0;i<10;i++){
      delay(10);
      if (check_state_ultrasonic_3()==1){
        swipe_right();
        break;
      }
    }
  }
  if (check_state_ultrasonic_3()==1&&check_state_ultrasonic_2_far ()==0){
    for (int i = 0;i<10;i++){
      delay(10);
      if (check_state_ultrasonic_1()==1){
        swipe_left();
        break;
      }
    }
  }
  
  if ((check_state_ultrasonic_2_far()==1)&&(check_state_ultrasonic_1()==0)&&(check_state_ultrasonic_3()==0)){
    for (int i = 0;i<10;i++){
      delay(10);
      if (check_state_ultrasonic_2_near()==1){
        blast();
        break;
      }
    }
  }
  delay(10);
//  debug();
//  delay(100);
}

int check_state_ultrasonic_1 (){
  int state;
  int temp_distance = ultrasonic1.ping_cm();
  if (temp_distance>=1&&temp_distance<=10){
    state = 1;
  }
  else{
    state = 0;
  }
  return state;
}

int check_state_ultrasonic_2_far (){
  int state;
  int temp_distance = ultrasonic2.ping_cm();
  if ((temp_distance>=5)&&(temp_distance<=20)){
    state = 1;
  }
  else{
    state = 0;
  }
  return state;
}

int check_state_ultrasonic_2_near (){
  int state;
  int temp_distance = ultrasonic2.ping_cm();
  if (temp_distance>=1&&temp_distance<=2){
    state = 1;
  }
  else{
    state = 0;
  }
  return state;
}

int check_state_ultrasonic_3 (){
  int state;
  int temp_distance = ultrasonic3.ping_cm();
  if (temp_distance>=1&&temp_distance<=10){
    state = 1;
  }
  else{
    state = 0;
  }
  return state;
}

void debug(){
  swipe_left();
  delay(200);
  Serial.println(" ------- D E B U G ------- ");
  Serial.print("Distance of ultrasonic 1: ");
  Serial.print(ultrasonic1.ping_cm());
  Serial.println("cm");
  Serial.print("Distance of ultrasonic 2: ");
  Serial.print(ultrasonic2.ping_cm());
  Serial.println("cm");
  Serial.print("Distance of ultrasonic 3: ");
  Serial.print(ultrasonic3.ping_cm());
  Serial.println("cm");
  swipe_right();
  delay(200);
}

void swipe_right(){ //swipe_right led effect
  for (int i=1;i<=6+tail;i++){
    digitalWrite(led[i],HIGH);
    digitalWrite(led[i-tail],LOW);
    delay(500/led_speed);
  }    
}

void swipe_left(){ //swipe_left led effect
  for (int i=6;i>=1-tail;i--){
    digitalWrite(led[i+tail],LOW);    
    if (i>=0){
      digitalWrite(led[i],HIGH);
    }
    delay(500/led_speed);
  }      
}

void blast(){ //blast led effect
  
  digitalWrite(led[3],HIGH);
  digitalWrite(led[4],HIGH);
  delay(500/led_speed);
  digitalWrite(led[2],HIGH);
  digitalWrite(led[5],HIGH);
  delay(500/led_speed);
  digitalWrite(led[1],HIGH);
  digitalWrite(led[6],HIGH);  
  digitalWrite(led[3],LOW);
  digitalWrite(led[4],LOW);
  delay(500/led_speed);
  digitalWrite(led[2],LOW);
  digitalWrite(led[5],LOW);
  delay(500/led_speed);  
  digitalWrite(led[1],LOW);
  digitalWrite(led[6],LOW);  
  delay(500/led_speed); 
  for (int i=1;i<=30;i++){
    digitalWrite(led[random(1,7)],HIGH);
    digitalWrite(led[random(1,7)],LOW);
    delay(500/led_speed);
  }  
  digitalWrite(led[3],LOW);
  digitalWrite(led[4],LOW);
  delay(500/led_speed);
  digitalWrite(led[2],LOW);
  digitalWrite(led[5],LOW);
  delay(500/led_speed);  
  digitalWrite(led[1],LOW);
  digitalWrite(led[6],LOW);  
  delay(500/led_speed);   
}

