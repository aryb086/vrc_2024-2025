// main.cpp
#include "main.h"
#include "robot.h"
#include "utils.h"


void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            pros::delay(20);
        }
    });
}

void disabled() {}

void competition_initialize() {}

void opcontrol() {
    while (true) {
        // hello
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        chassis.tank(leftY, rightY);


    bool intakeStarted = false;

    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        intake_motors.move(120);
        ;intakeStarted = true;
    }else{
        intake_motors.move(0)
        ;intakeStarted = false;
    }

    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        intake_motors.move(0);
    }

        pros::delay(25);

    }
    
}
