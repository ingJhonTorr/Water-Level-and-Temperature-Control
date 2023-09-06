// Define used pins
const int humiditySensor1 = A1;
const int humiditySensor2 = A2;
const int temperatureSensor = A4;
const int greenLedPin = 10;
const int redLedPin = 11;
const int buzzerPin = 12;

// Variables to store sensor values
int highHumidityValue = 0; // Sensor detecting high humidity (HIGH)
int lowHumidityValue = 0; // Sensor detecting low humidity (LOW)
int temperatureValue = 0;
float voltage;
float temperature;

void setup() {
  // Set pins as outputs
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  // Initialize serial communication for displaying results
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  highHumidityValue = analogRead(humiditySensor1);
  lowHumidityValue = analogRead(humiditySensor2);
  temperatureValue = analogRead(temperatureSensor);
  voltage = (temperatureValue * 5.0) / 1023.0; // Convert reading to voltage (5V reference)
  temperature = (voltage - 0.5) * 100.0; // Convert voltage to temperature in Celsius

  // Check humidity
  if (highHumidityValue > 50 && lowHumidityValue > 50) {
    // Both sensors detect humidity -> TANK FULL
    digitalWrite(greenLedPin, HIGH); // Turn on green LED
    digitalWrite(redLedPin, LOW); // Turn off red LED
    Serial.println("The tank is FULL");
    delay(500);
  } else if (highHumidityValue < 50 && lowHumidityValue > 50) {
    // Only low humidity sensor detects humidity -> TANK MEDIUM LEVEL
    blinkRedLed(); // Call function to blink red LED
    digitalWrite(greenLedPin, LOW); // Turn off green LED
    Serial.println("Caution, tank at MEDIUM level");
  } else if (highHumidityValue < 50 && lowHumidityValue < 50) {
    // No sensor detects humidity -> TANK ALMOST EMPTY
    digitalWrite(greenLedPin, LOW); // Turn off green LED
    digitalWrite(redLedPin, HIGH); // Turn on red LED
    Serial.println("DANGER! The tank is getting EMPTY");
    delay(500);
  } else {
    // Only high humidity sensor detects humidity -> INCORRECT READING
    // It's not possible for the high sensor to detect and the low sensor not to
    digitalWrite(greenLedPin, HIGH); // Turn on green LED
    digitalWrite(redLedPin, HIGH); // Turn on red LED
    Serial.println("ERROR! Incorrect reading, check sensors");
    delay(500);
  }

  // Check temperature
  if (temperature > 30 || temperature < 15) {
    // Activate buzzer using tone function
    tone(buzzerPin, 1000);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" degrees Celsius");
  } else {
    // Deactivate buzzer using noTone function
    noTone(buzzerPin);
  }
}

// Auxiliary function to blink the red LED
void blinkRedLed() {
  digitalWrite(redLedPin, HIGH);
  delay(500);
  digitalWrite(redLedPin, LOW);
  delay(500);
}
