#pragma once
#include "Vehicle.h"
#include "config.h"
#include <iostream>
#include <vector>
#include <memory>


class VehicleSystem {
public:
	std::vector<Vehicle> flock;

	VehicleSystem() {}
	~VehicleSystem() {}

	void flockInit(int flockSize);
	void addVehicle(Vehicle *v);
	void removeVehicle();

	int getSize();
};