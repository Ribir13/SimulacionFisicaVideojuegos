#pragma once

#include "Vector3D.h"
#include "PxPhysics.h"
#include "RenderUtils.hpp"

class Particle
{
public:
	Particle(Vector3D Pos, Vector3D Vel, Vector3D Acc, float Damp);
	~Particle();

	void integrate(double t);
	void integrateSemi(double t);

private:
	Vector3D acc;
	Vector3D vel;
	physx::PxTransform pose;
	RenderItem* renderItem;

	Vector3D prevPos;

	float damp;

	const double gFixedTimestep = 1.0 / 60.0;
};

