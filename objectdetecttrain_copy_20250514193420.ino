#define trig 9   // Pin setup
#define echo 10
#define relay 11

void setup() {
// Pin mode declaration
     pinMode(trig,OUTPUT);
     pinMode(echo,INPUT);
     pinMode(relay,OUTPUT);
     Serial.begin(9600);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);     // Sending data from triger
  delayMicroseconds(10);

  float t = pulseIn(echo,HIGH,40000);   // Reciving data from echo
   
  float d = 0.034*t / 2;
  Serial.println(d);
  

  if(d <= 15 && d>3 ){
    digitalWrite(relay,HIGH);
  }
  else if(d <= 3){
    digitalWrite(relay,LOW);
  }
  else{
    digitalWrite(relay,LOW);
  }
delay(100);

}