#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int aci = 5;
int mi1 = 3;
int mi2 =4;
int analog = 0;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  
  pinMode( mi1,OUTPUT);
  pinMode( mi2,OUTPUT);
  pinMode( aci,OUTPUT);
  digitalWrite(mi1,HIGH);
  digitalWrite(mi2,HIGH);
  
  
}

void loop() {
  
 
  if (mySwitch.available()) {
    int my = mySwitch.getReceivedValue();
    delay(100);
    int value = mySwitch.getReceivedValue();
     
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.print("Received ");
      Serial.print( mySwitch.getReceivedValue() );
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );
      Serial.print(analog);
    }

  mySwitch.resetAvailable();
    
    switch (my){
      case 23304:
      if (digitalRead(mi1) == HIGH ){
     digitalWrite(mi1, LOW);
      digitalWrite(mi2, HIGH);
      }else{digitalWrite(mi1, HIGH);
      }
      analogWrite(aci,analog);
   
      break;
       case 23300:
      if (digitalRead(mi2) == HIGH ){
     digitalWrite(mi2, LOW);
      digitalWrite(mi1, HIGH);
      }else{digitalWrite(mi2, HIGH);
      }
      analogWrite(aci,analog);
    
     break;
       case 23298:
     if (analog == 0 || analog < 255){
      analog++;
      }  
      
      break;
       case 23297:
    if (analog != 0 || analog == 255){
      analog--;
    }
      break;
    
      }
    
    }
   
  }

