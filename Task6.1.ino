#include <Wire.h>
const int MPU = 0x68; // MPU6050 I2C address
float AccZ;
float GyroZ;
float gyroAngleZ;
float yaw;
float GyroErrorZ;
float elapsedTime, currentTime, previousTime;
int c = 0;
void setup() {
  // Configure Accelerometer Sensitivity - Full Scale Range (default +/- 2g)
  Wire.beginTransmission(MPU);
  Wire.write(0x1C);                  //Talk to the ACCEL_CONFIG register (1C hex)
  Wire.write(0x10);                  //Set the register bits as 00010000 (+/- 8g full scale range)
  Wire.endTransmission(true);
  // Configure Gyro Sensitivity - Full Scale Range (default +/- 250deg/s)
  Wire.beginTransmission(MPU);
  Wire.write(0x1B);                   // Talk to the GYRO_CONFIG register (1B hex)
  Wire.write(0x10);                   // Set the register bits as 00010000 (1000deg/s full scale)
  Wire.endTransmission(true);
  delay(20);
  
  // Call this function if you need to get the IMU error values for your module
  calculate_IMU_error();
  delay(20);
}
void loop() {
  // === Read acceleromter data === //
  Wire.beginTransmission(MPU);
  Wire.write(0x3F); // Start with register 0x3B (ACCEL_ZOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 2, true); // Read 2 registers total
  //For a range of +-2g, we need to divide the raw values by 16384 (LSB sensitivity value) to get it in g, according to the datasheet
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value
  // === Read gyroscope data === //
  previousTime = currentTime;        // Previous time is stored before the actual time read
  currentTime = millis();            // Current time actual time read
  elapsedTime = (currentTime - previousTime) / 1000; // Divide by 1000 to get seconds
  Wire.beginTransmission(MPU);
  Wire.write(0x47); // Start with register 0x47 (GYRO_ZOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 2, true); // Read 2 registers total
  // For a 250deg/s range we have to divide first the raw value by 131.0 to get it in deg/sec, according to the datasheet
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
  // Correct the output with the calculated error values
  GyroZ = GyroZ + 0.79; // GyroErrorZ ~ (-0.8)
  // Currently the raw values are in degrees per seconds, deg/s, so we need to multiply by seconds (s) to get the angle in degrees
  yaw =  yaw + GyroZ * elapsedTime; //----(deg/s * s = deg)----//
  // Print the yaw angle on the serial monitor
  Serial.println(yaw);
}
void calculate_IMU_error() {
  // This function is used to calculate gyro data error. From here we will get the error values used in the above equation printed on the Serial Monitor.
  // Note that we should place the IMU flat in order to get the proper values, so that we then can get the correct values
  // Since we calculate yaw angle which cannot be measured by accelerometer so we get the gyro data error only
  // Read gyro values 200 times
  while (c < 200) {
    Wire.beginTransmission(MPU);
    Wire.write(0x47);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 2, true);
    GyroZ = Wire.read() << 8 | Wire.read();
    // Sum all readings
    GyroErrorZ = GyroErrorZ + (GyroZ / 131.0);
    c++;
  }
  //Divide the sum by 200 to get the error value
  GyroErrorZ = GyroErrorZ / 200;
  // Print the error value on the Serial Monitor
  Serial.print("GyroErrorZ: ");
  Serial.println(GyroErrorZ);
}
