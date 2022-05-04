#include "robocar.h"

/*
    Wheel Pin Configuration

         L             R

    (1,2)----|    |----(3,4)
             |    |
    (5,6)----|    |----(7,8)


    Wheel Speed Configuration
         L             R

      (1)----|    |----(2)
             |    |
      (3)----|    |----(4)

*/

//speedSelection mSpeed;

Robocar::Robocar(robocarType robocarType, uint8_t wheels[8], uint8_t speeds[4]){

    //Motor pins set as outputs
    uint8_t i=0;
    while(i<sizeof(wheels)){
        if(wheels[i]==0){
            break;
        }
        pinMode(wheels[i], OUTPUT);
        i++;
    }

    i=0;
    while(i<sizeof(speeds)){
        if(speeds[i]==0){
            break;
        }
        pinMode(speeds[i], OUTPUT);
        i++;
    }

    TCCR1B = TCCR1B & B11111000 | B00000001; // set timer 1 divisor to 1 for PWM frequency of 31372.55 Hz


    //  Define default speed
    Robocar::_mSpeed=low;

    _wheels = wheels;
    _speeds = speeds;

    Robocar::setMotorSpeed(Robocar::_mSpeed);
    Robocar::robotHalt();

}

void Robocar::setMotorSpeed(speedSelection speedSelection){
  Robocar::_mSpeed = speedSelection;
  Serial.print("Setting Speed to: ");
  Serial.println(Robocar::_mSpeed);
  while(i<sizeof(Robocar::_speeds)){
        if(Robocar::_speeds[i]==0){
            break;
        }
        analogWrite(Robocar::_speeds[i], Robocar::_mSpeed);
        i++;
    }
}

Robocar::robotForward(){
    while(i<sizeof(wheels)){
        if(wheels[i]==0){
            break;
        }
        if(i==0||i==2||i==4||i==6){
            digitalWrite(wheels[i], HIGH);
        }else{
            digitalWrite(wheels[i], LOW);
        }
        i++;
    }
}

Robocar::robotRight(){
    while(i<sizeof(wheels)){
        if(wheels[i]==0){
            break;
        }
        if(i==1||i==3||i==5||i==7){
            digitalWrite(wheels[i], HIGH);
        }else{
            digitalWrite(wheels[i], LOW);
        }
        i++;
    }
}

Robocar::robotReverse(){
    while(i<sizeof(wheels)){
        if(wheels[i]==0){
            break;
        }
        if(i==2||i==6){
            digitalWrite(wheels[i], HIGH);
        }else{
            digitalWrite(wheels[i], LOW);
        }
        i++;
    }
}

Robocar::robotLeft(){
    while(i<sizeof(wheels)){
        if(wheels[i]==0){
            break;
        }
        if(i==2||i==6){
            digitalWrite(wheels[i], HIGH);
        }else{
            digitalWrite(wheels[i], LOW);
        }
        i++;
    }
}

Robocar::robotHalt(){

    while(i<sizeof(wheels)){
        if(wheels[i]==0){
            break;
        }
        digitalWrite(wheels[i], LOW);
        i++;
    }
}

Robocar::robotDirection(uint8_t dir){
  //Direction Options
  //  forward=1,
  //  right=2,
  //  reverse=3,
  //  left=4,
  //  halt=0,
  if(dir==1){
    robotForward();
    Serial.println("forward");
  }else if(dir==2){
    robotRight();
    Serial.println("right");
  }else if(dir==3){
    robotReverse();
    Serial.println("reverse");
  }else if(dir==4){
    robotLeft();
    Serial.println("left");
  }else if(dir==0){
    robotHalt();
    Serial.println("stopped");
  }
}
