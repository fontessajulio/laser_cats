#include <Servo.h>

Servo myservo1;
Servo myservo2;

int memoria1=45;
int memoria2=45;

void setup()
{
  myservo1.attach(3);
  myservo1.write(memoria1); 

  myservo2.attach(5);
  myservo2.write(memoria2);   
}
void loop()
{
  Serial.begin(9600);

  int val1 = analogRead(0);
     val1 = map(val1, 0, 1020, -4, 4);
  int val2 = analogRead(1);
     val2 = map(val2, 0, 1017, -4, 4);
      
                                         Serial.print(val1);        Serial.print(val2);

if ( val1 != 1 && val1 != -1){
  memoria1=memoria1+val1;
    if (memoria1>=120) { memoria1=120; }
    if (memoria1<=0)  {memoria1=0;}
}
  myservo2.write(memoria1);          // Serial.print(memoria1);

if ( val2 != 1 && val2 != -1 ){
  memoria2=memoria2+val2;
    if (memoria2>=120) {memoria2=120;}
    if (memoria2<=0) {memoria2=0;}
}
  myservo1.write(memoria2);          //    Serial.print(memoria1);

  delay(50);
}
