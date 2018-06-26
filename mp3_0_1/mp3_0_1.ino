#include <boarddefs.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
#include "IRremote.h"
 
int rec = 3; // вывод, к которому подключен выход TSOP4838

#define volp  25245
#define volm  60891
#define on  19227 // код, принятый от кнопки 1
#define code1  26775 // код, принятый от кнопки 2
#define code2  39015 // код, принятый от кнопки 2
#define code3  45135
#define code4  48703
#define code5  58359
#define code6  31365
#define code7  25979
#define code8  15547
#define code9  23205
#define code0  19125

IRrecv ir_rec(rec);
 
decode_results result;
void setup () {
    Serial.begin (9600);
    mp3_set_serial (Serial);    
    mp3_set_volume (30);
   pinMode(rec, INPUT);
}
void loop () {        
    if (digitalRead(rec)==LOW) 
  {
       mp3_next ();   
            
    } 
          
    
      
    //Serial.println(val); 
                     // принять следующее значение
  
}
