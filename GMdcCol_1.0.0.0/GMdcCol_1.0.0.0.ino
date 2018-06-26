int dcP = 8;
int dcM = 9;

void setup() {
  pinMode(dcP, OUTPUT);
  pinMode(dcM, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(dcP, LOW);
  digitalWrite(dcM, HIGH);
  delay(10000);
  digitalWrite(dcP, LOW);
  digitalWrite(dcM, LOW);
  delay(1000);
  digitalWrite(dcM, LOW);
  digitalWrite(dcP, HIGH);
  delay(10000);
  digitalWrite(dcP, LOW);
  digitalWrite(dcM, LOW);
  delay(5000);
  // put your main code here, to run repeatedly:

}
