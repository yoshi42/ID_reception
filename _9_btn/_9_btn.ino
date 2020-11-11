int button_1 = 2;
int button_2 = 3;
int button_3 = 4;
int button_4 = 5;
int button_5 = 6;
int button_6 = 7;
int button_7 = 8;
int button_8 = 9;
int button_9 = 10;

int led_1 = A4;
int led_2 = A3;
int led_3 = A2;
int led_4 = A1;
int led_5 = A0;
int led_6 = 11;
int led_7 = 12;
int led_8 = 13;
int led_9 = A5;

int flag = 0;
int del = 500;

unsigned long time1 = 0;

void setup() {
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);
  pinMode(button_4, INPUT_PULLUP);
  pinMode(button_5, INPUT_PULLUP);
  pinMode(button_6, INPUT_PULLUP);
  pinMode(button_7, INPUT_PULLUP);
  pinMode(button_8, INPUT_PULLUP);
  pinMode(button_9, INPUT_PULLUP);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);
  pinMode(led_8, OUTPUT);
  pinMode(led_9, OUTPUT);
  ledLow();

}

void loop() {

  if(flag == 0){
    if(digitalRead(button_1)==LOW){digitalWrite(led_1, HIGH);flag = 1;}      //1
      if(digitalRead(button_2)==LOW){blinkOne(led_2);}
      if(digitalRead(button_3)==LOW){blinkOne(led_3);}
      if(digitalRead(button_4)==LOW){blinkOne(led_4);}
      if(digitalRead(button_5)==LOW){blinkOne(led_5);}
      if(digitalRead(button_6)==LOW){blinkOne(led_6);}
      if(digitalRead(button_7)==LOW){blinkOne(led_7);}
      if(digitalRead(button_8)==LOW){blinkOne(led_8);}
      if(digitalRead(button_9)==LOW){blinkOne(led_9);}   
  }
  if(flag == 1){
    if(digitalRead(button_1)==HIGH){time1 = millis(); flag = 2;}
  }
  
  if(flag == 2){
    if(digitalRead(button_4)==LOW){flag = 3;}      //4
      if(digitalRead(button_2)==LOW){blinkOne(led_2);}
      if(digitalRead(button_3)==LOW){blinkOne(led_3);}
      if(digitalRead(button_1)==LOW && millis()-time1>1000){blinkOne(led_1);}
      if(digitalRead(button_5)==LOW){blinkOne(led_5);}
      if(digitalRead(button_6)==LOW){blinkOne(led_6);}
      if(digitalRead(button_7)==LOW){blinkOne(led_7);}
      if(digitalRead(button_8)==LOW){blinkOne(led_8);}
      if(digitalRead(button_9)==LOW){blinkOne(led_9);} 
  }
  if(flag == 3){
    if(digitalRead(button_4)==HIGH){time1 = millis();digitalWrite(led_4, HIGH);flag = 4;}
  }
  
  if(flag == 4){
    if(digitalRead(button_2)==LOW){flag = 5;}      //2
      if(digitalRead(button_1)==LOW){blinkOne(led_1);}
      if(digitalRead(button_3)==LOW){blinkOne(led_3);}
      if(digitalRead(button_4)==LOW && millis()-time1>1000){blinkOne(led_4);}
      if(digitalRead(button_5)==LOW){blinkOne(led_5);}
      if(digitalRead(button_6)==LOW){blinkOne(led_6);}
      if(digitalRead(button_7)==LOW){blinkOne(led_7);}
      if(digitalRead(button_8)==LOW){blinkOne(led_8);}
      if(digitalRead(button_9)==LOW){blinkOne(led_9);} 
  }
  if(flag == 5){
    if(digitalRead(button_2)==HIGH){time1 = millis();digitalWrite(led_2, HIGH);flag = 6;}
  }
  
  if(flag == 6){
    if(digitalRead(button_3)==LOW){flag = 7;}      //3
      if(digitalRead(button_2)==LOW && millis()-time1>1000){blinkOne(led_2);}
      if(digitalRead(button_1)==LOW){blinkOne(led_1);}
      if(digitalRead(button_4)==LOW){blinkOne(led_4);}
      if(digitalRead(button_5)==LOW){blinkOne(led_5);}
      if(digitalRead(button_6)==LOW){blinkOne(led_6);}
      if(digitalRead(button_7)==LOW){blinkOne(led_7);}
      if(digitalRead(button_8)==LOW){blinkOne(led_8);}
      if(digitalRead(button_9)==LOW){blinkOne(led_9);} 
  }
  if(flag == 7){
    if(digitalRead(button_3)==HIGH){time1 = millis();digitalWrite(led_3, HIGH);flag = 8;}
  }
  
  if(flag == 8){
    if(digitalRead(button_6)==LOW){flag = 9;}      //6
      if(digitalRead(button_2)==LOW){blinkOne(led_2);}
      if(digitalRead(button_3)==LOW && millis()-time1>1000){blinkOne(led_3);}
      if(digitalRead(button_4)==LOW){blinkOne(led_4);}
      if(digitalRead(button_5)==LOW){blinkOne(led_5);}
      if(digitalRead(button_1)==LOW){blinkOne(led_1);}
      if(digitalRead(button_7)==LOW){blinkOne(led_7);}
      if(digitalRead(button_8)==LOW){blinkOne(led_8);}
      if(digitalRead(button_9)==LOW){blinkOne(led_9);} 
  }
  if(flag == 9){
    if(digitalRead(button_6)==HIGH){time1 = millis();digitalWrite(led_6, HIGH);flag = 10;}
  }
  
  if(flag == 10){
    if(digitalRead(button_8)==LOW){flag = 11;}      //8
      if(digitalRead(button_2)==LOW){blinkOne(led_2);}
      if(digitalRead(button_3)==LOW){blinkOne(led_3);}
      if(digitalRead(button_4)==LOW){blinkOne(led_4);}
      if(digitalRead(button_5)==LOW){blinkOne(led_5);}
      if(digitalRead(button_6)==LOW && millis()-time1>1000){blinkOne(led_6);}
      if(digitalRead(button_7)==LOW){blinkOne(led_7);}
      if(digitalRead(button_1)==LOW){blinkOne(led_1);}
      if(digitalRead(button_9)==LOW){blinkOne(led_9);} 
  }
  if(flag == 11){
    if(digitalRead(button_8)==HIGH){time1 = millis();digitalWrite(led_8, HIGH);flag = 12;}
  }
  
  if(flag == 12){
    if(digitalRead(button_7)==LOW){flag = 13;}      //7
      if(digitalRead(button_2)==LOW){blinkOne(led_2);}
      if(digitalRead(button_3)==LOW){blinkOne(led_3);}
      if(digitalRead(button_4)==LOW){blinkOne(led_4);}
      if(digitalRead(button_5)==LOW){blinkOne(led_5);}
      if(digitalRead(button_6)==LOW){blinkOne(led_6);}
      if(digitalRead(button_1)==LOW){blinkOne(led_1);}
      if(digitalRead(button_8)==LOW && millis()-time1>1000){blinkOne(led_8);}
      if(digitalRead(button_9)==LOW){blinkOne(led_9);} 
  }
  if(flag == 13){
    if(digitalRead(button_7)==HIGH){time1 = millis();digitalWrite(led_7, HIGH);flag = 14;}
  }
  
  if(flag == 14){
    if(digitalRead(button_5)==LOW){flag = 15;}      //5
      if(digitalRead(button_2)==LOW){blinkOne(led_2);}
      if(digitalRead(button_3)==LOW){blinkOne(led_3);}
      if(digitalRead(button_4)==LOW){blinkOne(led_4);}
      if(digitalRead(button_1)==LOW){blinkOne(led_1);}
      if(digitalRead(button_6)==LOW){blinkOne(led_6);}
      if(digitalRead(button_7)==LOW && millis()-time1>1000){blinkOne(led_7);}
      if(digitalRead(button_8)==LOW){blinkOne(led_8);}
      if(digitalRead(button_9)==LOW){blinkOne(led_9);} 
  }
  if(flag == 15){
    if(digitalRead(button_5)==HIGH){time1 = millis();digitalWrite(led_5, HIGH);flag = 16;}
  }
  
  if(flag == 16){
    if(digitalRead(button_9)==LOW){flag = 17;}      //9
      if(digitalRead(button_2)==LOW){blinkOne(led_2);}
      if(digitalRead(button_3)==LOW){blinkOne(led_3);}
      if(digitalRead(button_4)==LOW){blinkOne(led_4);}
      if(digitalRead(button_5)==LOW && millis()-time1>1000){blinkOne(led_5);}
      if(digitalRead(button_6)==LOW){blinkOne(led_6);}
      if(digitalRead(button_7)==LOW){blinkOne(led_7);}
      if(digitalRead(button_8)==LOW){blinkOne(led_8);}
      if(digitalRead(button_1)==LOW){blinkOne(led_1);} 
  }
  if(flag == 17){
    if(digitalRead(button_9)==HIGH){time1 = millis();digitalWrite(led_9, HIGH);flag = 18;}
  }
  if(flag == 18){
   blinkLed();
  }
  
}

void blinkOne(int a){
  digitalWrite(a, HIGH);
  delay(del);
  digitalWrite(a, LOW);
  delay(del);
  digitalWrite(a, HIGH);
  delay(del);
  digitalWrite(a, LOW);
  delay(del);
  digitalWrite(a, HIGH);
  delay(del);
  digitalWrite(a, LOW);
  delay(del);
  ledLow();
  flag = 0;
  
}

void blinkLed(){
  ledHigh();
  delay(1000);
  ledLow();
  delay(del);
  ledHigh();
  delay(del);
  ledLow();
  delay(del);
  ledHigh();
  delay(del);
  ledLow();
  delay(del);
  ledHigh();
  delay(del);
  ledLow();
  delay(del);
  flag = 0;
}


void ledHigh(){
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_7, HIGH);
  digitalWrite(led_8, HIGH);
  digitalWrite(led_9, HIGH);
}
void ledLow(){
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  digitalWrite(led_9, LOW);
  
}

