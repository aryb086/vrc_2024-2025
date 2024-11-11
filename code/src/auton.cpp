// autonomous.cpp
#include "main.h"
#include "robot.h"

void autonomous() {
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(180, 100000);
}