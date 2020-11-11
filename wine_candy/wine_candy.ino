#include <RemoteReceiver.h>
#include <Servo.h>


int button_wine = 3;
int button_candy = 4;
int button_gears = 5;

int wine = A0;
int candy = 9;
int gears = A1;


int flag_1 = 0;
int flag_2 = 0;
int flag_3 = 0;

int time_pouring = 5000;   // Час наливання 

unsigned long time1 = 0;
unsigned long time2 = 0;
unsigned long time3 = 0;

Servo servo1;

void setup() {
  Serial.begin(9600);

  servo1.attach(candy);
  
  pinMode(button_wine, INPUT_PULLUP);
  pinMode(button_candy, INPUT_PULLUP);
  pinMode(button_gears, INPUT_PULLUP);
   
  pinMode(wine, OUTPUT); 
  pinMode(candy, OUTPUT); 
  pinMode(gears, OUTPUT); 
  
  digitalWrite(wine, HIGH);
  digitalWrite(gears, HIGH);
  
  
  
  RemoteReceiver::init(0, 1, showCode);
}

void loop() {
   
    
   button();
   
   pourWine();
   rotateGears();
  // giveCandy();
}


void button(){
  if(digitalRead(button_wine)==LOW && flag_1==0){
    flag_1=1;
  }
  if(digitalRead(button_gears)==HIGH && flag_2==0){
    flag_2=1;
  }
  /*
  if(digitalRead(button_candy)==LOW && flag_3==0){
    time3 = millis();
    flag_3=1;
  }
  */
}
void giveCandy(){
  if(millis()-time3<830 && flag_3==1){
    servo1.write(180);    
  }
  if(millis()-time3>830 && flag_3==1){
    servo1.write(90);
    flag_3 = 0;
  }
  
}

void rotateGears(){
  if(flag_2==1){
    digitalWrite(gears, LOW);
    time2 = millis();
    flag_2 = 2;
  }
  if(millis()-time2>10000 && flag_2==2){
    digitalWrite(gears, HIGH);
    flag_2 = 0;
  }
}

void pourWine(){
  
  if(flag_1==1){
    digitalWrite(wine, LOW);
    time1 = millis();
    flag_1 = 2;
  }
  if(millis()-time1>100 && flag_1==2){
    digitalWrite(wine, HIGH);
    time1 = millis();
    flag_1 = 3;
  }
  if(millis()-time1>time_pouring && flag_1==3){
    digitalWrite(wine, LOW);
    time1 = millis();
    flag_1 = 4;
  }
  if((millis()-time1>100) && flag_1==4){
    digitalWrite(wine, HIGH);
    time1 = millis();
    flag_1 = 0;
  }
  
}



void showCode(unsigned long receivedCode, unsigned int period) {
  Serial.println(receivedCode);
   /*             
  Code: 528931,   A
  Code: 528933,   B
  Code: 528939,   C
  Code: 528957,   D
   */
   
  if(receivedCode==528931 && flag_1==0){flag_1=1;}//A
  if(receivedCode==528933 && flag_2==0){flag_2=1;}//B
  //if(receivedCode==528939 && flag_3==0){time3 = millis(); flag_3=1;}//C
  if(receivedCode==528957 ){}//D
}

