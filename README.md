# Soil Moisture Sensor Project

This project uses an Arduino Uno to measure soil moisture levels using a soil moisture sensor.

## Hardware Requirements

- Arduino Uno
- Soil Moisture Sensor Module

## Wiring Diagram

Connect the Soil Moisture Sensor Module to the Arduino Uno as follows:

| Sensor Module | Arduino Uno |
|---------------|-------------|
| +             | 5V          |
| -             | GND         |
| A             | A0          |

## Software Setup

1. Ensure you have the Arduino IDE installed on your computer.
2. Open the Arduino IDE and load the provided sketch.
3. Select "Arduino Uno" as your board type under Tools > Board.
4. Select the correct COM port under Tools > Port.
5. Upload the sketch to your Arduino Uno.

## Calibration

Calibration is crucial for accurate readings. The sensor must be calibrated to your specific soil and environmental conditions:

1. Insert the sensor into completely dry soil (or leave it in open air) and note the analog reading from the serial monitor. This will be your `soilMoistLevelLow` value.
2. Insert the sensor into water or very wet soil and note the reading. This will be your `soilMoistLevelHigh` value.
3. Update these values in the Arduino sketch:

```cpp
const int soilMoistLevelLow = [Your dry soil reading];    // Value for dry soil (0% humidity)
const int soilMoistLevelHigh = [Your wet soil reading];   // Value for wet soil (100% moisture)
```

Remember:
- Different soil types can affect readings.
- Environmental conditions (temperature, humidity) may influence sensor performance.
- Regular recalibration may be necessary to maintain accuracy.

## Usage

1. After uploading the calibrated sketch, open the Serial Monitor in the Arduino IDE.
2. Set the baud rate to 115200 in the Serial Monitor.
3. You will see moisture readings every 60 seconds in the following format:
   ```
   Analog Value: [raw sensor value]    [moisture percentage] %
   ```

## Troubleshooting

- No output: Ensure the baud rate in the Serial Monitor matches the one in the code (115200).
- Inaccurate readings: Recalibrate the sensor and check for proper soil contact.
- Inconsistent readings: Check all connections to ensure they are secure and correctly placed.
- Sensor malfunction: Try cleaning the sensor prongs and allowing them to dry completely before retesting.

## Maintenance

- Keep the sensor clean and dry when not in use.
- Avoid leaving the sensor in soil for extended periods to prevent corrosion.
- Periodically check and tighten all connections.

## Disclaimer

This project is for educational purposes. The accuracy of soil moisture measurements may vary based on various factors including soil composition, temperature, and sensor quality. For critical applications, consider using professional-grade equipment.
