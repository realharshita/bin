const int ledPin = 2;
const int buttonPin = 3;
const int onboardLedPin = PICO_DEFAULT_LED_PIN;


int buttonState = 0;

int lastButtonState = HIGH;

int ledState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(onboardLedPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  digitalWrite(onboardLedPin, LOW);



}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        digitalWrite(onboardLedPin, ledState);


      }
    }
  }
  lastButtonState = reading;
  
}
