#include <LiquidCrystal.h>

LiquidCrystal lcd(1,2,4,5,6,7); //nastavimo vse spremenljivke za lcd, gumbe, led diode in nekatere druge spremenljivke, ki preverjajo kdo je prvi pritisnil gumb in kateri gumb je bil pritisnjen.
int button1=8; // spremenljivke za gumbe
int button2=9;
int button3=10;
int button4=11;
int led1=12; // spremenljivke za led diode
int led2=13;
int led3=3;
String vrstniRed =""; // spremenljivka za beleženje vrstenga reda pritiskov
boolean button1State=false; // spremenljivke za preverjanje pritiskov gumbov
boolean button2State=false;
boolean button3State=false;
boolean button4State=false;
boolean allButtonsPressed=false; // spremenljivka, ki se uporablja za preverjanje pritiska vseh gumbov
int ATimer=0; // spremenljivke, ki omejijo pritisk gumbov na enkrat na igro
int BTimer=0;
int CTimer=0;

void setup() {
  lcd.begin(16,2); // inicializiramo lcd, gumbe in led diode
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

}

void loop() {
  lcd.setCursor(2,0); // nastavimo mesto lcd-ja
  if(digitalRead(button1)==true){ // preveri ali je bil pristisnjen prvi gumb. Če je bil nastavimo da je bil pritisnjenj in ga doda v vrstni red pritiskov
    button1State=true;
   if(ATimer==0){
       vrstniRed+="A";
       ATimer+=1;
    }

  }
  if(digitalRead(button2)==true){// preveri ali je bil pristisnjen drugi gumb. Če je bil nastavimo da je bil pritisnjenj in ga doda v vrstni red pritiskov
    button2State=true;
    if(BTimer==0){
       vrstniRed+="B";
       BTimer+=1;
    } 
  }
  if(digitalRead(button3)==true){// preveri ali je bil pristisnjen trerji gumb. Če je bil nastavimo da je bil pritisnjenj in ga doda v vrstni red pritiskov
    button3State=true;
    if(CTimer==0){
       vrstniRed+="C";
       CTimer+=1;
    }
  }
  if(digitalRead(button4)==true){
    button4State=true;
  }
  if(button1State==false && button2State==false && button3State==false){ // če noben gumb še ni bil pritisnjen sveti prva (zelena) led dioda
    digitalWrite(led1,1);
  }
  if(button1State==true || button2State==true || button3State==true){ // Če je bil pritisnjen kateri koli gumb se prva (zelena) dioda ugasne in se prižge druga (rumena) dioda
    if(allButtonsPressed==false){
      digitalWrite(led1,0);
      digitalWrite(led2,1);
    }
  }
  if(button1State==true && button2State==true && button3State==true){ // čo so bili vsi gumbi pritisnjeni nastavimo spremenljikvo, ki spremlja ali so bili vsi gumbi pritisnjeni na true
    allButtonsPressed=true;
  }
  if(allButtonsPressed==true){ // če so vsi gumbi bili pritisnjeni se ugasne druga (rumena) led dioda in začne utripati zadnja (rdeča) led dioda. Na lcd pa izpiše vrstni red pritiskov gumbov in zmagovalca.
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
  if(digitalRead(button4)==true){ // če pritisnemo zadnji gumb nastavi vse spremenljivke na njihovo prvotno vrednost (resetira vse pritiske gumbov, lcd, led diode)
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
