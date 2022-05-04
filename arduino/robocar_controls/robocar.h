#ifndef ROBOCAR_H_INCLUDED
#define ROBOCAR_H_INCLUDED
#include "arduino.h"

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

//Robocar Two Wheeled
class Robocar{
public:
    //motor speed selector
    typedef enum speedSelection{
        high=255,
        medium=210,
        low=190,
    };
    speedSelection _mSpeed;

    //Robocar Type selector
    typedef enum robocarType{
        normal,
        mecanum,
    };

    Robocar(robocarType robocarType, uint8_t wheels[8]={0}, uint8_t speeds[4]={0}); // pass the wheel pins and default speed

    uint8_t _wheels[8]={0}; //{1,2,3,4,5,6,7,8} as shown in Wheel Pin Configuration
    uint8_t _speeds[4]={0}; //{1,2,3,4} as shown in Wheel Speed Configuration
    uint8_t _dir;

    enum speedSelection;
    enum robocarType;

    void robotForward();
    void robotRight();
    void robotReverse();
    void robotLeft();
    void robotHalt();
    void setMotorSpeed(enum speedSelection);
    void robotDirection(uint8_t);


};

#endif // ROBOCAR_H_INCLUDED
