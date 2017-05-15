#include "PVector.h"

PVector::PVector(float x_i, float y_i)
{
	x = x_i;
	y = y_i;
}
void PVector::set(float x_i, float y_i) {
	x = x_i;
	y = y_i;
}


void PVector::sub(PVector pv1, PVector pv2) {
	set(pv1.x - pv2.x, pv1.y - pv2.y);
}
void PVector::add(PVector pv)
{
	x += pv.x;
	y += pv.y;
	//set(pv.x + x, pv.y + y);
}
void PVector::mul(float factor) {
	set(x * factor, y * factor);
}


float PVector::magnitude() {
	return sqrt(pow(x, 2) + pow(y, 2));
}
void PVector::normalize() {
	float length = magnitude();
	set(x / length, y / length);
}
void PVector::limit(float max) {
	float length = magnitude();
	if (length > max) {
		set(x / length * max, y / length * max);
	}
}

float PVector::angle() {
	return (float)(atan2(x, -y) * 180 / PI);
}

void PVector::DisplayInfo() {
	std::cout << x << ", " << y << endl;
}