#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define DHT sensor type and pin
#define DHTPIN 10       // DHT22 data pin connected to GP10
#define DHTTYPE DHT22   // DHT 22 (AM2302)

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Address 0x27 for a 16x2 display

void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(9600);
  
  // Initialize DHT sensor
  dht.begin();
  
  // Initialize LCD
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on backlight
  lcd.setCursor(0, 0);             // Set cursor to first column, first row
  lcd.print("Temperature:");       // Print initial message
}

void loop() {
  // Read temperature and humidity from DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Display temperature and humidity on LCD
  lcd.setCursor(0, 1);             // Set cursor to first column, second row
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(9, 1);             // Set cursor to ninth column, second row
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  // Wait a few seconds between measurements
  delay(2000);
}
