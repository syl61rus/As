#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int cont =12;
int led = 13;
int OnOff = 5;
int Speed1 = 3;
int Speed2 =4;
int Speed3 = 6;
long interval = 1000;
int sec = 0;
boolean progLed = false;
boolean prog = false;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  pinMode( cont,OUTPUT);
  pinMode( led,OUTPUT);
  pinMode( OnOff,OUTPUT);
  pinMode( Speed1,OUTPUT);
  pinMode( Speed2,OUTPUT);
  pinMode( Speed3,OUTPUT);
  digitalWrite(cont,HIGH);
  digitalWrite(led,LOW);
  digitalWrite(OnOff,HIGH);
  digitalWrite(Speed1,HIGH);
  digitalWrite(Speed2,HIGH);
  digitalWrite(Speed3,HIGH);
  Serial.println("On");
  
}

int liliya (int my){
  
 static int x;
 
  
    switch (my){
      case 13392648:
      prog = false;
      progLed = false;
     if (x>= 0 && x!=3){
      
        x++;
      delay(100);
      }
      
      break;
       case 13392644:
       prog = false;
       progLed = false;
       if (x <=3 && x!=0){
      --x;
      delay(100);
       }
     break;
     
       case 13392642:
       prog = true;
     break;
     case 13392641:
       prog = false;
       progLed = false;
       Serial.println("Reset");
       delay(500);
       void(* resetFunc) (void) = 0;
       resetFunc(); 
     break;
      }
     Serial.println(x);
     switch (x){
      case 0:
       digitalWrite(OnOff,HIGH);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(0);
       break;
      case 1:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed1,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(1);
       break;
      case 2:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(2);
       break;
      case 3:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed3,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed1,HIGH);
       Serial.println(3);
       break;
     }
  }
void loop() {
  if (mySwitch.available()) {
    int my = mySwitch.getReceivedValue();
    delay(500);
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
   if (prog == true){
    int prog;
    prog = programs();
    if(progLed == false){
      int l;
      l = ledProg();
      }
    }
  }
  int programs(){
    unsigned long currentMillis = millis();
    static long previusMillis;
    static int i;
    long timeLine;
    long t[] = {30,44,60,73,80,87,90,118,122,136,142,152,165,175,180,187,194,213,230,239,247,253,315};
       timeLine = t[i];
       //Serial.println(sec);
       //Serial.println(previusMillis);
      if (currentMillis - previusMillis >interval){
    previusMillis = currentMillis;
      sec++;
      }
      if(sec >= t[i]){
    i++;
 switch (sec){
       case 30:
          digitalWrite(OnOff,LOW);
          digitalWrite(Speed1,LOW);
          digitalWrite(Speed2,HIGH);
          digitalWrite(Speed3,HIGH);
          Serial.println(1);
         break;
       case 44:
          digitalWrite(OnOff,LOW);
          digitalWrite(Speed2,LOW);
          digitalWrite(Speed1,HIGH);
          digitalWrite(Speed3,HIGH);
          Serial.println(2);
         break;
       case 60:
          digitalWrite(OnOff,LOW);
          digitalWrite(Speed3,LOW);
          digitalWrite(Speed2,HIGH);
          digitalWrite(Speed1,HIGH);
          Serial.println(3);
         break;
       case 73:
        digitalWrite(OnOff,LOW);
        digitalWrite(Speed2,LOW);
        digitalWrite(Speed1,HIGH);
        digitalWrite(Speed3,HIGH);
        Serial.println(4);
        break;
       case 80:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed1,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(5);
        break;
      case 87:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(6);
        break;
      case 90:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed3,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed1,HIGH);
       Serial.println(7);
        break;
      case 118:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(8);
        break;
      case 122:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed1,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(9);
        break;
      case 136:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(10);
        break;
      case 142:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed1,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(11);
        break;
      case 152:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(12);
        break;
      case 165:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed1,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(13);
        break;
      case 175:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(14);
        break;
      case 180:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed3,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed1,HIGH);
       Serial.println(15);
        break;
      case 187:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed1,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(16);
        break;
      case 194:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(17);
        break;
      case 213:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed1,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(18);
        break;
      case 230:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(19);
        break;
      case 239:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed3,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed1,HIGH);
       Serial.println(20);
        break;
      case 247:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed2,LOW);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(21);
        break;
      case 253:
       digitalWrite(OnOff,LOW);
       digitalWrite(Speed1,LOW);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(22);
        break;
      case 315:
       digitalWrite(OnOff,HIGH);
       digitalWrite(Speed1,HIGH);
       digitalWrite(Speed2,HIGH);
       digitalWrite(Speed3,HIGH);
       Serial.println(23);
       i = 0;
       sec =0;
       prog = false;
       progLed = false;
        break;
  
  }
      }
      
    }
int ledProg(){
  static int intervalled = 500;
  static int timeLed;
  unsigned long cMillis = millis();
  static long pMillis;
  digitalWrite(cont,LOW);
  if (cMillis - pMillis >intervalled){
    pMillis = cMillis;
    timeLed++;
  }
          if(timeLed ==1){
             digitalWrite(led,HIGH);
          }
           if(timeLed == 2){
             digitalWrite(led,LOW);
          } if(timeLed == 3){
             digitalWrite(led,HIGH);
          }
          if(timeLed == 4){
             digitalWrite(led,LOW);
          }
          if(timeLed == 5){
             digitalWrite(led,HIGH);
          }
           if(timeLed == 9){
             digitalWrite(led,LOW);
             digitalWrite(cont,HIGH);
             timeLed = 0;
             progLed = true;
          }
          
          
  }
  
 
    

