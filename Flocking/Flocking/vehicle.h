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

	float desiredSep;
	float neighbordist;

	Vehicle();
	~Vehicle() {};
	void VehicleInit(float x, float y);
	void update();
	void shapeUpdate();
	void applyForce(PVector force);

	PVector seek(PVector target);
	float heading();

	float getSize();
	sf::Vector2f getLoc();

	void DoFlock(vector<Vehicle> vehicles, float SepWeight, float AliWeight, float CohWeight, sf::Vector2i cursor);
	PVector separate(vector<Vehicle> vehicles);
	PVector align(vector<Vehicle> vehicles);
	PVector coheret(vector<Vehicle> vehicles);
	
	void DisplayInfo();
};
