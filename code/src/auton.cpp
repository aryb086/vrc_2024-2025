// autonomous.cpp
#include "main.h"
#include "robot.h"


void intakeForward(){
    intake_motors.move(100);
}

void intakeReverse(){
    intake_motors.move(-100);
}

void intakeStop(){
    intake_motors.move(0);
}

void clampOut(){
    clamp.set_value(HIGH);
}

void clampIn(){
    clamp.set_value(LOW);
}

void autonomous() {
    clampOut();
    chassis.setPose(0, 0, 0);
    // chassis.moveToPose(60, 20, 90, 4000);
    chassis.moveToPoint(0, -35, 1000,{.forwards = false, .maxSpeed = 60}, false);
    pros::delay(200);
    clampIn();
    chassis.turnToPoint(15, -35, 1000);
    intakeForward();
    chassis.moveToPoint(15, -35, 1000, {.maxSpeed = 60}, false);
    pros::delay(1000);
    chassis.turnToPoint(-8, 7, 1000);
    intakeForward();
    chassis.moveToPoint(-8, 7, 10000, {.maxSpeed = 40}, false);
    chassis.turnToPoint(-19, -10, 1000);
    pros::delay(1000);
    intakeStop();
    chassis.moveToPoint(-19, -10, 10000, {.maxSpeed = 40}, false);
    clampOut();
}