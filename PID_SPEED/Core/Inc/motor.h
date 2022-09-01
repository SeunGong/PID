/*
 * motor.h
 *
 *  Created on: Sep 1, 2022
 *      Author: yunseoungho
 */

//Coefficient Kp,Ki,Kd
float Kp = 0.0;
float Ki = 0.0;
float Kd = 0.0;

float P, I = 0, D;
float error = 0, preError = 0;
float dt = 0.1;
extern uint8_t rdt; //[reverse dt] If dt=0.1s this is reverse variable for cacluation.

float PID(float target, float current) {
	error = (float) (target - current);
	P = Kp * error;
	I += Ki * error * dt;
	D = Kd * (error - preError) * rdt;
	preError = error;
	return P + I + D;
}
