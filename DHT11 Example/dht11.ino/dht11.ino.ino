#include <dht11.h>
#define DHT11PIN 4

const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int TEMP = 0;

const int LOWER_BOUND = 23;
const int UPPER_BOUND = 25;

int val = 0;

dht11 DHT11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (BLED, OUTPUT);
  pinMode (GLED, OUTPUT);
  pinMode (RLED, OUTPUT);
}

void loop() {
  //Serial.println();
  val = DHT11.temperature;

  if (val <= LOWER_BOUND)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  else if (val > UPPER_BOUND) 
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }

  
  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);

  
}
