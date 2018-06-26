#include <RCSwitch.h>
#include <Servo.h>

Servo myservo;
int p;
int m;
int mi1 = 4;
RCSwitch mySwitch = RCSwitch();
int analog = 0;
void setup() {
  
  Serial.begin(9600);
  mySwitch.enableReceive(0);// Receiver on interrupt 0 => that is pin #2
  myservo.attach(6);
  pinMode( mi1,OUTPUT);
  digitalWrite(mi1,HIGH);

}

void loop() {
  int my = mySwitch.getReceivedValue();
 if (mySwitch.available()) {
    /*int my = mySwitch.getReceivedValue();
    delay(100);*/
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

  mySwitch.resetAvailable(); // put your main code here, to run repeatedly:
 }
switch (my){
      case 6241313:
     
      p =20;
      myservo.write(p);
      Serial.print(p);
      digitalWrite(mi1,LOW);
      delay(50);
      digitalWrite(mi1,HIGH);
      break;
       case 6241316:
       digitalWrite(mi1,HIGH);
      m =150;
    myservo.write(m);
    Serial.print(m);
     break;
 }
}
 

