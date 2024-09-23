/*       
 *       Matthis Sanier
 *       chrono_1_v-1
 *       Système de chronomètre avec un afficheur lsc, un boutton poussoir.
 *       
 *       Afficheur LDC, bouton poussoir, carte arduino
 *       Afficheur LCD, button 2
 *       
 *       05/09/2024 Chrono_1_v-1, affichage du chrono sur l'afficheur et reset du chrono
*/


#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
int MIL = 0;
int SEC = 0;
int MIN = 0;
int HEU = 0;
unsigned long timer;



void setup() {
 lcd.begin(16, 2);
    lcd.print("Chrono : ");

   Serial.begin(9600);
   timer = millis();
  }
 


void loop() {
 if (millis() - timer > 0.11) {
      timer = millis();
      MIL = MIL + 1;
      if (MIL > 59) { MIL = 1; SEC = SEC + 1; }
      if (SEC > 59) { SEC = 1; MIN = MIN + 1; }
      
      lcd.begin(15, 1);
      lcd.print(String(MIN)+ " : " +String(SEC) + " : " + String(MIL));
   }
}

 
