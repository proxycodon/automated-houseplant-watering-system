const int soilMoistPin = A0;    // Pin definition for the soil moisture sensor
const int soilMoistLevelLow = 449;    // Value for dry soil (0% humidity)
const int soilMoistLevelHigh = 192;   // Value for wet soil (100% moisture)
const unsigned long measurementInterval = 60000;  // 60 seconds in milliseconds

unsigned long lastMeasurementTime = 0;

void setup() {
  Serial.begin(115200);  
  pinMode(soilMoistPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - lastMeasurementTime >= measurementInterval) {
    lastMeasurementTime = currentTime;
    
    int soilMoist = analogRead(soilMoistPin);
    int percentSoilMoist = map(soilMoist, soilMoistLevelHigh, soilMoistLevelLow, 100, 0);
    percentSoilMoist = constrain(percentSoilMoist, 0, 100);  // Ensure value is between 0 and 100
    
    Serial.print("Analog Value: ");
    Serial.print(soilMoist);
    Serial.print("\t");
    Serial.print(percentSoilMoist);
    Serial.println(" %");
  }
}
