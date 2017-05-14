#pragma once
#include "main.h"

class Vehicle {
	sf::Vector2f loc;	//location of vehicle
	sf::Vector2f vel;	//velocity of vehicle
	sf::Vector2f acc;	//velocity of acceleration

	float MaxSpeed;

	sf::Vector2f steer;	//steer force
	sf::Vector2f vel_desired; 

	Vehicle();

	void normalize();
	void setSteer();
	void getDesired(sf::Vector2f target);
	void seek(sf::Vector2f target);
	void applyForce();

};
