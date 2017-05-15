#include "Vehicle.h"


Vehicle::Vehicle()
{
	shape.setPointCount(3);
	shape.setPoint(0, sf::Vector2f(0, 0));
	shape.setPoint(1, sf::Vector2f(0, 10));
	shape.setPoint(2, sf::Vector2f(20, 5));
	shape.setPosition(0.0f, 0.0f);
	shape.setFillColor(sf::Color(81, 125, 153));
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(1);

	loc.set(0.0f, 0.0f);
	vel.set(0.0f, 0.0f);
	acc.set(0.0f, 0.0f);

	desired.set(0.0f, 0.0f);
	steer.set(0.0f, 0.0f);

	r = 10.0f;
	maxSpeed = 0.1f;
	maxForce = 0.5f;

	desiredSep = 40.0f;
	neighbordist = 50.0f;
}

void Vehicle::VehicleInit(float x, float y) {
	shape.setPosition(x, y);
	loc.set(x, y);
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
	shape.setRotation(heading());

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

void Vehicle::separate(vector<Vehicle> vehicles) {
	maxSpeed = 10.0f;
	PVector sum;
	int count = 0;
	for (Vehicle other : vehicles) {
		float dist = loc.dist(loc, other.loc);
		if (dist > 0 && dist < desiredSep) {
			PVector diff;
			diff.sub(loc, other.loc);
			diff.normalize();
			diff.div(dist);
			sum.add(diff);
			count++;
		}
	}
	
	if (count > 0) {
		sum.div(count);
		sum.normalize();
		sum.mul(maxSpeed);
		steer.sub(sum, vel);
		steer.limit(maxForce);
		applyForce(steer);
	}
}
void Vehicle::align(vector<Vehicle> vehicles) {
	maxSpeed = 10.0f;
	PVector sum;
	int count = 0;
	for (Vehicle other : vehicles) {
		float dist = loc.dist(loc, other.loc);
		if (dist > 0 && dist < neighbordist) {
			sum.add(other.vel);
			count++;
		}
		sum.add(other.vel);
	}
	
	if (count > 0) {
		sum.div(count);
		sum.normalize();
		sum.mul(maxSpeed);
		steer.sub(sum, vel);
		steer.limit(maxForce);
		applyForce(steer);
	}
}
void Vehicle::coheret(vector<Vehicle> vehicles) {
	maxSpeed = 10.0f; 
	PVector sum;
	sum.set(0, 0);
	int count = 0;
	for (Vehicle other : vehicles) {
		float dist = loc.dist(loc, other.loc);
		if (dist > 0 && dist < neighbordist) {
			sum.add(other.vel);
			count++;
		}
		sum.add(other.vel);
	}

	if (count > 0) {
		sum.div(count);
		seek(sum);
	}
}

