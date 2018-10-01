/* ONLINE ARDUINO WORKSHOP SAMPLE PROJECTS
   This is a sample code for "Shooting the LED Game"
   Written by: Prawira (praw0001@e.ntu.edu.sg) Contact me if you find any errors
   Supported by: Garage@EEE (School of Electrical and Electronics Engineering, Nanyang Technological University)
*/

//define all of the hardware pins
#define LDR1 A0
#define LDR2 A1
#define LDR3 A2
#define LDR4 A3
#define LDR5 A4

#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11
#define LED5 12

#define buzzer 6

//declare all the global variables used in the project
int interval;
int interval_min = 20;
int interval_max = 60;
int led[]={0,LED1, LED2, LED3, LED4, LED5}; //declare led in an array
int ldr[]={0, LDR1, LDR2, LDR3, LDR4, LDR5}; //declare ldr in an array
int score;
int chosen_led;
int threshold;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  threshold = calibrate_LDR(); //call the function calibrate_LDR
  randomSeed(analogRead(0)); //compulsory step to use random function subsequently
}

void loop() {
  // put your main code here, to run repeatedly:
  update_info(); //call the function update_info
  delay(500);
  chosen_led = random(1,6); //call the function choose_led
  digitalWrite(led[chosen_led],HIGH); //activate the chosen led
  interval=random(interval_min, interval_max); //decide on the active timing
  for (int i=0;i<interval;i++){
    int state = check_state(ldr[chosen_led]); //check if ldr is being shot
    if (state==1){
      score++;
      digitalWrite(buzzer,HIGH);
      delay(100);
      digitalWrite(buzzer,LOW);
      state=0;
      break;
    }
    delay(20);
  }
  digitalWrite(led[chosen_led],LOW); //disable the chosen led
}

void update_info() { //function for serial print all the information 
  Serial.print("The score is ");
  Serial.println(score);
  Serial.print("The chosen LED is ");
  Serial.println(chosen_led);
  Serial.print("The threshold is ");
  Serial.println(threshold);
}

int calibrate_LDR () { //function to set a threshold value according to the environment lighting
  int LDR1 = analogRead(LDR1);
  int LDR2 = analogRead(LDR2);
  int LDR3 = analogRead(LDR3);
  int LDR4 = analogRead(LDR4);
  int LDR5 = analogRead(LDR5);
  int average_reading = (LDR1 + LDR2 + LDR3 + LDR4 + LDR5) / 5;
  Serial.print("The average LDR reading is ");
  Serial.println(average_reading);
  int threshold = average_reading * 8 / 7;
  return threshold;
}

int check_state(int pin) { //check a specific led if being shot
  int state;
  int A_something = pin - 14;
  Serial.print("The A");
  Serial.print(A_something);
  Serial.print(" reading is ");
  Serial.print(analogRead(pin));
  if (analogRead(pin) >= threshold) {
    state = 1;
  }
  else {
    state = 0;
  }
  Serial.print(". It's state is ");
  Serial.println(state);
  return state;
}
