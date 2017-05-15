#include "VehicleSystem.h"

void VehicleSystem::flockInit(int flockSize) {
	for (int i = 0; i < flockSize; ++i) {
		Vehicle *v = new Vehicle;
		v->VehicleInit(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		addVehicle(v);
	}
}

void VehicleSystem::addVehicle(Vehicle *v) {
	flock.push_back(*v);
}

int VehicleSystem::getSize() {
	return flock.size();
}

void VehicleSystem::removeVehicle() {
	flock.pop_back();
}