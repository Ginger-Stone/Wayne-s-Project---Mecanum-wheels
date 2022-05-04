#ifndef ROBOCAR_H_INCLUDED
#define ROBOCAR_H_INCLUDED
#include "arduino.h"

class Robocar{
public:
    uint8_t _motor11;
    uint8_t _motor12;
    uint8_t _motor21;
    uint8_t _motor22;
    uint8_t _speed1;
    uint8_t _speed2;
    uint8_t _dir;

    //motor speed selector
    enum speedSelection{
      high=255,
      medium=210,
      low=190,
    };
    speedSelection _mSpeed;

    //wheels[4] --> pins used for the wheels - going clockwise
    Robocar(uint8_t wheels[4], uint8_t speed[2]); //1 pass the wheel pins and default speed


    void robotForward();
    void robotRight();
    void robotReverse();
    void robotLeft();
    void robotHalt();
    void setMotorSpeed(speedSelection speedSelection);
    void robotDirection(uint8_t);

};



#endif // ROBOCAR_H_INCLUDED
