#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, duration1, distance, distance1, change; // Duration used to calculate distance
int ledpin=2;//
int ledpin1=3;//
int buzzer=9;// select digital IO pin for the buzzer
int servopin=12;// select digital pin 9 for servomotor signal line
int servopin1=13;// select digital pin 9 for servomotor signal line
int myangle;// initialize angle variable
int pulsewidth;// initialize width variable
int val;
void servopulse(int servopin,int myangle)// define a servo pulse function
{
pulsewidth=(myangle*11)+500;// convert angle to 500-2480 pulse width
digitalWrite(servopin,HIGH);// set the level of servo pin as “high”
delayMicroseconds(pulsewidth);// delay microsecond of pulse width
digitalWrite(servopin,LOW);// set the level of servo pin as “low”
delay(20-pulsewidth/1000);
}
void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 pinMode(servopin,OUTPUT);// set servo pin as “output”
  pinMode(servopin1,OUTPUT);// set servo pin as “output”
 Serial.begin(9600);// connect to serial port, set baud rate at “9600”
 Serial.println("servo=o_seral_simple ready" ) ;
 pinMode(ledpin1,OUTPUT);// define digital pin 11 as “output”
 pinMode(ledpin,OUTPUT);// define digital pin 11 as “output”
 pinMode(buzzer,OUTPUT);// set digital IO pin pattern, OUTPUT to be output 
}

void loop() {

tone(9, 500);
digitalWrite(ledpin, HIGH);
digitalWrite(ledpin1, LOW);
val = '0';
val=val-'0';// convert characteristic quantity to numerical variable
val=val*(180/9);// convert number to angle
Serial.print("moving servo to ");
Serial.print(val,DEC);
Serial.println();
for(int i=0;i<=50;i++) // giving the servo time to rotate to commanded position
{
servopulse(servopin,val);// use the pulse function
}



digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration/58.2;

delay(1000);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);
duration1 = pulseIn(echoPin, HIGH);
distance1 = duration1/58.2;

change = distance1 - distance;
Serial.println(change);
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(LEDPin, HIGH); 
 }
 else if (change > 1 || change < -1){
for(int iu = 0; iu < 15; iu++){
 val = '0';
val=val-'0';// convert characteristic quantity to numerical variable
val=val*(180/9);// convert number to angle
Serial.print("moving servo to ");
Serial.print(val,DEC);
Serial.println();
for(int i=0;i<=50;i++) // giving the servo time to rotate to commanded position
{
servopulse(servopin1,val);// use the pulse function
}
 Serial.println(change);
 digitalWrite(LEDPin, LOW); 
}
 }
 else{
  Serial.println(distance);
  Serial.println(distance1);
 }
 
delay(1000);
delay (1000);

tone(9,3000);
digitalWrite(ledpin, LOW);
digitalWrite(ledpin1, HIGH);

val = '9';
val=val-'0';// convert characteristic quantity to numerical variable
val=val*(180/9);// convert number to angle
Serial.print("moving servo to ");
Serial.print(val,DEC);
Serial.println();
for(int i=0;i<=50;i++) // giving the servo time to rotate to commanded position
{
servopulse(servopin,val);// use the pulse function
}

delay(1000);
delay (1000);
delay(1000);
}
