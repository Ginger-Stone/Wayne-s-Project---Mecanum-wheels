#include <robocar.h>

uint8_t wheels[8] = {2,3,4,5,6,7,8,9};
uint8_t speed_pins[4] = {10,11,12,13};

int count=0;

Robocar car(car.mecanum, car.low, wheels, speed_pins);
void setup() {
  Serial.begin(9600);
  
//  Serial.println(wheels[2]);
  car.setMotorSpeed(car.low);
//  wheel 13 is very slow-- adjusting its speed
  car.setIndividualMotorSpeed(speed_pins[0],80);
  car.setIndividualMotorSpeed(speed_pins[1],80);
  car.setIndividualMotorSpeed(speed_pins[2],80);
  car.setIndividualMotorSpeed(speed_pins[3],100);
}

void loop() {
  if (count=1000){
    count=0;
    car.robotDirection(car.halt); //set value to change direction 
    delay(2000);
  }
  while(count<250){
    car.robotDirection(car.forwards); //set value to change direction 
    count++;
    Serial.println(count);
  }
  car.robotDirection(car.halt); //set value to change direction 
    delay(1000);
      
  while(count>=250 && count<500){
    car.robotDirection(car.right); //set value to change direction 
    count++;
  }
  car.robotDirection(car.halt); //set value to change direction 
    delay(1000);
      
  while(count>=500 && count<750){
    car.robotDirection(car.backwards); //set value to change direction 
    count++;
  }
  car.robotDirection(car.halt); //set value to change direction 
    delay(1000);
      
  while(count>=750 && count<1000){
    car.robotDirection(car.left); //set value to change direction 
    count++;
  }

  
}
