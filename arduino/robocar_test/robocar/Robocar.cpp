#include "robocar.h"

Robocar::Robocar(uint8_t wheels[4], uint8_t speed[2]){
    //Motor pins set as outputs
    uint8_t i=0;
    while(i<sizeof(wheels)){
        pinMode(wheels[i], OUTPUT);
        i++;
    }
    //Motor speed pins set as outputs
    i=0;
    while(i<sizeof(speed)){
        pinMode(speed[i], OUTPUT);
        i++;
    }

    TCCR1B = TCCR1B & B11111000 | B00000001; // set timer 1 divisor to 1 for PWM frequency of 31372.55 Hz

    //  Define default speed
    Robocar::_mSpeed=low;

    //Assign motor pins
    _motor11 = wheels[0];
    _motor12 = wheels[1];
    _motor21 = wheels[2];
    _motor22 = wheels[3];
    _speed1 = speed[0];
    _speed2 = speed[1];

    Robocar::setMotorSpeed(Robocar::_mSpeed);
    Robocar::robotHalt();

}

void Robocar::setMotorSpeed(speedSelection speedSelection){
  Robocar::_mSpeed = speedSelection;
  Serial.print("Setting Speed to: ");
  Serial.println(Robocar::_mSpeed);
  analogWrite(Robocar::_speed1, Robocar::_mSpeed);
  analogWrite(Robocar::_speed2, Robocar::_mSpeed);
}

void Robocar::robotForward(){
    digitalWrite(Robocar::_motor11, HIGH);
    digitalWrite(Robocar::_motor12, LOW);
    digitalWrite(Robocar::_motor21, HIGH);
    digitalWrite(Robocar::_motor22, LOW);
    //Robocar::setMotorSpeed(Robocar::_mSpeed);
}

void Robocar::robotHalt(){
    digitalWrite(_motor11, LOW);
    digitalWrite(_motor12, LOW);
    digitalWrite(_motor21, LOW);
    digitalWrite(_motor22, LOW);
    //Robocar::setMotorSpeed(Robocar._mSpeed);
}



void Robocar::robotRight(){
    digitalWrite(_motor11, HIGH);
    digitalWrite(_motor12, LOW);
    digitalWrite(_motor21, LOW);
    digitalWrite(_motor22, LOW);
    //Robocar::setMotorSpeed(Robocar._mSpeed);
}

void Robocar::robotReverse(){
    digitalWrite(_motor11, LOW);
    digitalWrite(_motor12, HIGH);
    digitalWrite(_motor21, LOW);
    digitalWrite(_motor22, HIGH);
    //Robocar::setMotorSpeed(Robocar._mSpeed);
}

void Robocar::robotLeft(){
    digitalWrite(_motor11, LOW);
    digitalWrite(_motor12, LOW);
    digitalWrite(_motor21, HIGH);
    digitalWrite(_motor22, LOW);
    //Robocar::setMotorSpeed(Robocar.mSpeed);
}



void Robocar::robotDirection(uint8_t dir){
  //Direction Options
  //  forward=1,
  //  right=2,
  //  reverse=3,
  //  left=4,
  //  halt=0,
  if(dir==1){
    Robocar::robotForward();
    Serial.println("forward");
  }else if(dir==2){
    Robocar::robotRight();
    Serial.println("right");
  }else if(dir==3){
    Robocar::robotReverse();
    Serial.println("reverse");
  }else if(dir==4){
    Robocar::robotLeft();
    Serial.println("left");
  }else if(dir==0){
    Robocar::robotHalt();
    Serial.println("stopped");
  }else{
      Serial.println(dir);
      Serial.println("not running");
  }
}
