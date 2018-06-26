#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int x;
int y = 0;
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

int prog1 (){
  
  long previusMillis = 0;
  long interval;
  int t[] = {30000,44000,60000,73000,80000,87000,90000,118000,122000,136000,142000,152000,165000,175000,180000,187000,194000,213000,23000,239000,247000,253000,315000};
  //int s[] = {1,2,3};
  int i;
  
  interval = t[0];
  
 y = 1;
  unsigned long currentMillis = millis();
  if (currentMillis - previusMillis > interval){
    previusMillis = currentMillis;
    for (i = 0; i < 23; i = i + 1) {
  interval = t[i];
        }
        if (interval = 30000 ){
          x = 1;
          interval = 0;
          Serial.println(interval);
          }
     }
     
  }

int liliya (int my){
  

  
    switch (my){
      case 13392648:
     if (x>= 0 && x!=3){
      
        x++;
      
      }
      
      break;
       case 13392644:
       if (x <=3 && x!=0){
      --x;
       }
     break;
    
       case 13392642:
      int p1;
      p1 = prog1();
      //x = 5;
     break;
     case 13392640:
      
    
     break;
    
      }
     /*Serial.println(x);
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
     }*/

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
  int a;
   if (my != 0){
   a = liliya(my);
    }
  }
int prog;
   if (y = 1){
   prog = prog1();
  
   }
  
}
  
 
    

