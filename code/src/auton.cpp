// autonomous.cpp
#include "main.h"
#include "robot.h"


void intakeForward(int speed){
    intake_motors.move(speed);
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
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 15, 1000, {.maxSpeed = 70}, false);
    chassis.turnToPoint(-10, 16, 1000, {.maxSpeed = 70}, false);
    intakeForward(80);
    pros::delay(200);
    chassis.moveToPoint(4, 15, 1000, {.maxSpeed = 5});
    pros::delay(1000);
    //at team stake
    chassis.moveToPoint(4.5, 14, 1000, {.maxSpeed = 80}, false);
    chassis.moveToPoint(5, 14, 1000, {.maxSpeed = 80}, false);
    pros::delay(100);
    intakeStop();

    //moving away from the team stake
    chassis.moveToPoint(-6, 14, 1000, {.maxSpeed = 60}, false);
    pros::delay(100);
    


    clampOut();
    chassis.moveToPoint(-6, -12, 1000,{.forwards = false, .maxSpeed = 80}, false);

    //going to yellow stake
    chassis.turnToPoint(-28, -5, 1000, {.forwards = false, .maxSpeed = 60}, false);
    chassis.moveToPoint(-34, -7, 2000,{.forwards = false, .maxSpeed = 60}, false);

    
    //clamping yellow stake
    clampIn();
    pros::delay(100);

    intakeForward(127);

    //going to intaked ring
    chassis.turnToPoint(-38, -20, 1000, {.maxSpeed = 60}, false);
    chassis.moveToPoint(-38, -26, 1000, {.maxSpeed = 80}, false);


    //chassis.moveToPoint(-40, -30, 1000, {.maxSpeed = 60}, false);

    chassis.turnToPoint(-50, -26, 1000);
    chassis.moveToPoint(-48, -26, 1000, {.maxSpeed = 80}, false);
    pros::delay(500);

    chassis.turnToPoint(-48, 14, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(-48, 14, 1000, {.forwards = false, .maxSpeed = 80});
    clampOut();
    chassis.moveToPoint(-48, 6, 1000, {.forwards = false, .maxSpeed = 80});
}

void auton1(){
    chassis.setPose(0, 0, 0);
    intakeForward(127);
    chassis.turnToPoint(20, 60, 1000);
    chassis.moveToPoint(20, 40, 2000, {.maxSpeed = 60}, false);
    chassis.turnToPoint(25, 60, 1000, {.forwards = false});
    clampOut();
    chassis.moveToPoint(25, 50, 2000, {.forwards = false, .maxSpeed = 40}, false);
    clampIn();
    pros::delay(1000);
    chassis.moveToPoint(0, 0, 4000);
}