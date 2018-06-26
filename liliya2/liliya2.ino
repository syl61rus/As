#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int OnOff = 5;
int Speed1 = 3;
int Speed2 =4;
int Speed3 = 6;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  
  pinMode( OnOff,OUTPUT);
  pinMode( Speed1,OUTPUT);
  pinMode( Speed2,OUTPUT);
  pinMode( Speed3,OUTPUT);
  digitalWrite(OnOff,HIGH);
  digitalWrite(Speed1,HIGH);
  digitalWrite(Speed2,HIGH);
  digitalWrite(Speed3,HIGH);
  
  
}

int liliya (int my){
  
 static int x;
  
    switch (my){
      case 13392648:
     if (x>= 0 && x!=3){
      
        x++;
      delay(100);
      }
      
      break;
       case 13392644:
       if (x <=3 && x!=0){
      --x;
      delay(100);
       }
     break;
     break;
       case 13392642:
      
    
     break;
    
      }
     Serial.println(x);
     switch (x){
      case 0:
       digitalWrite(OnOff,HIGH);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       break;
      case 1:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed1,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       break;
      case 2:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       break;
      case 3:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed3,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed1,HIGH);
       break;
     }

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
     // Serial.print(analog);
    }

  mySwitch.resetAvailable();
  int a;
   if (my != 0){
   a = liliya(my);
    }

    }
   
  }
  
 
    

