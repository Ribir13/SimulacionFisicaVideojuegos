#pragma once
#include "Particle.h"

class ForceGenerator
{
public:
	ForceGenerator() {};
	virtual void updateForce(Particle* p, double dt) = 0;
	virtual void update(double dt) {};
	virtual bool isFinished() { return false; }
};

