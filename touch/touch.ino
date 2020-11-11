#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>

int a;

int touch_1 = 2;
int touch_2 = 3;
int touch_3 = 4;

int flag1 = 0;
int flag2 = 0;
int flag3 = 0;

unsigned long time1 = 0;
unsigned long time2 = 0;
unsigned long time3 = 0;

int time_delay = 700;

void setup() {
  Serial.begin(9600);                       // Открываем последовательный порт для компьютера со скоростью 9600 бод
  randomSeed(analogRead(A0));
  mp3_set_serial (Serial);
  delay(80);
  mp3_set_volume(15);

  pinMode(touch_1, INPUT);
  pinMode(touch_2, INPUT);
  pinMode(touch_3, INPUT);
}

void loop() {
  if(digitalRead(touch_1)==HIGH && flag1==0){     
   
   time1 = millis();
    flag1 = 1;  
  }
  if(digitalRead(touch_1)==LOW && flag1==1){
   
   time1 = millis();
    flag1 = 0;
  }
  if(millis()-time1>time_delay && flag1 == 1){
    a = random(1,21);
    Serial.println(a);
    mp3_play(a);
    time1 = millis();
    
    flag1 = 2;
  }
  if(millis()-time1>15000 && flag1 == 2){
    mp3_stop();
    flag1 = 0;
    
  }

}
