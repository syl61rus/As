#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int OnOff = 5;
int Speed1 = 3;
int Speed2 =4;
int Speed3 = 6;
long interval;


boolean prog = false;

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
      //prog = false;
     if (x>= 0 && x!=3){
      
        x++;
      delay(100);
      }
      
      break;
       case 1005572:
       prog = false;
       if (x <=3 && x!=0){
      --x;
      delay(100);
       }
     break;
     
       case 1005576:
       prog = true;
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
   if (prog == true){

    int prog;
    prog = programs();
    }
   
  }
  int programs(){
    unsigned long currentMillis = millis();
    int previusMillis;
    static int i;
       long t[] = {30000,44000,60000,73000,80000,87000,90000,118000,122000,136000,142000,152000,165000,175000,180000,187000,194000,213000,23000,239000,247000,253000,315000};
       interval = t[i];
       
      if (currentMillis - previusMillis >interval){
    previusMillis = currentMillis;
   i++;
 switch (interval){
  
        case 30000:
        
  Serial.println(111);
        break;
        case 44000:
        
 Serial.println(2);
        break;
        case 60000:
 Serial.println(3);
        break;
        case 73000:
 Serial.println(4);
        break;
        case 80000:
 Serial.println(5);
        break;
        case 87000:
 Serial.println(6);
        break;
        case 90000:
 Serial.println(7);
        break;
        case 118000:
 Serial.println(8);
        break;
        case 122000:
 Serial.println(9);
        break;
        case 136000:
 Serial.println(10);
        break;
        case 142000:
 Serial.println(11);
        break;
        case 152000:
 Serial.println(12);
        break;
        case 165000:
Serial.println(13);
        break;
        case 175000:
 Serial.println(14);
        break;
        case 180000:
 Serial.println(15);
        break;
        case 187000:
 Serial.println(16);
        break;
        case 194000:
 Serial.println(17);
        break;
        case 213000:
 Serial.println(18);
        break;
        case 23000:
 Serial.println(19);
        break;
        case 239000:
 Serial.println(20);
        break;
        case 247000:
 Serial.println(21);
        break;
        case 253000:
 Serial.println(22);
        break;
        case 315000:
 Serial.println(23);
        break;
  
  }
      }
      
    }
  
 
    

