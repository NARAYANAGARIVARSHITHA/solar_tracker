#include <Servo.h>
 Servo horizontal; //Large motor
 Servo vertical; //Small motor
 int servoh= 85;
 int servohLimitHigh= 170; int 
servohLimitLow= 0;
 int servov= 100;
 int servovLimitHigh= 180; int 
servovLimitLow= 15;
 //LDR
 int ldrl= A4;//left
 int ldrr= A5;//right
 int ldrt= A1;//top
 int ldrd= A2;//down
//Code variables
 int l=0;//left top
 int r=0;//right top
 int t=0;//left down
 int d=0;//right down
 void setup() {
 Serial.begin(9600);
 horizontal.attach(5);
 vertical.attach(6);
 horizontal.write(70);
 vertical.write(100);
 delay(2000); }
void loop() {
 l= analogRead(ldrl);
 r= analogRead(ldrr);
 t= analogRead(ldrt);
 d= analogRead(ldrd);
 Serial.print(l);
 Serial.print(", ");
 Serial.print(r);
 Serial.print(", ");
 Serial.print(t);
 Serial.print(", ");
 Serial.println(d);
if(t-d>50){
 if(servov>servovLimitLow)
 servov-=7; } }
 else if(d-t>50){
 if(servov< servovLimitHigh){
 servov+=7; } }
 vertical.write(servov);
 if(l-r>50){
 if(servoh>servohLimitLow){
 servoh-=7;}}
 else if(r-l>50){
 if(servoh< servohLimitHigh){
 servoh+=7; } }
 horizontal.write(servoh);
 delay(250);
 }
