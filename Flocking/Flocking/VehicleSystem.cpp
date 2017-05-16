#include "VehicleSystem.h"

void VehicleSystem::flockInit(int flockSize) {
	SepWeight = 1.0f;
	AliWeight = 1.0f;
	CohWeight = 0.0f;

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

void VehicleSystem::TurnOnSep() {
	SepWeight = 1.0f;
}
void VehicleSystem::TurnOffSep() {
	SepWeight = 0.0f;
}
void VehicleSystem::IncreaseSep() {
	SepWeight += 0.001f;
}
void VehicleSystem::DecreaseSep() {
	if (SepWeight >= 0.001f)
		SepWeight -= 0.001f;
}

void VehicleSystem::TurnOnAli() {
	AliWeight = 1.0f;
}
void VehicleSystem::TurnOffAli() {
	AliWeight = 0.0f;
}
void VehicleSystem::IncreaseAli() {
	AliWeight += 0.001f;
}
void VehicleSystem::DecreaseAli() {
	if (AliWeight >= 0.001f)
		AliWeight -= 0.001f;
}

void VehicleSystem::TurnOnCoh() {
	CohWeight = 1.0f;
}
void VehicleSystem::TurnOffCoh() {
	CohWeight = 0.0f;
}
void VehicleSystem::IncreaseCoh() {
	CohWeight += 0.001f;
}
void VehicleSystem::DecreaseCoh() {
	if (CohWeight >= 0.001f)
		CohWeight -= 0.001f;
}
