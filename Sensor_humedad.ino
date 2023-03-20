#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

int rs = 2;
int e = 3;
int d4 = 4;
int d5 = 5;
int d6 = 6;
int d7 = 7;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
int sensor=9;
int temperatura;
int humedad;


DHT dht(sensor,DHT11);

void setup() {
  pinMode(sensor,INPUT);

  Serial.begin(9600);
  lcd.begin(16,2);
  dht.begin();
}

void loop() {
  temperatura = dht.readTemperature();
  humedad = dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.print(temperatura);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humedad: ");
  lcd.print(humedad);


  // Lee el valor de la temperatura y lo envía a Processing a través del puerto serie
  Serial.println(temperatura);
  delay(100); // Pequeña pausa para evitar una transmisión muy rápida de datos por el puerto serie
}
