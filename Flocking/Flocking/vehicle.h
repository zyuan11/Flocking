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

	//FOR SEPARATION
	

public:
	sf::ConvexShape shape;	//shape of vehicle

	float desiredSep;
	float neighbordist;

	Vehicle();
	~Vehicle() {};
	void VehicleInit(float x, float y);
	void update();
	void shapeUpdate();
	void applyForce(PVector force);
	void seek(PVector target);
	float heading();

	float getSize();
	sf::Vector2f getLoc();

	void separate(vector<Vehicle> vehicles);
	void align(vector<Vehicle> vehicles);
	void coheret(vector<Vehicle> vehicles);
	
	void DisplayInfo();
};
