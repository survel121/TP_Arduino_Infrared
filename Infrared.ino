// C++ code
//

#include <IRremote.h>
int PIN_IR = 8;
int PIN_LED = 7;
int iValue;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(PIN_IR); //Déclaration/Initialisation de mon objet IR
  pinMode(7,OUTPUT);
}

void loop()
{
  if ( IrReceiver.decode() ) {
    iValue = IrReceiver.decodedIRData.command; // Valeur en décimal
    Serial.println(iValue);
    if (iValue == 16){
      digitalWrite(7,HIGH);
    }
    else if (iValue == 17) {
      digitalWrite(7,LOW);
    }
    IrReceiver.resume(); //Important
  }
  delay(100);
}
