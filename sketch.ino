#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 28
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Current reading");
}

void loop() {
  float humidity = dht.readHumidity();
  
  if (isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    Serial.print("Humidity: ");
    Serial.println(humidity);
    return;
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  
  Serial.print("Humidity: ");
  Serial.println(humidity);
  
  delay(2000);
}
