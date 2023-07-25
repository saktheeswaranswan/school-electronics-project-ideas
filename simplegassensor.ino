#define MQ2pin A0      // Analog pin to which the MQ2 sensor is connected
#define BUZZERpin 9    // Pin to which the buzzer is connected

int sensorValue;       // variable to store sensor value

void setup() {
  Serial.begin(9600);  // sets the serial port to 9600
  Serial.println("MQ2 warming up!");
  delay(20000);        // allow the MQ2 to warm up

  pinMode(BUZZERpin, OUTPUT);  // Set BUZZERpin as an output pin
}

void loop() {
  sensorValue = analogRead(MQ2pin); // read analog output pin
  Serial.print("Analog Output: ");
  Serial.println(sensorValue);  // Print the sensor value

  // Determine the status
  if (sensorValue > 49) {  // Adjust the threshold value as per your requirement
    Serial.println("  |  Smoke: Detected!");
    digitalWrite(BUZZERpin, HIGH); // Turn on the buzzer
    delay(1000); // Buzzer ON time (1 second)
    digitalWrite(BUZZERpin, LOW); // Turn off the buzzer
  } else {
    Serial.println("  |  Smoke: -");
  }

  delay(4000); // wait 2s for the next reading
}
