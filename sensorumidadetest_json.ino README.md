#include "DHT.h"
#define DHTPIN 13  
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define SensorLaranja 12
#define SensorPrata 14
#define SensorRoxo 27
#define SensorRosaEscuro 26
#define SensorRosaClaro 33
#define Luximetro 32
#define Presenca 35

int dirPin1=15;
int stepPin1=2;
int dirPin2=4;
int stepPin2=16;

#define stepsPerRevolution 200
#define Velo 450

void setup() {
  pinMode(SensorLaranja, INPUT); 
  pinMode(SensorPrata, INPUT); 
  pinMode(SensorRoxo, INPUT); 
  pinMode(SensorRosaEscuro, INPUT); 
  pinMode(Presenca, INPUT); 
  pinMode(SensorRosaClaro, INPUT); 
  pinMode(Luximetro, INPUT); 
  dht.begin();
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
   
 float h = dht.readHumidity();
 float t = dht.readTemperature();

  Serial.println("{");
   
    Serial.print("\"UmidadeAr\"");
    Serial.print(" : ");
    Serial.print("\"");
    Serial.print(h);
    Serial.println("\",");

    Serial.print("\"TemperaturaAr\"");
    Serial.print(" : ");
    Serial.print("\"");
    Serial.print(t);
    Serial.println("\",");
    
  Serial.print("\"SensorSolo1\"");
  Serial.print(" : ");
  Serial.print("\"");
  Serial.print(analogRead(SensorRosaEscuro));
  Serial.println("\",");

  Serial.print("\"SensorSolo2\"");
  Serial.print(" : ");
  Serial.print("\"");
  Serial.print(analogRead(SensorRosaClaro));
  Serial.println("\",");
  
  Serial.print("\"SensorSolo3\"");
  Serial.print(" : ");
  Serial.print("\"");
  Serial.print(analogRead(SensorPrata));
  Serial.println("\",");
 
  Serial.print("\"SensorSolo4\"");
  Serial.print(" : ");
  Serial.print("\"");
  Serial.print(analogRead(SensorLaranja));
  Serial.println("\",");
  
  Serial.print("\"SensorSolo5\"");
  Serial.print(" : ");
  Serial.print("\"");
  Serial.print(analogRead(SensorRoxo));
  Serial.println("\",");
  
  Serial.print("\"Presença\"");
  Serial.print(" : ");
  Serial.print("\"");
  Serial.print(analogRead(Presenca));
  Serial.println("\",");
  
  Serial.print("\"Luximetro\"");
  Serial.print(" : ");
  Serial.print("\"");
  Serial.println(analogRead(Luximetro));

  Serial.println("}");
  Serial.println("");
  
  girar(dirPin1,stepPin1);
  girar(dirPin2,stepPin2);
  delay(500);
}
void girar(int dirPin, int stepPin) {
  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);
  // Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Velo);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Velo);
  }
  delay(Velo);
  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);
  //Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(Velo);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Velo);
  }
}
