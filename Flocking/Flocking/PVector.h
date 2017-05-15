#pragma once
#include "config.h"

class PVector {
public:
	float x;
	float y;

	PVector();
	~PVector() {}
	void set(float x, float y);

	void sub(PVector pv1, PVector pv2);
	void add(PVector pv);
	void mul(float factor);
	void div(float factor);
	
	float magnitude();
	void normalize();
	void limit(float max);
	
	float angle();
	float dist(PVector pv1, PVector pv2);

	void DisplayInfo();
};