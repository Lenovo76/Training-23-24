#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <math.h>

#define Samples 10

// This code gets the average of two sensor readings using Kalman Filter

// Sensor data arrays
float mpu6050[Samples] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
float bno55[Samples] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
//Sensors accuracies
float mpu6050_accuracy = 0.79;
float bno55_accuracy = 0.92;

// Initial velocity and angle
float initial_velocity = 30.0;
float initial_angle = 46.0;

/* Function Declaration*/
void kalmanFilter(float sensor1[], float sensor2[], float output[]);

int main() {

  float output[Samples];

  // Kalman filtering function call
  kalmanFilter(mpu6050, bno55, output);

  // print the y-component of the projectile velocity
  float y_velocity = initial_velocity * sin(initial_angle*M_PI/180);
  printf("Initial velocity (y_component): %.2f m/s\n", y_velocity);

  // Output average measurements

  printf("Filtered measurement of the two sensors:");
  for(int i=0; i<Samples; i++) {
      printf(" %.2f  ", output[i]);
  }

  return 0;
}
      /*Funciton for sensor fusion of the two given sensors*/
/* Function Definition*/
void kalmanFilter(float sensor1[], float sensor2[], float output[]) {
    int p=7; //uncertainty of sensor 1
    int q=2; //process variance
    int p_hat=9; //prediction uncertainty of sensor1
    int pn;
    int y; //Residual(difference between the two sensors readings)

  float sensor1_accuracy = 0.79;
  float sensor2_accuracy = 0.92;

  float Kalman_gain = sensor1_accuracy / (sensor1_accuracy + sensor2_accuracy);

  for(int i=0; i<Samples; i++) {
    // Weighted average of the two sensor measurements and its certainity
        y= sensor2[i]-sensor1[i];
        output[i]=sensor1[i]+Kalman_gain*y;
        pn=(1-Kalman_gain)*p_hat;

  }

}

