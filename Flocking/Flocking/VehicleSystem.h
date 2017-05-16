#pragma once
#include "Vehicle.h"
#include "config.h"
#include <iostream>
#include <vector>
#include <memory>


class VehicleSystem {
public:
	std::vector<Vehicle> flock;
	float SepWeight, AliWeight, CohWeight;

	VehicleSystem() {}
	~VehicleSystem() {}

	void flockInit(int flockSize);
	void addVehicle(Vehicle *v);
	void removeVehicle();
	
	void TurnOnSep();
	void TurnOffSep();
	void IncreaseSep();
	void DecreaseSep();

	void TurnOnAli();
	void TurnOffAli();
	void IncreaseAli();
	void DecreaseAli();
	
	void TurnOnCoh();
	void TurnOffCoh();
	void IncreaseCoh();
	void DecreaseCoh();

	int getSize();
};