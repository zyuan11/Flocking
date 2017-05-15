#include "Vehicle.h"


Vehicle::Vehicle(float x, float y)
{
	shape.setPointCount(3);
	shape.setPoint(0, sf::Vector2f(0, 0));
	shape.setPoint(1, sf::Vector2f(0, 10));
	shape.setPoint(2, sf::Vector2f(20, 5));
	shape.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	shape.setFillColor(sf::Color(81, 125, 153));
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(1);

	loc = PVector(x, y);
	vel = PVector(0.0f, 0.0f);
	acc = PVector(0.0f, 0.0f);

	desired = PVector(0.0f, 0.0f);
	steer = PVector(0.0f, 0.0f);

	r = 10.0f;
	maxSpeed = 0.005f;
	maxForce = 0.1f;
}

void Vehicle::update() {
	vel.add(acc);
	vel.limit(maxSpeed);
	loc.add(vel);
	acc.mul(0);

	shapeUpdate();
}

void Vehicle::shapeUpdate() {
	shape.setPosition(sf::Vector2f(loc.x, loc.y));

	// If boid exits right boundary
	if (shape.getPosition().x > WINDOW_WIDTH)
		shape.setPosition(shape.getPosition().x - WINDOW_WIDTH, shape.getPosition().y);
	// If boid exits bottom boundary
	if (shape.getPosition().y > WINDOW_HEIGHT)
		shape.setPosition(shape.getPosition().x, shape.getPosition().y - WINDOW_HEIGHT);
	// If boid exits left boundary
	if (shape.getPosition().x < 0)
		shape.setPosition(shape.getPosition().x + WINDOW_WIDTH, shape.getPosition().y);
	// If boid exits top boundary
	if (shape.getPosition().y < 0)
		shape.setPosition(shape.getPosition().x, shape.getPosition().y + WINDOW_HEIGHT);
	
}

void Vehicle::applyForce(PVector force) {
	acc.add(force);
}

void Vehicle::seek(PVector target) {
	desired.sub(target, loc);
	desired.normalize();
	desired.mul(maxSpeed);

	steer.sub(desired, vel);
	steer.limit(maxForce);
	applyForce(steer);

}

float Vehicle::getSize() {
	return r;
}
sf::Vector2f Vehicle::getLoc() {
	return sf::Vector2f(loc.x, loc.y);
}

float Vehicle::heading() {
	return vel.angle();
}


void Vehicle::DisplayInfo() {
	std::cout << "Vehicle Loc: " << loc.x << ", " << loc.y << endl;
	std::cout << "Acceleration: " << acc.x << ", " << acc.y << endl;
	std::cout << "Velocity: " << vel.x << ", " << vel.y << endl;

}
