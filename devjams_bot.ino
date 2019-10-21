#define in3 D3
#define in4 D4
#define in5 D5
#define in6 D6


int trigpin1=D2; 
int echopin1=D1;
int trigpin2 = D7;
int echopin2 = D8; 
int dist = 0;
float pingTime; 
float targetDistance;
float speedOfSound=776.5;

 
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(in5,OUTPUT);
  pinMode(in6,OUTPUT);
}
 
void loop() {
  //Serial.print("dist1 : ");
 //ultrasonic_distance_val( trigpin1, echopin1);
  //Serial.print("dist2 : ");
  //ultrasonic_distance_val( trigpin2, echopin2);
  if(Serial.available()>0)
  {
int x = Serial.read();
Serial.println(x);
    if(x == 2)
    {
      Serial.println("backward");
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
    }
    else if(x == 1)
    {
      Serial.println("forward");
    digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
    }
    else if(x == 3)
    {
      Serial.println("right");
      digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
      
    }
    else if(x == 4)
    {
      Serial.println("left");
      digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
    }
    else if(x == 0)
    {
      digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
    }
    else if(x == 5)
    {
      ultrasonic_distance_val( trigpin1, echopin1);
      
    }
  }
   
  
  
}
void ultrasonic_distance_val(int trigPin,int echoPin)
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2000);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(15); 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  
  pingTime = pulseIn(echoPin, HIGH);  
  pingTime=pingTime/1000000; 
  pingTime=pingTime/3600; 
  targetDistance= speedOfSound * pingTime;  
  targetDistance=targetDistance/2; 
  targetDistance= targetDistance*63360*2.54;   
  dist = targetDistance;
 // Serial.println(dist);
 Serial.write(dist);
  
  delay(100); 
} 

