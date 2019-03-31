#ifndef SERVOS_H
#define SERVOS_H

#include <VarSpeedServo.h>
#include <Arduino.h>

class servos{
public:
	servos(void);
	void attach(int *angle_max, int *reset_position);
	void detach(void);
	
	void movement(void);
	void reset(void);
	void Backward_Circle(void);
	void Chest_Sport(void);			
	void Chest_Sport2(void);			
	void Clockwise(void);			
	void Counter_Clockwise(void);			
	void Forward_Circle(void);			
	void Left_Turn(void);			
	void Right_Turn(void);			
	void Swing(void);			
	
	void motor(void);
	
	void write(int num, int angle, int speed);
	void write_all(int *position, int *speed);
	void write_all(int *position); // defualt speed: 30
	
	
private:

	VarSpeedServo sv[6];
	int reset_position[6];
	int n_servo_movement;

};

#endif