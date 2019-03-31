#ifndef SERVOS_CPP
#define SERVOS_CPP

#include "servos.h"
#include <Arduino.h>

servos::servos(void){}

void servos::attach(int *angle_max, int *reset_pos){
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	digitalWrite(12, LOW);
	int pin[6] = {4, 5, 6, 7, 8, 9};
	for(int i = 0 ; i<=5; i++){
		this->sv[i].attach(pin[i]);
		this->sv[i].set_angle_max(angle_max[i]);
		this->reset_position[i] = reset_pos[i];
	}
	this->reset();
	this->n_servo_movement = 10;
}

void servos::detach() {
	for(int i = 0; i<= 5; i++)
		this->sv[i].detach();
}

//====================== movement ======================

void servos::reset(void){
	int speed[6] = { 50, 30, 30, 30, 30, 30};
	this->write_all(this->reset_position, speed);
}

void servos::movement(void){
	int value = analogRead(A0);
	int space = 1023/this->n_servo_movement;
	int choice = value % space;
	
	if(choice == 0) // 
		this->reset();
	if(choice == 1) // 
		this->Backward_Circle();
	if(choice == 2) // 
		this->Chest_Sport();
	if(choice == 3) // 
		this->Chest_Sport2();
	if(choice == 4) // 
		this->Clockwise();
	if(choice == 5) // 
		this->Counter_Clockwise();
	if(choice == 6) // 
		this->Forward_Circle();
	if(choice == 7) // 
		this->Left_Turn();
	if(choice == 8) // 
		this->Right_Turn();
	if(choice == 9) // 
		this->Swing();
	
	digitalWrite(12, HIGH);
	delay(10); //sending signal to the master after complete the movement
	digitalWrite(12, LOW);
}

void servos::Backward_Circle(void){
	// reset
	this->reset();
	
	// swing up
	int position[6] = {180, -1, -1, 0, -1, -1};
	this->write_all(position);
	
	int position1[6] = {-1, 45, -1, -1, 135, -1};
	int speed[6] = {30, 50, 30, 30, 50, 30};
	this->write_all(position1, speed);
	
	int position2[6] = {0, -1, -1, 180, -1, -1};
	int speed1[6] = {255, 30, 30, 255, 30, 30};
	this->write_all(position2, speed1);
	
	int position3[6] = {-1, 135, -1, -1, 45, -1};
	int speed2[6] = {30, 50, 30, 30, 50, 30};
	this->write_all(position3, speed2);
	
	// reset
	this->reset();
}

void servos::Chest_Sport(void){
	// reset
	this->reset();
	
	// swing up
	int position[6] = {147, -1, -1, 30, -1, -1};
	this->write_all(position);
	
	int position1[6] = {-1, 45, -1, -1, 135, -1};
	this->write_all(position1);
	
	int position2[6] = {-1, 90, -1, -1, 90, -1};
	this->write_all(position2);
	
	int position3[6] = {-1, 30, 80, -1, 150, 110};
	this->write_all(position3);
	
	int position4[6] = {147, 135, 100, 30, 45, 90};
	int speed[6] = {50, 30, 30, 30, 30, 30};
	this->write_all(position4, speed);
	
	// reset
	this->reset();
}

void servos::Chest_Sport2(void){
	// reset
	this->reset();
	
	int position[6] = {180, -1, -1, 0, -1, -1};
	this->write_all(position);
	
	int position1[6] = {57, 0, 70, 120, 180, 120};
	this->write_all(position1);
	
	int position2[6] = {180, 135, 100, 0, 45, 90};
	this->write_all(position2);
	
	// reset
	this->reset();
}

void servos::Clockwise(void){
	// reset
	this->reset();
	
	int position[6] = {0, -1, -1, 0, -1, -1};
	int speed[6] = {30, 30, 30, 90, 30, 30};
	this->write_all(position, speed);
	
	int position1[6] = {-1, 45, -1, -1, 135, -1};
	int speed2[6] = {30, 50, 30, 30, 50, 30};
	this->write_all(position1, speed2);
	
	int position2[6] = {180, -1, -1, 180, -1, -1};
	int speed3[6] = {255, 30, 30, 255, 30, 30};
	this->write_all(position2, speed3);
	
	int position3[6] = {-1, 135, -1, -1, 45, -1};
	int speed4[6] = {30, 50, 30, 30, 50, 30};
	this->write_all(position3, speed4);
	
	// reset
	this->reset();
	
}

void servos::Counter_Clockwise(void){
	// reset
	this->reset();
	
	int position[6] = {180, -1, -1, 180, -1, -1};
	int speed[6] = {90, 30, 30, 30, 30, 30};
	this->write_all(position, speed);
	
	int position1[6] = {-1, 45, -1, -1, 135, -1};
	int speed2[6] = {30, 50, 30, 30, 50, 30};
	this->write_all(position1, speed2);
	
	int position2[6] = {0, -1, -1, 0, -1, -1};
	int speed3[6] = {255, 30, 30, 255, 30, 30};
	this->write_all(position2, speed3);
	
	int position3[6] = {-1, 135, -1, -1, 45, -1};
	int speed4[6] = {30, 50, 30, 30, 50, 30};
	this->write_all(position3, speed4);
	
	// reset
	this->reset();
	
}

void servos::Forward_Circle(void){
	// reset
	this->reset();
	
	int position[6] = {0, -1, -1, 180, -1, -1};
	int speed[6] = {30, 30, 30, 30, 30, 30};
	this->write_all(position, speed);
	
	int position1[6] = {-1, 45, -1, -1, 135, -1};
	int speed2[6] = {30, 70, 30, 30, 70, 30};
	this->write_all(position1, speed2);
	
	int position2[6] = {180, -1, -1, 0, -1, -1};
	int speed3[6] = {255, 30, 30, 255, 30, 30};
	this->write_all(position2, speed3);
	
	int position3[6] = {-1, 135, -1, -1, 45, -1};
	int speed4[6] = {30, 70, 30, 30, 70, 30};
	this->write_all(position3, speed4);
	
	// reset
	this->reset();
	
}

void servos::Left_Turn(void){
	// reset
	this->reset();
	
	int position[6] = {147, -1, -1, 30, -1, -1};
	int speed[6] = {255, 30, 30, 255, 30, 30};
	this->write_all(position, speed);
	
	int position1[6] = {-1, 145, 140, -1, 150, -1};
	int speed2[6] = {30, 70, 15, 30, 50, 30};
	this->write_all(position1, speed2);
	
	int position2[6] = {-1, 135, 100, -1, 45, -1};
	int speed3[6] = {255, 70, 15, 255, 50, 30};
	this->write_all(position2, speed3);
	
	int position3[6] = {-1, 145, 140, -1, 150, -1};
	int speed4[6] = {30, 70, 15, 30, 50, 30};
	this->write_all(position3, speed4);
	
	// reset
	this->reset();
	
}

void servos::Right_Turn(void){
  // reset
  this->reset();
  
  // swing up
  int position[6] = {147, -1, -1, 30, -1, -1};
  this->write_all(position);
  
  int position1[6] = {-1, 20, -1, -1, 35, 50};
  int speed[6] = {30, 50, 30, 30, 50, 15};
  this->write_all(position1, speed);
  
  int position2[6] = {-1, 135, -1, -1, 45, 90};
  int speed1[6] = {30, 50, 30, 30, 50, 15};
  this->write_all(position2, speed1);
  
  int position3[6] = {-1, 20, -1, -1, 35, 50};
  int speed2[6] = {30, 50, 30, 30, 50, 15};
  this->write_all(position3, speed2);
  
  // reset
  this->reset();
}

void servos::Swing(void){
	// reset
	this->reset();
	
	// swing up
	int position[6] = {147, -1, -1, 30, -1, -1};
	this->write_all(position);
	
	int position1[6] = {-1, 95, 180, -1, 85, 10};
	this->write_all(position1);
	
	delay(5000);
	
	// reset
	this->reset();
}

void servos::motor(void){
	int value = analogRead(A0);
	if(value >= 0 && value <= 341){
		analogWrite(2, 0);
		analogWrite(3, 0);
		analogWrite(10, 0);
		analogWrite(11, 0);
	}
	else if(value >= 342 && value <= 683){ //clockwise
		analogWrite(2, 255);
		analogWrite(3, 0);
		analogWrite(10, 255);
		analogWrite(11, 0);
	}
	else if(value >= 684 && value <= 1023){ //counter clockwise
		analogWrite(2, 255);
		analogWrite(3, 0);
		analogWrite(10, 0);
		analogWrite(11, 255);
	}
}

//====================== low level ======================

void servos::write(int num, int angle, int speed){
	this->sv[num].write(angle, speed);
}

void servos::write_all(int *position){
	for (int i = 0; i<=5; i++){
		if (position[i] > 0){
			this->sv[i].write(position[i], 30);
		}
	}
	for(int i = 0; i<=5; i++)
		this->sv[i].wait();
}

void servos::write_all(int *position, int *speed){
	for (int i = 0; i<=5; i++){
		if (position[i] > 0){
			this->sv[i].write(position[i], speed[i]);
		}
	}
	for(int i = 0; i<=5; i++)
		this->sv[i].wait();
}


	

#endif