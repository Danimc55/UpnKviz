#include <LiquidCrystal.h>

LiquidCrystal lcd(1,2,4,5,6,7);
int button1=8;
int button2=9;
int button3=10;
int button4=11;
int led1=12;
int led2=13;
int led3=3;
String vrstniRed ="";
boolean button1State=false;
boolean button2State=false;
boolean button3State=false;
boolean button4State=false;
boolean allButtonsPressed=false;
int ATimer=0;
int BTimer=0;
int CTimer=0;

void setup() {
  lcd.begin(16,2);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

}

void loop() {
  lcd.setCursor(2,0);
  if(digitalRead(button1)==true){
    button1State=true;
   if(ATimer==0){
       vrstniRed+="A";
       ATimer+=1;
    }

  }
  if(digitalRead(button2)==true){
    button2State=true;
    if(BTimer==0){
       vrstniRed+="B";
       BTimer+=1;
    }
  }
  if(digitalRead(button3)==true){
    button3State=true;
    if(CTimer==0){
       vrstniRed+="C";
       CTimer+=1;
    }
  }
  if(digitalRead(button4)==true){
    button4State=true;
  }
  if(button1State==false && button2State==false && button3State==false){
    digitalWrite(led1,1);
  }
  if(button1State==true || button2State==true || button3State==true){
    if(allButtonsPressed==false){
      digitalWrite(led1,0);
      digitalWrite(led2,1);
    }
  }
  if(button1State==true && button2State==true && button3State==true){
    allButtonsPressed=true;
  }
  if(allButtonsPressed==true){
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,1);
    delay(500);
    digitalWrite(led3,0);
    delay(500);
    String test = "1:" + String(vrstniRed.charAt(0)) + " 2:" + String(vrstniRed.charAt(1)) + " 3:" + String(vrstniRed.charAt(2));
    lcd.print(test);
    lcd.setCursor(2,1);
    lcd.print("Winner: "+String(vrstniRed.charAt(0)));
  }
  if(digitalRead(button4)==true){
    button1State=false;
    button2State=false;
    button3State=false;
    button4State=false;
    allButtonsPressed=false;
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    vrstniRed="";
    lcd.clear();
    ATimer=0;
    BTimer=0;
    CTimer=0;
  }
}
