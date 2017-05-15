#include "VehicleSystem.h"

void VehicleSystem::flockInit(int flockSize) {
	//flock = std::vector<Vehicle>(flockSize);
	//Vehicle v = Vehicle(500.0f, 250.0f);
	Vehicle v = Vehicle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	addVehicle(v);
	/*for (int i = 0; i < flockSize; ++i) {
		
	}*/
}

void VehicleSystem::addVehicle(Vehicle v) {
	flock.push_back(v);
}

int VehicleSystem::getSize() {
	return flock.size();
}