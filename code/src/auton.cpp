// autonomous.cpp
#include "main.h"
#include "robot.h"




void autonomous() {
    chassis.setPose(0, 0, 0);
    // chassis.moveToPose(60, 20, 90, 4000);
    chassis.moveToPose(138, -61, 0, 100);
}