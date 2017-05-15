#pragma once
#include "PVector.h"
#include "config.h"

class Vehicle {
	PVector loc;	//location of vehicle
	PVector vel;	//velocity of vehicle
	PVector acc;	//acceleration of vehicle

	float r;		//for size
	float maxForce;	//maximum force can be applied to vehicle
	float maxSpeed;	//maximum speed vehicle can have

	PVector desired;
	PVector steer;

public:
	sf::ConvexShape shape;	//shape of vehicle

	Vehicle() {}
	Vehicle(float x, float y);
	void update();
	void shapeUpdate();
	void applyForce(PVector force);
	void seek(PVector target);

	float getSize();
	sf::Vector2f getLoc();


	float heading();

	void DisplayInfo();
};
