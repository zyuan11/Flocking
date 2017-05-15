#pragma once
#include "config.h"

class PVector {
public:
	float x;
	float y;

	PVector() {};
	PVector(float x, float y);
	void set(float x, float y);

	void sub(PVector pv1, PVector pv2);
	void add(PVector pv);
	void mul(float factor);
	
	float magnitude();
	void normalize();
	void limit(float max);
	
	float angle();

	void DisplayInfo();
};