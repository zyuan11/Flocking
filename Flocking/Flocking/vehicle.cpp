#include "vehicle.h"

Vehicle::Vehicle() {
	vel = sf::Vector2f(0, 0);
	loc = sf::Vector2f(0, 0);
	acc = sf::Vector2f(0, 0);

	MaxSpeed = 4;
}

void Vehicle::normalize() {
	float length_vel_desired = sqrt(pow(vel_desired.x, 2) + pow(vel_desired.y, 2));
	vel_desired.x = vel_desired.x / length_vel_desired;
	vel_desired.y = vel_desired.y / length_vel_desired;
}

void Vehicle::setSteer() {
	steer = vel_desired - vel;
}

void Vehicle::getDesired(sf::Vector2f target) {
	vel_desired = target - loc;
}

void Vehicle::seek(sf::Vector2f target) {
	getDesired(target);
	normalize();
	vel_desired *= MaxSpeed;

	setSteer();
	applyForce();
}

void Vehicle::applyForce() {
	acc += steer;
}