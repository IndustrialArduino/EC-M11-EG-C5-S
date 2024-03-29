#include <Wire.h>
// Define the I2C device address
#define DEVICE_ADDRESS 0x49

void setup() {
  Wire.begin(16, 17);  // SDA on GPIO16, SCL on GPIO17
  Serial.begin(115200);
}

void loop() {
  // Write data to the I2C device
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(0x01);  // Replace with your data
  Wire.write(0x02);
  Wire.write(0x03);
  Wire.endTransmission();
  delay(100);
  // Read data from the I2C device
  Wire.requestFrom(DEVICE_ADDRESS, 3);  // 3 bytes of data
  if (Wire.available() >= 3) {
    byte data1 = Wire.read();
    byte data2 = Wire.read();
    byte data3 = Wire.read();
    Serial.print("Read Data: ");
    Serial.print(data1, HEX);
    Serial.print(" ");
    Serial.print(data2, HEX);
    Serial.print(" ");
    Serial.println(data3, HEX);
  }
  delay(1000);  // Delay for demonstration purposes
}
