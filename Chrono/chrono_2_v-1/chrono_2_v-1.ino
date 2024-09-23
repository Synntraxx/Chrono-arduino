/*       
 *       Matthis Sanier
 *       chrono_2_v-2
 *       Système de chronomètre avec un afficheur lsc, un boutton poussoir.
 *       
 *       Afficheur LDC, bouton poussoir, carte arduino
 *       Afficheur LCD, button 2
 *       
 *       05/09/2024 Chrono_1_v-1, affichage du chrono sur l'afficheur et reset du chrono
*/


//Bibliotheque LCD
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

//constantes
const int colorR = 0; //rouge
const int colorG = 0; //vert
const int colorB = 255; //bleu
unsigned long timet;
const int buttonPin = 2;
int buttonState = 0;



//Setup
void setup() {
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    delay(1000);
    pinMode(buttonPin, INPUT);
}


//Loop
void loop() {  
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("00:00:00");
  
  buttonState = digitalRead(buttonPin);
  
  while(buttonState==0){
    buttonState = digitalRead(buttonPin);
  }
  
  timet=millis();
  
  while(buttonState==1){
    buttonState = digitalRead(buttonPin);
    lcd.clear();
  }
  
  while(buttonState==0){
    buttonState = digitalRead(buttonPin);
    lcd.setCursor(0,1);
    lcd.print((millis()-timet) / 60000);
        lcd.print(":"); 
    lcd.print((millis()-timet) / 1000%60);
        lcd.print(":"); 
    lcd.print((millis()-timet) / 10%100);  
  }

  while ((buttonState == 1) && millis() <=3000){
     buttonState = digitalRead(buttonPin);
  }
      
  while(buttonState==1){
    buttonState = digitalRead(buttonPin);
  }
  
  
    
  while(buttonState==0){
     buttonState = digitalRead(buttonPin);
  }
   
  

  delay(1000);


}


 
